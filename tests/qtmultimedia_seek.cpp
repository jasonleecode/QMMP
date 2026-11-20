#include <QApplication>
#include <QAudioDevice>
#include <QElapsedTimer>
#include <QFileInfo>
#include <QMediaDevices>
#include <QPluginLoader>
#include <QProcess>
#include <QScopeGuard>
#include <QTemporaryDir>
#include <QThread>
#include <qmmp/output.h>
#include <qmmp/outputfactory.h>
#include <memory>

int main(int argc, char **argv)
{
    QTemporaryDir temp;
    if(argc != 3 || !temp.isValid())
        return 1;
    const QString socket = temp.filePath("native");
    for(const char *key : {"XDG_RUNTIME_DIR", "XDG_CONFIG_HOME", "XDG_CACHE_HOME", "PULSE_RUNTIME_PATH"})
        qputenv(key, temp.path().toUtf8());
    qputenv("PULSE_SERVER", "unix:" + socket.toUtf8());
    QApplication app(argc, argv);

    QProcess server;
    server.setProcessChannelMode(QProcess::ForwardedChannels);
    server.start(argv[1], {"-n", "--daemonize=no", "--use-pid-file=no", "--exit-idle-time=-1",
                           "--load=module-null-sink sink_name=test rate=48000",
                           "--load=module-native-protocol-unix auth-anonymous=1"});
    if(!server.waitForStarted())
        return 1;
    const auto stopServer = qScopeGuard([&server] { server.terminate(); server.waitForFinished(); });
    QElapsedTimer timer;
    timer.start();
    while(!QFileInfo::exists(socket) && timer.elapsed() < 3000)
        QThread::msleep(10);
    if(!QFileInfo::exists(socket))
        return 1;
    if(QMediaDevices::defaultAudioOutput().id() != "test")
    {
        qInfo() << "This Qt audio backend did not select the isolated PulseAudio sink";
        return 77;
    }

    QPluginLoader loader(argv[2]);
    auto *factory = qobject_cast<OutputFactory *>(loader.instance());
    if(!factory)
    {
        qCritical() << loader.errorString();
        return 1;
    }
    unsigned char silence[32768] = {};
    for(quint32 rate : {44100, 96000})
    {
        std::unique_ptr<Output> output(factory->create());
        if(!output->initialize(rate, ChannelMap(2), Qmmp::PCM_S16LE))
            return 1;
        // The first write to an empty push stream exposes its negotiated capacity.
        const qint64 initial = output->writeAudio(silence, sizeof(silence));
        if(initial <= 0)
            return 1;
        for(int seek = 1; seek <= 16; ++seek)
        {
            output->reset();
            app.processEvents();
            const qint64 capacity = output->writeAudio(silence, sizeof(silence));
            if(capacity < initial / 2)
            {
                qCritical() << "Output capacity after seek" << seek << "at" << rate
                            << "Hz fell from" << initial << "to" << capacity << "bytes";
                return 1;
            }
        }
        output.reset();
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
    }
    return 0;
}

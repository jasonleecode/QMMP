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
#include <array>
#include <cmath>
#include <cstring>
#include <QSettings>
#include <qmmp/soundcore.h>

// The null sink and monitor both run at 48 kHz. Opposite channel polarity
// and unequal amplitudes expose float/int reinterpretation and channel swaps.
static bool checkFloatSignal(OutputFactory *factory, const QString &recorder)
{
    std::unique_ptr<Output> output(factory->create());
    if(!output->initialize(48000, ChannelMap(2), Qmmp::PCM_FLOAT))
        return false;
    QProcess monitor;
    monitor.start(recorder, {"--device=test.monitor", "--format=float32ne", "--rate=48000",
                             "--channels=2", "--latency-msec=10"});
    if(!monitor.waitForStarted())
        return false;
    const auto stop = qScopeGuard([&] { monitor.terminate(); monitor.waitForFinished(); });
    std::array<float, 192> tone;
    for(int i = 0; i < 96; ++i)
    {
        tone[2*i] = .25f * std::sin(6.283185307179586 * i / 96);
        tone[2*i+1] = -.5f * tone[2*i];
    }
    auto *bytes = reinterpret_cast<unsigned char *>(tone.data());
    QElapsedTimer timer;
    timer.start();
    int offset = 0;
    QByteArray capture;
    while(timer.elapsed() < 5000 && capture.size() < 48000*8)
    {
        QCoreApplication::processEvents();
        const qint64 wrote = output->writeAudio(bytes + offset, sizeof(tone)-offset);
        if(wrote < 0)
            return false;
        offset = (offset + wrote) % sizeof(tone);
        capture += monitor.readAllStandardOutput();
    }
    int matches = 0;
    for(qsizetype i = 0; i+8 <= capture.size(); i += 8)
    {
        float pair[2];
        std::memcpy(pair, capture.constData()+i, sizeof(pair));
        if(std::abs(pair[0]) > .255f || std::abs(pair[1] + .5f*pair[0]) > .002f)
            return false;
        if(std::abs(pair[0]) > .22f)
            ++matches;
    }
    return matches > 100;
}

static bool waitFor(const std::function<bool()> &ready)
{
    QElapsedTimer timer;
    timer.start();
    while(!ready() && timer.elapsed() < 5000)
    {
        QCoreApplication::processEvents();
        QThread::msleep(5);
    }
    return ready();
}

int main(int argc, char **argv)
{
    QTemporaryDir temp;
    if(argc < 3 || !temp.isValid())
        return 1;
    const QString socket = temp.filePath("native");
    for(const char *key : {"XDG_RUNTIME_DIR", "XDG_CONFIG_HOME", "XDG_CACHE_HOME", "PULSE_RUNTIME_PATH"})
        qputenv(key, temp.path().toUtf8());
    qputenv("PULSE_SERVER", "unix:" + socket.toUtf8());
    QApplication app(argc, argv);
    app.setOrganizationName("qmmp");
    app.setApplicationName("output-test");

    QProcess server;
    server.setProcessChannelMode(QProcess::ForwardedChannels);
    server.start(argv[1], {"-n", "--daemonize=no", "--use-pid-file=no", "--exit-idle-time=-1",
                           "--load=module-null-sink sink_name=test rate=48000",
                           "--load=module-native-protocol-unix auth-anonymous=1"});
    if(!server.waitForStarted())
        return 1;
    const auto stopServer = qScopeGuard([&server] {
        if(server.state() != QProcess::NotRunning)
        {
            server.terminate();
            server.waitForFinished();
        }
    });
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
    if(argc >= 4 && !checkFloatSignal(factory, argv[3]))
    {
        qCritical() << "Float monitor signal differed from the stereo reference";
        return 1;
    }
    if(argc >= 7)
    {
        const QString root = temp.filePath("plugins");
        qputenv("QMMP_PLUGINS", root.toUtf8());
        auto link = [&](const QString &file, const QString &type) {
            QDir dir(root + "/" + type);
            return dir.mkpath(".") && QFile::link(file, dir.filePath(QFileInfo(file).fileName()));
        };
        const QString music = temp.filePath("tone.mp3");
        if(!link(argv[2], "Output") || !link(argv[5], "Input") || !link(argv[6], "Output") ||
           QProcess::execute(argv[4], {"-v", "error", "-f", "lavfi", "-i", "sine=frequency=440",
                                      "-ac", "2", "-t", "12", music}) != 0)
            return 1;
        QSettings().setValue("Output/current_plugin", "qtmultimedia");
        SoundCore core;
        auto playing = [&] { return core.state() == Qmmp::Playing && core.elapsed() > 250; };
        if(!core.play(music) || !waitFor(playing))
            return 1;
        server.terminate();
        server.waitForFinished();
        if(!waitFor([&] { return core.state() == Qmmp::FatalError; }))
        {
            qCritical() << "Device loss did not reach the playback engine";
            return 1;
        }
        core.stop();
        QSettings().setValue("Output/current_plugin", "null");
        if(!core.play(music) || !waitFor(playing))
            return 1;
        core.stop();
    }
    return 0;
}

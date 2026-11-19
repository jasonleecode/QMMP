#include <QApplication>
#include <QDir>
#include <QDockWidget>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QElapsedTimer>
#include <QFile>
#include <QLabel>
#include <QListView>
#include <QMainWindow>
#include <QProcess>
#include <QSettings>
#include <QTemporaryDir>
#include <QThread>
#include <qmmp/decoderfactory.h>
#include <qmmp/soundcore.h>
#include <qmmpui/mediaplayer.h>
#include <qmmpui/uihelper.h>
#include <qmmpui/uiloader.h>
#include <qmmpui/uifactory.h>
#include <memory>

static bool waitFor(const std::function<bool()> &condition)
{
    QElapsedTimer timeout;
    timeout.start();
    while(!condition() && timeout.elapsed() < 5000)
    {
        QCoreApplication::processEvents();
        QThread::msleep(10);
    }
    return condition();
}

static bool linkPlugin(const QString &source, const QString &dir)
{
    return QDir().mkpath(dir) && QFile::link(source, QDir(dir).filePath(QFileInfo(source).fileName()));
}

#define CHECK(expression) do { if(!(expression)) { qCritical() << "Failed at line" << __LINE__ << #expression; return 1; } } while(false)

int main(int argc, char **argv)
{
    QTemporaryDir temp;
    CHECK(temp.isValid() && argc >= 6);
    qputenv("XDG_CONFIG_HOME", temp.path().toUtf8());
    qputenv("XDG_DATA_HOME", temp.path().toUtf8());
    qputenv("XDG_CACHE_HOME", temp.path().toUtf8());
    const QString root = temp.filePath("plugins");
    qputenv("QMMP_PLUGINS", root.toUtf8());
    QApplication app(argc, argv);
    app.setOrganizationName("qmmp");
    app.setApplicationName("test");
    QSettings().setValue("Output/current_plugin", "null");
    CHECK(linkPlugin(argv[2], root + "/Ui"));
    CHECK(linkPlugin(argv[3], root + "/Input"));
    CHECK(linkPlugin(argv[4], Qmmp::configDir() + "/plugins-2.3/Input"));
    CHECK(linkPlugin(argv[5], root + "/Output"));

    QString music;
    for(const QString &ext : { "mp3", "wav", "flac", "ogg", "m4a" })
    {
        const QString path = temp.filePath("春天." + ext);
        const QString seconds = ext == "mp3" ? "0.15" : (ext == "wav" ? "9" : "1");
        CHECK(QProcess::execute(argv[1], { "-v", "error", "-f", "lavfi", "-i", "sine=frequency=440",
                "-ac", "2", "-t", seconds, path }) == 0);
        if(ext == "mp3")
            CHECK(QFileInfo(path).size() < 8192);
        auto *factory = Decoder::findByFilePath(path);
        CHECK(factory);
        QFile input(path);
        CHECK(input.open(QIODevice::ReadOnly));
        std::unique_ptr<Decoder> decoder(factory->create(path, &input));
        CHECK(decoder && decoder->initialize());
        unsigned char buffer[8192];
        qint64 size = 0, n = 0;
        while((n = decoder->read(buffer, sizeof(buffer))) > 0)
            size += n;
        CHECK(n == 0 && size > 0);
        if(ext == "wav")
            music = path;
    }

    QFile invalid(temp.filePath("invalid.mp3"));
    CHECK(invalid.open(QIODevice::WriteOnly));
    invalid.write("invalid audio");
    invalid.close();
    CHECK(!Decoder::findByFilePath(invalid.fileName()));

    // GB18030 bytes for 春天, with repeated timestamps and a global offset.
    QFile lyrics(temp.filePath("春天.lrc"));
    CHECK(lyrics.open(QIODevice::WriteOnly));
    lyrics.write("[offset:100]\n[00:00.10][00:06.10]");
    lyrics.write(QByteArray::fromHex("b4baccec"));
    lyrics.write("\n[00:03.10]Chorus\n");
    lyrics.close();

    MediaPlayer player;
    UiHelper helper(&player);
    auto *factory = UiLoader::selected();
    CHECK(factory && factory->properties().shortName == "classic");
    std::unique_ptr<QObject> ui(factory->create());
    auto *window = qobject_cast<QMainWindow *>(ui.get());
    CHECK(window && window->isVisible());
    auto *current = window->findChild<QLabel *>("activeLyric");
    auto *list = window->findChild<QListView *>();
    auto *title = window->findChild<QLabel *>("song");
    CHECK(current && list && title);
    helper.replaceAndPlay({music});
    auto *core = SoundCore::instance();
    CHECK(waitFor([&] { return core->state() == Qmmp::Playing && current->text() == "春天"; }));
    CHECK(list->currentIndex().row() == 0 && title->text() == "春天");
    core->seek(4200);
    CHECK(waitFor([&] { return current->text() == "Chorus"; }));
    core->seek(6500);
    CHECK(waitFor([&] { return current->text() == "春天"; }));
    core->seek(4000);
    CHECK(waitFor([&] { return current->text() == "Chorus"; }));
    if(argc == 7)
        CHECK(window->grab().save(QString::fromLocal8Bit(argv[6])));
    // Reload the sidecar on a track change and exercise UTF-8 with a BOM.
    const QString second = temp.filePath("雨声.wav");
    CHECK(QFile::copy(music, second));
    QFile utf8Lyrics(temp.filePath("雨声.lrc"));
    CHECK(utf8Lyrics.open(QIODevice::WriteOnly));
    utf8Lyrics.write(QByteArray::fromHex("efbbbf") + QStringLiteral("[00:00]雨声响起").toUtf8());
    utf8Lyrics.close();
    auto dropTrack = [&](QWidget *target) {
        QMimeData data;
        data.setUrls({QUrl::fromLocalFile(second)});
        QDragEnterEvent enter(QPoint(4, 4), Qt::CopyAction, &data, Qt::LeftButton, Qt::NoModifier);
        QApplication::sendEvent(target, &enter);
        QDropEvent drop(QPointF(4, 4), Qt::CopyAction, &data, Qt::LeftButton, Qt::NoModifier);
        QApplication::sendEvent(target, &drop);
        return enter.isAccepted() && drop.isAccepted();
    };
    auto *dock = window->findChild<QDockWidget *>("playlist");
    CHECK(dock && dock->acceptDrops());
    for(bool floating : {false, true})
    {
        dock->setFloating(floating);
        const int count = list->model()->rowCount();
        CHECK(dropTrack(list->viewport()));
        CHECK(waitFor([&] { return list->model()->rowCount() == count + 1; }));
        CHECK(core->state() == Qmmp::Playing && title->text() == "春天");
    }
    CHECK(dropTrack(title));
    CHECK(waitFor([&] { return title->text() == "雨声" && current->text() == "雨声响起"; }));
    player.stop();
    return 0;
}

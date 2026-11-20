#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QPainter>
#include <QSlider>
#include <QToolButton>
#include <QDir>
#include <QDataStream>
#include <QMouseEvent>
#include <QDockWidget>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QElapsedTimer>
#include <QFile>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QLayout>
#include <QLibraryInfo>
#include <QListView>
#include <QListWidget>
#include <QMainWindow>
#include <QProcess>
#include <QSettings>
#include <QScreen>
#include <QTemporaryDir>
#include <QThread>
#include <QTimer>
#include <QTranslator>
#include <qmmp/decoderfactory.h>
#include <qmmp/qmmptextcodec.h>
#include <qmmp/soundcore.h>
#include <qmmpui/mediaplayer.h>
#include <qmmpui/uihelper.h>
#include <qmmpui/qmmpuisettings.h>
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

static void clickWidget(QWidget *widget)
{
    const QPointF pos(widget->rect().center());
    for(auto type : {QEvent::MouseButtonPress, QEvent::MouseButtonRelease})
    {
        QMouseEvent event(type, pos, widget->mapToGlobal(pos), Qt::LeftButton,
                          type == QEvent::MouseButtonPress ? Qt::LeftButton : Qt::NoButton, {});
        QApplication::sendEvent(widget, &event);
    }
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
    QApplication::setAttribute(Qt::AA_DontUseNativeDialogs);
    QApplication app(argc, argv);
    app.setOrganizationName("qmmp");
    app.setApplicationName("test");
    QSettings().setValue("Output/current_plugin", "null");
    Qmmp::setUiLanguageID(QStringLiteral("zh_CN"));
    QTranslator qtChinese;
    if(qtChinese.load(QLibraryInfo::path(QLibraryInfo::TranslationsPath) + "/qtbase_zh_CN"))
        app.installTranslator(&qtChinese);
    CHECK(linkPlugin(argv[2], root + "/Ui"));
    CHECK(linkPlugin(argv[3], root + "/Input"));
    CHECK(linkPlugin(argv[4], Qmmp::configDir() + "/plugins-2.3/Input"));
    CHECK(linkPlugin(argv[5], root + "/Output"));
    const QString systemCopy = root + "/Input/system-ffmpeg.so";
    CHECK(QFile::copy(argv[4], systemCopy));
    int ffmpegCount = 0;
    for(auto *decoder : Decoder::factories())
        if(decoder->properties().shortName == "ffmpeg")
        {
            ++ffmpegCount;
            CHECK(Decoder::file(decoder) == QFileInfo(argv[4]).canonicalFilePath());
        }
    CHECK(ffmpegCount == 1);

    QString music;
    QStringList samples;
    const QStringList titles = {"短音", "春天", "月光慢板", "雨中的街道", "夏日序曲"};
    for(const QString &ext : { "mp3", "wav", "flac", "ogg", "m4a" })
    {
        const QString path = temp.filePath(titles.at(samples.size()) + "." + ext);
        samples << path;
        const QString seconds = ext == "mp3" ? "0.15" : (ext == "wav" ? "9" : "1");
        const QString source = ext == "wav" ? "anoisesrc=color=pink:amplitude=0.45:seed=42" : "sine=frequency=440";
        CHECK(QProcess::execute(argv[1], { "-v", "error", "-f", "lavfi", "-i", source,
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

    // Encode stereo 24-bit PCM with distinct low-order bits on each channel.
    // FFmpeg delivers decoded 24-bit FLAC left-aligned in signed 32-bit samples.
    QByteArray original;
    QDataStream pcm(&original, QIODevice::WriteOnly);
    pcm.setByteOrder(QDataStream::LittleEndian);
    for(int i = 0; i < 9600; ++i)
        for(int step : {4711, 8231})
            pcm << qint32((i * step % 15485863 - 7742931) * 256);
    QFile raw(temp.filePath("reference.s32le"));
    CHECK(raw.open(QIODevice::WriteOnly) && raw.write(original) == original.size());
    raw.close();
    QFile hires(temp.filePath("reference.flac"));
    CHECK(QProcess::execute(argv[1], {"-v", "error", "-f", "s32le", "-ar", "96000", "-ac", "2",
                    "-i", raw.fileName(), "-c:a", "flac", hires.fileName()}) == 0);
    auto *flac = Decoder::findByFilePath(hires.fileName());
    CHECK(flac && hires.open(QIODevice::ReadOnly));
    {
        std::unique_ptr<Decoder> decoder(flac->create(hires.fileName(), &hires));
        CHECK(decoder && decoder->initialize() && decoder->audioParameters().sampleRate() == 96000);
        QByteArray decoded;
        unsigned char buffer[8192];
        qint64 n;
        while((n = decoder->read(buffer, sizeof(buffer))) > 0)
            decoded.append(reinterpret_cast<const char *>(buffer), n);
        CHECK(n == 0 && decoded == original);
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
    QmmpTextCodec legacy("GB18030");
    lyrics.write(legacy.fromUnicode(QStringLiteral("\n[00:01.10]风把夜色轻轻吹散\n"
        "[00:02.10]街灯亮起\n[00:03.10]窗外的光，落在琴弦上\n"
        "[00:07.10]一曲未央\n[00:08.10]等天色微亮\n")));
    lyrics.close();

    MediaPlayer player;
    UiHelper helper(&player);
    auto *factory = UiLoader::selected();
    CHECK(factory && factory->properties().shortName == "classic");
    std::unique_ptr<QObject> ui(factory->create());
    auto *window = qobject_cast<QMainWindow *>(ui.get());
    CHECK(window && window->isVisible());
    auto *menuButton = window->findChild<QToolButton *>("medallion");
    CHECK(menuButton && menuButton->menu());
    const auto menuItems = menuButton->menu()->actions();
    CHECK(menuItems.size() >= 4 && menuItems.last()->text() == "退出");
    CHECK(menuItems.at(menuItems.size() - 2)->isSeparator());
    int skinIndex = -1;
    for(int i = 1; i < menuItems.size(); ++i)
        if(menuItems[i]->text() == "皮肤" && menuItems[i]->menu())
            skinIndex = i;
    CHECK(skinIndex > 0 && menuItems[skinIndex - 1]->text() == "视图");
    auto *current = window->findChild<QLabel *>("activeLyric");
    auto *list = window->findChild<QListView *>("tracks");
    auto *title = window->findChild<QLabel *>("song");
    CHECK(current && list && title);
    helper.replaceAndPlay({music});
    auto *core = SoundCore::instance();
    CHECK(waitFor([&] { return core->state() == Qmmp::Playing && current->text() == "春天"; }));
    CHECK(list->currentIndex().row() == 0 && title->text() == "春天");
    auto *seek = window->findChild<QSlider *>("progress");
    auto *clock = window->findChild<QLabel *>("clock");
    CHECK(seek && clock);
    seek->setSliderDown(true);
    seek->setSliderPosition(7500);
    CHECK(clock->text() == "00:06" && current->text() == "春天");
    const qint64 beforeDrag = core->elapsed();
    CHECK(waitFor([&] { return core->elapsed() > beforeDrag + 250; }));
    CHECK(core->elapsed() < 3000 && clock->text() == "00:06" && seek->sliderPosition() == 7500);
    seek->setSliderDown(false);
    CHECK(waitFor([&] { return core->elapsed() >= 6500; }));
    core->seek(4200);
    CHECK(waitFor([&] { return current->text() == "窗外的光，落在琴弦上"; }));
    CHECK(clock->text() == "00:04");
    auto *mute = window->findChild<QToolButton *>("mute");
    CHECK(mute && !mute->isChecked());
    mute->click();
    CHECK(core->isMuted() && mute->isChecked());
    core->setMuted(false);
    CHECK(!mute->isChecked());
    core->pause();
    CHECK(waitFor([&] { return core->state() == Qmmp::Paused; }));
    clickWidget(clock);
    CHECK(clock->text() == "-00:05" && core->state() == Qmmp::Paused);
    seek->setValue(seek->maximum() / 2);
    CHECK(clock->text() == "-00:05");
    seek->setValue(3 * seek->maximum() / 4);
    CHECK(clock->text() == "-00:03");
    clickWidget(clock);
    CHECK(clock->text() == "00:06");
    core->pause();
    CHECK(waitFor([&] { return core->state() == Qmmp::Playing; }));
    core->seek(6500);
    CHECK(waitFor([&] { return current->text() == "春天"; }));
    core->seek(4000);
    CHECK(waitFor([&] { return current->text() == "窗外的光，落在琴弦上"; }));
    CHECK(window->windowFlags().testFlag(Qt::FramelessWindowHint));
    CHECK(list->currentIndex().data(Qt::UserRole).toLongLong() == 9000);
    auto *eqDock = window->findChild<QDockWidget *>("equalizer");
    auto *lyricDock = window->findChild<QDockWidget *>("lyrics");
    auto *listDock = window->findChild<QDockWidget *>("playlist");
    CHECK(eqDock && lyricDock && listDock);
    auto *order = listDock->findChild<QToolButton *>("playOrder");
    auto *playSettings = QmmpUiSettings::instance();
    CHECK(order && order->parentWidget()->layout()->itemAt(3)->widget() == order);
    CHECK(!playSettings->isShuffle() && order->accessibleName() == "顺序播放");
    order->click();
    CHECK(playSettings->isShuffle() && order->accessibleName() == "随机播放");
    playSettings->setShuffle(false);
    CHECK(!order->isChecked() && order->accessibleName() == "顺序播放");
    CHECK(waitFor([&] { return eqDock->isFloating() && eqDock->isVisible() &&
                               eqDock->y() == window->frameGeometry().bottom()+1 &&
                               listDock->y() == eqDock->frameGeometry().bottom()+1 &&
                               lyricDock->y() == listDock->frameGeometry().bottom()+1; }));
    CHECK(!core->eqSettings().isEnabled());
    auto *visual = window->findChild<QWidget *>("visualization");
    CHECK(visual && visual->accessibleName() == "频谱柱");
    for(const QString &name : {"时域波形", "左右声道电平", "频谱柱"})
    {
        clickWidget(visual);
        CHECK(visual->accessibleName() == name && core->state() == Qmmp::Playing);
    }
    auto *band = eqDock->findChild<QSlider *>("band4");
    CHECK(band && core->eqSettings().bands() == 10);
    band->setValue(5);
    CHECK(core->eqSettings().gain(4) == 5);
    QAction *rock = nullptr;
    for(auto *action : eqDock->findChildren<QAction *>())
        if(action->text() == "Rock")
            rock = action;
    CHECK(rock);
    rock->trigger();
    CHECK(core->eqSettings().isEnabled() && band->value() == core->eqSettings().gain(4));
    QAction *blue = nullptr, *violet = nullptr, *obsidian = nullptr, *amber = nullptr, *importSkin = nullptr;
    for(auto *action : window->findChildren<QAction *>())
    {
        if(action->data() == ":/classic/skins/amber/skin.xml") amber = action;
        if(action->text() == "载入皮肤…") importSkin = action;
        if(action->data() == ":/classic/skins/midnight.ini") blue = action;
        if(action->data() == ":/classic/skins/violet.ini") violet = action;
        if(action->data() == ":/classic/skins/obsidian.ini") obsidian = action;
    }
    CHECK(blue && violet && obsidian && amber && importSkin && obsidian->text() == "曜石黑");
    const QString download = temp.filePath("分享的皮肤.qmmp-skin");
    CHECK(QFile::copy(AMBER_SKIN_FILE, download));
    QTimer::singleShot(0, [&] {
        auto *dialog = qobject_cast<QFileDialog *>(QApplication::activeModalWidget());
        if(dialog)
        {
            dialog->selectFile(download);
            QMetaObject::invokeMethod(dialog, "accept", Qt::QueuedConnection);
        }
    });
    importSkin->trigger();
    const QString installed = QSettings().value("Classic/skin").toString();
    CHECK(installed.startsWith(Qmmp::configDir() + "/skins/") && QFile::exists(installed));
    CHECK(QFile::remove(download));
    CHECK(window->property("spectrumColor").toString() == "#fff39b");
    CHECK(clock->x() < title->x() && window->findChild<QLabel *>("volumeReadout")->isVisible());
    CHECK(waitFor([&] { return order->mapTo(listDock, QPoint()).y() > list->mapTo(listDock, QPoint()).y(); }));
    QAction *imported = nullptr;
    for(auto *action : window->findChildren<QAction *>())
        if(action->data() == installed)
            imported = action;
    CHECK(imported && imported->isChecked() && imported->text() == "琥珀静听");
    obsidian->trigger();
    CHECK(obsidian->isChecked() && QSettings().value("Classic/skin") == obsidian->data());
    CHECK(window->property("spectrumColor").toString() == "#ffbf62");
    CHECK(clock->palette().color(QPalette::WindowText) == QColor("#ffbf62"));
    CHECK(list->palette().color(QPalette::Base) == QColor("#101113"));
    CHECK(current->palette().color(QPalette::WindowText) == QColor("#ffbf62"));
    CHECK(waitFor([&] { return clock->x() > title->x(); }));
    imported->trigger();
    CHECK(window->property("spectrumColor").toString() == "#fff39b");
    blue->trigger();
    CHECK(window->property("spectrumColor").toString() == "#89e6db");
    violet->trigger();
    if(argc >= 7)
    {
        samples.removeAll(music);
        PlayListManager::instance()->addPaths(samples);
        CHECK(waitFor([&] { return list->model()->rowCount() == samples.size()+1; }));
        const QList<QWidget *> panels {window,eqDock,listDock,lyricDock};
        auto savePanels = [&](const QString &path) {
            QRect bounds;
            for(auto *panel : panels)
                bounds |= panel->frameGeometry();
            QImage image(bounds.size(),QImage::Format_ARGB32_Premultiplied);
            image.fill(Qt::transparent);
            QPainter painter(&image);
            for(auto *panel : panels)
                painter.drawPixmap(panel->frameGeometry().topLeft()-bounds.topLeft(),panel->grab());
            painter.end();
            return image.save(path);
        };
        CHECK(savePanels(QString::fromLocal8Bit(argv[6])));
        if(argc >= 8)
        {
            obsidian->trigger();
            CHECK(savePanels(QDir(argv[7]).filePath("classic-obsidian.png")));
            amber->trigger();
            QAction *arrange = nullptr;
            for(auto *action : window->findChildren<QAction *>())
                if(action->text() == "磁吸排列")
                    arrange = action;
            CHECK(arrange);
            arrange->trigger();
            CHECK(waitFor([&] { return lyricDock->y() == listDock->frameGeometry().bottom()+1 &&
                                       listDock->height() == listDock->property("stackHeight").toInt(); }));
            CHECK(savePanels(QDir(argv[7]).filePath("classic-amber.png")));
            violet->trigger();
        }
    }
    auto *library = window->findChild<QToolButton *>("libraryKey");
    CHECK(library);
    library->click();
    auto *search = window->findChild<QDialog *>("JumpToTrackDialog");
    CHECK(search && search->isVisible() && search->windowFlags().testFlag(Qt::FramelessWindowHint));
    auto *input = search->findChild<QLineEdit *>("filterLineEdit");
    auto *results = search->findChild<QListView *>("songsListView");
    CHECK(input && results && results->model()->rowCount() > 0);
    CHECK(input->palette().color(QPalette::Base) == QColor("#11101f"));
    obsidian->trigger();
    CHECK(input->palette().color(QPalette::Base) == QColor("#101113"));
    blue->trigger();
    CHECK(input->palette().color(QPalette::Base) != QColor("#11101f"));
    violet->trigger();
    input->setText("春天");
    CHECK(results->model()->rowCount() == 1);
    input->clear();
    if(argc >= 8)
        CHECK(search->grab().save(QDir(argv[7]).filePath("classic-music.png")));
    search->close();
    QAction *preferences = nullptr;
    for(auto *action : menuItems)
        if(action->text() == "设置…")
            preferences = action;
    CHECK(preferences);
    bool preferencesStyled = false;
    QTimer::singleShot(0, [&] {
        auto *dialog = qobject_cast<QDialog *>(QApplication::activeModalWidget());
        if(!dialog)
            return;
        auto *pages = dialog->findChild<QListWidget *>("contentsWidget");
        auto *edit = dialog->findChild<QLineEdit *>("groupLineEdit");
        preferencesStyled = dialog->windowFlags().testFlag(Qt::FramelessWindowHint) &&
                pages && pages->count() >= 5 && edit && edit->palette().color(QPalette::Base) == QColor("#11101f");
        if(argc >= 8)
            preferencesStyled &= dialog->grab().save(QDir(argv[7]).filePath("classic-settings.png"));
        dialog->reject();
    });
    preferences->trigger();
    CHECK(preferencesStyled);
    const QString nextSong = temp.filePath("下一曲.wav");
    CHECK(QFile::copy(music, nextSong));
    helper.replaceAndPlay({music, nextSong});
    CHECK(waitFor([&] { return list->model()->rowCount() == 2 && core->state() == Qmmp::Playing; }));
    auto *compact = window->findChild<QToolButton *>("compactMode");
    auto *minimize = window->findChild<QToolButton *>("minimize");
    auto *bar = window->findChild<QWidget *>("compactBar");
    auto *barTitle = window->findChild<QLabel *>("compactTitle");
    CHECK(compact && minimize && bar && barTitle);
    const QRect mainFrame = window->frameGeometry();
    const QRect listFrame = listDock->frameGeometry();
    lyricDock->hide();
    compact->click();
    CHECK(waitFor([&] { return bar->isVisible() && window->height() == 32 &&
                               window->frameGeometry().topRight() == window->screen()->availableGeometry().topRight(); }));
    CHECK(!eqDock->isVisible() && !listDock->isVisible() && !lyricDock->isVisible());
    // Offscreen has no window manager, so pointer events exercise the manual move fallback.
    if(QGuiApplication::platformName() == "offscreen")
    {
        const QPoint titlePoint = barTitle->mapTo(window, barTitle->rect().center());
        const QPoint marginPoint = bar->mapTo(window, QPoint(3, bar->height() / 2));
        for(const QPoint &point : {titlePoint, marginPoint})
        {
            QWidget *hit = window->childAt(point);
            CHECK(hit == bar);
            const QPoint before = window->pos();
            const QPoint delta(-35, 25);
            const QPoint start = window->mapToGlobal(point);
            auto send = [&](QEvent::Type type, QPoint global, Qt::MouseButton button, Qt::MouseButtons buttons) {
                QMouseEvent e(type, hit->mapFromGlobal(global), global, button, buttons, {});
                QApplication::sendEvent(hit, &e);
            };
            send(QEvent::MouseButtonPress, start, Qt::LeftButton, Qt::LeftButton);
            send(QEvent::MouseMove, start + delta, Qt::NoButton, Qt::LeftButton);
            send(QEvent::MouseButtonRelease, start + delta, Qt::LeftButton, Qt::NoButton);
            CHECK(window->pos() == before + delta);
        }
    }
    CHECK(waitFor([&] { return barTitle->text() == "春天" && barTitle->accessibleName().contains("00:"); }));
    if(argc >= 8)
    {
        CHECK(window->grab().save(QDir(argv[7]).filePath("classic-mini.png")));
        amber->trigger();
        QCoreApplication::processEvents();
        CHECK(window->grab().save(QDir(argv[7]).filePath("classic-amber-mini.png")));
        violet->trigger();
    }
    auto barButton = [&](const QString &name) -> QToolButton * {
        for(auto *key : bar->findChildren<QToolButton *>())
            if(key->accessibleName() == name)
                return key;
        return nullptr;
    };
    CHECK(barButton("下一首") && barButton("上一首") && barButton("还原主窗口"));
    CHECK(waitFor([&] { return barButton("暂停") != nullptr; }));
    const QPoint compactPosition = window->pos();
    barButton("还原主窗口")->click();
    compact->click();
    CHECK(window->pos() == compactPosition);
    CHECK(barTitle->accessibleName().contains(barTitle->text()));
    clickWidget(barButton("下一首"));
    CHECK(waitFor([&] { return barTitle->text() == "下一曲"; }));
    CHECK(window->pos() == compactPosition);
    barButton("上一首")->click();
    CHECK(waitFor([&] { return barTitle->text() == "春天"; }));
    barButton("暂停")->click();
    CHECK(waitFor([&] { return core->state() == Qmmp::Paused && barButton("播放"); }));
    barButton("播放")->click();
    CHECK(waitFor([&] { return core->state() == Qmmp::Playing; }));
    barButton("还原主窗口")->click();
    CHECK(waitFor([&] { return !bar->isVisible() && window->frameGeometry() == mainFrame &&
                               listDock->frameGeometry() == listFrame && listDock->isVisible() && eqDock->isVisible(); }));
    CHECK(!lyricDock->isVisible());
    minimize->click();
    CHECK(window->isMinimized() && !listDock->isVisible() && !eqDock->isVisible());
    window->showNormal();
    CHECK(eqDock->isVisible() && listDock->isVisible() && !lyricDock->isVisible());
    lyricDock->show();
    minimize->click();
    CHECK(window->isMinimized() && !listDock->isVisible() && !lyricDock->isVisible());
    window->showNormal();
    CHECK(waitFor([&] { return eqDock->y() == window->frameGeometry().bottom()+1 &&
                               listDock->y() == eqDock->frameGeometry().bottom()+1 &&
                               lyricDock->y() == listDock->frameGeometry().bottom()+1; }));
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
        list->setCurrentIndex(list->model()->index(1, 0));
        CHECK(dropTrack(list->viewport()));
        CHECK(waitFor([&] { return list->model()->rowCount() == count + 1; }));
        CHECK(list->currentIndex().row() == 1);
        CHECK(core->state() == Qmmp::Playing && title->text() == "春天");
    }
    clickWidget(clock);
    CHECK(dropTrack(title));
    CHECK(waitFor([&] { return title->text() == "雨声" && current->text() == "雨声响起"; }));
    CHECK(clock->text() == "-00:09");
    player.stop();
    // A user skin may override palette and widget artwork and survive relaunch.
    const QString skinFile = temp.filePath("custom.ini");
    CHECK(QFile::copy(":/classic/skins/midnight.ini", skinFile));
    QFile::setPermissions(skinFile, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    {
        QSettings skin(skinFile,QSettings::IniFormat);
        skin.setValue("Skin/Name","自定义");
        skin.setValue("Skin/Style","custom.qss");
        skin.setValue("Colors/spectrum","#88aa77");
    }
    QFile style(temp.filePath("custom.qss"));
    CHECK(style.open(QIODevice::WriteOnly));
    style.write("QLabel#clock { color: #77aa88; }");
    style.close();
    QSettings().setValue("Classic/skinFiles", QStringList{skinFile});
    QSettings().setValue("Classic/skin",skinFile);
    clickWidget(visual);
    const QRect savedNormalFrame = window->frameGeometry();
    compact->click();
    window->move(compactPosition);
    ui.reset();
    ui.reset(factory->create());
    window = qobject_cast<QMainWindow *>(ui.get());
    CHECK(window && window->findChild<QWidget *>("compactBar")->isVisible() && window->pos() == compactPosition);
    CHECK(window->property("spectrumColor") == "#88aa77");
    CHECK(window->findChild<QWidget *>("visualization")->accessibleName() == "时域波形");
    CHECK(window->styleSheet().contains("#77aa88"));
    for(auto *key : window->findChild<QWidget *>("compactBar")->findChildren<QToolButton *>())
        if(key->accessibleName() == "还原主窗口")
            key->click();
    CHECK(window->frameGeometry() == savedNormalFrame);
    QSettings().setValue("Classic/compactScreen", "disconnected-test-screen");
    QSettings().setValue("Classic/compactOffset", QPoint(100000, 100000));
    window->findChild<QToolButton *>("compactMode")->click();
    CHECK(window->frameGeometry().bottomRight() == window->screen()->availableGeometry().bottomRight());
    ui.reset();
    QSettings().setValue("Classic/skin", installed);
    ui.reset(factory->create());
    window = qobject_cast<QMainWindow *>(ui.get());
    CHECK(window && window->property("spectrumColor").toString() == "#fff39b");
    CHECK(window->findChild<QWidget *>("compactBar")->isVisible());
    CHECK(!window->findChild<QToolButton *>("medallion")->icon().isNull());
    return 0;
}

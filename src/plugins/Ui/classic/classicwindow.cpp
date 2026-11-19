#include "classicwindow.h"
#include <qmmp/soundcore.h>
#include <qmmpui/configdialog.h>
#include <qmmpui/mediaplayer.h>
#include <qmmpui/playlistmanager.h>
#include <qmmpui/playlisttrack.h>
#include <qmmpui/uihelper.h>
#include <QAbstractListModel>
#include <QCloseEvent>
#include <QDockWidget>
#include <QDragEnterEvent>
#include <QFileInfo>
#include <QLabel>
#include <QListView>
#include <QMenuBar>
#include <QMimeData>
#include <QSettings>
#include <QSlider>
#include <QStyle>
#include <QToolButton>
#include <QVBoxLayout>

class TrackList : public QAbstractListModel
{
public:
    using QAbstractListModel::QAbstractListModel;

    void resetPlaylist(PlayListModel *playlist)
    {
        beginResetModel();
        m_playlist = playlist;
        m_count = playlist ? playlist->trackCount() : 0;
        endResetModel();
    }
    int rowCount(const QModelIndex &parent) const override { return parent.isValid() ? 0 : m_count; }
    QVariant data(const QModelIndex &index, int role) const override
    {
        if(!m_playlist || !index.isValid() || index.row() >= m_playlist->trackCount())
            return {};
        const auto *track = m_playlist->track(index.row());
        if(!track)
            return {};
        if(role == Qt::ToolTipRole)
            return track->path();
        if(role != Qt::DisplayRole)
            return {};
        return track->formattedTitle(0);
    }
    void refreshMetadata()
    {
        if(m_count)
            emit dataChanged(index(0, 0), index(m_count - 1, 0), {Qt::DisplayRole});
    }
private:
    PlayListModel *m_playlist = nullptr;
    int m_count = 0;
};

static QString timeLabel(qint64 ms)
{
    const qint64 seconds = qMax<qint64>(0, ms) / 1000;
    return QStringLiteral("%1:%2").arg(seconds / 60).arg(seconds % 60, 2, 10, QLatin1Char('0'));
}

ClassicWindow::ClassicWindow()
{
    auto *core = SoundCore::instance();
    auto *player = MediaPlayer::instance();
    auto *manager = PlayListManager::instance();
    auto *helper = UiHelper::instance();
    setWindowTitle(QStringLiteral("Qmmp · 经典播放器"));
    setAcceptDrops(true);
    setObjectName("ClassicWindow");
    setStyleSheet(QStringLiteral(
        "QMainWindow#ClassicWindow{background:#e8efee;color:#233d40;}"
        "QWidget#deck{background:#203a3d;color:#f2f6eb;}"
        "QLabel#song{font-size:22px;font-weight:600;color:#fff8df;}"
        "QWidget#deck QLabel{color:#d8e6da;}"
        "QLabel#clock{color:#d9e7cc;font-family:monospace;}"
        "QWidget#deck QSlider::groove:horizontal{height:4px;border-radius:2px;background:#647e79;}"
        "QWidget#deck QSlider::sub-page:horizontal{background:#ecc688;border-radius:2px;}"
        "QWidget#deck QSlider::handle:horizontal{background:#fbf2d0;border:1px solid #abc0ad;"
        "width:10px;margin:-4px 0;border-radius:3px;}"
        "QToolButton{background:#e6efec;color:#193a38;border:1px solid #a8bbb5;"
        "border-radius:5px;padding:5px;} QToolButton:hover{background:#fff8dc;}"
        "QToolButton#play{background:#f3c57d;padding:6px 13px;}"
        "QDockWidget::title{background:#d3e2de;color:#29423e;padding:4px;}"
        "QListView{background:#f6f8f4;color:#203d38;border:0;outline:0;}"
        "QListView::item{padding:4px 8px;} QListView::item:selected{background:#c6dfd5;color:#163f33;}"
        "QWidget#lyricPanel{background:#f2f5ed;} QLabel#activeLyric{font-size:18px;"
        "font-weight:600;color:#176653;} QLabel#nearLyric{color:#566d63;}"));
    auto *deck = new QWidget;
    deck->setObjectName("deck");
    auto *panel = new QVBoxLayout(deck);
    panel->setContentsMargins(14, 10, 14, 12);
    m_title = new QLabel;
    m_title->setObjectName("song");
    m_title->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
    m_artist = new QLabel;
    m_artist->setObjectName("artist");
    panel->addWidget(m_title);
    panel->addWidget(m_artist);
    auto *timeline = new QHBoxLayout;
    m_position = new QSlider(Qt::Horizontal);
    m_position->setAccessibleName(QStringLiteral("播放进度"));
    m_position->setRange(0, 10000);
    m_clock = new QLabel;
    m_clock->setObjectName("clock");
    timeline->addWidget(m_position, 1);
    timeline->addWidget(m_clock);
    panel->addLayout(timeline);
    auto *controls = new QHBoxLayout;
    auto button = [&](QStyle::StandardPixmap icon, const QString &label) {
        auto *b = new QToolButton;
        b->setIcon(style()->standardIcon(icon));
        b->setToolTip(label);
        b->setAccessibleName(label);
        controls->addWidget(b);
        return b;
    };
    connect(button(QStyle::SP_MediaSkipBackward, tr("上一首")), &QToolButton::clicked, player, &MediaPlayer::previous);
    m_play = button(QStyle::SP_MediaPlay, tr("播放"));
    m_play->setObjectName("play");
    auto toggle = [=]() {
        if(core->state() == Qmmp::Playing || core->state() == Qmmp::Paused)
            player->pause();
        else if(manager->currentPlayList()->isEmpty())
            helper->playFiles(this);
        else
            player->play();
    };
    connect(m_play, &QToolButton::clicked, this, toggle);
    connect(button(QStyle::SP_MediaSkipForward, tr("下一首")), &QToolButton::clicked, player, &MediaPlayer::next);
    connect(button(QStyle::SP_MediaStop, tr("停止")), &QToolButton::clicked, player, &MediaPlayer::stop);
    controls->addStretch();
    controls->addWidget(new QLabel(tr("音量")));
    auto *volume = new QSlider(Qt::Horizontal);
    volume->setAccessibleName(tr("音量"));
    volume->setRange(0, 100);
    volume->setMaximumWidth(96);
    volume->setValue(core->volume());
    controls->addWidget(volume);
    connect(volume, &QSlider::valueChanged, core, &SoundCore::setVolume);
    connect(core, &SoundCore::volumeChanged, volume, &QSlider::setValue);
    panel->addLayout(controls);
    setCentralWidget(deck);

    auto *fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(tr("打开并播放…"), this, [=] { helper->playFiles(this); })->setShortcut(QKeySequence::Open);
    fileMenu->addAction(tr("添加文件…"), this, [=] { helper->addFiles(this); });
    fileMenu->addAction(tr("添加文件夹…"), this, [=] { helper->addDirectory(this); });
    fileMenu->addAction(tr("设置…"), this, [this] { ConfigDialog dialog(this); dialog.exec(); });
    fileMenu->addAction(tr("退出"), helper, &UiHelper::exit)->setShortcut(QKeySequence::Quit);
    auto *playlists = menuBar()->addMenu(tr("列表"));
    connect(playlists, &QMenu::aboutToShow, this, [=] {
        playlists->clear();
        for(auto *playlist : manager->playLists())
        {
            auto *action = playlists->addAction(playlist->name(), this, [=] { manager->selectPlayList(playlist); });
            action->setCheckable(true);
            action->setChecked(playlist == manager->selectedPlayList());
        }
    });
    auto *view = menuBar()->addMenu(tr("视图"));
    auto *tools = menuBar()->addMenu(tr("工具"));
    helper->registerMenu(UiHelper::TOOLS_MENU, tools, true);
    auto *playAction = new QAction(this);
    playAction->setShortcut(Qt::Key_Space);
    addAction(playAction);
    connect(playAction, &QAction::triggered, this, toggle);

    auto addDock = [&](const QString &name, const QString &title, QWidget *content) {
        auto *dock = new QDockWidget(title, this);
        dock->setObjectName(name);
        dock->setWidget(content);
        addDockWidget(Qt::BottomDockWidgetArea, dock);
        view->addAction(dock->toggleViewAction());
        return dock;
    };
    m_list = new QListView;
    m_list->setUniformItemSizes(true);
    m_tracks = new TrackList(m_list);
    m_list->setModel(m_tracks);
    auto *listDock = addDock(QStringLiteral("playlist"), tr("播放列表"), m_list);
    auto *lyrics = new QWidget;
    lyrics->setObjectName("lyricPanel");
    auto *lines = new QVBoxLayout(lyrics);
    lines->addStretch();
    auto lyricLabel = [&](const QString &name) {
        auto *label = new QLabel;
        label->setObjectName(name);
        label->setAlignment(Qt::AlignCenter);
        label->setTextFormat(Qt::PlainText);
        label->setWordWrap(true);
        lines->addWidget(label);
        return label;
    };
    m_previousLine = lyricLabel(QStringLiteral("nearLyric"));
    m_currentLine = lyricLabel(QStringLiteral("activeLyric"));
    m_nextLine = lyricLabel(QStringLiteral("nearLyric"));
    lines->addStretch();
    auto *lyricsDock = addDock(QStringLiteral("lyrics"), tr("同步歌词"), lyrics);
    splitDockWidget(listDock, lyricsDock, Qt::Horizontal);
    m_title->setTextFormat(Qt::PlainText);
    m_artist->setTextFormat(Qt::PlainText);
    connect(m_list, &QListView::activated, this, [=](const QModelIndex &index) {
        if(!m_playlist || !m_playlist->setCurrent(index.row()))
            return;
        player->stop();
        manager->activatePlayList(m_playlist);
        player->play();
    });
    bindPlaylist(manager->selectedPlayList());
    connect(manager, &PlayListManager::selectedPlayListChanged, this, &ClassicWindow::bindPlaylist);
    connect(core, &SoundCore::trackInfoChanged, this, &ClassicWindow::updateTrack);
    connect(core, &SoundCore::elapsedChanged, this, &ClassicWindow::updatePosition);
    connect(core, &SoundCore::stateChanged, this, &ClassicWindow::updateState);
    m_position->setTracking(false);
    connect(m_position, &QSlider::valueChanged, this, [=](int value) {
        const qint64 time = core->duration() * value / m_position->maximum();
        core->seek(time);
        updateLyrics(time);
    });
    connect(helper, &UiHelper::toggleVisibilityCalled, this, [this] { setVisible(!isVisible()); });
    connect(helper, &UiHelper::showMainWindowCalled, this, [this] { showNormal(); raise(); activateWindow(); });
    resize(540, 370);
    QSettings settings;
    restoreGeometry(settings.value("Classic/geometry").toByteArray());
    if(!restoreState(settings.value("Classic/docks").toByteArray()))
        resizeDocks({listDock, lyricsDock}, {260, 260}, Qt::Horizontal);
    updateState();
    show();
}

void ClassicWindow::bindPlaylist(PlayListModel *playlist)
{
    if(m_playlist)
        disconnect(m_playlist, nullptr, this, nullptr);
    m_playlist = playlist;
    m_tracks->resetPlaylist(playlist);
    if(!playlist)
        return;
    auto selectCurrent = [this] {
        const auto index = m_tracks->index(m_playlist->currentIndex(), 0);
        m_list->setCurrentIndex(index);
        if(index.isValid())
            m_list->scrollTo(index);
    };
    selectCurrent();
    connect(playlist, &PlayListModel::listChanged, this, [=](int flags) {
        if(flags & PlayListModel::STRUCTURE)
            m_tracks->resetPlaylist(playlist);
        else if(flags & PlayListModel::METADATA)
            m_tracks->refreshMetadata();
        if(flags & (PlayListModel::CURRENT | PlayListModel::STRUCTURE))
            selectCurrent();
    });
}

void ClassicWindow::updateState()
{
    auto *core = SoundCore::instance();
    const bool playing = core->state() == Qmmp::Playing;
    m_play->setIcon(style()->standardIcon(playing ? QStyle::SP_MediaPause : QStyle::SP_MediaPlay));
    m_play->setToolTip(playing ? tr("暂停") : tr("播放"));
    m_play->setAccessibleName(m_play->toolTip());
    if(playing || core->state() == Qmmp::Paused)
        updateTrack();
    else
    {
        m_path.clear();
        m_lyrics = {};
        m_line = -2;
        m_title->setText(tr("尚未播放"));
        m_artist->setText(tr("打开音乐或拖入文件"));
        if(core->state() == Qmmp::NormalError)
            m_artist->setText(tr("无法读取这首歌曲"));
        if(core->state() == Qmmp::FatalError)
            m_artist->setText(tr("音频输出不可用，请检查输出设备"));
        updatePosition(0);
    }
}

void ClassicWindow::updateTrack()
{
    auto *core = SoundCore::instance();
    const auto &info = core->trackInfo();
    const QString path = info.path().isEmpty() ? core->path() : info.path();
    const QString title = info.value(Qmmp::TITLE);
    m_title->setText(title.isEmpty() ? QFileInfo(path).completeBaseName() : title);
    m_title->setToolTip(m_title->text());
    QStringList details;
    const QString artist = info.value(Qmmp::ARTIST);
    if(!artist.isEmpty())
        details << artist;
    const QString album = info.value(Qmmp::ALBUM);
    if(!album.isEmpty())
        details << album;
    if(details.isEmpty())
    {
        const QString type = QFileInfo(path).suffix().toUpper();
        if(!type.isEmpty())
            details << type;
        const int rate = info.value(Qmmp::SAMPLERATE).toInt();
        if(rate > 0)
            details << QStringLiteral("%1 kHz").arg(rate / 1000.0);
    }
    m_artist->setText(details.join(QStringLiteral("  ·  ")));
    if(path != m_path)
    {
        m_path = path;
        m_lyrics.loadForTrack(path);
        m_line = -2;
    }
    updatePosition(core->elapsed());
}

void ClassicWindow::updatePosition(qint64 time)
{
    const qint64 duration = m_path.isEmpty() ? 0 : SoundCore::instance()->duration();
    m_position->setEnabled(duration > 0);
    if(!m_position->isSliderDown())
    {
        QSignalBlocker block(m_position);
        m_position->setValue(duration > 0 ? time * m_position->maximum() / duration : 0);
    }
    m_clock->setText(timeLabel(time) + QStringLiteral(" / ") + timeLabel(duration));
    updateLyrics(time);
}

void ClassicWindow::updateLyrics(qint64 time)
{
    const int line = m_lyrics.indexAt(time);
    if(m_line == line)
        return;
    m_line = line;
    m_previousLine->setText(m_lyrics.textAt(line - 1));
    m_currentLine->setText(m_lyrics.isEmpty() ? tr("暂无同步歌词") : m_lyrics.textAt(line));
    m_nextLine->setText(m_lyrics.textAt(line + 1));
}

void ClassicWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("Classic/geometry", saveGeometry());
    settings.setValue("Classic/docks", saveState());
    QMainWindow::closeEvent(event);
    UiHelper::instance()->exit();
}

void ClassicWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void ClassicWindow::dropEvent(QDropEvent *event)
{
    QStringList paths;
    for(const auto &url : event->mimeData()->urls())
        paths << (url.isLocalFile() ? url.toLocalFile() : url.toString());
    if(!paths.isEmpty())
    {
        UiHelper::instance()->replaceAndPlay(paths);
        event->acceptProposedAction();
    }
}

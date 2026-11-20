#include "classicwindow.h"
#include "classicskin.h"
#include "classicequalizer.h"
#include "consolecontrols.h"
#include "windowmagnet.h"
#include "spectrum.h"
#include <qmmp/soundcore.h>
#include <qmmpui/configdialog.h>
#include <qmmpui/mediaplayer.h>
#include <qmmpui/playlistmanager.h>
#include <qmmpui/playlisttrack.h>
#include <qmmpui/qmmpuisettings.h>
#include <qmmpui/uihelper.h>
#include <QAbstractListModel>
#include <QCloseEvent>
#include <QDockWidget>
#include <QDragEnterEvent>
#include <QFileInfo>
#include <QLabel>
#include <QLineEdit>
#include <QListView>
#include <QMenu>
#include <QMouseEvent>
#include <QListWidget>
#include <QPainter>
#include <QSplitter>
#include <QSizeGrip>
#include <QStyledItemDelegate>
#include <QMimeData>
#include <QSettings>
#include <QScreen>
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
        if(role == Qt::UserRole+1)
            return m_playlist == PlayListManager::instance()->currentPlayList() &&
                   index.row() == m_playlist->currentIndex();
        if(role == Qt::UserRole)
            return track->duration();
        if(role == Qt::ToolTipRole)
            return track->path();
        if(role != Qt::DisplayRole)
            return {};
        return track->formattedTitle(0);
    }
    void refreshMetadata()
    {
        if(m_count)
            emit dataChanged(index(0, 0), index(m_count - 1, 0), {Qt::DisplayRole, Qt::UserRole});
    }
private:
    PlayListModel *m_playlist = nullptr;
    int m_count = 0;
};

static QStringList droppedPaths(const QMimeData *data)
{
    QStringList paths;
    for(const auto &url : data->urls())
        paths << (url.isLocalFile() ? url.toLocalFile() : url.toString());
    return paths;
}

static QString timeLabel(qint64 ms)
{
    const qint64 seconds = qMax<qint64>(0, ms) / 1000;
    return QStringLiteral("%1:%2").arg(seconds / 60).arg(seconds % 60, 2, 10, QLatin1Char('0'));
}

static void decorateDialog(QDialog *dialog, const QString &title)
{
    dialog->setProperty("classicDialog", true);
    dialog->setAttribute(Qt::WA_WindowPropagation);
    dialog->setWindowFlag(Qt::FramelessWindowHint);
    dialog->setWindowTitle(title);
    dialog->layout()->setContentsMargins(12, 9, 12, 8);
    dialog->layout()->setSpacing(8);
    dialog->layout()->setMenuBar(new ConsoleTitle(title, dialog));
    dialog->setSizeGripEnabled(true);
}

// Keep the duration column visible even when a title is longer than the viewport.
class TrackDelegate final : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *p, const QStyleOptionViewItem &option, const QModelIndex &index) const override
    {
        QStyleOptionViewItem opt(option);
        initStyleOption(&opt,index);
        const QString title = QStringLiteral("%1. %2").arg(index.row()+1).arg(opt.text);
        opt.text.clear();
        const QWidget *widget = opt.widget;
        widget->style()->drawControl(QStyle::CE_ItemViewItem,&opt,p,widget);
        p->save();
        p->setPen(opt.palette.color(opt.state.testFlag(QStyle::State_Selected) ?
                                    QPalette::HighlightedText : QPalette::Text));
        const QRect area = opt.rect.adjusted(4,0,-5,0);
        const qint64 duration = index.data(Qt::UserRole).toLongLong();
        const QString length = duration > 0 ? timeLabel(duration) : QStringLiteral("—");
        const int right = qMax(opt.fontMetrics.horizontalAdvance("00:00"), opt.fontMetrics.horizontalAdvance(length));
        p->drawText(area, Qt::AlignVCenter | Qt::AlignRight, length);
        if(index.data(Qt::UserRole+1).toBool())
        {
            const QPoint at = area.topLeft() + QPoint(0,area.height()/2);
            p->save();
            p->setBrush(p->pen().color());
            p->setPen(Qt::NoPen);
            p->drawPolygon(QPolygon{at+QPoint(0,-3),at+QPoint(4,0),at+QPoint(0,3)});
            p->restore();
        }
        const QRect left = area.adjusted(7,0,-right-9,0);
        p->drawText(left, Qt::AlignVCenter | Qt::AlignLeft, opt.fontMetrics.elidedText(title,Qt::ElideRight,left.width()));
        p->restore();
    }
    QSize sizeHint(const QStyleOptionViewItem &opt, const QModelIndex &) const override
    {
        return {80, qMax(19, opt.fontMetrics.height()+2)};
    }
};

ClassicWindow::ClassicWindow()
{
    setWindowTitle(QStringLiteral("Qmmp · 经典播放器"));
    setWindowFlag(Qt::FramelessWindowHint);
    setAcceptDrops(true);
    setObjectName("ClassicWindow");
    createMenus();
    auto panel = [this](const QString &id,const QString &title,QWidget *content) {
        auto *dock = new QDockWidget(title,this);
        dock->setObjectName(id);
        dock->setTitleBarWidget(new ConsoleTitle(title,dock));
        dock->setWidget(content);
        return dock;
    };
    m_eqDock = createClassicEqualizer(this);
    m_playlistDock = panel("playlist",tr("播放列表"),createPlaylist());
    m_lyricsDock = panel("lyrics",tr("歌词秀"),createLyrics());
    m_playlistDock->setAcceptDrops(true);
    m_playlistDock->installEventFilter(this);
    const QList<QDockWidget *> panels {m_eqDock, m_playlistDock, m_lyricsDock};
    for(auto *dock : panels)
    {
        addDockWidget(Qt::BottomDockWidgetArea,dock);
        m_view->addAction(dock->toggleViewAction());
    }
    m_eqDock->setProperty("stackHeight",126);
    m_playlistDock->setProperty("stackHeight",238);
    m_lyricsDock->setProperty("stackHeight",160);
    auto *console = new QWidget(this);
    auto *pages = new QVBoxLayout(console);
    pages->setContentsMargins(0, 0, 0, 0);
    m_deck = createDeck();
    m_compactBar = createCompactBar();
    pages->addWidget(m_deck);
    pages->addWidget(m_compactBar);
    m_compactBar->hide();
    setCentralWidget(console);
    auto *core = SoundCore::instance();
    auto *manager = PlayListManager::instance();
    bindPlaylist(manager->selectedPlayList());
    connect(manager,&PlayListManager::selectedPlayListChanged,this,&ClassicWindow::bindPlaylist);
    connect(core,&SoundCore::trackInfoChanged,this,&ClassicWindow::updateTrack);
    connect(core,&SoundCore::elapsedChanged,this,&ClassicWindow::updatePosition);
    connect(core,&SoundCore::stateChanged,this,&ClassicWindow::updateState);
    auto *helper = UiHelper::instance();
    connect(helper,&UiHelper::toggleVisibilityCalled,this,[this] { setVisible(!isVisible()); });
    connect(helper,&UiHelper::showMainWindowCalled,this,[this] { show(); raise(); activateWindow(); });

    QSettings settings;
    const bool saved = settings.contains("Classic/consoleDocks");
    for(auto *dock : panels)
        dock->setFloating(true);
    resize(396,238);
    if(saved)
    {
        restoreGeometry(settings.value("Classic/consoleGeometry").toByteArray());
        restoreState(settings.value("Classic/consoleDocks").toByteArray());
    }
    else if(settings.contains("Classic/geometry"))
    {
        restoreGeometry(settings.value("Classic/geometry").toByteArray());
        resize(396,238);
    }
    updateState();
    show();
    m_magnet = std::make_unique<WindowMagnet>(this, panels);
    m_view->addAction(tr("磁吸排列"), m_magnet.get(), &WindowMagnet::arrange);
    if(!saved)
        m_magnet->arrange();
}

ClassicWindow::~ClassicWindow() = default;

void ClassicWindow::createMenus()
{
    auto *helper = UiHelper::instance();
    m_menu = new QMenu(this);
    auto *open = m_menu->addAction(tr("打开并播放…"),this,[=]{ helper->playFiles(this); });
    open->setShortcut(QKeySequence::Open);
    addAction(open);
    m_menu->addAction(tr("添加文件夹…"),this,[=]{ helper->addDirectory(this); });
    connect(helper, &UiHelper::trackSearchDialogCreated, this, [this](QDialog *dialog) {
        if(dialog->parentWidget() != this)
            return;
        decorateDialog(dialog, tr("音乐窗"));
        if(auto *search = dialog->findChild<QLineEdit *>("filterLineEdit"))
            search->setPlaceholderText(tr("搜索当前播放列表"));
    });
    m_menu->addAction(tr("设置…"), this, [this] {
        ConfigDialog dialog(this);
        decorateDialog(&dialog, tr("设置"));
        if(auto *navigation = dialog.findChild<QListWidget *>("contentsWidget"))
            navigation->setIconSize(QSize(23, 23));
        dialog.exec();
    });
    m_view = m_menu->addMenu(tr("视图"));
    installClassicSkins(this, m_menu->addMenu(tr("皮肤")));
    auto *tools = m_menu->addMenu(tr("工具"));
    helper->registerMenu(UiHelper::TOOLS_MENU,tools,true);
    m_menu->addSeparator();
    auto *quit = m_menu->addAction(tr("退出"),helper,&UiHelper::exit);
    quit->setShortcut(QKeySequence::Quit);
    addAction(quit);
    auto *play = new QAction(this);
    play->setShortcut(Qt::Key_Space);
    addAction(play);
    connect(play,&QAction::triggered,this,&ClassicWindow::togglePlayback);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,&QWidget::customContextMenuRequested,this,[this](QPoint p){ m_menu->popup(mapToGlobal(p)); });
}

void ClassicWindow::togglePlayback()
{
    auto *core = SoundCore::instance();
    auto *player = MediaPlayer::instance();
    if(core->state() == Qmmp::Playing || core->state() == Qmmp::Paused)
        player->pause();
    else if(PlayListManager::instance()->currentPlayList()->isEmpty())
        UiHelper::instance()->playFiles(this);
    else
        player->play();
}

QWidget *ClassicWindow::createDeck()
{
    auto *core = SoundCore::instance();
    auto *player = MediaPlayer::instance();
    auto *deck = new QWidget(this);
    deck->setObjectName("deck");
    auto *outer = new QVBoxLayout(deck);
    outer->setContentsMargins(2,1,2,2);
    outer->setSpacing(1);
    auto *titleBar = new ConsoleTitle(tr("Qmmp 静听"), this, m_menu);
    connect(titleBar, &ConsoleTitle::compactRequested, this, [this] { setCompactMode(true); });
    outer->addWidget(titleBar);
    auto *inner = new QVBoxLayout;
    inner->setContentsMargins(6,0,6,0);
    inner->setSpacing(2);
    outer->addLayout(inner,1);
    auto *strip = new QWidget(deck);
    strip->setMinimumHeight(27);
    strip->setObjectName("readout");
    auto *readout = new QHBoxLayout(strip);
    readout->setContentsMargins(7,2,6,2);
    m_title = new QLabel(strip);
    m_title->setObjectName("song");
    m_title->setTextFormat(Qt::PlainText);
    m_title->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Preferred);
    m_clock = new QLabel(strip);
    m_clock->setObjectName("clock");
    m_showRemaining = QSettings().value("Classic/showRemainingTime", false).toBool();
    m_clock->setCursor(Qt::PointingHandCursor);
    m_clock->installEventFilter(this);
    readout->addWidget(m_title,1);
    readout->addWidget(m_clock);
    inner->addWidget(strip);
    auto *display = new SpectrumDisplay(deck);
    display->setObjectName("display");
    auto *screen = new QHBoxLayout(display);
    screen->setContentsMargins(5,4,5,4);
    screen->addWidget(new ClassicSpectrum(display),3);
    auto *right = new QVBoxLayout;
    screen->addLayout(right,2);
    m_status = new QLabel(display);
    m_status->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    right->addWidget(m_status);
    auto *audio = new QHBoxLayout;
    auto *mute = new ConsoleKey(ConsoleKey::Speaker,tr("静音"),display);
    mute->setObjectName("mute");
    mute->setFixedSize(22,18);
    mute->setCheckable(true);
    mute->setChecked(core->isMuted());
    connect(mute,&QToolButton::clicked,core,&SoundCore::setMuted);
    connect(core,&SoundCore::mutedChanged,mute,&QToolButton::setChecked);
    audio->addWidget(mute);
    auto *volume = new QSlider(Qt::Horizontal,display);
    volume->setAccessibleName(tr("音量"));
    volume->setRange(0,100);
    volume->setValue(core->volume());
    connect(volume,&QSlider::valueChanged,core,&SoundCore::setVolume);
    connect(core,&SoundCore::volumeChanged,volume,&QSlider::setValue);
    audio->addWidget(volume);
    right->addLayout(audio);
    auto *switches = new QHBoxLayout;
    for(auto *dock : {m_playlistDock,m_eqDock,m_lyricsDock})
    {
        auto *key = new QToolButton(display);
        key->setCheckable(true);
        key->setChecked(dock->isVisible());
        connect(key,&QToolButton::clicked,dock,&QDockWidget::setVisible);
        connect(dock,&QDockWidget::visibilityChanged,key,&QToolButton::setChecked);
        key->setText(dock == m_playlistDock ? "PL" : dock == m_eqDock ? "EQ" : "LRC");
        key->setToolTip(dock->windowTitle());
        key->setAccessibleName(dock->windowTitle());
        key->setObjectName("consoleKey");
        switches->addWidget(key);
    }
    right->addLayout(switches);
    inner->addWidget(display,1);
    m_position = new QSlider(Qt::Horizontal,deck);
    m_position->setObjectName("progress");
    m_position->setAccessibleName(tr("播放进度"));
    m_position->setRange(0,10000);
    m_position->setTracking(false);
    connect(m_position,&QSlider::valueChanged,this,[=](int value) {
        const qint64 time = core->duration()*value/m_position->maximum();
        core->seek(time);
        updatePosition(time);
    });
    inner->addWidget(m_position);
    auto *transport = new QWidget(deck);
    transport->setObjectName("transport");
    auto *keys = new QHBoxLayout(transport);
    keys->setContentsMargins(11,2,4,4);
    keys->setSpacing(3);
    auto key = [&](ConsoleKey::Glyph glyph,const QString &name) {
        auto *b = new ConsoleKey(glyph,name,transport);
        const int size = glyph == ConsoleKey::Play ? 60 : 40;
        b->setObjectName(glyph == ConsoleKey::Play ? "play" : "round");
        b->setFixedSize(size,size);
        if(keys->count()) keys->addStretch(1);
        keys->addWidget(b);
        return b;
    };
    connect(key(ConsoleKey::Stop,tr("停止")),&QToolButton::clicked,player,&MediaPlayer::stop);
    connect(key(ConsoleKey::Previous,tr("上一首")),&QToolButton::clicked,player,&MediaPlayer::previous);
    m_play = key(ConsoleKey::Play,tr("播放"));
    connect(m_play,&QToolButton::clicked,this,&ClassicWindow::togglePlayback);
    connect(key(ConsoleKey::Next,tr("下一首")),&QToolButton::clicked,player,&MediaPlayer::next);
    connect(key(ConsoleKey::Eject,tr("打开文件")),&QToolButton::clicked,this,[this]{ UiHelper::instance()->playFiles(this); });
    keys->addStretch(2);
    auto *library = new QToolButton(transport);
    library->setObjectName("libraryKey");
    library->setText(tr("♫ 音乐窗"));
    library->setToolTip(tr("搜索播放列表中的音乐"));
    library->setFixedSize(76,24);
    connect(library,&QToolButton::clicked,this,[this]{ UiHelper::instance()->jumpToTrack(this); });
    keys->addWidget(library);
    auto *grip = new QSizeGrip(transport);
    grip->setFixedSize(10,10);
    keys->addWidget(grip,0,Qt::AlignBottom);
    outer->addWidget(transport);
    return deck;
}

QWidget *ClassicWindow::createCompactBar()
{
    auto *bar = new WindowDragArea(this);
    bar->setObjectName("compactBar");
    auto *row = new QHBoxLayout(bar);
    row->setContentsMargins(8, 3, 4, 3);
    row->setSpacing(3);
    m_compactTitle = new QLabel(bar);
    m_compactTitle->setObjectName("compactTitle");
    m_compactTitle->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_compactTitle->setTextFormat(Qt::PlainText);
    m_compactTitle->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
    row->addWidget(m_compactTitle, 1);
    auto button = [&](ConsoleKey::Glyph glyph, const QString &name) {
        auto *key = new ConsoleKey(glyph, name, bar);
        key->setFixedSize(26, 22);
        row->addWidget(key);
        return key;
    };
    auto *player = MediaPlayer::instance();
    connect(button(ConsoleKey::Previous, tr("上一首")), &QToolButton::clicked, player, &MediaPlayer::previous);
    m_compactPlay = button(ConsoleKey::Play, tr("播放"));
    connect(m_compactPlay, &QToolButton::clicked, this, &ClassicWindow::togglePlayback);
    connect(button(ConsoleKey::Next, tr("下一首")), &QToolButton::clicked, player, &MediaPlayer::next);
    connect(button(ConsoleKey::Restore, tr("还原主窗口")), &QToolButton::clicked, this,
            [this] { setCompactMode(false); });
    return bar;
}

void ClassicWindow::setCompactMode(bool compact)
{
    if(compact == !m_normalGeometry.isEmpty())
        return;
    m_magnet->setSuspended(true);
    m_view->setEnabled(!compact);
    if(compact)
    {
        const QRect area = screen()->availableGeometry();
        m_normalRect = geometry();
        m_normalGeometry = saveGeometry();
        m_normalDocks = saveState();
        for(auto *panel : {m_eqDock, m_playlistDock, m_lyricsDock})
            panel->hide();
        m_deck->hide();
        m_compactBar->show();
        setWindowFlag(Qt::WindowStaysOnTopHint, true);
        setFixedSize(qMin(320, area.width()), 32);
        move(area.right() - width() + 1, area.top());
        showNormal();
    }
    else
    {
        setWindowFlag(Qt::WindowStaysOnTopHint, false);
        setMinimumSize(0, 0);
        setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
        m_compactBar->hide();
        m_deck->show();
        restoreState(m_normalDocks);
        restoreGeometry(m_normalGeometry);
        // restoreGeometry reserves space for a native title bar, even on a frameless window.
        if(!isMaximized() && screen()->availableGeometry().intersects(m_normalRect))
            setGeometry(m_normalRect);
        show();
        m_normalGeometry.clear();
        m_normalDocks.clear();
        m_magnet->setSuspended(false);
    }
}

QWidget *ClassicWindow::createPlaylist()
{
    auto *helper = UiHelper::instance();
    auto *manager = PlayListManager::instance();
    auto *body = new QWidget(this);
    body->setObjectName("panelBody");
    auto *layout = new QVBoxLayout(body);
    layout->setContentsMargins(5,1,5,5);
    layout->setSpacing(2);
    auto *tools = new QWidget(body);
    tools->setObjectName("listTools");
    auto *row = new QHBoxLayout(tools);
    row->setContentsMargins(2,0,2,0);
    row->setSpacing(0);
    auto tool = [&](const QString &symbol,const QString &label,auto callback, QToolButton *b = nullptr) {
        if(!b)
            b = new QToolButton(tools);
        b->setText(symbol);
        b->setToolTip(label);
        b->setAccessibleName(label);
        b->setFixedHeight(24);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        row->addWidget(b);
        connect(b,&QToolButton::clicked,this,callback);
        return b;
    };
    tool("+",tr("添加歌曲"),[=]{ helper->addFiles(this); });
    tool("−",tr("移除所选曲目"),[this] {
        if(m_list->currentIndex().isValid())
            m_playlist->removeTrack(m_list->currentIndex().row());
    });
    auto *sort = tool("≡", tr("排序"), []{});
    auto *sortMenu = new QMenu(sort);
    sortMenu->addAction(tr("按曲名排序"), this, [this]{ m_playlist->sort(PlayListModel::TITLE); });
    sortMenu->addAction(tr("反转列表顺序"), this, [this]{ m_playlist->reverseList(); });
    sort->setMenu(sortMenu);
    sort->setPopupMode(QToolButton::InstantPopup);
    auto *settings = QmmpUiSettings::instance();
    auto *order = new ConsoleKey(ConsoleKey::Sequential, tr("播放顺序"), tools);
    order->setObjectName("playOrder");
    order->setCheckable(true);
    tool({}, tr("播放顺序"), [settings](bool checked){ settings->setShuffle(checked); }, order);
    auto syncOrder = [order](bool shuffle) {
        order->setChecked(shuffle);
        order->setGlyph(shuffle ? ConsoleKey::Shuffle : ConsoleKey::Sequential);
        order->setAccessibleName(shuffle ? tr("随机播放") : tr("顺序播放"));
        order->setToolTip(shuffle ? tr("随机播放 · 点击切换为顺序播放") : tr("顺序播放 · 点击切换为随机播放"));
    };
    connect(settings, &QmmpUiSettings::shuffleChanged, order, syncOrder);
    syncOrder(settings->isShuffle());
    tool("⌕",tr("查找歌曲"),[=]{ helper->jumpToTrack(this); });
    tool("▤",tr("保存播放列表"),[=]{ helper->savePlayList(this); });
    auto *manage = new QMenu(body);
    manage->addAction(tr("新建列表"),this,[=]{ manager->createPlayList(); });
    manage->addAction(tr("载入播放列表…"),this,[=]{ helper->loadPlayList(this); });
    auto *menuKey = tool("M",tr("管理列表"),[]{});
    menuKey->setMenu(manage);
    menuKey->setPopupMode(QToolButton::InstantPopup);
    layout->addWidget(tools);
    auto *split = new QSplitter(Qt::Horizontal,body);
    split->setHandleWidth(4);
    split->setChildrenCollapsible(false);
    m_collections = new QListWidget(split);
    m_collections->setObjectName("collections");
    m_collections->setAccessibleName(tr("列表分组"));
    m_collections->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_list = new QListView(split);
    m_list->setObjectName("tracks");
    m_list->setAccessibleName(tr("曲目"));
    m_list->setUniformItemSizes(true);
    m_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_tracks = new TrackList(m_list);
    m_list->setModel(m_tracks);
    m_list->setItemDelegate(new TrackDelegate(m_list));
    split->setStretchFactor(1,1);
    split->setSizes({78,300});
    layout->addWidget(split);
    auto sync = [=] {
        QSignalBlocker block(m_collections);
        m_collections->clear();
        for(const QString &name : manager->playListNames())
            m_collections->addItem("[" + name + "]");
        m_collections->setCurrentRow(manager->selectedPlayListIndex());
    };
    sync();
    connect(manager,&PlayListManager::playListsChanged,this,sync);
    connect(manager,&PlayListManager::selectedPlayListChanged,this,[=] {
        QSignalBlocker block(m_collections);
        m_collections->setCurrentRow(manager->selectedPlayListIndex());
    });
    connect(m_collections,&QListWidget::currentRowChanged,manager,&PlayListManager::selectPlayListIndex);
    connect(m_list,&QListView::activated,this,[=](const QModelIndex &index) {
        if(!m_playlist || !m_playlist->setCurrent(index.row()))
            return;
        MediaPlayer::instance()->stop();
        manager->activatePlayList(m_playlist);
        MediaPlayer::instance()->play();
    });
    return body;
}

QWidget *ClassicWindow::createLyrics()
{
    auto *lyrics = new QWidget(this);
    lyrics->setObjectName("lyricPanel");
    auto *lines = new QVBoxLayout(lyrics);
    lines->setContentsMargins(5,2,5,2);
    lines->setSpacing(0);
    lines->addStretch();
    for(size_t i = 0; i < m_lines.size(); ++i)
    {
        auto *label = new QLabel(lyrics);
        label->setObjectName(i == m_lines.size()/2 ? "activeLyric" : "nearLyric");
        label->setAlignment(Qt::AlignCenter);
        label->setTextFormat(Qt::PlainText);
        label->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Preferred);
        m_lines[i] = label;
        lines->addWidget(label);
    }
    lines->addStretch();
    return lyrics;
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
    for(auto *key : {m_play, m_compactPlay})
    {
        key->setGlyph(playing ? ConsoleKey::Pause : ConsoleKey::Play);
        key->setToolTip(playing ? tr("暂停") : tr("播放"));
        key->setAccessibleName(key->toolTip());
    }
    if(playing || core->state() == Qmmp::Paused)
        updateTrack();
    else
    {
        m_path.clear();
        m_lyrics = {};
        m_line = -2;
        m_title->setText(tr("尚未播放"));
        m_compactTitle->setText(m_title->text());
        m_compactBar->setToolTip({});
        m_status->setText(tr("状态: 停止"));
        if(core->state() == Qmmp::NormalError)
            m_status->setText(tr("无法读取歌曲"));
        if(core->state() == Qmmp::FatalError)
            m_status->setText(tr("音频输出不可用"));
        updatePosition(0);
    }
}

void ClassicWindow::updateTrack()
{
    auto *core = SoundCore::instance();
    const auto &info = core->trackInfo();
    const QString path = info.path().isEmpty() ? core->path() : info.path();
    const QString title = info.value(Qmmp::TITLE);
    const QString artist = info.value(Qmmp::ARTIST);
    const QString song = title.isEmpty() ? QFileInfo(path).completeBaseName() : title;
    m_title->setText(artist.isEmpty() ? song : artist + QStringLiteral(" - ") + song);
    m_title->setToolTip(m_title->text());
    m_compactTitle->setText(m_title->text());
    m_compactBar->setToolTip(m_title->text());
    const int channels = core->audioParameters().channels();
    const QString mode = channels == 2 ? tr("立体声") : channels == 1 ? tr("单声道") : QString();
    m_status->setText((core->state() == Qmmp::Paused ? tr("状态: 暂停") : tr("状态: 播放"))
                      + QStringLiteral("  ") + mode);
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
    m_displayPosition = time;
    const qint64 duration = m_path.isEmpty() ? 0 : SoundCore::instance()->duration();
    m_position->setEnabled(duration > 0);
    if(!m_position->isSliderDown())
    {
        QSignalBlocker block(m_position);
        m_position->setValue(duration > 0 ? time * m_position->maximum() / duration : 0);
    }
    const QString elapsed = timeLabel(time);
    QString display = elapsed.rightJustified(5, QLatin1Char('0'));
    if(m_showRemaining && !m_path.isEmpty())
    {
        const qint64 remaining = qMax<qint64>(0, duration - qMax<qint64>(0, time));
        // Keep the last partial second visible until the track actually ends.
        display = duration > 0 ? "-" + timeLabel(remaining + 999).rightJustified(5, QLatin1Char('0'))
                               : QStringLiteral("--:--");
    }
    m_clock->setText(display);
    const QString hint = m_showRemaining ? tr("点击显示已播放时间") : tr("点击显示剩余时间");
    m_clock->setToolTip(elapsed + " / " + (duration > 0 ? timeLabel(duration) : QStringLiteral("--:--"))
                        + QChar::LineFeed + hint);
    updateLyrics(time);
}

void ClassicWindow::updateLyrics(qint64 time)
{
    const int line = m_lyrics.indexAt(time);
    if(m_line == line)
        return;
    m_line = line;
    const int middle = int(m_lines.size()/2);
    for(int i = 0; i < int(m_lines.size()); ++i)
        m_lines[i]->setText(m_lyrics.isEmpty() && i == middle ? tr("暂无同步歌词") :
                            m_lyrics.textAt(line+i-middle));
}

void ClassicWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings;
    settings.setValue("Classic/consoleGeometry", m_normalGeometry.isEmpty() ? saveGeometry() : m_normalGeometry);
    settings.setValue("Classic/consoleDocks", m_normalDocks.isEmpty() ? saveState() : m_normalDocks);
    QMainWindow::closeEvent(event);
    UiHelper::instance()->exit();
}

bool ClassicWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_clock && (event->type() == QEvent::MouseButtonPress ||
                              event->type() == QEvent::MouseButtonRelease))
    {
        const auto *mouse = static_cast<QMouseEvent *>(event);
        if(mouse->button() == Qt::LeftButton && m_clock->rect().contains(mouse->position().toPoint()))
        {
            if(event->type() == QEvent::MouseButtonRelease)
            {
                m_showRemaining = !m_showRemaining;
                QSettings().setValue("Classic/showRemainingTime", m_showRemaining);
                updatePosition(m_displayPosition);
            }
            return true;
        }
    }
    if((event->type() == QEvent::DragEnter || event->type() == QEvent::Drop) &&
       watched == m_playlistDock)
    {
        auto *drop = static_cast<QDropEvent *>(event);
        if(m_playlist && drop->mimeData()->hasUrls())
        {
            if(event->type() == QEvent::Drop)
                m_playlist->addPaths(droppedPaths(drop->mimeData()));
            drop->acceptProposedAction();
            return true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void ClassicWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if(event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void ClassicWindow::dropEvent(QDropEvent *event)
{
    const QStringList paths = droppedPaths(event->mimeData());
    if(!paths.isEmpty())
    {
        UiHelper::instance()->replaceAndPlay(paths);
        event->acceptProposedAction();
    }
}

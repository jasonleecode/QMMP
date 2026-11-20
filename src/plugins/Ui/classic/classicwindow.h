#ifndef CLASSICWINDOW_H
#define CLASSICWINDOW_H
#include <QMainWindow>
#include <array>
#include <memory>
#include "syncedlyrics.h"

struct SkinLayout;
class QLabel;
class QMenu;
class QDockWidget;
class QSlider;
class QListView;
class QListWidget;
class ConsoleKey;
class PlayListModel;
class TrackList;
class WindowMagnet;
class ConsoleTitle;
class CompactDisplay;

class ClassicWindow : public QMainWindow
{
public:
    ClassicWindow();
    ~ClassicWindow() override;
    void applySkinLayout(const SkinLayout &skin);
protected:
    void changeEvent(QEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    void createMenus();
    QWidget *createDeck();
    QWidget *createCompactBar();
    void setCompactMode(bool compact);
    void saveLayout() const;
    void saveCompactPosition() const;
    QWidget *createPlaylist();
    QWidget *createLyrics();
    void togglePlayback();
    void bindPlaylist(PlayListModel *playlist);
    void updateTrack();
    void updatePosition(qint64 time);
    void updateLyrics(qint64 time);
    void updateState();

    QMenu *m_menu, *m_view, *m_skinMenu;
    QDockWidget *m_playlistDock, *m_eqDock, *m_lyricsDock;
    QLabel *m_title, *m_status, *m_clock = nullptr;
    bool m_showRemaining = false;
    qint64 m_displayPosition = 0;
    std::array<QLabel *,7> m_lines;
    QSlider *m_position;
    ConsoleTitle *m_titleBar;
    ConsoleKey *m_play;
    QWidget *m_deck, *m_compactBar;
    QWidget *m_audioControls, *m_panelSwitches;
    QLabel *m_volumeReadout;
    int m_preferredHeight = 238;
    ConsoleKey *m_compactPlay;
    CompactDisplay *m_compactTitle;
    bool m_savedOnClose = false;
    QByteArray m_normalGeometry, m_normalDocks, m_minimizedDocks;
    QRect m_normalRect;
    QListView *m_list;
    QListWidget *m_collections;
    TrackList *m_tracks;
    PlayListModel *m_playlist = nullptr;
    LyricsLoader m_lyricsLoader;
    SyncedLyrics m_lyrics;
    QString m_path;
    int m_line = -2;
    // Remove the event filters before QMainWindow starts deleting the floating panels.
    std::unique_ptr<WindowMagnet> m_magnet;
};
#endif

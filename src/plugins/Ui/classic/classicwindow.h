#ifndef CLASSICWINDOW_H
#define CLASSICWINDOW_H
#include <QMainWindow>
#include <array>
#include <memory>
#include "syncedlyrics.h"

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

class ClassicWindow : public QMainWindow
{
public:
    ClassicWindow();
    ~ClassicWindow() override;
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
    QWidget *createPlaylist();
    QWidget *createLyrics();
    void togglePlayback();
    void bindPlaylist(PlayListModel *playlist);
    void updateTrack();
    void updatePosition(qint64 time);
    void updateLyrics(qint64 time);
    void updateState();

    QMenu *m_menu, *m_view;
    QDockWidget *m_playlistDock, *m_eqDock, *m_lyricsDock;
    QLabel *m_title, *m_status, *m_clock = nullptr;
    bool m_showRemaining = false;
    qint64 m_displayPosition = 0;
    std::array<QLabel *,7> m_lines;
    QSlider *m_position;
    ConsoleTitle *m_titleBar;
    ConsoleKey *m_play;
    QWidget *m_deck, *m_compactBar;
    ConsoleKey *m_compactPlay;
    QLabel *m_compactTitle;
    QByteArray m_normalGeometry, m_normalDocks, m_minimizedDocks;
    QRect m_normalRect;
    QListView *m_list;
    QListWidget *m_collections;
    TrackList *m_tracks;
    PlayListModel *m_playlist = nullptr;
    SyncedLyrics m_lyrics;
    QString m_path;
    int m_line = -2;
    // Remove the event filters before QMainWindow starts deleting the floating panels.
    std::unique_ptr<WindowMagnet> m_magnet;
};
#endif

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

class ClassicWindow : public QMainWindow
{
public:
    ClassicWindow();
    ~ClassicWindow() override;
protected:
    void closeEvent(QCloseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    bool eventFilter(QObject *watched, QEvent *event) override;
private:
    void createMenus();
    QWidget *createDeck();
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
    QLabel *m_title, *m_status, *m_clock;
    std::array<QLabel *,7> m_lines;
    QSlider *m_position;
    ConsoleKey *m_play;
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

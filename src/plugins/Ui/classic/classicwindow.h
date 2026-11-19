#ifndef CLASSICWINDOW_H
#define CLASSICWINDOW_H

#include <QMainWindow>
#include "syncedlyrics.h"

class QLabel;
class QSlider;
class QToolButton;
class QListView;
class PlayListModel;
class TrackList;

class ClassicWindow : public QMainWindow
{
public:
    ClassicWindow();

protected:
    void closeEvent(QCloseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

private:
    void bindPlaylist(PlayListModel *playlist);
    void updateTrack();
    void updatePosition(qint64 time);
    void updateLyrics(qint64 time);
    void updateState();

    QLabel *m_title, *m_artist, *m_clock;
    QLabel *m_previousLine, *m_currentLine, *m_nextLine;
    QSlider *m_position;
    QToolButton *m_play;
    QListView *m_list;
    TrackList *m_tracks;
    PlayListModel *m_playlist = nullptr;
    SyncedLyrics m_lyrics;
    QString m_path;
    int m_line = -2;
};

#endif

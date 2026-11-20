#ifndef SYNCEDLYRICS_H
#define SYNCEDLYRICS_H

#include <QString>
#include <QList>
#include <QFutureWatcher>

struct LyricLine
{
    qint64 time;
    QString text;
};

class SyncedLyrics
{
public:
    void parse(const QByteArray &data);
    void loadForTrack(const QString &path);
    int indexAt(qint64 milliseconds) const;
    QString textAt(int index) const;
    bool isEmpty() const { return m_lines.isEmpty(); }

private:
    QList<LyricLine> m_lines;
};

class LyricsLoader final : public QObject
{
    Q_OBJECT
public:
    LyricsLoader();
    void request(const QString &path);
signals:
    void loaded(const SyncedLyrics &lyrics);
private:
    QString m_requested, m_loading;
    QFutureWatcher<SyncedLyrics> m_watcher;
};

#endif

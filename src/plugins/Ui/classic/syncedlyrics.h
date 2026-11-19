#ifndef SYNCEDLYRICS_H
#define SYNCEDLYRICS_H

#include <QString>
#include <QList>

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

#endif

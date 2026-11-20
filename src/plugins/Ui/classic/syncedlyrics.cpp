#include "syncedlyrics.h"
#include <QtConcurrentRun>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QRegularExpression>
#include <QStringDecoder>
#include <qmmp/qmmptextcodec.h>
#include <algorithm>

void SyncedLyrics::loadForTrack(const QString &path)
{
    m_lines.clear();
    QFileInfo track(path);
    if(!track.isFile())
        return;
    QFile file(track.dir().filePath(track.completeBaseName() + QStringLiteral(".lrc")));
    if(!file.open(QIODevice::ReadOnly))
    {
        file.setFileName(track.dir().filePath(track.completeBaseName() + QStringLiteral(".LRC")));
        if(!file.open(QIODevice::ReadOnly))
            return;
    }
    parse(file.readAll());
}

void SyncedLyrics::parse(const QByteArray &data)
{
    m_lines.clear();
    QStringDecoder decoder(QStringDecoder::Utf8, QStringConverter::Flag::Stateless);
    QString contents = decoder.decode(data);
    if(decoder.hasError())
        contents = QmmpTextCodec("GB18030").toUnicode(data);

    static const QRegularExpression stamp(QStringLiteral(R"(\[(\d{1,6}):([0-5]\d)(?:[.:](\d{1,3}))?\])"));
    static const QRegularExpression offsetTag(QStringLiteral(R"(\[offset:\s*([+-]?\d+)\s*\])"),
                                               QRegularExpression::CaseInsensitiveOption);
    qint64 offset = 0;
    for(const QString &line : contents.split(QChar::LineFeed))
    {
        const auto offsetMatch = offsetTag.match(line);
        if(offsetMatch.hasMatch())
            offset = offsetMatch.captured(1).toInt();
        QList<qint64> times;
        auto matches = stamp.globalMatch(line);
        qsizetype end = 0;
        while(matches.hasNext())
        {
            const auto match = matches.next();
            times << (match.captured(1).toLongLong() * 60 + match.captured(2).toInt()) * 1000
                     + match.captured(3).leftJustified(3, QLatin1Char('0')).toInt();
            end = match.capturedEnd();
        }
        const QString text = line.mid(end).trimmed();
        for(qint64 time : times)
            m_lines.append({time, text});
    }
    for(auto &line : m_lines)
        line.time -= offset;
    std::stable_sort(m_lines.begin(), m_lines.end(), [](const LyricLine &a, const LyricLine &b) {
        return a.time < b.time;
    });
}

int SyncedLyrics::indexAt(qint64 milliseconds) const
{
    auto it = std::upper_bound(m_lines.cbegin(), m_lines.cend(), milliseconds,
                               [](qint64 t, const LyricLine &line) { return t < line.time; });
    return int(it - m_lines.cbegin()) - 1;
}

QString SyncedLyrics::textAt(int index) const
{
    return index >= 0 && index < m_lines.size() ? m_lines.at(index).text : QString();
}

LyricsLoader::LyricsLoader()
{
    connect(&m_watcher, &QFutureWatcher<SyncedLyrics>::finished, this, [this] {
        const QString finished = m_loading;
        m_loading.clear();
        if(finished == m_requested)
            emit loaded(m_watcher.result());
        else
            request(m_requested);
    });
}

void LyricsLoader::request(const QString &path)
{
    m_requested = path;
    if(path.isEmpty() || !m_loading.isEmpty())
        return;
    m_loading = path;
    m_watcher.setFuture(QtConcurrent::run([path] {
        SyncedLyrics lyrics;
        lyrics.loadForTrack(path);
        return lyrics;
    }));
}

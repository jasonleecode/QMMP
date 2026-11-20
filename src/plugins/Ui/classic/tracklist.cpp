#include "tracklist.h"
#include <QSet>
#include <algorithm>
#include <qmmpui/playlistmanager.h>
#include <qmmpui/playlisttrack.h>

void TrackList::resetPlaylist(PlayListModel *playlist)
{
    beginResetModel();
    m_playlist = playlist;
    m_rows = playlist ? playlist->tracks() : QList<PlayListTrack *>();
    endResetModel();
}

void TrackList::syncStructure()
{
    const auto rows = m_playlist->tracks();
    const int oldSize = m_rows.size(), newSize = rows.size();
    int first = 0, suffix = 0;
    while(first < qMin(oldSize, newSize) && m_rows[first] == rows[first])
        ++first;
    while(suffix < qMin(oldSize, newSize)-first && m_rows[oldSize-1-suffix] == rows[newSize-1-suffix])
        ++suffix;
    const int removed = oldSize-first-suffix, added = newSize-first-suffix;
    if(!added && !removed)
        return;
    if(!removed)
    {
        beginInsertRows({}, first, first+added-1);
        m_rows = rows;
        endInsertRows();
    }
    else if(!added)
    {
        beginRemoveRows({}, first, first+removed-1);
        m_rows = rows;
        endRemoveRows();
    }
    else if(oldSize != newSize)
    {
        // A bulk edit can leave selected tracks between two disjoint removals.
        const QSet<PlayListTrack *> wanted(rows.cbegin()+first, rows.cbegin()+first+added);
        for(int end = first+removed; end > first;)
        {
            int start = end;
            while(start > first && !wanted.contains(m_rows.at(start-1)))
                --start;
            if(start < end)
            {
                beginRemoveRows({}, start, end-1);
                m_rows.remove(start, end-start);
                endRemoveRows();
            }
            end = start-1;
        }
        if(m_rows.size() < newSize)
        {
            const QSet<PlayListTrack *> kept(m_rows.cbegin()+first, m_rows.cend()-suffix);
            for(int start = first; start < first+added;)
            {
                int end = start;
                while(end < first+added && !kept.contains(rows.at(end)))
                    ++end;
                if(start < end)
                {
                    beginInsertRows({}, start, end-1);
                    m_rows.insert(start, end-start, nullptr);
                    std::copy_n(rows.cbegin()+start, end-start, m_rows.begin()+start);
                    endInsertRows();
                }
                start = end+1;
            }
        }
    }
    if(m_rows != rows)
    {
        // A sort or a multi-range edit can move the selection and the scroll anchor.
        emit layoutAboutToBeChanged();
        const QModelIndexList before = persistentIndexList();
        QHash<PlayListTrack *, int> positions;
        for(int i = 0; i < newSize; ++i)
            positions.insert(rows[i], i);
        const auto old = m_rows;
        m_rows = rows;
        QModelIndexList after;
        for(const QModelIndex &previous : before)
            after << index(positions.value(old.at(previous.row()), -1), 0);
        changePersistentIndexList(before, after);
        emit layoutChanged();
    }
}

int TrackList::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : m_rows.size();
}

QVariant TrackList::data(const QModelIndex &index, int role) const
{
    if(!m_playlist || !index.isValid() || index.row() >= m_rows.size())
        return {};
    auto *track = m_rows.at(index.row());
    // The source has already applied the whole edit when Qt requests an intermediate row.
    if(m_playlist->track(index.row()) != track && !m_playlist->tracks().contains(track))
        return {};
    switch(role)
    {
    case Qt::UserRole + 1:
        return m_playlist == PlayListManager::instance()->currentPlayList() &&
               track == m_playlist->currentTrack();
    case Qt::UserRole: return track->duration();
    case Qt::ToolTipRole: return track->path();
    case Qt::DisplayRole: return track->formattedTitle(0);
    default: return {};
    }
}

void TrackList::refreshMetadata()
{
    if(!m_rows.isEmpty())
        emit dataChanged(index(0, 0), index(m_rows.size()-1, 0), {Qt::DisplayRole, Qt::UserRole});
}

#ifndef CLASSICTRACKLIST_H
#define CLASSICTRACKLIST_H

#include <QAbstractListModel>

class PlayListModel;
class PlayListTrack;

class TrackList final : public QAbstractListModel
{
public:
    using QAbstractListModel::QAbstractListModel;
    void resetPlaylist(PlayListModel *playlist);
    void syncStructure();
    void refreshMetadata();
    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
private:
    PlayListModel *m_playlist = nullptr;
    QList<PlayListTrack *> m_rows;
};
#endif

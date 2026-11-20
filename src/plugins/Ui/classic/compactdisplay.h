#ifndef COMPACTDISPLAY_H
#define COMPACTDISPLAY_H

#include <QLabel>
#include <QTimer>

class CompactDisplay final : public QLabel
{
public:
    explicit CompactDisplay(QWidget *parent);
    void setReadout(const QString &title, const QString &time, bool playing);

protected:
    void paintEvent(QPaintEvent *) override;
    void showEvent(QShowEvent *event) override;
    void hideEvent(QHideEvent *event) override;

private:
    void updateTimer();
    QTimer m_timer;
    QString m_readout;
    int m_offset = 0;
    bool m_playing = false;
};
#endif

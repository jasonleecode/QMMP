#ifndef COMPACTDISPLAY_H
#define COMPACTDISPLAY_H

#include <QLabel>
#include <QTimer>

class CompactDisplay final : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QColor backlight MEMBER m_backlight)
    Q_PROPERTY(QColor ink MEMBER m_ink)
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
    QColor m_backlight{"#f6cf58"}, m_ink{"#38270e"};
    int m_offset = 0;
    bool m_playing = false;
};
#endif

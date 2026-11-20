#ifndef WINDOWMAGNET_H
#define WINDOWMAGNET_H

#include <QDockWidget>
#include <QMainWindow>
#include <QList>

class WindowMagnet final : public QObject
{
public:
    WindowMagnet(QMainWindow *main, const QList<QDockWidget *> &panels);
    void arrange();
    void setSuspended(bool suspended);

private:
    bool eventFilter(QObject *object, QEvent *event) override;
    void follow(int source);
    void remember();

    QList<QWidget *> windows;
    QList<QRect> frames;
    bool adjusting = false;
    bool suspended = false;
};

#endif

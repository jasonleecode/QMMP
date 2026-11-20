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
    bool beginGroupDrag();
    void moveGroup(QPoint position);
    void endGroupDrag();
    void setSuspended(bool suspended);

private:
    bool eventFilter(QObject *object, QEvent *event) override;
    void follow(int source, QPoint position);
    void remember();

    QList<QWidget *> windows;
    QList<QRect> frames;
    bool dragging = false;
    bool adjusting = false;
    bool suspended = false;
};

#endif

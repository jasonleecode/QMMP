#ifndef WINDOWMAGNET_H
#define WINDOWMAGNET_H

#include <QDockWidget>
#include <QMainWindow>
#include <array>

class WindowMagnet final : public QObject
{
public:
    WindowMagnet(QMainWindow *main, QDockWidget *list, QDockWidget *lyrics);
    void arrange();

private:
    bool eventFilter(QObject *object, QEvent *event) override;
    void follow(int source);
    void remember();

    std::array<QWidget *, 3> windows;
    std::array<QRect, 3> frames;
    bool adjusting = false;
};

#endif

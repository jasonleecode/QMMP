#include "windowmagnet.h"
#include <QEvent>
#include <QScreen>
#include <QWindow>
#include <QTimer>
#include <limits>

namespace {
constexpr int reach = 13;

// Return the smallest translation that joins parallel, overlapping edges.
bool join(const QRect &a, const QRect &b, int distance, QPoint &shift)
{
    int best = distance + 1;
    auto consider = [&](int gap, bool horizontal) {
        if(qAbs(gap) >= best)
            return;
        best = qAbs(gap);
        shift = horizontal ? QPoint(gap, 0) : QPoint(0, gap);
    };
    if(qMin(a.bottom(), b.bottom()) >= qMax(a.top(), b.top()))
    {
        consider(b.left() - a.right() - 1, true);
        consider(b.right() + 1 - a.left(), true);
    }
    if(qMin(a.right(), b.right()) >= qMax(a.left(), b.left()))
    {
        consider(b.top() - a.bottom() - 1, false);
        consider(b.bottom() + 1 - a.top(), false);
    }
    return best <= distance;
}
}

WindowMagnet::WindowMagnet(QMainWindow *main, QDockWidget *list, QDockWidget *lyrics)
    : QObject(main), windows{main, list, lyrics}
{
    for(auto *w : windows)
        w->installEventFilter(this);
    remember();
}

void WindowMagnet::remember()
{
    for(int i = 0; i < 3; ++i)
        frames[i] = windows[i]->isVisible() && windows[i]->isWindow()
                  ? windows[i]->frameGeometry() : QRect();
}

static void matchFrameWidth(QWidget *panel, int width)
{
    const int margins = panel->frameGeometry().width() - panel->width();
    if(panel->frameGeometry().width() != width)
        panel->resize(qMax(1, width - margins), panel->height());
}

void WindowMagnet::arrange()
{
    auto *handle = windows[0]->windowHandle();
    if(!handle || !handle->isExposed())
    {
        if(windows[0]->isVisible())
            QTimer::singleShot(100, this, &WindowMagnet::arrange);
        return;
    }
    adjusting = true;
    auto *main = windows[0];
    const int width = main->frameGeometry().width();
    for(int i = 1; i < 3; ++i)
    {
        auto *dock = static_cast<QDockWidget *>(windows[i]);
        dock->setFloating(true);
        dock->resize(width, qBound(100, (main->screen()->availableGeometry().height() - main->frameGeometry().height()) / 2, 180));
        dock->show();
    }
    // Window managers publish frame margins after mapping the floating panels.
    QTimer::singleShot(100, this, [this] {
        auto *main = windows[0];
        const QRect area = main->screen()->availableGeometry();
        const int groupWidth = main->frameGeometry().width();
        matchFrameWidth(windows[1], groupWidth);
        matchFrameWidth(windows[2], groupWidth);
        const int groupHeight = main->frameGeometry().height() +
            windows[1]->frameGeometry().height() + windows[2]->frameGeometry().height();
        int x = qBound(area.left(), main->x(), qMax(area.left(), area.right()+1-groupWidth));
        int y = qBound(area.top(), main->y(), qMax(area.top(), area.bottom()+1-groupHeight));
        main->move(x,y);
        y += main->frameGeometry().height();
        windows[1]->move(x,y);
        windows[2]->move(x, y + windows[1]->frameGeometry().height());
        remember();
        adjusting = false;
    });
}

bool WindowMagnet::eventFilter(QObject *object, QEvent *event)
{
    if(!adjusting)
    {
        for(int i = 0; i < 3; ++i)
        {
            QWidget *w = windows[i];
            if(object != w)
                continue;
            if(event->type() == QEvent::Move && w->isWindow() && w->isVisible() &&
               frames[i].isValid() && w->frameGeometry().topLeft() != frames[i].topLeft())
            {
                follow(i);
            }
            else if(i == 0 && event->type() == QEvent::Resize && frames[0].isValid())
            {
                // Keep a vertical stack aligned when the player itself is resized.
                adjusting = true;
                bool placed[3] = {true, false, false};
                for(int pass = 0; pass < 2; ++pass)
                    for(int k = 1; k < 3; ++k)
                        for(int j = 0; j < 3; ++j)
                        {
                            if(placed[k] || !placed[j] || !frames[k].isValid() ||
                               frames[k].left() != frames[j].left())
                                continue;
                            const bool below = frames[k].top() == frames[j].bottom() + 1;
                            if(!below && frames[k].bottom() + 1 != frames[j].top())
                                continue;
                            QWidget *panel = windows[k];
                            const QRect anchor = windows[j]->frameGeometry();
                            matchFrameWidth(panel, windows[0]->frameGeometry().width());
                            panel->move(anchor.left(), below ? anchor.bottom() + 1 :
                                        anchor.top() - panel->frameGeometry().height());
                            placed[k] = true;
                        }
                remember();
                adjusting = false;
            }
            else if(event->type() == QEvent::Show || event->type() == QEvent::Hide ||
                    event->type() == QEvent::Resize || event->type() == QEvent::Move)
                remember();
        }
    }
    return QObject::eventFilter(object, event);
}

void WindowMagnet::follow(int source)
{
    adjusting = true;
    bool group[3] = {};
    group[source] = true;
    QPoint shift;
    // Moving the player carries every panel attached to it, including a chain.
    if(source == 0)
        for(int pass = 0; pass < 2; ++pass)
            for(int i = 1; i < 3; ++i)
                for(int j = 0; j < 3; ++j)
                    if(group[j] && !group[i] && frames[i].isValid() &&
                       join(frames[i], frames[j], 1, shift))
                        group[i] = true;
    QPoint delta = windows[source]->frameGeometry().topLeft() - frames[source].topLeft();
    QPoint snap;
    int best = std::numeric_limits<int>::max();
    int target = -1, member = -1;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(group[i] && !group[j] && windows[j]->isVisible() && windows[j]->isWindow() &&
               join(frames[i].translated(delta), windows[j]->frameGeometry(), reach, shift) &&
               shift.manhattanLength() < best)
            {
                target = j;
                member = i;
                best = shift.manhattanLength();
                snap = shift;
            }
    for(int i = 0; i < 3; ++i)
        if(group[i] && windows[i]->isVisible() && windows[i]->isWindow())
        {
            const QPoint pos = frames[i].topLeft() + delta + snap;
            if(windows[i]->frameGeometry().topLeft() != pos)
                windows[i]->move(pos);
        }
    // Compare outside edges: the main frame and a Qt tool window can have
    // different decoration margins under the same window manager.
    if(target == 0 || (member == 0 && target > 0))
    {
        QWidget *panel = windows[target == 0 ? member : target];
        const QRect main = windows[0]->frameGeometry();
        const QRect before = panel->frameGeometry();
        matchFrameWidth(panel, main.width());
        if(before.bottom() + 1 == main.top() || before.top() == main.bottom() + 1)
            panel->move(main.left(), before.top());
        else if(before.right() + 1 == main.left())
            panel->move(main.left() - panel->frameGeometry().width(), before.top());
    }
    remember();
    adjusting = false;
}

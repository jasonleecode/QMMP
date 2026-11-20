#ifndef CONSOLECONTROLS_H
#define CONSOLECONTROLS_H
#include <QToolButton>
#include <QWidget>
#include <QPixmap>

class QHBoxLayout;
class QMenu;
class WindowMagnet;
class SpectrumDisplay final : public QWidget
{
public:
    using QWidget::QWidget;
protected:
    void paintEvent(QPaintEvent *) override;
    void changeEvent(QEvent *) override;
private:
    QPixmap m_glass;
    QColor m_tint;
};

class ConsoleKey final : public QToolButton
{
public:
    enum Glyph { Play, Pause, Stop, Previous, Next, Eject, Minimize, Compact, Restore, Close, Speaker, Sequential, Shuffle };
    ConsoleKey(Glyph glyph, const QString &label, QWidget *parent);
    void setGlyph(Glyph glyph);
protected:
    void paintEvent(QPaintEvent *) override;
private:
    Glyph m_glyph;
};

class WindowDragArea : public QWidget
{
public:
    explicit WindowDragArea(QWidget *parent, bool draggable = true);
    void setWindowMagnet(WindowMagnet *magnet) { m_magnet = magnet; }
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    WindowMagnet *m_magnet = nullptr;
    bool m_groupDrag = false;
    bool m_draggable;
    bool m_manualDrag = false;
    QPoint m_offset;
};

class ConsoleTitle final : public WindowDragArea
{
    Q_OBJECT
public:
    ConsoleTitle(const QString &title, QWidget *owner, QMenu *playerMenu = nullptr);
    QHBoxLayout *row;
signals:
    void compactRequested();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
private:
    bool m_main;
};
#endif

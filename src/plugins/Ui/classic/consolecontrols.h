#ifndef CONSOLECONTROLS_H
#define CONSOLECONTROLS_H
#include <QToolButton>
#include <QWidget>
#include <QPixmap>

class QHBoxLayout;
class QMenu;
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

class ConsoleTitle final : public QWidget
{
    Q_OBJECT
public:
    ConsoleTitle(const QString &title, QWidget *owner, QMenu *playerMenu = nullptr);
    QHBoxLayout *row;
signals:
    void compactRequested();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
private:
    QWidget *m_owner;
    bool m_main;
    bool m_manualDrag = false;
    QPoint m_offset;
};
#endif

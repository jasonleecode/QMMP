#include "consolecontrols.h"
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionToolButton>
#include <QWindow>

void SpectrumDisplay::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    const QColor tint(window()->property("spectrumColor").toString());
    const qreal dpr = devicePixelRatioF();
    if(m_glass.size() != size()*dpr || m_glass.devicePixelRatio() != dpr || tint != m_tint)
    {
        m_tint = tint;
        m_glass = QPixmap(size()*dpr);
        m_glass.setDevicePixelRatio(dpr);
        m_glass.fill(Qt::transparent);
        QPainter film(&m_glass);
        QStyleOption option;
        option.initFrom(this);
        style()->drawPrimitive(QStyle::PE_Widget, &option, &film, this);
        film.setRenderHint(QPainter::Antialiasing);
        film.scale(width()/380., height()/90.);
        film.setPen(Qt::NoPen);
        for(int i = 0; i < 6; ++i)
        {
            const int x = 83+i*27;
            QPainterPath path(QPointF(x,-2));
            path.cubicTo(x+25,16,x+16,57,x+70,97);
            path.cubicTo(x+23,61,x+35,29,x+13,-2);
            path.closeSubpath();
            QLinearGradient gradient(x,0,x+58,85);
            QColor light = tint;
            light.setAlpha(10+i*3);
            gradient.setColorAt(0,light);
            light.setAlpha(4);
            gradient.setColorAt(.56,light);
            light.setAlpha(20);
            gradient.setColorAt(1,light);
            film.fillPath(path,gradient);
        }
    }
    p.drawPixmap(0,0,m_glass);
}

void SpectrumDisplay::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::StyleChange || event->type() == QEvent::PaletteChange)
        m_glass = {};
    QWidget::changeEvent(event);
}

ConsoleKey::ConsoleKey(Glyph glyph, const QString &label, QWidget *parent) :
    QToolButton(parent), m_glyph(glyph)
{
    setAccessibleName(label);
    setToolTip(label);
}

void ConsoleKey::setGlyph(Glyph glyph)
{
    m_glyph = glyph;
    update();
}

void ConsoleKey::paintEvent(QPaintEvent *)
{
    QStyleOptionToolButton option;
    initStyleOption(&option);
    QPainter p(this);
    style()->drawComplexControl(QStyle::CC_ToolButton, &option, &p, this);
    p.setRenderHint(QPainter::Antialiasing);
    if(objectName() == "round" || objectName() == "play")
    {
        const QRectF lens = QRectF(rect()).adjusted(3,3,-3,-3);
        QLinearGradient gloss(0,lens.top(),0,lens.center().y());
        gloss.setColorAt(0,QColor(255,255,255,isDown() ? 35 : 115));
        gloss.setColorAt(1,QColor(255,255,255,0));
        p.setPen(Qt::NoPen);
        p.setBrush(gloss);
        p.drawEllipse(QRectF(lens.x()+1,lens.y(),lens.width()-2,lens.height()*.56));
    }
    p.translate(rect().center() + QPointF(.5, isDown() ? 1.5 : .5));
    const qreal scale = qMin(width(), height()) / (height() > 32 ? 3.4 : 1.9);
    p.scale(scale / 12, scale / 12);
    QColor ink = palette().color(QPalette::ButtonText);
    p.setPen(QPen(ink, 1.65, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin));
    p.setBrush(Qt::NoBrush);
    const Glyph glyph = m_glyph == Maximize && window()->isMaximized() ? Restore : m_glyph;
    switch(glyph)
    {
    case Sequential:
        p.drawLine(-7,-4,6,-4);
        p.drawLine(-7,4,6,4);
        p.drawPolyline(QPolygonF{{3,1},{6,4},{3,7}});
        break;
    case Shuffle:
        p.drawPolyline(QPolygonF{{-7,4},{-4,4},{3,-4},{7,-4}});
        p.drawPolyline(QPolygonF{{-7,-4},{-4,-4},{-2,-2}});
        p.drawPolyline(QPolygonF{{2,2},{4,4},{7,4}});
        for(int y : {-4, 4})
            p.drawPolyline(QPolygonF{{5.,y-2.},{7.,qreal(y)},{5.,y+2.}});
        break;
    case Close:
        p.drawLine(-4,-4,4,4); p.drawLine(-4,4,4,-4); break;
    case Minimize: p.drawLine(-5,4,5,4); break;
    case Maximize: p.drawRect(QRectF(-5,-4.5,10,9)); break;
    case Restore:
        p.drawPolyline(QPolygonF{{-2,-3},{-2,-5},{5,-5},{5,2},{3,2}});
        p.drawRect(QRectF(-5,-2,8,7)); break;
    default:
        p.setPen(Qt::NoPen);
        p.setBrush(ink);
        switch(glyph)
        {
        case Previous: case Next:
            if(glyph == Previous) p.scale(-1,1);
            p.drawPolygon(QPolygonF{{-7,-4.5},{0,0},{-7,4.5}});
            p.drawPolygon(QPolygonF{{0,-4.5},{7,0},{0,4.5}}); break;
        case Stop: p.drawRect(QRectF(-4.5,-4.5,9,9)); break;
        case Pause: p.drawRect(QRectF(-5,-6,3.7,12)); p.drawRect(QRectF(1.3,-6,3.7,12)); break;
        case Play: p.drawPolygon(QPolygonF{{-4,-6},{6,0},{-4,6}}); break;
        case Eject:
            p.drawPolygon(QPolygonF{{0,-6},{5,2},{-5,2}}); p.drawRect(QRectF(-5,3.5,10,1.8)); break;
        case Speaker:
            p.drawPolygon(QPolygonF{{-7,-2},{-4,-2},{0,-5},{0,5},{-4,2},{-7,2}});
            p.setPen(QPen(ink,1.4)); p.setBrush(Qt::NoBrush);
            p.drawArc(QRectF(-3,-4,8,8),-65*16,130*16); break;
        default: break;
        }
    }
}

ConsoleTitle::ConsoleTitle(const QString &title, QWidget *owner, QMenu *playerMenu) :
    QWidget(owner), m_owner(owner), m_main(playerMenu != nullptr)
{
    setObjectName("chrome");
    setAttribute(Qt::WA_StyledBackground);
    setFixedHeight(m_main ? 27 : 25);
    row = new QHBoxLayout(this);
    row->setContentsMargins(7, 2, 6, 2);
    row->setSpacing(4);
    if(m_main)
    {
        auto *logo = new QToolButton(this);
        logo->setText(QStringLiteral("♫"));
        logo->setToolTip(tr("主菜单 · 皮肤与设置"));
        logo->setAccessibleName(tr("主菜单"));
        logo->setMenu(playerMenu);
        logo->setPopupMode(QToolButton::InstantPopup);
        logo->setObjectName("medallion");
        logo->setFixedSize(17,17);
        row->addWidget(logo);
    }
    auto *caption = new QLabel(title, this);
    caption->setObjectName("caption");
    row->addWidget(caption);
    row->addStretch();
    auto add = [&](ConsoleKey::Glyph glyph, const QString &label, auto callback) {
        auto *key = new ConsoleKey(glyph, label, this);
        key->setFixedSize(21,17);
        row->addWidget(key);
        connect(key, &QToolButton::clicked, owner, callback);
        return key;
    };
    if(m_main)
    {
        add(ConsoleKey::Maximize, tr("最大化 / 还原"), [owner] {
            owner->isMaximized() ? owner->showNormal() : owner->showMaximized();
        })->setObjectName("maximize");
        add(ConsoleKey::Minimize, tr("最小化"), [owner] { owner->showMinimized(); })->setObjectName("minimize");
    }
    add(ConsoleKey::Close, tr("关闭"), [owner] { owner->close(); })->setObjectName("closeKey");
}

void ConsoleTitle::mousePressEvent(QMouseEvent *e)
{
    if((m_main || qobject_cast<QDialog *>(m_owner)) && e->button() == Qt::LeftButton)
    {
        m_offset = e->globalPosition().toPoint() - m_owner->frameGeometry().topLeft();
        m_manualDrag = !m_owner->windowHandle() || !m_owner->windowHandle()->startSystemMove();
        e->accept();
    }
    else e->ignore(); // QDockWidget handles dragging its custom title bar.
}
void ConsoleTitle::mouseMoveEvent(QMouseEvent *e)
{
    if(m_manualDrag && !m_owner->isMaximized() && e->buttons().testFlag(Qt::LeftButton))
        m_owner->move(e->globalPosition().toPoint() - m_offset);
    else e->ignore();
}
void ConsoleTitle::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(m_main && e->button() == Qt::LeftButton)
        m_owner->isMaximized() ? m_owner->showNormal() : m_owner->showMaximized();
    else e->ignore();
}

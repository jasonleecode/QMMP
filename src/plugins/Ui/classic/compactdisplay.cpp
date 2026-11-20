#include "compactdisplay.h"
#include <QPainter>
#include <QPainterPath>

CompactDisplay::CompactDisplay(QWidget *parent) : QLabel(parent)
{
    setObjectName("compactTitle");
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
    setTextFormat(Qt::PlainText);
    m_timer.setInterval(50);
    connect(&m_timer, &QTimer::timeout, this, [this] { ++m_offset; update(); });
}

void CompactDisplay::setReadout(const QString &title, const QString &time, bool playing)
{
    if(title != text())
    {
        setText(title);
        m_offset = 0;
    }
    const QString readout = time.isEmpty() ? title : time + QStringLiteral("   ·   ") + title;
    if(m_readout != readout)
    {
        m_readout = readout;
        setAccessibleName(readout);
        update();
    }
    m_playing = playing;
    updateTimer();
}

void CompactDisplay::updateTimer()
{
    if(m_playing && isVisible() && !window()->isMinimized())
    {
        if(!m_timer.isActive())
            m_timer.start();
    }
    else
        m_timer.stop();
}

void CompactDisplay::showEvent(QShowEvent *event)
{
    QLabel::showEvent(event);
    updateTimer();
}

void CompactDisplay::hideEvent(QHideEvent *event)
{
    m_timer.stop();
    QLabel::hideEvent(event);
}

void CompactDisplay::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    const QRectF face = QRectF(rect()).adjusted(1, 1, -1, -1);
    QPainterPath lens;
    lens.moveTo(face.left()+5, face.top());
    lens.lineTo(face.right()-1, face.top());
    lens.lineTo(face.right(), face.top()+3);
    lens.lineTo(face.right()-4, face.bottom());
    lens.lineTo(face.left(), face.bottom());
    lens.lineTo(face.left(), face.top()+6);
    lens.closeSubpath();
    QLinearGradient backlight(0, face.top(), 0, face.bottom());
    backlight.setColorAt(0, QColor("#a16a20"));
    backlight.setColorAt(.12, QColor("#fff09a"));
    backlight.setColorAt(.54, QColor("#f6cf58"));
    backlight.setColorAt(1, QColor("#daa03f"));
    p.setPen(QColor("#59431e"));
    p.setBrush(backlight);
    p.drawPath(lens);

    const QRect area = rect().adjusted(6, 1, -6, -1);
    p.setClipRect(area);
    QFont lcd = font();
    lcd.setPixelSize(13);
    lcd.setWeight(QFont::DemiBold);
    p.setFont(lcd);
    const QFontMetrics metrics(lcd);
    const int cycle = qMax(area.width(), metrics.horizontalAdvance(m_readout)) + 24;
    m_offset %= cycle;
    const int x = area.left() - m_offset;
    const int baseline = area.top() + (area.height() - metrics.height()) / 2 + metrics.ascent();
    p.setPen(QColor("#38270e"));
    p.drawText(x, baseline, m_readout);
    if(x + cycle <= area.right())
        p.drawText(x + cycle, baseline, m_readout);
}

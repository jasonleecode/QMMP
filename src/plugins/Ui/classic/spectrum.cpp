#include "spectrum.h"
#include <qmmp/soundcore.h>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QSettings>
#include <algorithm>
#include <cmath>

ClassicSpectrum::ClassicSpectrum(QWidget *parent) : Visual(parent)
{
    setMinimumSize(130, 52);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setObjectName("visualization");
    setCursor(Qt::PointingHandCursor);
    setFocusPolicy(Qt::StrongFocus);
    const int saved = QSettings().value("Classic/visualization", Spectrum).toInt();
    if(saved >= Spectrum && saved <= StereoLevels)
        mode = static_cast<Mode>(saved);
    updateDescription();
    timer.setInterval(50);
    connect(&timer, &QTimer::timeout, this, &ClassicSpectrum::sample);
    connect(SoundCore::instance(), &SoundCore::stateChanged, this, &ClassicSpectrum::refreshState);
    window()->installEventFilter(this);
    Visual::add(this);
}

ClassicSpectrum::~ClassicSpectrum()
{
    Visual::remove(this);
}

void ClassicSpectrum::refreshState()
{
    if(isVisible() && !window()->isMinimized() && SoundCore::instance()->state() == Qmmp::Playing)
        timer.start();
    else
    {
        timer.stop();
        clearSamples();
        update();
    }
}

bool ClassicSpectrum::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange)
        refreshState();
    return Visual::eventFilter(object, event);
}

void ClassicSpectrum::showEvent(QShowEvent *event)
{
    Visual::showEvent(event);
    refreshState();
}

void ClassicSpectrum::hideEvent(QHideEvent *event)
{
    Visual::hideEvent(event);
    timer.stop();
    clearSamples();
}

void ClassicSpectrum::clearSamples()
{
    levels.fill(0);
    peaks.fill(0);
    wave.fill(0);
    meters.fill(0);
}

void ClassicSpectrum::updateDescription()
{
    const QStringList names = {tr("频谱柱"), tr("时域波形"), tr("左右声道电平")};
    setAccessibleName(names.at(mode));
    setToolTip(tr("%1 · 点击切换到%2").arg(names.at(mode), names.at((mode + 1) % names.size())));
}

void ClassicSpectrum::nextMode()
{
    mode = static_cast<Mode>((mode + 1) % (StereoLevels + 1));
    QSettings().setValue("Classic/visualization", int(mode));
    clearSamples();
    updateDescription();
    update();
}

void ClassicSpectrum::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && rect().contains(event->position().toPoint()))
    {
        nextMode();
        event->accept();
    }
    else Visual::mouseReleaseEvent(event);
}

void ClassicSpectrum::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        nextMode();
    else Visual::keyPressEvent(event);
}

void ClassicSpectrum::sampleSpectrum()
{
    float left[QMMP_VISUAL_FFT_SIZE], right[QMMP_VISUAL_FFT_SIZE];
    const bool ready = takeFFTData(left, right);
    // Narrow bass bands, progressively wider treble bands. Combine the
    // channels after the FFT so opposite-phase stereo remains visible.
    const int bands = int(levels.size());
    auto edge = [bands](int n) { return n + n*n*(QMMP_VISUAL_FFT_SIZE-bands)/(bands*bands); };
    for(size_t i = 0; i < levels.size(); ++i)
    {
        float peak = 0;
        if(ready)
            for(int k = edge(i); k < edge(i + 1); ++k)
                peak = std::max({peak, left[k], right[k]});
        const float db = 20.f * std::log10(std::max(peak / (32767.f * QMMP_VISUAL_FFT_SIZE), 0.00001f));
        levels[i] = std::max(std::clamp((db + 60.f) / 60.f, 0.f, 1.f), levels[i] - 0.09f);
        peaks[i] = std::max(levels[i],peaks[i] - 0.025f);
    }
}

void ClassicSpectrum::sample()
{
    if(mode == Spectrum)
        sampleSpectrum();
    else if(mode == Waveform)
    {
        if(!takeData(wave.data()))
            wave.fill(0);
    }
    else
    {
        std::array<float, QMMP_VISUAL_NODE_SIZE> left, right;
        const bool ready = takeData(left.data(), right.data());
        for(int ch = 0; ch < 2; ++ch)
        {
            float peak = 0;
            if(ready)
                for(float value : (ch ? right : left))
                    peak = std::max(peak, std::abs(value));
            const float db = 20.f * std::log10(std::max(peak, .001f));
            meters[ch] = std::max(std::clamp((db + 60.f) / 60.f, 0.f, 1.f), meters[ch] - .06f);
        }
    }
    update();
}

void ClassicSpectrum::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    const QColor ink(window()->property("spectrumColor").toString());
    if(mode == Waveform)
    {
        // Start on a rising zero crossing so periodic tones stay visually stable.
        constexpr int count = QMMP_VISUAL_NODE_SIZE / 2;
        int start = 0;
        for(int i = 1; i < count; ++i)
            if(wave[i-1] < 0 && wave[i] >= 0) { start = i; break; }
        std::array<QPointF, count> line;
        for(int i = 0; i < count; ++i)
            line[i] = {(width()-1.) * i / (count-1), height() * (.5 - .47 * wave[start+i])};
        p.setRenderHint(QPainter::Antialiasing);
        p.setPen(QPen(ink, 1.5));
        p.drawPolyline(line.data(), count);
        return;
    }
    if(mode == StereoLevels)
    {
        constexpr int segments = 24;
        const qreal step = (width()-18.) / segments;
        for(int ch = 0; ch < 2; ++ch)
        {
            const int center = height() * (ch ? 2 : 1) / 3;
            p.setPen(ink);
            p.drawText(QRect(0,center-9,15,18), Qt::AlignCenter, ch ? "R" : "L");
            for(int i = 0; i < segments; ++i)
            {
                QColor cell = ink;
                if(i >= qRound(meters[ch] * segments))
                    cell.setAlpha(45);
                p.fillRect(QRectF(17+i*step, center-5, qMax(1.,step-2), 10), cell);
            }
        }
        return;
    }
    const qreal step = qreal(width()) / levels.size();
    QLinearGradient ramp(0,0,0,height());
    ramp.setColorAt(0, ink.lighter(130));
    ramp.setColorAt(1, ink.darker(125));
    for(size_t i = 0; i < levels.size(); ++i)
    {
        const int bar = qMax(1, qRound(levels[i] * (height()-4)));
        const QRectF column(i*step, height()-bar, qMax(2.,step-2), bar);
        p.fillRect(column, ramp);
        p.fillRect(QRectF(column.left(), qMax(0, height()-qRound(peaks[i]*(height()-4))-2), column.width(), 1), ink);
    }
}

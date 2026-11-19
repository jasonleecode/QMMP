#include "spectrum.h"
#include <qmmp/soundcore.h>
#include <QPainter>
#include <algorithm>
#include <cmath>

ClassicSpectrum::ClassicSpectrum(QWidget *parent) : Visual(parent)
{
    setFixedSize(120, 44);
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setAccessibleName(tr("音频频谱"));
    timer.setInterval(50);
    connect(&timer, &QTimer::timeout, this, &ClassicSpectrum::sample);
    connect(SoundCore::instance(), &SoundCore::stateChanged, this, &ClassicSpectrum::refreshState);
    Visual::add(this);
}

ClassicSpectrum::~ClassicSpectrum()
{
    Visual::remove(this);
}

void ClassicSpectrum::refreshState()
{
    if(isVisible() && SoundCore::instance()->state() == Qmmp::Playing)
        timer.start();
    else
    {
        timer.stop();
        levels.fill(0);
        update();
    }
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
    levels.fill(0);
}

void ClassicSpectrum::sample()
{
    float left[QMMP_VISUAL_FFT_SIZE], right[QMMP_VISUAL_FFT_SIZE];
    const bool ready = takeFFTData(left, right);
    // Narrow bass bands, progressively wider treble bands. Combine the
    // channels after the FFT so opposite-phase stereo remains visible.
    constexpr int edges[] = {0,1,2,3,4,5,7,9,12,16,21,27,35,45,58,75,96,123,157,201,256};
    for(size_t i = 0; i < levels.size(); ++i)
    {
        float peak = 0;
        if(ready)
            for(int k = edges[i]; k < edges[i + 1]; ++k)
                peak = std::max({peak, left[k], right[k]});
        const float db = 20.f * std::log10(std::max(peak / (32767.f * QMMP_VISUAL_FFT_SIZE), 0.00001f));
        levels[i] = std::max(std::clamp((db + 60.f) / 60.f, 0.f, 1.f), levels[i] - 0.09f);
    }
    update();
}

void ClassicSpectrum::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.fillRect(rect(), QColor(23,48,49));
    for(size_t i = 0; i < levels.size(); ++i)
    {
        const int lit = qRound(levels[i] * 10);
        for(int row = 0; row < 10; ++row)
        {
            const QColor ink = row < 7 ? QColor(105,215,178) : QColor(241,193,112);
            p.fillRect(1 + int(i)*6, height()-5-row*4, 4, 3, row < lit ? ink : QColor(41,73,72));
        }
    }
}

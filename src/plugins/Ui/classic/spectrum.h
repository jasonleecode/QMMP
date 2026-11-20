#ifndef CLASSICSPECTRUM_H
#define CLASSICSPECTRUM_H

#include <qmmp/visual.h>
#include <QTimer>
#include <array>

class ClassicSpectrum final : public Visual
{
public:
    explicit ClassicSpectrum(QWidget *parent);
    ~ClassicSpectrum() override;

protected:
    bool eventFilter(QObject *, QEvent *) override;
    void paintEvent(QPaintEvent *) override;
    void showEvent(QShowEvent *) override;
    void hideEvent(QHideEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void keyPressEvent(QKeyEvent *) override;

private:
    void refreshState();
    void sample();
    enum Mode { Spectrum, Waveform, StereoLevels };
    void nextMode();
    void updateDescription();
    void clearSamples();
    void sampleSpectrum();

    QTimer timer;
    Mode mode = Spectrum;
    std::array<float, 40> levels{}, peaks{};
    std::array<float, QMMP_VISUAL_NODE_SIZE> wave{};
    std::array<float, 2> meters{};
};

#endif

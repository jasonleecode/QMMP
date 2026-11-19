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
    void paintEvent(QPaintEvent *) override;
    void showEvent(QShowEvent *) override;
    void hideEvent(QHideEvent *) override;

private:
    void refreshState();
    void sample();

    QTimer timer;
    std::array<float, 20> levels{};
};

#endif

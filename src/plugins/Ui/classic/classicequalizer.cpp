#include "classicequalizer.h"
#include "consolecontrols.h"
#include <qmmp/qmmpsettings.h>
#include <qmmp/soundcore.h>
#include <QDockWidget>
#include <QLabel>
#include <QMenu>
#include <QSettings>
#include <QSignalBlocker>
#include <QSlider>
#include <QVBoxLayout>

QDockWidget *createClassicEqualizer(QWidget *parent)
{
    auto *core = SoundCore::instance();
    QmmpSettings::instance()->readEqSettings(EqSettings::EQ_BANDS_10);
    auto *dock = new QDockWidget(QObject::tr("均衡器"), parent);
    dock->setObjectName("equalizer");
    auto *bar = new ConsoleTitle(dock->windowTitle(), dock);
    dock->setTitleBarWidget(bar);
    auto key = [&](const QString &text, const QString &label) {
        auto *button = new QToolButton(bar);
        button->setObjectName("consoleKey");
        button->setText(text);
        button->setToolTip(label);
        button->setAccessibleName(label);
        bar->row->insertWidget(bar->row->count()-1, button);
        return button;
    };
    auto *enable = key("OFF", QObject::tr("启用均衡器"));
    enable->setCheckable(true);
    auto *reset = key("RESET", QObject::tr("复位均衡器"));
    auto *preset = key("PRESETS", QObject::tr("均衡器预设"));
    auto *body = new QWidget(dock);
    body->setObjectName("eqBody");
    auto *layout = new QHBoxLayout(body);
    layout->setContentsMargins(10,7,9,7);
    layout->setSpacing(3);

    auto *channels = new QVBoxLayout;
    auto horizontal = [&](const QString &label, int minimum, int value) {
        auto *slider = new QSlider(Qt::Horizontal, body);
        slider->setRange(minimum, 100);
        slider->setValue(value);
        slider->setAccessibleName(label);
        slider->setToolTip(label);
        slider->setMaximumWidth(95);
        channels->addWidget(slider, 0, Qt::AlignCenter);
        return slider;
    };
    auto *balance = horizontal(QObject::tr("声道平衡"), -100, core->balance());
    auto *volume = horizontal(QObject::tr("音量"), 0, core->volume());
    layout->addLayout(channels, 3);
    auto *gains = new QHBoxLayout;
    gains->setSpacing(2);
    layout->addLayout(gains, 5);
    QObject::connect(balance, &QSlider::valueChanged, core, &SoundCore::setBalance);
    QObject::connect(core, &SoundCore::balanceChanged, balance, &QSlider::setValue);
    QObject::connect(volume, &QSlider::valueChanged, core, &SoundCore::setVolume);
    QObject::connect(core, &SoundCore::volumeChanged, volume, &QSlider::setValue);
    const QStringList bands = {"Preamp","60 Hz","170 Hz","310 Hz","600 Hz","1 kHz",
                               "3 kHz","6 kHz","12 kHz","14 kHz","16 kHz"};
    QList<QSlider *> sliders;
    for(int i = 0; i < bands.size(); ++i)
    {
        auto *slider = new QSlider(Qt::Vertical, body);
        slider->setObjectName(i == 0 ? "preamp" : QStringLiteral("band%1").arg(i-1));
        slider->setRange(-20,20);
        slider->setFixedWidth(13);
        slider->setAccessibleName(bands[i]);
        sliders << slider;
        slider->setMaximumHeight(55);
        gains->addWidget(slider, 1, Qt::AlignCenter);
        if(i == 0)
        {
            auto *ticks = new QLabel("+20 dB\n\n  0 dB\n\n−20 dB", body);
            ticks->setObjectName("eqMark");
            ticks->setStyleSheet("font:8px sans-serif");
            gains->addWidget(ticks, 0, Qt::AlignCenter);
        }
        QObject::connect(slider, &QSlider::valueChanged, dock, [=](int gain) {
            auto eq = core->eqSettings();
            if(i == 0) eq.setPreamp(gain);
            else eq.setGain(i-1, gain);
            core->setEqSettings(eq);
        });
    }
    auto sync = [=] {
        const auto eq = core->eqSettings();
        QSignalBlocker block(enable);
        enable->setChecked(eq.isEnabled());
        enable->setText(eq.isEnabled() ? "ON" : "OFF");
        QStringList frequencies = bands;
        const auto rate = core->audioParameters().sampleRate();
        if(rate == 96000 || rate == 22050 || rate == 11025)
        {
            frequencies = QStringList{"Preamp","31 Hz","62 Hz","125 Hz","250 Hz","500 Hz",
                                      "1 kHz","2 kHz","4 kHz","8 kHz","16 kHz"};
            if(rate == 22050) frequencies.last() = "11 kHz";
            if(rate == 11025)
            {
                frequencies[8] = "3 kHz";
                frequencies[9] = "4 kHz";
                frequencies[10] = "5.5 kHz";
            }
        }
        for(int i = 0; i < sliders.size(); ++i)
        {
            QSignalBlocker blocked(sliders[i]);
            const double gain = i ? eq.gain(i-1) : eq.preamp();
            sliders[i]->setValue(qRound(gain));
            sliders[i]->setAccessibleName(frequencies[i]);
            sliders[i]->setToolTip(QStringLiteral("%1 · %2 dB").arg(frequencies[i]).arg(gain));
        }
    };
    QObject::connect(core, &SoundCore::eqSettingsChanged, dock, sync);
    QObject::connect(core, &SoundCore::audioParametersChanged, dock, sync);
    QObject::connect(enable, &QToolButton::clicked, dock, [core](bool on) {
        auto eq = core->eqSettings();
        eq.setEnabled(on);
        core->setEqSettings(eq);
    });
    QObject::connect(reset, &QToolButton::clicked, dock, [core] {
        auto eq = core->eqSettings();
        eq.setPreamp(0);
        for(int i = 0; i < eq.bands(); ++i)
            eq.setGain(i,0);
        core->setEqSettings(eq);
    });
    auto *presets = new QMenu(preset);
    QSettings values(":/classic/eq.preset", QSettings::IniFormat);
    for(int i = 1; values.contains(QStringLiteral("Presets/Preset%1").arg(i)); ++i)
    {
        const QString name = values.value(QStringLiteral("Presets/Preset%1").arg(i)).toString();
        auto setting = core->eqSettings();
        setting.setPreamp(values.value(name + "/Preamp").toDouble());
        for(int j = 0; j < setting.bands(); ++j)
            setting.setGain(j, values.value(name + QStringLiteral("/Band%1").arg(j)).toDouble());
        presets->addAction(name, dock, [=] {
            auto eq = core->eqSettings();
            eq.setEnabled(true);
            eq.setPreamp(setting.preamp());
            for(int j = 0; j < eq.bands(); ++j)
                eq.setGain(j,setting.gain(j));
            core->setEqSettings(eq);
        });
    }
    preset->setMenu(presets);
    preset->setPopupMode(QToolButton::InstantPopup);
    sync();
    dock->setWidget(body);
    return dock;
}

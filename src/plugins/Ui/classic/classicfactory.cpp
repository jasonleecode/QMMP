#include <QObject>
#include <QString>
#include <qmmpui/uifactory.h>
#include "classicwindow.h"

class ClassicFactory : public QObject, public UiFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qmmp.qmmpui.UiFactoryInterface.1.0")
    Q_INTERFACES(UiFactory)
public:
    UiProperties properties() const override
    {
        UiProperties props;
        props.shortName = QStringLiteral("classic");
        props.name = QStringLiteral("经典中文播放器");
        return props;
    }
    QObject *create() override { return new ClassicWindow; }
    void showAbout(QWidget *) override {}
    QString translation() const override { return {}; }
};

#include "classicfactory.moc"

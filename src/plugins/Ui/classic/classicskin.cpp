#include "classicskin.h"
#include "classicwindow.h"
#include "skinpackage.h"
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QMenu>
#include <QPalette>
#include <QColor>
#include <QFileInfo>

namespace {
const QString defaultSkin = QStringLiteral(":/classic/skins/violet.ini");
class ActiveSkin final : public QObject
{
public:
    explicit ActiveSkin(ClassicWindow *owner) : QObject(owner), window(owner) {}
    bool apply(const QString &file, bool install = false);
    QString path, name;
private:
    ClassicWindow *window;
    std::unique_ptr<QTemporaryDir> assets;
};

bool ActiveSkin::apply(const QString &file, bool install)
{
    ClassicSkinDefinition skin;
    if(!readClassicSkin(file, skin))
        return false;
    QFile base(":/classic/skins/classic.qss");
    if(!base.open(QIODevice::ReadOnly))
        return false;
    QString sheet = QString::fromUtf8(base.readAll());
    const QString extension = skin.style;
    if(!extension.isEmpty())
    {
        QFile extra(QDir(skin.directory).filePath(extension));
        if(!extra.open(QIODevice::ReadOnly))
            return false;
        QString custom = QString::fromUtf8(extra.readAll());
        sheet += QChar::LineFeed + custom.replace("@SKIN_DIR@", skin.directory);
    }
    for(const QString &key : {"edge","shadow","body","metal","shine","display","glow",
                              "accent","spectrum","text","muted"})
    {
        const QColor color(skin.colors.value(key));
        if(!color.isValid())
            return false;
        sheet.replace("@" + key + "@", color.name());
    }
    auto color = [&](const QString &name) { return QColor(skin.colors.value(name)); };
    const QString selected = install && !skin.package.isEmpty() ? installClassicSkinPackage(skin.package) : file;
    if(selected.isEmpty())
        return false;
    QPalette palette = window->palette();
    palette.setColor(QPalette::Window, color("body"));
    palette.setColor(QPalette::Base, color("shadow"));
    palette.setColor(QPalette::AlternateBase, color("body"));
    palette.setColor(QPalette::Button, color("metal"));
    palette.setColor(QPalette::Text, color("text"));
    palette.setColor(QPalette::WindowText, color("text"));
    palette.setColor(QPalette::ButtonText, color("text"));
    palette.setColor(QPalette::PlaceholderText, color("muted"));
    palette.setColor(QPalette::Highlight, color("glow"));
    palette.setColor(QPalette::HighlightedText, color("text"));
    for(auto role : {QPalette::Text, QPalette::WindowText, QPalette::ButtonText})
        palette.setColor(QPalette::Disabled, role, color("muted"));
    window->setPalette(palette);
    window->setProperty("spectrumColor", skin.colors.value("spectrum"));
    window->applySkinLayout(skin.layout);
    window->setStyleSheet(sheet);
    assets = std::move(skin.unpacked);
    name = skin.name;
    path = selected;
    return true;
}
}

void installClassicSkins(ClassicWindow *window, QMenu *menu)
{
    QSettings settings;
    QString current = settings.value("Classic/skin", defaultSkin).toString();
    auto *active = new ActiveSkin(window);
    if(!active->apply(current))
    {
        current = defaultSkin;
        active->apply(current);
    }
    auto *group = new QActionGroup(menu);
    auto add = [=](const QString &path, QString name) {
        if(name.isEmpty())
        {
            ClassicSkinDefinition skin;
            name = readClassicSkin(path, skin) ? skin.name : QFileInfo(path).baseName();
        }
        auto *action = new QAction(name, group);
        action->setData(path);
        action->setCheckable(true);
        menu->addAction(action);
        return action;
    };
    QStringList files = {defaultSkin, QStringLiteral(":/classic/skins/midnight.ini"),
                         QStringLiteral(":/classic/skins/obsidian.ini"), QStringLiteral(":/classic/skins/amber/skin.xml")};
    files += settings.value("Classic/skinFiles").toStringList();
    files.removeDuplicates();
    const auto names = settings.value("Classic/skinNames").toMap();
    for(const QString &file : files)
        if(QFileInfo::exists(file))
            add(file, names.value(file).toString())->setChecked(file == current);
    QObject::connect(group, &QActionGroup::triggered, window, [=](QAction *action) {
        const QString file = action->data().toString();
        if(active->apply(file))
            QSettings().setValue("Classic/skin", file);
        else
        {
            const QString previous = active->path;
            for(auto *item : group->actions())
                item->setChecked(item->data().toString() == previous);
            QMessageBox::warning(window, QObject::tr("皮肤"), QObject::tr("皮肤文件无效或已移动。"));
        }
    });
    auto *separator = menu->addSeparator();
    menu->addAction(QObject::tr("载入皮肤…"), window, [=] {
        const QString source = QFileDialog::getOpenFileName(window, QObject::tr("载入皮肤"), {},
                QObject::tr("Qmmp 皮肤 (*.qmmp-skin *.zip *.xml *.ini)"));
        if(source.isEmpty())
            return;
        if(!active->apply(source, true))
        {
            QMessageBox::warning(window, QObject::tr("皮肤"), QObject::tr("请检查皮肤包中的 skin.xml、版本、颜色和素材文件。"));
            return;
        }
        const QString file = active->path;
        QSettings config;
        auto names = config.value("Classic/skinNames").toMap();
        names.insert(file, active->name);
        config.setValue("Classic/skinNames", names);
        config.setValue("Classic/skin", file);
        QStringList paths = config.value("Classic/skinFiles").toStringList();
        if(!paths.contains(file))
        {
            paths << file;
            config.setValue("Classic/skinFiles", paths);
        }
        for(auto *action : group->actions())
            if(action->data() == file)
            {
                action->setChecked(true);
                return;
            }
        auto *item = add(file, active->name);
        menu->insertAction(separator, item);
        item->setChecked(true);
    });
}

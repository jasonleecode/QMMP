#include "classicskin.h"
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
bool applySkin(QWidget *window, const QString &path)
{
    QSettings values(path, QSettings::IniFormat);
    QFile base(":/classic/skins/classic.qss");
    if(!base.open(QIODevice::ReadOnly) || values.value("Skin/Name").toString().isEmpty())
        return false;
    QString sheet = QString::fromUtf8(base.readAll());
    for(const QString &key : {"edge","shadow","body","metal","shine","display","glow",
                              "accent","spectrum","text","muted"})
    {
        const QColor color(values.value("Colors/" + key).toString());
        if(!color.isValid())
            return false;
        sheet.replace("@" + key + "@", color.name());
    }
    const QString extension = values.value("Skin/Style").toString();
    if(!extension.isEmpty())
    {
        QFile extra(QFileInfo(path).dir().filePath(extension));
        if(!extra.open(QIODevice::ReadOnly))
            return false;
        QString custom = QString::fromUtf8(extra.readAll());
        sheet += QChar::LineFeed + custom.replace("@SKIN_DIR@", QFileInfo(path).absolutePath());
    }
    auto color = [&](const QString &name) { return QColor(values.value("Colors/" + name).toString()); };
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
    window->setProperty("spectrumColor", values.value("Colors/spectrum"));
    window->setStyleSheet(sheet);
    return true;
}
}

void installClassicSkins(QWidget *window, QMenu *menu)
{
    QSettings settings;
    QString current = settings.value("Classic/skin", defaultSkin).toString();
    if(!applySkin(window, current))
    {
        current = defaultSkin;
        applySkin(window, current);
    }
    auto *group = new QActionGroup(menu);
    auto add = [=](const QString &path) {
        QSettings skin(path, QSettings::IniFormat);
        auto *action = new QAction(skin.value("Skin/Name", QFileInfo(path).baseName()).toString(), group);
        action->setData(path);
        action->setCheckable(true);
        menu->addAction(action);
        return action;
    };
    QStringList files = {defaultSkin, QStringLiteral(":/classic/skins/midnight.ini")};
    files += settings.value("Classic/skinFiles").toStringList();
    files.removeDuplicates();
    for(const QString &file : files)
        if(QFileInfo::exists(file))
            add(file)->setChecked(file == current);
    QObject::connect(group, &QActionGroup::triggered, window, [=](QAction *action) {
        const QString file = action->data().toString();
        if(applySkin(window, file))
            QSettings().setValue("Classic/skin", file);
        else
        {
            const QString previous = QSettings().value("Classic/skin", defaultSkin).toString();
            for(auto *item : group->actions())
                item->setChecked(item->data().toString() == previous);
            QMessageBox::warning(window, QObject::tr("皮肤"), QObject::tr("皮肤文件无效或已移动。"));
        }
    });
    menu->addSeparator();
    menu->addAction(QObject::tr("载入皮肤…"), window, [=] {
        const QString file = QFileDialog::getOpenFileName(window, QObject::tr("载入皮肤"), {}, "Qmmp Classic (*.ini)");
        if(file.isEmpty())
            return;
        if(!applySkin(window, file))
        {
            QMessageBox::warning(window, QObject::tr("皮肤"), QObject::tr("请检查皮肤清单中的颜色与样式文件。"));
            return;
        }
        QSettings config;
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
        add(file)->setChecked(true);
    });
}

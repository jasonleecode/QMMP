#ifndef SKINPACKAGE_H
#define SKINPACKAGE_H
#include "classicskin.h"
#include <QHash>
#include <QTemporaryDir>
#include <memory>

struct ClassicSkinDefinition
{
    QString name, directory, style;
    QHash<QString, QString> colors;
    SkinLayout layout;
    std::unique_ptr<QTemporaryDir> unpacked;
    QByteArray package;
};

bool readClassicSkin(const QString &path, ClassicSkinDefinition &skin);
QString installClassicSkinPackage(const QByteArray &package);
#endif

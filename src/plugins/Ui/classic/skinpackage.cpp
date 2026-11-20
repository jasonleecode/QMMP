#include "skinpackage.h"
#include <archive.h>
#include <archive_entry.h>
#include <qmmp/qmmp.h>
#include <QCryptographicHash>
#include <QDir>
#include <QFile>
#include <QSaveFile>
#include <QSettings>
#include <QXmlStreamReader>
#include <array>

namespace {
constexpr qint64 maxPackageSize = 32 * 1024 * 1024;

bool relativePath(const QString &name)
{
    if(name.isEmpty() || name.contains('\\') || name.contains(':') || QDir::isAbsolutePath(name))
        return false;
    for(const auto &part : name.split('/'))
        if(part.isEmpty() || part == "." || part == "..")
            return false;
    return true;
}

bool unpack(const QByteArray &bytes, const QString &directory)
{
    std::unique_ptr<archive, decltype(&archive_read_free)> reader(archive_read_new(), archive_read_free);
    if(!reader || archive_read_support_format_zip(reader.get()) != ARCHIVE_OK ||
       archive_read_open_memory(reader.get(), bytes.constData(), bytes.size()) != ARCHIVE_OK)
        return false;

    QDir root(directory);
    std::array<char, 16384> chunk;
    archive_entry *entry = nullptr;
    qint64 total = 0;
    int status, count = 0;
    while((status = archive_read_next_header(reader.get(), &entry)) == ARCHIVE_OK)
    {
        QString name = QString::fromUtf8(archive_entry_pathname(entry));
        const auto type = archive_entry_filetype(entry);
        if(type == AE_IFDIR && name.endsWith('/'))
            name.chop(1);
        if(++count > 512 || !relativePath(name) || archive_entry_symlink(entry) || archive_entry_hardlink(entry))
            return false;
        if(type == AE_IFDIR)
            continue;
        const QString destination = root.filePath(name);
        if(type != AE_IFREG || !root.mkpath(QFileInfo(destination).absolutePath()))
            return false;
        QFile file(destination);
        if(!file.open(QIODevice::WriteOnly | QIODevice::NewOnly))
            return false;
        qint64 n;
        while((n = archive_read_data(reader.get(), chunk.data(), chunk.size())) > 0)
        {
            total += n;
            if(total > maxPackageSize || file.write(chunk.data(), n) != n)
                return false;
        }
        if(n < 0)
            return false;
    }
    return status == ARCHIVE_EOF;
}

bool readLayout(const QXmlStreamAttributes &a, SkinLayout &s)
{
    auto location = [&](const char *key, const char *first, const char *second, bool &value) {
        if(!a.hasAttribute(key)) return true;
        value = a.value(key) == QLatin1String(first);
        return value || a.value(key) == QLatin1String(second);
    };
    if(!location("clock","left","right",s.clockLeft) || !location("playlistTools","bottom","top",s.toolsBottom) ||
       !location("volume","transport","display",s.volumeInTransport) ||
       !location("panelSwitches","transport","display",s.switchesInTransport) ||
       !location("volumeReadout","true","false",s.volumeReadout) || !location("flatKeys","true","false",s.flatKeys))
        return false;
    const std::pair<const char *, int *> metrics[] = {
        {"keyWidth",&s.keyWidth}, {"keyHeight",&s.keyHeight}, {"playWidth",&s.playWidth}, {"playHeight",&s.playHeight},
        {"libraryWidth",&s.libraryWidth}, {"libraryHeight",&s.libraryHeight}, {"keySpacing",&s.keySpacing},
        {"volumeWidth",&s.volumeWidth}, {"screenMargin",&s.screenMargin}, {"screenSpacing",&s.screenSpacing},
        {"mainHeight",&s.mainHeight}, {"playlistHeight",&s.playlistHeight}, {"lyricsHeight",&s.lyricsHeight}
    };
    for(auto [name, value] : metrics)
    {
        if(!a.hasAttribute(name))
            continue;
        bool ok;
        *value = a.value(name).toInt(&ok);
        if(!ok || *value < 0 || *value > 4096)
            return false;
    }
    s.libraryText = a.value("libraryText").toString();
    return true;
}

bool readManifest(const QString &path, ClassicSkinDefinition &skin)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly) || file.size() > 1024 * 1024)
        return false;
    QXmlStreamReader xml(&file);
    if(!xml.readNextStartElement() || xml.name() != QStringLiteral("qmmp-skin") ||
       xml.attributes().value("version") != QStringLiteral("1"))
        return false;
    skin.name = xml.attributes().value("name").toString();
    while(xml.readNextStartElement())
    {
        const auto a = xml.attributes();
        if(xml.name() == QStringLiteral("colors"))
        {
            for(const auto &item : a)
                skin.colors.insert(item.name().toString(), item.value().toString());
        }
        else if(xml.name() == QStringLiteral("layout"))
        {
            if(!readLayout(a, skin.layout))
                return false;
        }
        else if(xml.name() == QStringLiteral("captions"))
        {
            skin.layout.mainCaption = a.value("main").toString();
            skin.layout.eqCaption = a.value("equalizer").toString();
            skin.layout.playlistCaption = a.value("playlist").toString();
            skin.layout.lyricsCaption = a.value("lyrics").toString();
        }
        else if(xml.name() == QStringLiteral("icon"))
        {
            const QString action = a.value("action").toString();
            if(action.isEmpty() || !a.hasAttribute("file"))
                return false;
            const std::pair<const char *, QIcon::Mode> modes[] = {
                {"file", QIcon::Normal}, {"hover", QIcon::Active}, {"pressed", QIcon::Selected}, {"disabled", QIcon::Disabled}
            };
            QIcon icon;
            for(auto [key, mode] : modes)
            {
                if(!a.hasAttribute(key))
                    continue;
                const QString name = a.value(key).toString();
                const QString file = QDir(skin.directory).filePath(name);
                if(!relativePath(name) || !QFileInfo(file).isFile())
                    return false;
                icon.addFile(file, {}, mode);
            }
            skin.layout.icons.insert(action, icon);
        }
        else if(xml.name() == QStringLiteral("style"))
        {
            skin.style = a.value("file").toString();
            if(!relativePath(skin.style))
                return false;
        }
        else if(xml.name() == QStringLiteral("artwork"))
        {
            const QString emblem = a.value("emblem").toString();
            if(!relativePath(emblem))
                return false;
            skin.layout.emblem = QDir(skin.directory).filePath(emblem);
            if(!QFileInfo::exists(skin.layout.emblem))
                return false;
        }
        xml.skipCurrentElement();
    }
    while(!xml.atEnd())
        xml.readNext();
    return !xml.hasError() && !skin.name.isEmpty();
}
}

bool readClassicSkin(const QString &path, ClassicSkinDefinition &skin)
{
    const QFileInfo info(path);
    skin.directory = info.absolutePath();
    if(info.suffix().compare("ini", Qt::CaseInsensitive) == 0)
    {
        QSettings ini(path, QSettings::IniFormat);
        skin.name = ini.value("Skin/Name").toString();
        skin.style = ini.value("Skin/Style").toString();
        ini.beginGroup("Colors");
        for(const auto &key : ini.childKeys())
            skin.colors.insert(key, ini.value(key).toString());
        return !skin.name.isEmpty();
    }
    if(info.suffix().compare("xml", Qt::CaseInsensitive) == 0)
        return readManifest(path, skin);
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly) || file.size() <= 0 || file.size() > maxPackageSize)
        return false;
    skin.package = file.read(maxPackageSize + 1);
    skin.unpacked = std::make_unique<QTemporaryDir>();
    if(skin.package.size() > maxPackageSize || !skin.unpacked->isValid() || !unpack(skin.package, skin.unpacked->path()))
        return false;
    skin.directory = skin.unpacked->path();
    return readManifest(QDir(skin.directory).filePath("skin.xml"), skin);
}

QString installClassicSkinPackage(const QByteArray &package)
{
    QDir dir(Qmmp::configDir() + "/skins");
    if(!dir.mkpath("."))
        return {};
    const QByteArray hash = QCryptographicHash::hash(package, QCryptographicHash::Sha256).toHex();
    const QString path = dir.filePath(QString::fromLatin1(hash) + ".qmmp-skin");
    QSaveFile file(path);
    if(!file.open(QIODevice::WriteOnly) || file.write(package) != package.size() || !file.commit())
        return {};
    return path;
}

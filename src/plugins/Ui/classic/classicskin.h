#ifndef CLASSICSKIN_H
#define CLASSICSKIN_H
#include <QString>
#include <QHash>
#include <QIcon>
class QMenu;
class ClassicWindow;

struct SkinLayout
{
    bool clockLeft = false, toolsBottom = false, volumeInTransport = false, switchesInTransport = false;
    bool volumeReadout = false, flatKeys = false;
    int keyWidth = 40, keyHeight = 40, playWidth = 60, playHeight = 60;
    int libraryWidth = 76, libraryHeight = 24, keySpacing = 3, volumeWidth = 16777215;
    int screenMargin = 6, screenSpacing = 2, mainHeight = 238, playlistHeight = 238, lyricsHeight = 160;
    QHash<QString, QIcon> icons;
    QString libraryText, mainCaption, eqCaption, playlistCaption, lyricsCaption, emblem;
};

void installClassicSkins(ClassicWindow *window, QMenu *menu);
#endif

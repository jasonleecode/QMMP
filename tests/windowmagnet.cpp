#include "../src/plugins/Ui/classic/windowmagnet.h"
#include <QApplication>
#include <QDebug>

static bool stacked(const QWidget &upper, const QWidget &lower)
{
    const QRect a = upper.frameGeometry();
    const QRect b = lower.frameGeometry();
    return b.left() == a.left() && b.width() == a.width() && b.top() == a.bottom() + 1;
}

static int fail(const char *message)
{
    qCritical("%s", message);
    return 1;
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QMainWindow player;
    QDockWidget playlist(&player), lyrics(&player);
    player.resize(360, 90);
    player.move(40, 40);
    player.show();
    for(auto *panel : {&playlist, &lyrics})
    {
        panel->setFloating(true);
        panel->resize(180, 80);
        panel->show();
    }
    playlist.move(420, 250);
    lyrics.move(480, 440);
    app.processEvents();
    WindowMagnet magnet(&player, &playlist, &lyrics);

    auto moveBelow = [&](QWidget &panel, const QWidget &anchor) {
        const QRect frame = anchor.frameGeometry();
        panel.move(frame.left() + 20, frame.bottom() + 6);
        app.processEvents();
    };
    moveBelow(playlist, player);
    if(!stacked(player, playlist))
        return fail("Playlist did not match the player");
    moveBelow(lyrics, playlist);
    if(!stacked(playlist, lyrics))
        return fail("Lyrics did not match the playlist");
    player.resize(450, player.height());
    app.processEvents();
    if(!stacked(player, playlist) || !stacked(playlist, lyrics))
        return fail("Resizing the player broke the stack");
    playlist.move(420, 380);
    playlist.resize(240, playlist.height());
    app.processEvents();
    const QRect detachedPlaylist = playlist.frameGeometry();
    moveBelow(lyrics, playlist);
    if(playlist.frameGeometry() != detachedPlaylist || !stacked(playlist, lyrics))
        return fail("Lyrics did not adopt the detached playlist's width");
    return 0;
}

/***************************************************************************
 *   Copyright (C) 2008-2025 by Ilya Kotov                                 *
 *   forkotov02@ya.ru                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#include <QMenu>
#include <QMainWindow>
#include <QSettings>
#include <QDir>
#include <QTimer>
#include <QCoreApplication>
#include <QWheelEvent>
#include <QEvent>
#include <QStyle>
#include <QApplication>
#include <qmmp/soundcore.h>
#include <qmmpui/mediaplayer.h>
#include <qmmpui/uihelper.h>
#include "qmmptrayicon.h"
#include "statusicon.h"

StatusIcon::StatusIcon(QObject *parent) : QObject(parent)
{
    m_tray = new QmmpTrayIcon(this);
    connect(m_tray, &QmmpTrayIcon::activated, this, &StatusIcon::trayActivated);
    //m_tray->show();
    m_core = SoundCore::instance();
    m_player = MediaPlayer::instance();
    QSettings settings;
    settings.beginGroup(u"Tray"_s);
    m_showMessage = settings.value(u"show_message"_s, false).toBool();
    m_messageDelay = settings.value(u"message_delay"_s, 2000).toInt();
    m_useStandardIcons = settings.value(u"use_standard_icons"_s, false).toBool();
    m_showToolTip = settings.value(u"show_tooltip"_s, true).toBool();
    m_splitFileName = settings.value(u"split_file_name"_s, true).toBool();
#ifdef QMMP_WS_X11
    m_toolTipTemplate = settings.value(u"tooltip_template"_s, DEFAULT_TEMPLATE).toString();
#else
    m_toolTipTemplate = u"%p%if(%p&%t, - ,)%t"_s;
#endif
    m_toolTipFormatter.setPattern(m_toolTipTemplate);
    m_messageFormatter.setPattern(u"%p%if(%p&%t, - ,)%t"_s);
    if(m_useStandardIcons)
        m_tray->setIcon(QApplication::style ()->standardIcon(QStyle::SP_MediaStop));
    else
        m_tray->setIcon(QIcon(u":/tray_stop.png"_s));
    settings.endGroup();
    m_menu = new QMenu();
    m_menu->setObjectName(u"trayMenu"_s);
    m_menu->setMinimumWidth(220);
    m_menu->setStyleSheet(QStringLiteral(
        "QMenu#trayMenu { background:palette(window); color:palette(window-text); "
        "border:1px solid palette(mid); padding:5px; }"
        "QMenu#trayMenu::item { padding:6px 18px 6px 30px; border-radius:3px; }"
        "QMenu#trayMenu::item:selected { background:palette(highlight); color:palette(highlighted-text); }"
        "QMenu#trayMenu::item:disabled { color:palette(mid); }"
        "QMenu#trayMenu::separator { height:1px; background:palette(mid); margin:4px 7px; }"));
    connect(m_menu, &QMenu::aboutToShow, this, [this] {
        for(auto *widget : QApplication::topLevelWidgets())
            if(qobject_cast<QMainWindow *>(widget))
            {
                m_menu->setPalette(widget->palette());
                break;
            }
    });

    auto *helper = UiHelper::instance();
    m_trackAction = m_menu->addAction(QApplication::windowIcon(), tr("Open player"), helper, &UiHelper::showMainWindow);
    QFont heading = m_menu->font();
    heading.setBold(true);
    m_trackAction->setFont(heading);
    m_trackAction->setToolTip(tr("Open player"));
    m_menu->addSeparator();
    m_playPauseAction = m_menu->addAction(tr("Play"), this, [this] {
        if(m_core->state() == Qmmp::Playing)
            m_player->pause();
        else
            m_player->play();
    });
    auto icon = [](const QString &name, QStyle::StandardPixmap fallback) {
        return QIcon::fromTheme(name, QApplication::style()->standardIcon(fallback));
    };
    m_menu->addAction(icon(u"media-skip-backward-symbolic"_s, QStyle::SP_MediaSkipBackward),
                      tr("Previous"), m_player, &MediaPlayer::previous);
    m_menu->addAction(icon(u"media-skip-forward-symbolic"_s, QStyle::SP_MediaSkipForward),
                      tr("Next"), m_player, &MediaPlayer::next);
    m_stopAction = m_menu->addAction(icon(u"media-playback-stop-symbolic"_s, QStyle::SP_MediaStop),
                                     tr("Stop"), m_player, &MediaPlayer::stop);
    m_menu->addSeparator();
    auto *mute = m_menu->addAction(tr("Mute"), m_core, &SoundCore::setMuted);
    mute->setCheckable(true);
    mute->setChecked(m_core->isMuted());
    connect(m_core, &SoundCore::mutedChanged, mute, &QAction::setChecked);
    m_menu->addSeparator();
    m_menu->addAction(QIcon::fromTheme(u"application-exit-symbolic"_s), tr("Exit"), helper, &UiHelper::exit);
    m_tray->setContextMenu(m_menu);
    m_tray->show();
    connect(m_core, &SoundCore::trackInfoChanged, this, &StatusIcon::showMetaData);
    connect(m_core, &SoundCore::stateChanged, this, &StatusIcon::setState);
    setState(m_core->state()); //update state
    if (m_core->state() == Qmmp::Playing) //show test message
        QTimer::singleShot(1500, this, &StatusIcon::showMetaData);
}

StatusIcon::~StatusIcon()
{
    delete m_menu;
}

void StatusIcon::setState(Qmmp::State state)
{
    const bool playing = state == Qmmp::Playing;
    m_playPauseAction->setText(playing ? tr("Pause") : state == Qmmp::Paused ? tr("Resume") : tr("Play"));
    m_playPauseAction->setIcon(QIcon::fromTheme(playing ? u"media-playback-pause-symbolic"_s : u"media-playback-start-symbolic"_s,
            QApplication::style()->standardIcon(playing ? QStyle::SP_MediaPause : QStyle::SP_MediaPlay)));
    m_stopAction->setEnabled(playing || state == Qmmp::Paused || state == Qmmp::Buffering);
    updateMenuTrack();
    switch ((uint) state)
    {
    case Qmmp::Playing:
    {
         if(m_useStandardIcons)
            m_tray->setIcon(QApplication::style ()->standardIcon(QStyle::SP_MediaPlay));
        else
            m_tray->setIcon (QIcon(u":/tray_play.png"_s));
        break;
    }
    case Qmmp::Paused:
    {
         if(m_useStandardIcons)
            m_tray->setIcon(QApplication::style ()->standardIcon(QStyle::SP_MediaPause));
        else
            m_tray->setIcon (QIcon(u":/tray_pause.png"_s));
        break;
    }
    case Qmmp::Stopped:
    {
        if(m_useStandardIcons)
            m_tray->setIcon(QApplication::style ()->standardIcon(QStyle::SP_MediaStop));
        else
            m_tray->setIcon (QIcon(u":/tray_stop.png"_s));
        if(m_showToolTip)
            m_tray->setToolTip(tr("Stopped"));
        break;
    }
    }
}

void StatusIcon::updateMenuTrack()
{
    QString text;
    if(m_core->state() == Qmmp::Playing || m_core->state() == Qmmp::Paused)
    {
        const auto &info = m_core->trackInfo();
        text = info.value(Qmmp::TITLE).simplified();
        if(text.isEmpty())
            text = QFileInfo(info.path()).completeBaseName();
        const QString artist = info.value(Qmmp::ARTIST).simplified();
        if(!text.isEmpty() && !artist.isEmpty())
            text += u" · "_s + artist;
    }
    if(text.isEmpty())
        text = tr("Open player");
    text = QFontMetrics(m_trackAction->font()).elidedText(text, Qt::ElideRight, 260);
    m_trackAction->setText(text.replace(u'&', u"&&"_s));
}

void StatusIcon::showMetaData()
{
    updateMenuTrack();
    TrackInfo info = m_core->trackInfo();
    if(m_splitFileName && info.value(Qmmp::TITLE).isEmpty() && !info.path().contains(u"://"_s))
    {
        QString name = QFileInfo(info.path()).completeBaseName();
        if(name.contains(QLatin1Char('-')))
        {
            info.setValue(Qmmp::TITLE, name.section(QLatin1Char('-'), 1, 1).trimmed());
            if(info.value(Qmmp::ARTIST).isEmpty())
                info.setValue(Qmmp::ARTIST, name.section(QLatin1Char('-'), 0, 0).trimmed());
        }
    }

    QString message = m_messageFormatter.format(info);
    if (message.isEmpty())
        message = info.path().section(QLatin1Char('-'), -1);

    if (m_showMessage)
        m_tray->showMessage (tr("Now Playing"), message,
                             QSystemTrayIcon::Information, m_messageDelay);

    if(m_showToolTip)
    {
        message = m_toolTipFormatter.format(info);
        if(message.isEmpty())
            message = info.path().section(QLatin1Char('-'), -1);
        m_tray->setToolTip(message);
    }
}

void StatusIcon::trayActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::Trigger)
        UiHelper::instance()->toggleVisibility();
    else if (reason == QSystemTrayIcon::MiddleClick)
    {
        if (SoundCore::instance()->state() == Qmmp::Stopped)
            m_player->play();
        else
            m_player->pause();
    }
}

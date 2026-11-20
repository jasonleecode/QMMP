/***************************************************************************
 *   Copyright (C) 2015 by Ivan Ponomarev                                  *
 *   ivantrue@gmail.com                                                    *
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

#include "outputqtmultimedia.h"
#include <qmmp/audioparameters.h>
#include <QMetaObject>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QAudioDevice>
#include <QAudioSink>
#include <QMediaDevices>
#include <QSettings>
#include <QCoreApplication>
#include <QThread>


OutputQtMultimedia::OutputQtMultimedia() : Output()
{
}

OutputQtMultimedia::~OutputQtMultimedia()
{
    if(m_control)
        m_control->deleteLater();
}

bool OutputQtMultimedia::initialize(quint32 freq, ChannelMap map, Qmmp::AudioFormat format)
{
    QAudioFormat qformat;
    qformat.setSampleRate(freq);
    qformat.setChannelCount(map.size());

    //Size of sample representation in input data. For 24-bit is 4, high byte is ignored.
    qint64 bytes_per_sample = AudioParameters::sampleSize(format);

    if(format == Qmmp::PCM_S24LE)
        format = Qmmp::PCM_S32LE;

    switch (format)
    {
    case Qmmp::PCM_U8:
    case Qmmp::PCM_S8:
        qformat.setSampleFormat(QAudioFormat::UInt8);
        break;
    case Qmmp::PCM_S16LE:
        qformat.setSampleFormat(QAudioFormat::Int16);
        break;
    case Qmmp::PCM_S32LE:
        qformat.setSampleFormat(QAudioFormat::Int32);
        break;
    case Qmmp::PCM_FLOAT:
        qformat.setSampleFormat(QAudioFormat::Int32);
        break;
    default:
        break;
    }

#if Q_BYTE_ORDER == Q_BIG_ENDIAN
    if(format == Qmmp::PCM_S16LE)
        format = Qmmp::PCM_S16BE;
    else if(format == Qmmp::PCM_S32LE)
        format = Qmmp::PCM_S32BE;
#endif

    if (!qformat.isValid())
        return false;

    const QSettings settings;
    const QByteArray saved_device_name = settings.value("QTMULTIMEDIA/device"_L1).toByteArray();
    m_bytes_per_second = bytes_per_sample * freq * qformat.channelCount();

    QAudioDevice device_info;
    if (!saved_device_name.isEmpty())
    {
        const QList<QAudioDevice> devices = QMediaDevices::audioOutputs();
        for(const QAudioDevice &info : devices)
        {
            if (info.id() == saved_device_name)
            {
                if (info.isFormatSupported(qformat))
                {
                    device_info = info;
                    break;
                }
                else
                    qCDebug(plugin) << "Output device:" << saved_device_name << " is not supported";
            }
        }
    }

    if (device_info.isNull())
    {
        device_info = QMediaDevices::defaultAudioOutput();
        if (!device_info.isFormatSupported(qformat))
            return false;
    }

    qCDebug(plugin) << "using output device: " << device_info.description();

    m_control = new OutputControl;
    m_output = m_control->output = new QAudioSink(device_info, qformat, m_control);
    m_control->start();
    if(!m_control->buffer)
        return false;

    // A format change can initialize the sink on the decoder thread, which has no event loop.
    auto *controlThread = QCoreApplication::instance()->thread();
    if(!m_control->buffer->parent())
        m_control->buffer->moveToThread(controlThread);
    m_control->moveToThread(controlThread);

    configure(freq, map, format);
    return true;
}


qint64 OutputQtMultimedia::latency()
{
    if(m_control->restarting || !m_control->buffer)
        return 0;
    return qMax<qint64>(0, m_output->bufferSize() - m_output->bytesFree()) * 1000 / m_bytes_per_second;
}

qint64 OutputQtMultimedia::writeAudio(unsigned char *data, qint64 maxSize)
{
    if(!m_control->restarting)
    {
        if(!m_control->buffer || m_output->state() == QAudio::StoppedState)
            return -1;
        const qint64 frame = sampleSize() * channels();
        const qint64 available = qMin<qint64>(m_output->bytesFree(), maxSize);
        if(available >= frame)
            return m_control->buffer->write(reinterpret_cast<const char *>(data), available / frame * frame);
    }

    // Some push devices accept more than bytesFree() and queue the excess for seconds.
    // Yield to the sink and let the writer check for pause or seek before trying again.
    QThread::usleep(qBound(1000LL, maxSize * 500000 / m_bytes_per_second, 10000LL));
    return 0;
}

void OutputQtMultimedia::drain()
{
    QThread::msleep(latency());
}

void OutputQtMultimedia::reset()
{
    if(!m_control->restarting.exchange(true))
        QMetaObject::invokeMethod(m_control, &OutputControl::restart, Qt::QueuedConnection);
}

void OutputQtMultimedia::suspend()
{
    QMetaObject::invokeMethod(m_control, "suspend", Qt::QueuedConnection);
}

void OutputQtMultimedia::resume()
{
    QMetaObject::invokeMethod(m_control, "resume", Qt::QueuedConnection);
}

void OutputControl::suspend()
{
    output->suspend();
}

void OutputControl::resume()
{
    output->resume();
}

void OutputControl::start()
{
    // Qt may replace the requested size with the device's negotiated size on start.
    // Request the same 24 ms of audio on every open, including after a seek.
    output->setBufferSize(output->format().bytesForDuration(24000));
    buffer = output->start();
}

void OutputControl::restart()
{
    output->reset();
    start();
    restarting = false;
}

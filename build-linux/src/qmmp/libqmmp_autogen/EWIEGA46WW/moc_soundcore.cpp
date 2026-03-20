/****************************************************************************
** Meta object code from reading C++ file 'soundcore.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qmmp/soundcore.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'soundcore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSoundCoreENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSoundCoreENDCLASS = QtMocHelpers::stringData(
    "SoundCore",
    "bufferingProgress",
    "",
    "progress",
    "elapsedChanged",
    "time",
    "bitrateChanged",
    "bitrate",
    "audioParametersChanged",
    "AudioParameters",
    "p",
    "streamInfoChanged",
    "trackInfoChanged",
    "stateChanged",
    "Qmmp::State",
    "newState",
    "finished",
    "mutedChanged",
    "muted",
    "volumeChanged",
    "volume",
    "balanceChanged",
    "balance",
    "eqSettingsChanged",
    "nextTrackRequest",
    "setVolumePerChannel",
    "left",
    "right",
    "setMuted",
    "mute",
    "changeVolume",
    "delta",
    "setVolume",
    "volumeUp",
    "volumeDown",
    "setBalance",
    "play",
    "source",
    "queue",
    "offset",
    "stop",
    "pause",
    "seek",
    "pos",
    "seekRelative",
    "startNextSource",
    "startNextEngine"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSoundCoreENDCLASS_t {
    uint offsetsAndSizes[94];
    char stringdata0[10];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[15];
    char stringdata5[5];
    char stringdata6[15];
    char stringdata7[8];
    char stringdata8[23];
    char stringdata9[16];
    char stringdata10[2];
    char stringdata11[18];
    char stringdata12[17];
    char stringdata13[13];
    char stringdata14[12];
    char stringdata15[9];
    char stringdata16[9];
    char stringdata17[13];
    char stringdata18[6];
    char stringdata19[14];
    char stringdata20[7];
    char stringdata21[15];
    char stringdata22[8];
    char stringdata23[18];
    char stringdata24[17];
    char stringdata25[20];
    char stringdata26[5];
    char stringdata27[6];
    char stringdata28[9];
    char stringdata29[5];
    char stringdata30[13];
    char stringdata31[6];
    char stringdata32[10];
    char stringdata33[9];
    char stringdata34[11];
    char stringdata35[11];
    char stringdata36[5];
    char stringdata37[7];
    char stringdata38[6];
    char stringdata39[7];
    char stringdata40[5];
    char stringdata41[6];
    char stringdata42[5];
    char stringdata43[4];
    char stringdata44[13];
    char stringdata45[16];
    char stringdata46[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSoundCoreENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSoundCoreENDCLASS_t qt_meta_stringdata_CLASSSoundCoreENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "SoundCore"
        QT_MOC_LITERAL(10, 17),  // "bufferingProgress"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 8),  // "progress"
        QT_MOC_LITERAL(38, 14),  // "elapsedChanged"
        QT_MOC_LITERAL(53, 4),  // "time"
        QT_MOC_LITERAL(58, 14),  // "bitrateChanged"
        QT_MOC_LITERAL(73, 7),  // "bitrate"
        QT_MOC_LITERAL(81, 22),  // "audioParametersChanged"
        QT_MOC_LITERAL(104, 15),  // "AudioParameters"
        QT_MOC_LITERAL(120, 1),  // "p"
        QT_MOC_LITERAL(122, 17),  // "streamInfoChanged"
        QT_MOC_LITERAL(140, 16),  // "trackInfoChanged"
        QT_MOC_LITERAL(157, 12),  // "stateChanged"
        QT_MOC_LITERAL(170, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(182, 8),  // "newState"
        QT_MOC_LITERAL(191, 8),  // "finished"
        QT_MOC_LITERAL(200, 12),  // "mutedChanged"
        QT_MOC_LITERAL(213, 5),  // "muted"
        QT_MOC_LITERAL(219, 13),  // "volumeChanged"
        QT_MOC_LITERAL(233, 6),  // "volume"
        QT_MOC_LITERAL(240, 14),  // "balanceChanged"
        QT_MOC_LITERAL(255, 7),  // "balance"
        QT_MOC_LITERAL(263, 17),  // "eqSettingsChanged"
        QT_MOC_LITERAL(281, 16),  // "nextTrackRequest"
        QT_MOC_LITERAL(298, 19),  // "setVolumePerChannel"
        QT_MOC_LITERAL(318, 4),  // "left"
        QT_MOC_LITERAL(323, 5),  // "right"
        QT_MOC_LITERAL(329, 8),  // "setMuted"
        QT_MOC_LITERAL(338, 4),  // "mute"
        QT_MOC_LITERAL(343, 12),  // "changeVolume"
        QT_MOC_LITERAL(356, 5),  // "delta"
        QT_MOC_LITERAL(362, 9),  // "setVolume"
        QT_MOC_LITERAL(372, 8),  // "volumeUp"
        QT_MOC_LITERAL(381, 10),  // "volumeDown"
        QT_MOC_LITERAL(392, 10),  // "setBalance"
        QT_MOC_LITERAL(403, 4),  // "play"
        QT_MOC_LITERAL(408, 6),  // "source"
        QT_MOC_LITERAL(415, 5),  // "queue"
        QT_MOC_LITERAL(421, 6),  // "offset"
        QT_MOC_LITERAL(428, 4),  // "stop"
        QT_MOC_LITERAL(433, 5),  // "pause"
        QT_MOC_LITERAL(439, 4),  // "seek"
        QT_MOC_LITERAL(444, 3),  // "pos"
        QT_MOC_LITERAL(448, 12),  // "seekRelative"
        QT_MOC_LITERAL(461, 15),  // "startNextSource"
        QT_MOC_LITERAL(477, 15)   // "startNextEngine"
    },
    "SoundCore",
    "bufferingProgress",
    "",
    "progress",
    "elapsedChanged",
    "time",
    "bitrateChanged",
    "bitrate",
    "audioParametersChanged",
    "AudioParameters",
    "p",
    "streamInfoChanged",
    "trackInfoChanged",
    "stateChanged",
    "Qmmp::State",
    "newState",
    "finished",
    "mutedChanged",
    "muted",
    "volumeChanged",
    "volume",
    "balanceChanged",
    "balance",
    "eqSettingsChanged",
    "nextTrackRequest",
    "setVolumePerChannel",
    "left",
    "right",
    "setMuted",
    "mute",
    "changeVolume",
    "delta",
    "setVolume",
    "volumeUp",
    "volumeDown",
    "setBalance",
    "play",
    "source",
    "queue",
    "offset",
    "stop",
    "pause",
    "seek",
    "pos",
    "seekRelative",
    "startNextSource",
    "startNextEngine"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSoundCoreENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  188,    2, 0x06,    1 /* Public */,
       4,    1,  191,    2, 0x06,    3 /* Public */,
       6,    1,  194,    2, 0x06,    5 /* Public */,
       8,    1,  197,    2, 0x06,    7 /* Public */,
      11,    0,  200,    2, 0x06,    9 /* Public */,
      12,    0,  201,    2, 0x06,   10 /* Public */,
      13,    1,  202,    2, 0x06,   11 /* Public */,
      16,    0,  205,    2, 0x06,   13 /* Public */,
      17,    1,  206,    2, 0x06,   14 /* Public */,
      19,    1,  209,    2, 0x06,   16 /* Public */,
      21,    1,  212,    2, 0x06,   18 /* Public */,
      23,    0,  215,    2, 0x06,   20 /* Public */,
      24,    0,  216,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      25,    2,  217,    2, 0x0a,   22 /* Public */,
      28,    1,  222,    2, 0x0a,   25 /* Public */,
      30,    1,  225,    2, 0x0a,   27 /* Public */,
      32,    1,  228,    2, 0x0a,   29 /* Public */,
      33,    0,  231,    2, 0x0a,   31 /* Public */,
      34,    0,  232,    2, 0x0a,   32 /* Public */,
      35,    1,  233,    2, 0x0a,   33 /* Public */,
      36,    3,  236,    2, 0x0a,   35 /* Public */,
      36,    2,  243,    2, 0x2a,   39 /* Public | MethodCloned */,
      36,    1,  248,    2, 0x2a,   42 /* Public | MethodCloned */,
      40,    0,  251,    2, 0x0a,   44 /* Public */,
      41,    0,  252,    2, 0x0a,   45 /* Public */,
      42,    1,  253,    2, 0x0a,   46 /* Public */,
      44,    1,  256,    2, 0x0a,   48 /* Public */,
      45,    0,  259,    2, 0x08,   50 /* Private */,
      46,    0,  260,    2, 0x08,   51 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::LongLong,   37,   38,   39,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   37,   38,
    QMetaType::Bool, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   43,
    QMetaType::Void, QMetaType::LongLong,   39,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SoundCore::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSoundCoreENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSoundCoreENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSoundCoreENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SoundCore, std::true_type>,
        // method 'bufferingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'elapsedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'bitrateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'audioParametersChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const AudioParameters &, std::false_type>,
        // method 'streamInfoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'trackInfoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qmmp::State, std::false_type>,
        // method 'finished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mutedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'balanceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'eqSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextTrackRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setVolumePerChannel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setMuted'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'changeVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'volumeUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'volumeDown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setBalance'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'seek'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'seekRelative'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'startNextSource'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startNextEngine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SoundCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SoundCore *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->bufferingProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->elapsedChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 2: _t->bitrateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->audioParametersChanged((*reinterpret_cast< std::add_pointer_t<AudioParameters>>(_a[1]))); break;
        case 4: _t->streamInfoChanged(); break;
        case 5: _t->trackInfoChanged(); break;
        case 6: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<Qmmp::State>>(_a[1]))); break;
        case 7: _t->finished(); break;
        case 8: _t->mutedChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->volumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->balanceChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->eqSettingsChanged(); break;
        case 12: _t->nextTrackRequest(); break;
        case 13: _t->setVolumePerChannel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->setMuted((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->changeVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->volumeUp(); break;
        case 18: _t->volumeDown(); break;
        case 19: _t->setBalance((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: { bool _r = _t->play((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { bool _r = _t->play((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->play((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->stop(); break;
        case 24: _t->pause(); break;
        case 25: _t->seek((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 26: _t->seekRelative((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 27: _t->startNextSource(); break;
        case 28: _t->startNextEngine(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SoundCore::*)(int );
            if (_t _q_method = &SoundCore::bufferingProgress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(qint64 );
            if (_t _q_method = &SoundCore::elapsedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(int );
            if (_t _q_method = &SoundCore::bitrateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(const AudioParameters & );
            if (_t _q_method = &SoundCore::audioParametersChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)();
            if (_t _q_method = &SoundCore::streamInfoChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)();
            if (_t _q_method = &SoundCore::trackInfoChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(Qmmp::State );
            if (_t _q_method = &SoundCore::stateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)();
            if (_t _q_method = &SoundCore::finished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(bool );
            if (_t _q_method = &SoundCore::mutedChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(int );
            if (_t _q_method = &SoundCore::volumeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)(int );
            if (_t _q_method = &SoundCore::balanceChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)();
            if (_t _q_method = &SoundCore::eqSettingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (SoundCore::*)();
            if (_t _q_method = &SoundCore::nextTrackRequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject *SoundCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SoundCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSoundCoreENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SoundCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void SoundCore::bufferingProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SoundCore::elapsedChanged(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SoundCore::bitrateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SoundCore::audioParametersChanged(const AudioParameters & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SoundCore::streamInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SoundCore::trackInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SoundCore::stateChanged(Qmmp::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SoundCore::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SoundCore::mutedChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SoundCore::volumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SoundCore::balanceChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SoundCore::eqSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void SoundCore::nextTrackRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP

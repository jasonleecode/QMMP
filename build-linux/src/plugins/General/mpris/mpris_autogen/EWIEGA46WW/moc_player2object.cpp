/****************************************************************************
** Meta object code from reading C++ file 'player2object.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/mpris/player2object.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player2object.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS = QtMocHelpers::stringData(
    "Player2Object",
    "D-Bus Interface",
    "org.mpris.MediaPlayer2.Player",
    "Seeked",
    "",
    "Position",
    "Next",
    "OpenUri",
    "in0",
    "Pause",
    "Play",
    "PlayPause",
    "Previous",
    "Seek",
    "Offset",
    "SetPosition",
    "QDBusObjectPath",
    "TrackId",
    "Stop",
    "emitPropertiesChanged",
    "updateId",
    "checkState",
    "Qmmp::State",
    "state",
    "checkSeeking",
    "elapsed",
    "playTrack",
    "QList<PlayListTrack*>",
    "tracks",
    "disconnectPl",
    "setModel",
    "PlayListModel*",
    "selected",
    "previous",
    "CanControl",
    "CanGoNext",
    "CanGoPrevious",
    "CanPause",
    "CanPlay",
    "CanSeek",
    "LoopStatus",
    "MaximumRate",
    "Metadata",
    "MinimumRate",
    "PlaybackStatus",
    "Rate",
    "Shuffle",
    "Volume"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS_t {
    uint offsetsAndSizes[96];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[30];
    char stringdata3[7];
    char stringdata4[1];
    char stringdata5[9];
    char stringdata6[5];
    char stringdata7[8];
    char stringdata8[4];
    char stringdata9[6];
    char stringdata10[5];
    char stringdata11[10];
    char stringdata12[9];
    char stringdata13[5];
    char stringdata14[7];
    char stringdata15[12];
    char stringdata16[16];
    char stringdata17[8];
    char stringdata18[5];
    char stringdata19[22];
    char stringdata20[9];
    char stringdata21[11];
    char stringdata22[12];
    char stringdata23[6];
    char stringdata24[13];
    char stringdata25[8];
    char stringdata26[10];
    char stringdata27[22];
    char stringdata28[7];
    char stringdata29[13];
    char stringdata30[9];
    char stringdata31[15];
    char stringdata32[9];
    char stringdata33[9];
    char stringdata34[11];
    char stringdata35[10];
    char stringdata36[14];
    char stringdata37[9];
    char stringdata38[8];
    char stringdata39[8];
    char stringdata40[11];
    char stringdata41[12];
    char stringdata42[9];
    char stringdata43[12];
    char stringdata44[15];
    char stringdata45[5];
    char stringdata46[8];
    char stringdata47[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS_t qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "Player2Object"
        QT_MOC_LITERAL(14, 15),  // "D-Bus Interface"
        QT_MOC_LITERAL(30, 29),  // "org.mpris.MediaPlayer2.Player"
        QT_MOC_LITERAL(60, 6),  // "Seeked"
        QT_MOC_LITERAL(67, 0),  // ""
        QT_MOC_LITERAL(68, 8),  // "Position"
        QT_MOC_LITERAL(77, 4),  // "Next"
        QT_MOC_LITERAL(82, 7),  // "OpenUri"
        QT_MOC_LITERAL(90, 3),  // "in0"
        QT_MOC_LITERAL(94, 5),  // "Pause"
        QT_MOC_LITERAL(100, 4),  // "Play"
        QT_MOC_LITERAL(105, 9),  // "PlayPause"
        QT_MOC_LITERAL(115, 8),  // "Previous"
        QT_MOC_LITERAL(124, 4),  // "Seek"
        QT_MOC_LITERAL(129, 6),  // "Offset"
        QT_MOC_LITERAL(136, 11),  // "SetPosition"
        QT_MOC_LITERAL(148, 15),  // "QDBusObjectPath"
        QT_MOC_LITERAL(164, 7),  // "TrackId"
        QT_MOC_LITERAL(172, 4),  // "Stop"
        QT_MOC_LITERAL(177, 21),  // "emitPropertiesChanged"
        QT_MOC_LITERAL(199, 8),  // "updateId"
        QT_MOC_LITERAL(208, 10),  // "checkState"
        QT_MOC_LITERAL(219, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(231, 5),  // "state"
        QT_MOC_LITERAL(237, 12),  // "checkSeeking"
        QT_MOC_LITERAL(250, 7),  // "elapsed"
        QT_MOC_LITERAL(258, 9),  // "playTrack"
        QT_MOC_LITERAL(268, 21),  // "QList<PlayListTrack*>"
        QT_MOC_LITERAL(290, 6),  // "tracks"
        QT_MOC_LITERAL(297, 12),  // "disconnectPl"
        QT_MOC_LITERAL(310, 8),  // "setModel"
        QT_MOC_LITERAL(319, 14),  // "PlayListModel*"
        QT_MOC_LITERAL(334, 8),  // "selected"
        QT_MOC_LITERAL(343, 8),  // "previous"
        QT_MOC_LITERAL(352, 10),  // "CanControl"
        QT_MOC_LITERAL(363, 9),  // "CanGoNext"
        QT_MOC_LITERAL(373, 13),  // "CanGoPrevious"
        QT_MOC_LITERAL(387, 8),  // "CanPause"
        QT_MOC_LITERAL(396, 7),  // "CanPlay"
        QT_MOC_LITERAL(404, 7),  // "CanSeek"
        QT_MOC_LITERAL(412, 10),  // "LoopStatus"
        QT_MOC_LITERAL(423, 11),  // "MaximumRate"
        QT_MOC_LITERAL(435, 8),  // "Metadata"
        QT_MOC_LITERAL(444, 11),  // "MinimumRate"
        QT_MOC_LITERAL(456, 14),  // "PlaybackStatus"
        QT_MOC_LITERAL(471, 4),  // "Rate"
        QT_MOC_LITERAL(476, 7),  // "Shuffle"
        QT_MOC_LITERAL(484, 6)   // "Volume"
    },
    "Player2Object",
    "D-Bus Interface",
    "org.mpris.MediaPlayer2.Player",
    "Seeked",
    "",
    "Position",
    "Next",
    "OpenUri",
    "in0",
    "Pause",
    "Play",
    "PlayPause",
    "Previous",
    "Seek",
    "Offset",
    "SetPosition",
    "QDBusObjectPath",
    "TrackId",
    "Stop",
    "emitPropertiesChanged",
    "updateId",
    "checkState",
    "Qmmp::State",
    "state",
    "checkSeeking",
    "elapsed",
    "playTrack",
    "QList<PlayListTrack*>",
    "tracks",
    "disconnectPl",
    "setModel",
    "PlayListModel*",
    "selected",
    "previous",
    "CanControl",
    "CanGoNext",
    "CanGoPrevious",
    "CanPause",
    "CanPlay",
    "CanSeek",
    "LoopStatus",
    "MaximumRate",
    "Metadata",
    "MinimumRate",
    "PlaybackStatus",
    "Rate",
    "Shuffle",
    "Volume"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlayer2ObjectENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
      17,   16, // methods
      15,  155, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,  118,    4, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  121,    4, 0x0a,   18 /* Public */,
       7,    1,  122,    4, 0x0a,   19 /* Public */,
       9,    0,  125,    4, 0x0a,   21 /* Public */,
      10,    0,  126,    4, 0x0a,   22 /* Public */,
      11,    0,  127,    4, 0x0a,   23 /* Public */,
      12,    0,  128,    4, 0x0a,   24 /* Public */,
      13,    1,  129,    4, 0x0a,   25 /* Public */,
      15,    2,  132,    4, 0x0a,   27 /* Public */,
      18,    0,  137,    4, 0x0a,   30 /* Public */,
      19,    0,  138,    4, 0x08,   31 /* Private */,
      20,    0,  139,    4, 0x08,   32 /* Private */,
      21,    1,  140,    4, 0x08,   33 /* Private */,
      24,    1,  143,    4, 0x08,   35 /* Private */,
      26,    1,  146,    4, 0x08,   37 /* Private */,
      29,    0,  149,    4, 0x08,   39 /* Private */,
      30,    2,  150,    4, 0x08,   40 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::LongLong,   17,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::LongLong,   25,
    QMetaType::Void, 0x80000000 | 27,   28,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31, 0x80000000 | 31,   32,   33,

 // properties: name, type, flags
      34, QMetaType::Bool, 0x00015001, uint(-1), 0,
      35, QMetaType::Bool, 0x00015001, uint(-1), 0,
      36, QMetaType::Bool, 0x00015001, uint(-1), 0,
      37, QMetaType::Bool, 0x00015001, uint(-1), 0,
      38, QMetaType::Bool, 0x00015001, uint(-1), 0,
      39, QMetaType::Bool, 0x00015001, uint(-1), 0,
      40, QMetaType::QString, 0x00015103, uint(-1), 0,
      41, QMetaType::Double, 0x00015001, uint(-1), 0,
      42, QMetaType::QVariantMap, 0x00015001, uint(-1), 0,
      43, QMetaType::Double, 0x00015001, uint(-1), 0,
      44, QMetaType::QString, 0x00015001, uint(-1), 0,
       5, QMetaType::LongLong, 0x00015001, uint(-1), 0,
      45, QMetaType::Double, 0x00015103, uint(-1), 0,
      46, QMetaType::Bool, 0x00015103, uint(-1), 0,
      47, QMetaType::Double, 0x00015103, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Player2Object::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlayer2ObjectENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS_t,
        // property 'CanControl'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CanGoNext'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CanGoPrevious'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CanPause'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CanPlay'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CanSeek'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'LoopStatus'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'MaximumRate'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'Metadata'
        QtPrivate::TypeAndForceComplete<QVariantMap, std::true_type>,
        // property 'MinimumRate'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'PlaybackStatus'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'Position'
        QtPrivate::TypeAndForceComplete<qlonglong, std::true_type>,
        // property 'Rate'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // property 'Shuffle'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Volume'
        QtPrivate::TypeAndForceComplete<double, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Player2Object, std::true_type>,
        // method 'Seeked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qlonglong, std::false_type>,
        // method 'Next'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OpenUri'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'Pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PlayPause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Previous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Seek'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qlonglong, std::false_type>,
        // method 'SetPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDBusObjectPath &, std::false_type>,
        QtPrivate::TypeAndForceComplete<qlonglong, std::false_type>,
        // method 'Stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'emitPropertiesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateId'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qmmp::State, std::false_type>,
        // method 'checkSeeking'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'playTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>,
        // method 'disconnectPl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>
    >,
    nullptr
} };

void Player2Object::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Player2Object *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Seeked((*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[1]))); break;
        case 1: _t->Next(); break;
        case 2: _t->OpenUri((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->Pause(); break;
        case 4: _t->Play(); break;
        case 5: _t->PlayPause(); break;
        case 6: _t->Previous(); break;
        case 7: _t->Seek((*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[1]))); break;
        case 8: _t->SetPosition((*reinterpret_cast< std::add_pointer_t<QDBusObjectPath>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qlonglong>>(_a[2]))); break;
        case 9: _t->Stop(); break;
        case 10: _t->emitPropertiesChanged(); break;
        case 11: _t->updateId(); break;
        case 12: _t->checkState((*reinterpret_cast< std::add_pointer_t<Qmmp::State>>(_a[1]))); break;
        case 13: _t->checkSeeking((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 14: _t->playTrack((*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[1]))); break;
        case 15: _t->disconnectPl(); break;
        case 16: _t->setModel((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusObjectPath >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Player2Object::*)(qlonglong );
            if (_t _q_method = &Player2Object::Seeked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Player2Object *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->canControl(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->canGoNext(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->canGoPrevious(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->canPause(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->canPlay(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->canSeek(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->loopStatus(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->maximumRate(); break;
        case 8: *reinterpret_cast< QVariantMap*>(_v) = _t->metadata(); break;
        case 9: *reinterpret_cast< double*>(_v) = _t->minimumRate(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->playbackStatus(); break;
        case 11: *reinterpret_cast< qlonglong*>(_v) = _t->position(); break;
        case 12: *reinterpret_cast< double*>(_v) = _t->rate(); break;
        case 13: *reinterpret_cast< bool*>(_v) = _t->shuffle(); break;
        case 14: *reinterpret_cast< double*>(_v) = _t->volume(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Player2Object *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 6: _t->setLoopStatus(*reinterpret_cast< QString*>(_v)); break;
        case 12: _t->setRate(*reinterpret_cast< double*>(_v)); break;
        case 13: _t->setShuffle(*reinterpret_cast< bool*>(_v)); break;
        case 14: _t->setVolume(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Player2Object::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player2Object::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlayer2ObjectENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int Player2Object::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Player2Object::Seeked(qlonglong _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'mediaplayer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qmmpui/mediaplayer.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediaplayer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMediaPlayerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMediaPlayerENDCLASS = QtMocHelpers::stringData(
    "MediaPlayer",
    "playbackFinished",
    "",
    "play",
    "playFromPosition",
    "offset",
    "stop",
    "pause",
    "next",
    "previous",
    "playNext",
    "updateNextUrl",
    "processState",
    "Qmmp::State",
    "state",
    "updateMetaData",
    "onCurrentTrackRemoved"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMediaPlayerENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[12];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[17];
    char stringdata5[7];
    char stringdata6[5];
    char stringdata7[6];
    char stringdata8[5];
    char stringdata9[9];
    char stringdata10[9];
    char stringdata11[14];
    char stringdata12[13];
    char stringdata13[12];
    char stringdata14[6];
    char stringdata15[15];
    char stringdata16[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMediaPlayerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMediaPlayerENDCLASS_t qt_meta_stringdata_CLASSMediaPlayerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "MediaPlayer"
        QT_MOC_LITERAL(12, 16),  // "playbackFinished"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 4),  // "play"
        QT_MOC_LITERAL(35, 16),  // "playFromPosition"
        QT_MOC_LITERAL(52, 6),  // "offset"
        QT_MOC_LITERAL(59, 4),  // "stop"
        QT_MOC_LITERAL(64, 5),  // "pause"
        QT_MOC_LITERAL(70, 4),  // "next"
        QT_MOC_LITERAL(75, 8),  // "previous"
        QT_MOC_LITERAL(84, 8),  // "playNext"
        QT_MOC_LITERAL(93, 13),  // "updateNextUrl"
        QT_MOC_LITERAL(107, 12),  // "processState"
        QT_MOC_LITERAL(120, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(132, 5),  // "state"
        QT_MOC_LITERAL(138, 14),  // "updateMetaData"
        QT_MOC_LITERAL(153, 21)   // "onCurrentTrackRemoved"
    },
    "MediaPlayer",
    "playbackFinished",
    "",
    "play",
    "playFromPosition",
    "offset",
    "stop",
    "pause",
    "next",
    "previous",
    "playNext",
    "updateNextUrl",
    "processState",
    "Qmmp::State",
    "state",
    "updateMetaData",
    "onCurrentTrackRemoved"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMediaPlayerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   87,    2, 0x0a,    2 /* Public */,
       4,    1,   88,    2, 0x0a,    3 /* Public */,
       6,    0,   91,    2, 0x0a,    5 /* Public */,
       7,    0,   92,    2, 0x0a,    6 /* Public */,
       8,    0,   93,    2, 0x0a,    7 /* Public */,
       9,    0,   94,    2, 0x0a,    8 /* Public */,
      10,    0,   95,    2, 0x08,    9 /* Private */,
      11,    0,   96,    2, 0x08,   10 /* Private */,
      12,    1,   97,    2, 0x08,   11 /* Private */,
      15,    0,  100,    2, 0x08,   13 /* Private */,
      16,    0,  101,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MediaPlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMediaPlayerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMediaPlayerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMediaPlayerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MediaPlayer, std::true_type>,
        // method 'playbackFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playFromPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'next'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'previous'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playNext'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateNextUrl'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qmmp::State, std::false_type>,
        // method 'updateMetaData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCurrentTrackRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MediaPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaPlayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->playbackFinished(); break;
        case 1: _t->play(); break;
        case 2: _t->playFromPosition((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 3: _t->stop(); break;
        case 4: _t->pause(); break;
        case 5: _t->next(); break;
        case 6: _t->previous(); break;
        case 7: _t->playNext(); break;
        case 8: _t->updateNextUrl(); break;
        case 9: _t->processState((*reinterpret_cast< std::add_pointer_t<Qmmp::State>>(_a[1]))); break;
        case 10: _t->updateMetaData(); break;
        case 11: _t->onCurrentTrackRemoved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MediaPlayer::*)();
            if (_t _q_method = &MediaPlayer::playbackFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MediaPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMediaPlayerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MediaPlayer::playbackFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP

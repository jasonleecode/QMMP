/****************************************************************************
** Meta object code from reading C++ file 'trackchange.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/trackchange/trackchange.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackchange.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTrackChangeENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTrackChangeENDCLASS = QtMocHelpers::stringData(
    "TrackChange",
    "onStateChanged",
    "",
    "Qmmp::State",
    "state",
    "onTrackInfoChanged",
    "onFinised",
    "onAppStartup",
    "onAppExit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTrackChangeENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[19];
    char stringdata6[10];
    char stringdata7[13];
    char stringdata8[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTrackChangeENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTrackChangeENDCLASS_t qt_meta_stringdata_CLASSTrackChangeENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "TrackChange"
        QT_MOC_LITERAL(12, 14),  // "onStateChanged"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(40, 5),  // "state"
        QT_MOC_LITERAL(46, 18),  // "onTrackInfoChanged"
        QT_MOC_LITERAL(65, 9),  // "onFinised"
        QT_MOC_LITERAL(75, 12),  // "onAppStartup"
        QT_MOC_LITERAL(88, 9)   // "onAppExit"
    },
    "TrackChange",
    "onStateChanged",
    "",
    "Qmmp::State",
    "state",
    "onTrackInfoChanged",
    "onFinised",
    "onAppStartup",
    "onAppExit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTrackChangeENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x08,    1 /* Private */,
       5,    0,   47,    2, 0x08,    3 /* Private */,
       6,    0,   48,    2, 0x08,    4 /* Private */,
       7,    0,   49,    2, 0x08,    5 /* Private */,
       8,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TrackChange::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTrackChangeENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTrackChangeENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTrackChangeENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TrackChange, std::true_type>,
        // method 'onStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qmmp::State, std::false_type>,
        // method 'onTrackInfoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFinised'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAppStartup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAppExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TrackChange::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrackChange *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onStateChanged((*reinterpret_cast< std::add_pointer_t<Qmmp::State>>(_a[1]))); break;
        case 1: _t->onTrackInfoChanged(); break;
        case 2: _t->onFinised(); break;
        case 3: _t->onAppStartup(); break;
        case 4: _t->onAppExit(); break;
        default: ;
        }
    }
}

const QMetaObject *TrackChange::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackChange::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTrackChangeENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TrackChange::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'mediakeys.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/gnomehotkey/mediakeys.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mediakeys.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMediaKeysENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMediaKeysENDCLASS = QtMocHelpers::stringData(
    "MediaKeys",
    "grabMediaPlayerKeys",
    "QDBusPendingReply<>",
    "",
    "application",
    "time",
    "releaseMediaPlayerKeys",
    "onRegisterFinished",
    "QDBusPendingCallWatcher*",
    "watcher",
    "onKeyPressed",
    "in0",
    "in1"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMediaKeysENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[10];
    char stringdata1[20];
    char stringdata2[20];
    char stringdata3[1];
    char stringdata4[12];
    char stringdata5[5];
    char stringdata6[23];
    char stringdata7[19];
    char stringdata8[25];
    char stringdata9[8];
    char stringdata10[13];
    char stringdata11[4];
    char stringdata12[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMediaKeysENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMediaKeysENDCLASS_t qt_meta_stringdata_CLASSMediaKeysENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "MediaKeys"
        QT_MOC_LITERAL(10, 19),  // "grabMediaPlayerKeys"
        QT_MOC_LITERAL(30, 19),  // "QDBusPendingReply<>"
        QT_MOC_LITERAL(50, 0),  // ""
        QT_MOC_LITERAL(51, 11),  // "application"
        QT_MOC_LITERAL(63, 4),  // "time"
        QT_MOC_LITERAL(68, 22),  // "releaseMediaPlayerKeys"
        QT_MOC_LITERAL(91, 18),  // "onRegisterFinished"
        QT_MOC_LITERAL(110, 24),  // "QDBusPendingCallWatcher*"
        QT_MOC_LITERAL(135, 7),  // "watcher"
        QT_MOC_LITERAL(143, 12),  // "onKeyPressed"
        QT_MOC_LITERAL(156, 3),  // "in0"
        QT_MOC_LITERAL(160, 3)   // "in1"
    },
    "MediaKeys",
    "grabMediaPlayerKeys",
    "QDBusPendingReply<>",
    "",
    "application",
    "time",
    "releaseMediaPlayerKeys",
    "onRegisterFinished",
    "QDBusPendingCallWatcher*",
    "watcher",
    "onKeyPressed",
    "in0",
    "in1"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMediaKeysENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   38,    3, 0x08,    1 /* Private */,
       6,    1,   43,    3, 0x08,    4 /* Private */,
       7,    1,   46,    3, 0x08,    6 /* Private */,
      10,    2,   49,    3, 0x08,    8 /* Private */,

 // slots: parameters
    0x80000000 | 2, QMetaType::QString, QMetaType::UInt,    4,    5,
    0x80000000 | 2, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject MediaKeys::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSMediaKeysENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMediaKeysENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMediaKeysENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MediaKeys, std::true_type>,
        // method 'grabMediaPlayerKeys'
        QtPrivate::TypeAndForceComplete<QDBusPendingReply<>, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint, std::false_type>,
        // method 'releaseMediaPlayerKeys'
        QtPrivate::TypeAndForceComplete<QDBusPendingReply<>, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onRegisterFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDBusPendingCallWatcher *, std::false_type>,
        // method 'onKeyPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MediaKeys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaKeys *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QDBusPendingReply<> _r = _t->grabMediaPlayerKeys((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusPendingReply<> _r = _t->releaseMediaPlayerKeys((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->onRegisterFinished((*reinterpret_cast< std::add_pointer_t<QDBusPendingCallWatcher*>>(_a[1]))); break;
        case 3: _t->onKeyPressed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusPendingCallWatcher* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MediaKeys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaKeys::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMediaKeysENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaKeys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP

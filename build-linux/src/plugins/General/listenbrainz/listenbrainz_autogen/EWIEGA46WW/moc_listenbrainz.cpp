/****************************************************************************
** Meta object code from reading C++ file 'listenbrainz.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/listenbrainz/listenbrainz.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listenbrainz.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSListenBrainzENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSListenBrainzENDCLASS = QtMocHelpers::stringData(
    "ListenBrainz",
    "setState",
    "",
    "Qmmp::State",
    "state",
    "updateMetaData",
    "processResponse",
    "QNetworkReply*",
    "reply",
    "setupProxy",
    "submit"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSListenBrainzENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[13];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[15];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[6];
    char stringdata9[11];
    char stringdata10[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSListenBrainzENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSListenBrainzENDCLASS_t qt_meta_stringdata_CLASSListenBrainzENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ListenBrainz"
        QT_MOC_LITERAL(13, 8),  // "setState"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(35, 5),  // "state"
        QT_MOC_LITERAL(41, 14),  // "updateMetaData"
        QT_MOC_LITERAL(56, 15),  // "processResponse"
        QT_MOC_LITERAL(72, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(87, 5),  // "reply"
        QT_MOC_LITERAL(93, 10),  // "setupProxy"
        QT_MOC_LITERAL(104, 6)   // "submit"
    },
    "ListenBrainz",
    "setState",
    "",
    "Qmmp::State",
    "state",
    "updateMetaData",
    "processResponse",
    "QNetworkReply*",
    "reply",
    "setupProxy",
    "submit"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSListenBrainzENDCLASS[] = {

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
       6,    1,   48,    2, 0x08,    4 /* Private */,
       9,    0,   51,    2, 0x08,    6 /* Private */,
      10,    0,   52,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ListenBrainz::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSListenBrainzENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSListenBrainzENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSListenBrainzENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ListenBrainz, std::true_type>,
        // method 'setState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qmmp::State, std::false_type>,
        // method 'updateMetaData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'setupProxy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'submit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ListenBrainz::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListenBrainz *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setState((*reinterpret_cast< std::add_pointer_t<Qmmp::State>>(_a[1]))); break;
        case 1: _t->updateMetaData(); break;
        case 2: _t->processResponse((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 3: _t->setupProxy(); break;
        case 4: _t->submit(); break;
        default: ;
        }
    }
}

const QMetaObject *ListenBrainz::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListenBrainz::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSListenBrainzENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ListenBrainz::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

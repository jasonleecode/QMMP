/****************************************************************************
** Meta object code from reading C++ file 'scrobbler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/scrobbler/scrobbler.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scrobbler.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSScrobblerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSScrobblerENDCLASS = QtMocHelpers::stringData(
    "Scrobbler",
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
struct qt_meta_stringdata_CLASSScrobblerENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[10];
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
    uint(sizeof(qt_meta_stringdata_CLASSScrobblerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSScrobblerENDCLASS_t qt_meta_stringdata_CLASSScrobblerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "Scrobbler"
        QT_MOC_LITERAL(10, 8),  // "setState"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(32, 5),  // "state"
        QT_MOC_LITERAL(38, 14),  // "updateMetaData"
        QT_MOC_LITERAL(53, 15),  // "processResponse"
        QT_MOC_LITERAL(69, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(84, 5),  // "reply"
        QT_MOC_LITERAL(90, 10),  // "setupProxy"
        QT_MOC_LITERAL(101, 6)   // "submit"
    },
    "Scrobbler",
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

Q_CONSTINIT static const uint qt_meta_data_CLASSScrobblerENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject Scrobbler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSScrobblerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSScrobblerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSScrobblerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Scrobbler, std::true_type>,
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

void Scrobbler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Scrobbler *>(_o);
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

const QMetaObject *Scrobbler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scrobbler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSScrobblerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Scrobbler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSScrobblerAuthENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSScrobblerAuthENDCLASS = QtMocHelpers::stringData(
    "ScrobblerAuth",
    "tokenRequestFinished",
    "",
    "error",
    "sessionRequestFinished",
    "checkSessionFinished",
    "processResponse",
    "QNetworkReply*",
    "reply"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSScrobblerAuthENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[14];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[23];
    char stringdata5[21];
    char stringdata6[16];
    char stringdata7[15];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSScrobblerAuthENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSScrobblerAuthENDCLASS_t qt_meta_stringdata_CLASSScrobblerAuthENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ScrobblerAuth"
        QT_MOC_LITERAL(14, 20),  // "tokenRequestFinished"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 5),  // "error"
        QT_MOC_LITERAL(42, 22),  // "sessionRequestFinished"
        QT_MOC_LITERAL(65, 20),  // "checkSessionFinished"
        QT_MOC_LITERAL(86, 15),  // "processResponse"
        QT_MOC_LITERAL(102, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(117, 5)   // "reply"
    },
    "ScrobblerAuth",
    "tokenRequestFinished",
    "",
    "error",
    "sessionRequestFinished",
    "checkSessionFinished",
    "processResponse",
    "QNetworkReply*",
    "reply"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSScrobblerAuthENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    1,   41,    2, 0x06,    3 /* Public */,
       5,    1,   44,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   47,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject ScrobblerAuth::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSScrobblerAuthENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSScrobblerAuthENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSScrobblerAuthENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ScrobblerAuth, std::true_type>,
        // method 'tokenRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sessionRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'checkSessionFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'processResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>
    >,
    nullptr
} };

void ScrobblerAuth::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScrobblerAuth *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tokenRequestFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->sessionRequestFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->checkSessionFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->processResponse((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScrobblerAuth::*)(int );
            if (_t _q_method = &ScrobblerAuth::tokenRequestFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScrobblerAuth::*)(int );
            if (_t _q_method = &ScrobblerAuth::sessionRequestFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScrobblerAuth::*)(int );
            if (_t _q_method = &ScrobblerAuth::checkSessionFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ScrobblerAuth::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrobblerAuth::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSScrobblerAuthENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ScrobblerAuth::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ScrobblerAuth::tokenRequestFinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ScrobblerAuth::sessionRequestFinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ScrobblerAuth::checkSessionFinished(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP

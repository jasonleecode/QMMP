/****************************************************************************
** Meta object code from reading C++ file 'qmmpstarter.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/app/qmmpstarter.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmmpstarter.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQMMPStarterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQMMPStarterENDCLASS = QtMocHelpers::stringData(
    "QMMPStarter",
    "writeCommand",
    "",
    "readCommand",
    "savePosition",
    "commitData",
    "QSessionManager&",
    "manager",
    "handleSigTerm"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQMMPStarterENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[13];
    char stringdata5[11];
    char stringdata6[17];
    char stringdata7[8];
    char stringdata8[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQMMPStarterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQMMPStarterENDCLASS_t qt_meta_stringdata_CLASSQMMPStarterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "QMMPStarter"
        QT_MOC_LITERAL(12, 12),  // "writeCommand"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 11),  // "readCommand"
        QT_MOC_LITERAL(38, 12),  // "savePosition"
        QT_MOC_LITERAL(51, 10),  // "commitData"
        QT_MOC_LITERAL(62, 16),  // "QSessionManager&"
        QT_MOC_LITERAL(79, 7),  // "manager"
        QT_MOC_LITERAL(87, 13)   // "handleSigTerm"
    },
    "QMMPStarter",
    "writeCommand",
    "",
    "readCommand",
    "savePosition",
    "commitData",
    "QSessionManager&",
    "manager",
    "handleSigTerm"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQMMPStarterENDCLASS[] = {

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
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    1,   47,    2, 0x08,    4 /* Private */,
       8,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QMMPStarter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQMMPStarterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQMMPStarterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQMMPStarterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QMMPStarter, std::true_type>,
        // method 'writeCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'savePosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'commitData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSessionManager &, std::false_type>,
        // method 'handleSigTerm'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QMMPStarter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMMPStarter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->writeCommand(); break;
        case 1: _t->readCommand(); break;
        case 2: _t->savePosition(); break;
        case 3: _t->commitData((*reinterpret_cast< std::add_pointer_t<QSessionManager&>>(_a[1]))); break;
        case 4: _t->handleSigTerm(); break;
        default: ;
        }
    }
}

const QMetaObject *QMMPStarter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMMPStarter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQMMPStarterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMMPStarter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

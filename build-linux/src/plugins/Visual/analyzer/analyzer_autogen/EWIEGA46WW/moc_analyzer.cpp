/****************************************************************************
** Meta object code from reading C++ file 'analyzer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Visual/analyzer/analyzer.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'analyzer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAnalyzerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAnalyzerENDCLASS = QtMocHelpers::stringData(
    "Analyzer",
    "start",
    "",
    "stop",
    "timeout",
    "toggleFullScreen",
    "readSettings",
    "writeSettings"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAnalyzerENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[9];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[8];
    char stringdata5[17];
    char stringdata6[13];
    char stringdata7[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAnalyzerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAnalyzerENDCLASS_t qt_meta_stringdata_CLASSAnalyzerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "Analyzer"
        QT_MOC_LITERAL(9, 5),  // "start"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 4),  // "stop"
        QT_MOC_LITERAL(21, 7),  // "timeout"
        QT_MOC_LITERAL(29, 16),  // "toggleFullScreen"
        QT_MOC_LITERAL(46, 12),  // "readSettings"
        QT_MOC_LITERAL(59, 13)   // "writeSettings"
    },
    "Analyzer",
    "start",
    "",
    "stop",
    "timeout",
    "toggleFullScreen",
    "readSettings",
    "writeSettings"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAnalyzerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x0a,    1 /* Public */,
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Analyzer::staticMetaObject = { {
    QMetaObject::SuperData::link<Visual::staticMetaObject>(),
    qt_meta_stringdata_CLASSAnalyzerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAnalyzerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAnalyzerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Analyzer, std::true_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'toggleFullScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writeSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Analyzer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Analyzer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->stop(); break;
        case 2: _t->timeout(); break;
        case 3: _t->toggleFullScreen(); break;
        case 4: _t->readSettings(); break;
        case 5: _t->writeSettings(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Analyzer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Analyzer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAnalyzerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return Visual::qt_metacast(_clname);
}

int Analyzer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Visual::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP

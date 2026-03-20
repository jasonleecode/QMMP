/****************************************************************************
** Meta object code from reading C++ file 'symboldisplay.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/skinned/symboldisplay.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'symboldisplay.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSymbolDisplayENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSymbolDisplayENDCLASS = QtMocHelpers::stringData(
    "SymbolDisplay",
    "display",
    "",
    "displayNum",
    "draw",
    "updateSkin"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSymbolDisplayENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[14];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[5];
    char stringdata5[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSymbolDisplayENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSymbolDisplayENDCLASS_t qt_meta_stringdata_CLASSSymbolDisplayENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "SymbolDisplay"
        QT_MOC_LITERAL(14, 7),  // "display"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 10),  // "displayNum"
        QT_MOC_LITERAL(34, 4),  // "draw"
        QT_MOC_LITERAL(39, 10)   // "updateSkin"
    },
    "SymbolDisplay",
    "display",
    "",
    "displayNum",
    "draw",
    "updateSkin"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSymbolDisplayENDCLASS[] = {

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
       1,    1,   38,    2, 0x0a,    1 /* Public */,
       3,    1,   41,    2, 0x0a,    3 /* Public */,
       4,    0,   44,    2, 0x08,    5 /* Private */,
       5,    0,   45,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SymbolDisplay::staticMetaObject = { {
    QMetaObject::SuperData::link<PixmapWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSymbolDisplayENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSymbolDisplayENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSymbolDisplayENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SymbolDisplay, std::true_type>,
        // method 'display'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'displayNum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'draw'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSkin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SymbolDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SymbolDisplay *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->display((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->displayNum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->draw(); break;
        case 3: _t->updateSkin(); break;
        default: ;
        }
    }
}

const QMetaObject *SymbolDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SymbolDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSymbolDisplayENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return PixmapWidget::qt_metacast(_clname);
}

int SymbolDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PixmapWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP

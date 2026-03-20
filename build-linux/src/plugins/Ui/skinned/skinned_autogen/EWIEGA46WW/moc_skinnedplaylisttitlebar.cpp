/****************************************************************************
** Meta object code from reading C++ file 'skinnedplaylisttitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/skinned/skinnedplaylisttitlebar.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skinnedplaylisttitlebar.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS = QtMocHelpers::stringData(
    "SkinnedPlayListTitleBar",
    "showCurrent",
    "",
    "setModel",
    "PlayListModel*",
    "selected",
    "previous",
    "updateSkin",
    "shade"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[24];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[15];
    char stringdata5[9];
    char stringdata6[9];
    char stringdata7[11];
    char stringdata8[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS_t qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "SkinnedPlayListTitleBar"
        QT_MOC_LITERAL(24, 11),  // "showCurrent"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 8),  // "setModel"
        QT_MOC_LITERAL(46, 14),  // "PlayListModel*"
        QT_MOC_LITERAL(61, 8),  // "selected"
        QT_MOC_LITERAL(70, 8),  // "previous"
        QT_MOC_LITERAL(79, 10),  // "updateSkin"
        QT_MOC_LITERAL(90, 5)   // "shade"
    },
    "SkinnedPlayListTitleBar",
    "showCurrent",
    "",
    "setModel",
    "PlayListModel*",
    "selected",
    "previous",
    "updateSkin",
    "shade"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSkinnedPlayListTitleBarENDCLASS[] = {

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
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    2,   45,    2, 0x0a,    2 /* Public */,
       3,    1,   50,    2, 0x2a,    5 /* Public | MethodCloned */,
       7,    0,   53,    2, 0x08,    7 /* Private */,
       8,    0,   54,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SkinnedPlayListTitleBar::staticMetaObject = { {
    QMetaObject::SuperData::link<PixmapWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSkinnedPlayListTitleBarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SkinnedPlayListTitleBar, std::true_type>,
        // method 'showCurrent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'setModel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'updateSkin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shade'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SkinnedPlayListTitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SkinnedPlayListTitleBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showCurrent(); break;
        case 1: _t->setModel((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[2]))); break;
        case 2: _t->setModel((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1]))); break;
        case 3: _t->updateSkin(); break;
        case 4: _t->shade(); break;
        default: ;
        }
    }
}

const QMetaObject *SkinnedPlayListTitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SkinnedPlayListTitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSkinnedPlayListTitleBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return PixmapWidget::qt_metacast(_clname);
}

int SkinnedPlayListTitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PixmapWidget::qt_metacall(_c, _id, _a);
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

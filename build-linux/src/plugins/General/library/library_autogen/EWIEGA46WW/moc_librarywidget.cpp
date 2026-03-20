/****************************************************************************
** Meta object code from reading C++ file 'librarywidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/library/librarywidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'librarywidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLibraryWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLibraryWidgetENDCLASS = QtMocHelpers::stringData(
    "LibraryWidget",
    "on_filterLineEdit_textChanged",
    "",
    "text",
    "addSelected",
    "replaceSelected",
    "showTrackInformation",
    "showLibraryInformation"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLibraryWidgetENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[30];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[12];
    char stringdata5[16];
    char stringdata6[21];
    char stringdata7[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLibraryWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLibraryWidgetENDCLASS_t qt_meta_stringdata_CLASSLibraryWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "LibraryWidget"
        QT_MOC_LITERAL(14, 29),  // "on_filterLineEdit_textChanged"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 4),  // "text"
        QT_MOC_LITERAL(50, 11),  // "addSelected"
        QT_MOC_LITERAL(62, 15),  // "replaceSelected"
        QT_MOC_LITERAL(78, 20),  // "showTrackInformation"
        QT_MOC_LITERAL(99, 22)   // "showLibraryInformation"
    },
    "LibraryWidget",
    "on_filterLineEdit_textChanged",
    "",
    "text",
    "addSelected",
    "replaceSelected",
    "showTrackInformation",
    "showLibraryInformation"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLibraryWidgetENDCLASS[] = {

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
       4,    0,   47,    2, 0x08,    3 /* Private */,
       5,    0,   48,    2, 0x08,    4 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    0,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject LibraryWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSLibraryWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLibraryWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLibraryWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LibraryWidget, std::true_type>,
        // method 'on_filterLineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'replaceSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTrackInformation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showLibraryInformation'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LibraryWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LibraryWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_filterLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->addSelected(); break;
        case 2: _t->replaceSelected(); break;
        case 3: _t->showTrackInformation(); break;
        case 4: _t->showLibraryInformation(); break;
        default: ;
        }
    }
}

const QMetaObject *LibraryWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LibraryWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLibraryWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LibraryWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

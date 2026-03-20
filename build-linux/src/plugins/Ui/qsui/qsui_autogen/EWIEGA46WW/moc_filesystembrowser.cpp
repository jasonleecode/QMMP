/****************************************************************************
** Meta object code from reading C++ file 'filesystembrowser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/qsui/filesystembrowser.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filesystembrowser.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS = QtMocHelpers::stringData(
    "FileSystemBrowser",
    "onListViewActivated",
    "",
    "QModelIndex",
    "index",
    "addToPlayList",
    "replacePlayList",
    "selectDirectory",
    "onFilterLineEditTextChanged",
    "str",
    "setTreeViewMode",
    "enabled"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[18];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[14];
    char stringdata6[16];
    char stringdata7[16];
    char stringdata8[28];
    char stringdata9[4];
    char stringdata10[16];
    char stringdata11[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS_t qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "FileSystemBrowser"
        QT_MOC_LITERAL(18, 19),  // "onListViewActivated"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 11),  // "QModelIndex"
        QT_MOC_LITERAL(51, 5),  // "index"
        QT_MOC_LITERAL(57, 13),  // "addToPlayList"
        QT_MOC_LITERAL(71, 15),  // "replacePlayList"
        QT_MOC_LITERAL(87, 15),  // "selectDirectory"
        QT_MOC_LITERAL(103, 27),  // "onFilterLineEditTextChanged"
        QT_MOC_LITERAL(131, 3),  // "str"
        QT_MOC_LITERAL(135, 15),  // "setTreeViewMode"
        QT_MOC_LITERAL(151, 7)   // "enabled"
    },
    "FileSystemBrowser",
    "onListViewActivated",
    "",
    "QModelIndex",
    "index",
    "addToPlayList",
    "replacePlayList",
    "selectDirectory",
    "onFilterLineEditTextChanged",
    "str",
    "setTreeViewMode",
    "enabled"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFileSystemBrowserENDCLASS[] = {

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
       1,    1,   50,    2, 0x08,    1 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    0,   54,    2, 0x08,    4 /* Private */,
       7,    0,   55,    2, 0x08,    5 /* Private */,
       8,    1,   56,    2, 0x08,    6 /* Private */,
      10,    1,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject FileSystemBrowser::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFileSystemBrowserENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FileSystemBrowser, std::true_type>,
        // method 'onListViewActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'addToPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'replacePlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectDirectory'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFilterLineEditTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setTreeViewMode'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void FileSystemBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileSystemBrowser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onListViewActivated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->addToPlayList(); break;
        case 2: _t->replacePlayList(); break;
        case 3: _t->selectDirectory(); break;
        case 4: _t->onFilterLineEditTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setTreeViewMode((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *FileSystemBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSystemBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFileSystemBrowserENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FileSystemBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

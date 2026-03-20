/****************************************************************************
** Meta object code from reading C++ file 'qsuiplaylistbrowser.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/qsui/qsuiplaylistbrowser.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsuiplaylistbrowser.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS = QtMocHelpers::stringData(
    "QSUiPlayListBrowser",
    "updateList",
    "",
    "onLineEditTextChanged",
    "str",
    "onListViewActivated",
    "QModelIndex",
    "index",
    "updateCurrentRow"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[20];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[4];
    char stringdata5[20];
    char stringdata6[12];
    char stringdata7[6];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS_t qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "QSUiPlayListBrowser"
        QT_MOC_LITERAL(20, 10),  // "updateList"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 21),  // "onLineEditTextChanged"
        QT_MOC_LITERAL(54, 3),  // "str"
        QT_MOC_LITERAL(58, 19),  // "onListViewActivated"
        QT_MOC_LITERAL(78, 11),  // "QModelIndex"
        QT_MOC_LITERAL(90, 5),  // "index"
        QT_MOC_LITERAL(96, 16)   // "updateCurrentRow"
    },
    "QSUiPlayListBrowser",
    "updateList",
    "",
    "onLineEditTextChanged",
    "str",
    "onListViewActivated",
    "QModelIndex",
    "index",
    "updateCurrentRow"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSUiPlayListBrowserENDCLASS[] = {

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
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    1,   39,    2, 0x08,    2 /* Private */,
       5,    1,   42,    2, 0x08,    4 /* Private */,
       8,    2,   45,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject QSUiPlayListBrowser::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSUiPlayListBrowserENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QSUiPlayListBrowser, std::true_type>,
        // method 'updateList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLineEditTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onListViewActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'updateCurrentRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>,
        QtPrivate::TypeAndForceComplete<QModelIndex, std::false_type>
    >,
    nullptr
} };

void QSUiPlayListBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSUiPlayListBrowser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateList(); break;
        case 1: _t->onLineEditTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onListViewActivated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->updateCurrentRow((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *QSUiPlayListBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSUiPlayListBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSUiPlayListBrowserENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QSUiPlayListBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

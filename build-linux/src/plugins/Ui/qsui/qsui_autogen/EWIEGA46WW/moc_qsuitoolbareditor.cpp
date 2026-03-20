/****************************************************************************
** Meta object code from reading C++ file 'qsuitoolbareditor.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/qsui/qsuitoolbareditor.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsuitoolbareditor.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS = QtMocHelpers::stringData(
    "QSUiToolBarEditor",
    "accept",
    "",
    "on_addToolButton_clicked",
    "on_removeToolButton_clicked",
    "on_upToolButton_clicked",
    "on_downToolButton_clicked",
    "on_toolbarNameComboBox_activated",
    "index",
    "onRowsAboutToBeRemoved",
    "QModelIndex",
    "start",
    "on_createButton_clicked",
    "on_renameButton_clicked",
    "on_removeButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[18];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[28];
    char stringdata5[24];
    char stringdata6[26];
    char stringdata7[33];
    char stringdata8[6];
    char stringdata9[23];
    char stringdata10[12];
    char stringdata11[6];
    char stringdata12[24];
    char stringdata13[24];
    char stringdata14[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS_t qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "QSUiToolBarEditor"
        QT_MOC_LITERAL(18, 6),  // "accept"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 24),  // "on_addToolButton_clicked"
        QT_MOC_LITERAL(51, 27),  // "on_removeToolButton_clicked"
        QT_MOC_LITERAL(79, 23),  // "on_upToolButton_clicked"
        QT_MOC_LITERAL(103, 25),  // "on_downToolButton_clicked"
        QT_MOC_LITERAL(129, 32),  // "on_toolbarNameComboBox_activated"
        QT_MOC_LITERAL(162, 5),  // "index"
        QT_MOC_LITERAL(168, 22),  // "onRowsAboutToBeRemoved"
        QT_MOC_LITERAL(191, 11),  // "QModelIndex"
        QT_MOC_LITERAL(203, 5),  // "start"
        QT_MOC_LITERAL(209, 23),  // "on_createButton_clicked"
        QT_MOC_LITERAL(233, 23),  // "on_renameButton_clicked"
        QT_MOC_LITERAL(257, 23)   // "on_removeButton_clicked"
    },
    "QSUiToolBarEditor",
    "accept",
    "",
    "on_addToolButton_clicked",
    "on_removeToolButton_clicked",
    "on_upToolButton_clicked",
    "on_downToolButton_clicked",
    "on_toolbarNameComboBox_activated",
    "index",
    "onRowsAboutToBeRemoved",
    "QModelIndex",
    "start",
    "on_createButton_clicked",
    "on_renameButton_clicked",
    "on_removeButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSUiToolBarEditorENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    1,   79,    2, 0x08,    6 /* Private */,
       9,    3,   82,    2, 0x08,    8 /* Private */,
      12,    0,   89,    2, 0x08,   12 /* Private */,
      13,    0,   90,    2, 0x08,   13 /* Private */,
      14,    0,   91,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,    2,   11,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QSUiToolBarEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSUiToolBarEditorENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QSUiToolBarEditor, std::true_type>,
        // method 'accept'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_upToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_downToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolbarNameComboBox_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onRowsAboutToBeRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_createButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_renameButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_removeButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QSUiToolBarEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSUiToolBarEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->on_addToolButton_clicked(); break;
        case 2: _t->on_removeToolButton_clicked(); break;
        case 3: _t->on_upToolButton_clicked(); break;
        case 4: _t->on_downToolButton_clicked(); break;
        case 5: _t->on_toolbarNameComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->onRowsAboutToBeRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->on_createButton_clicked(); break;
        case 8: _t->on_renameButton_clicked(); break;
        case 9: _t->on_removeButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *QSUiToolBarEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSUiToolBarEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSUiToolBarEditorENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QSUiToolBarEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP

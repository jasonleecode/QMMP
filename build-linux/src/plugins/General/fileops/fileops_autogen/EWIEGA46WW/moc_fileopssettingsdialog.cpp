/****************************************************************************
** Meta object code from reading C++ file 'fileopssettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/fileops/fileopssettingsdialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileopssettingsdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS = QtMocHelpers::stringData(
    "FileOpsSettingsDialog",
    "accept",
    "",
    "on_newButton_clicked",
    "on_deleteButton_clicked",
    "updateLineEdits",
    "on_destinationEdit_textChanged",
    "dest",
    "on_patternEdit_textChanged",
    "pattern",
    "addTitleString",
    "str",
    "on_destButton_clicked",
    "on_tableWidget_itemDoubleClicked",
    "QTableWidgetItem*",
    "item"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[22];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[24];
    char stringdata5[16];
    char stringdata6[31];
    char stringdata7[5];
    char stringdata8[27];
    char stringdata9[8];
    char stringdata10[15];
    char stringdata11[4];
    char stringdata12[22];
    char stringdata13[33];
    char stringdata14[18];
    char stringdata15[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS_t qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "FileOpsSettingsDialog"
        QT_MOC_LITERAL(22, 6),  // "accept"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 20),  // "on_newButton_clicked"
        QT_MOC_LITERAL(51, 23),  // "on_deleteButton_clicked"
        QT_MOC_LITERAL(75, 15),  // "updateLineEdits"
        QT_MOC_LITERAL(91, 30),  // "on_destinationEdit_textChanged"
        QT_MOC_LITERAL(122, 4),  // "dest"
        QT_MOC_LITERAL(127, 26),  // "on_patternEdit_textChanged"
        QT_MOC_LITERAL(154, 7),  // "pattern"
        QT_MOC_LITERAL(162, 14),  // "addTitleString"
        QT_MOC_LITERAL(177, 3),  // "str"
        QT_MOC_LITERAL(181, 21),  // "on_destButton_clicked"
        QT_MOC_LITERAL(203, 32),  // "on_tableWidget_itemDoubleClicked"
        QT_MOC_LITERAL(236, 17),  // "QTableWidgetItem*"
        QT_MOC_LITERAL(254, 4)   // "item"
    },
    "FileOpsSettingsDialog",
    "accept",
    "",
    "on_newButton_clicked",
    "on_deleteButton_clicked",
    "updateLineEdits",
    "on_destinationEdit_textChanged",
    "dest",
    "on_patternEdit_textChanged",
    "pattern",
    "addTitleString",
    "str",
    "on_destButton_clicked",
    "on_tableWidget_itemDoubleClicked",
    "QTableWidgetItem*",
    "item"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSFileOpsSettingsDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x0a,    1 /* Public */,
       3,    0,   69,    2, 0x08,    2 /* Private */,
       4,    0,   70,    2, 0x08,    3 /* Private */,
       5,    0,   71,    2, 0x08,    4 /* Private */,
       6,    1,   72,    2, 0x08,    5 /* Private */,
       8,    1,   75,    2, 0x08,    7 /* Private */,
      10,    1,   78,    2, 0x08,    9 /* Private */,
      12,    0,   81,    2, 0x08,   11 /* Private */,
      13,    1,   82,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject FileOpsSettingsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSFileOpsSettingsDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FileOpsSettingsDialog, std::true_type>,
        // method 'accept'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_newButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLineEdits'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_destinationEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_patternEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addTitleString'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_destButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableWidget_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>
    >,
    nullptr
} };

void FileOpsSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileOpsSettingsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->on_newButton_clicked(); break;
        case 2: _t->on_deleteButton_clicked(); break;
        case 3: _t->updateLineEdits(); break;
        case 4: _t->on_destinationEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->on_patternEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->addTitleString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_destButton_clicked(); break;
        case 8: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *FileOpsSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileOpsSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSFileOpsSettingsDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FileOpsSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP

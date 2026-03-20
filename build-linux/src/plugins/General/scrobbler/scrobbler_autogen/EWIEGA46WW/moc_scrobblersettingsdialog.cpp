/****************************************************************************
** Meta object code from reading C++ file 'scrobblersettingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/scrobbler/scrobblersettingsdialog.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scrobblersettingsdialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS = QtMocHelpers::stringData(
    "ScrobblerSettingsDialog",
    "accept",
    "",
    "on_newSessionButton_lastfm_clicked",
    "on_newSessionButton_librefm_clicked",
    "processTokenResponse",
    "error",
    "processSessionResponse",
    "on_checkButton_lastfm_clicked",
    "on_checkButton_librefm_clicked",
    "processCheckResponse"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[24];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[35];
    char stringdata4[36];
    char stringdata5[21];
    char stringdata6[6];
    char stringdata7[23];
    char stringdata8[30];
    char stringdata9[31];
    char stringdata10[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS_t qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "ScrobblerSettingsDialog"
        QT_MOC_LITERAL(24, 6),  // "accept"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 34),  // "on_newSessionButton_lastfm_cl..."
        QT_MOC_LITERAL(67, 35),  // "on_newSessionButton_librefm_c..."
        QT_MOC_LITERAL(103, 20),  // "processTokenResponse"
        QT_MOC_LITERAL(124, 5),  // "error"
        QT_MOC_LITERAL(130, 22),  // "processSessionResponse"
        QT_MOC_LITERAL(153, 29),  // "on_checkButton_lastfm_clicked"
        QT_MOC_LITERAL(183, 30),  // "on_checkButton_librefm_clicked"
        QT_MOC_LITERAL(214, 20)   // "processCheckResponse"
    },
    "ScrobblerSettingsDialog",
    "accept",
    "",
    "on_newSessionButton_lastfm_clicked",
    "on_newSessionButton_librefm_clicked",
    "processTokenResponse",
    "error",
    "processSessionResponse",
    "on_checkButton_lastfm_clicked",
    "on_checkButton_librefm_clicked",
    "processCheckResponse"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSScrobblerSettingsDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x0a,    1 /* Public */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    1,   65,    2, 0x08,    4 /* Private */,
       7,    1,   68,    2, 0x08,    6 /* Private */,
       8,    0,   71,    2, 0x08,    8 /* Private */,
       9,    0,   72,    2, 0x08,    9 /* Private */,
      10,    1,   73,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject ScrobblerSettingsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSScrobblerSettingsDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ScrobblerSettingsDialog, std::true_type>,
        // method 'accept'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_newSessionButton_lastfm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_newSessionButton_librefm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processTokenResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'processSessionResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_checkButton_lastfm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkButton_librefm_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processCheckResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ScrobblerSettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScrobblerSettingsDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->on_newSessionButton_lastfm_clicked(); break;
        case 2: _t->on_newSessionButton_librefm_clicked(); break;
        case 3: _t->processTokenResponse((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->processSessionResponse((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_checkButton_lastfm_clicked(); break;
        case 6: _t->on_checkButton_librefm_clicked(); break;
        case 7: _t->processCheckResponse((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ScrobblerSettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrobblerSettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSScrobblerSettingsDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ScrobblerSettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP

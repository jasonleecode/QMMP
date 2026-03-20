/****************************************************************************
** Meta object code from reading C++ file 'qsuiequalizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/qsui/qsuiequalizer.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsuiequalizer.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS = QtMocHelpers::stringData(
    "QSUiEqualizer",
    "applySettings",
    "",
    "resetSettings",
    "updateLabel",
    "loadPreset",
    "index",
    "savePreset",
    "savePresets",
    "deletePreset"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[12];
    char stringdata5[11];
    char stringdata6[6];
    char stringdata7[11];
    char stringdata8[12];
    char stringdata9[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS_t qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QSUiEqualizer"
        QT_MOC_LITERAL(14, 13),  // "applySettings"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 13),  // "resetSettings"
        QT_MOC_LITERAL(43, 11),  // "updateLabel"
        QT_MOC_LITERAL(55, 10),  // "loadPreset"
        QT_MOC_LITERAL(66, 5),  // "index"
        QT_MOC_LITERAL(72, 10),  // "savePreset"
        QT_MOC_LITERAL(83, 11),  // "savePresets"
        QT_MOC_LITERAL(95, 12)   // "deletePreset"
    },
    "QSUiEqualizer",
    "applySettings",
    "",
    "resetSettings",
    "updateLabel",
    "loadPreset",
    "index",
    "savePreset",
    "savePresets",
    "deletePreset"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSUiEqualizerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    1,   59,    2, 0x08,    4 /* Private */,
       7,    0,   62,    2, 0x08,    6 /* Private */,
       8,    0,   63,    2, 0x08,    7 /* Private */,
       9,    0,   64,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QSUiEqualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSUiEqualizerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QSUiEqualizer, std::true_type>,
        // method 'applySettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLabel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadPreset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'savePreset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'savePresets'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deletePreset'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QSUiEqualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSUiEqualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->applySettings(); break;
        case 1: _t->resetSettings(); break;
        case 2: _t->updateLabel(); break;
        case 3: _t->loadPreset((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->savePreset(); break;
        case 5: _t->savePresets(); break;
        case 6: _t->deletePreset(); break;
        default: ;
        }
    }
}

const QMetaObject *QSUiEqualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSUiEqualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSUiEqualizerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QSUiEqualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP

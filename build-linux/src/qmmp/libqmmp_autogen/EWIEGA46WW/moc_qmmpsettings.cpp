/****************************************************************************
** Meta object code from reading C++ file 'qmmpsettings.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qmmp/qmmpsettings.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmmpsettings.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQmmpSettingsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQmmpSettingsENDCLASS = QtMocHelpers::stringData(
    "QmmpSettings",
    "replayGainSettingsChanged",
    "",
    "audioSettingsChanged",
    "coverSettingsChanged",
    "networkSettingsChanged",
    "eqSettingsChanged",
    "sync"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmmpSettingsENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[13];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[21];
    char stringdata5[23];
    char stringdata6[18];
    char stringdata7[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmmpSettingsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmmpSettingsENDCLASS_t qt_meta_stringdata_CLASSQmmpSettingsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "QmmpSettings"
        QT_MOC_LITERAL(13, 25),  // "replayGainSettingsChanged"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 20),  // "audioSettingsChanged"
        QT_MOC_LITERAL(61, 20),  // "coverSettingsChanged"
        QT_MOC_LITERAL(82, 22),  // "networkSettingsChanged"
        QT_MOC_LITERAL(105, 17),  // "eqSettingsChanged"
        QT_MOC_LITERAL(123, 4)   // "sync"
    },
    "QmmpSettings",
    "replayGainSettingsChanged",
    "",
    "audioSettingsChanged",
    "coverSettingsChanged",
    "networkSettingsChanged",
    "eqSettingsChanged",
    "sync"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmmpSettingsENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,
       4,    0,   52,    2, 0x06,    3 /* Public */,
       5,    0,   53,    2, 0x06,    4 /* Public */,
       6,    0,   54,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QmmpSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmmpSettingsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmmpSettingsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQmmpSettingsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QmmpSettings, std::true_type>,
        // method 'replayGainSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'audioSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'coverSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'networkSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eqSettingsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sync'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QmmpSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QmmpSettings *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->replayGainSettingsChanged(); break;
        case 1: _t->audioSettingsChanged(); break;
        case 2: _t->coverSettingsChanged(); break;
        case 3: _t->networkSettingsChanged(); break;
        case 4: _t->eqSettingsChanged(); break;
        case 5: _t->sync(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QmmpSettings::*)();
            if (_t _q_method = &QmmpSettings::replayGainSettingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QmmpSettings::*)();
            if (_t _q_method = &QmmpSettings::audioSettingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QmmpSettings::*)();
            if (_t _q_method = &QmmpSettings::coverSettingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QmmpSettings::*)();
            if (_t _q_method = &QmmpSettings::networkSettingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QmmpSettings::*)();
            if (_t _q_method = &QmmpSettings::eqSettingsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *QmmpSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmmpSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmmpSettingsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QmmpSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QmmpSettings::replayGainSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QmmpSettings::audioSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QmmpSettings::coverSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QmmpSettings::networkSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QmmpSettings::eqSettingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP

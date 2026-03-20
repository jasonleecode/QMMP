/****************************************************************************
** Meta object code from reading C++ file 'root2object.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/mpris/root2object.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'root2object.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRoot2ObjectENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRoot2ObjectENDCLASS = QtMocHelpers::stringData(
    "Root2Object",
    "D-Bus Interface",
    "org.mpris.MediaPlayer2",
    "Quit",
    "",
    "Raise",
    "CanQuit",
    "CanRaise",
    "DesktopEntry",
    "HasTrackList",
    "Identity",
    "SupportedMimeTypes",
    "SupportedUriSchemes"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRoot2ObjectENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[23];
    char stringdata3[5];
    char stringdata4[1];
    char stringdata5[6];
    char stringdata6[8];
    char stringdata7[9];
    char stringdata8[13];
    char stringdata9[13];
    char stringdata10[9];
    char stringdata11[19];
    char stringdata12[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRoot2ObjectENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRoot2ObjectENDCLASS_t qt_meta_stringdata_CLASSRoot2ObjectENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "Root2Object"
        QT_MOC_LITERAL(12, 15),  // "D-Bus Interface"
        QT_MOC_LITERAL(28, 22),  // "org.mpris.MediaPlayer2"
        QT_MOC_LITERAL(51, 4),  // "Quit"
        QT_MOC_LITERAL(56, 0),  // ""
        QT_MOC_LITERAL(57, 5),  // "Raise"
        QT_MOC_LITERAL(63, 7),  // "CanQuit"
        QT_MOC_LITERAL(71, 8),  // "CanRaise"
        QT_MOC_LITERAL(80, 12),  // "DesktopEntry"
        QT_MOC_LITERAL(93, 12),  // "HasTrackList"
        QT_MOC_LITERAL(106, 8),  // "Identity"
        QT_MOC_LITERAL(115, 18),  // "SupportedMimeTypes"
        QT_MOC_LITERAL(134, 19)   // "SupportedUriSchemes"
    },
    "Root2Object",
    "D-Bus Interface",
    "org.mpris.MediaPlayer2",
    "Quit",
    "",
    "Raise",
    "CanQuit",
    "CanRaise",
    "DesktopEntry",
    "HasTrackList",
    "Identity",
    "SupportedMimeTypes",
    "SupportedUriSchemes"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRoot2ObjectENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       7,   30, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   28,    4, 0x0a,    8 /* Public */,
       5,    0,   29,    4, 0x0a,    9 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x00015001, uint(-1), 0,
       7, QMetaType::Bool, 0x00015001, uint(-1), 0,
       8, QMetaType::QString, 0x00015001, uint(-1), 0,
       9, QMetaType::Bool, 0x00015001, uint(-1), 0,
      10, QMetaType::QString, 0x00015001, uint(-1), 0,
      11, QMetaType::QStringList, 0x00015001, uint(-1), 0,
      12, QMetaType::QStringList, 0x00015001, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Root2Object::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_CLASSRoot2ObjectENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRoot2ObjectENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRoot2ObjectENDCLASS_t,
        // property 'CanQuit'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'CanRaise'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'DesktopEntry'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'HasTrackList'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'Identity'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'SupportedMimeTypes'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'SupportedUriSchemes'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Root2Object, std::true_type>,
        // method 'Quit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Raise'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Root2Object::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Root2Object *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Quit(); break;
        case 1: _t->Raise(); break;
        default: ;
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Root2Object *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->canQuit(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->canRaise(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->desktopEntry(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->hasTrackList(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->identity(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->supportedMimeTypes(); break;
        case 6: *reinterpret_cast< QStringList*>(_v) = _t->supportedUriSchemes(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *Root2Object::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Root2Object::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRoot2ObjectENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int Root2Object::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP

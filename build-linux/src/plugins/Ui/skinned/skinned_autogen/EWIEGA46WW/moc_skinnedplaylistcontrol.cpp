/****************************************************************************
** Meta object code from reading C++ file 'skinnedplaylistcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/skinned/skinnedplaylistcontrol.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skinnedplaylistcontrol.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS = QtMocHelpers::stringData(
    "SkinnedPlaylistControl",
    "previousClicked",
    "",
    "nextClicked",
    "pauseClicked",
    "playClicked",
    "stopClicked",
    "ejectClicked",
    "updateSkin"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[23];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[13];
    char stringdata5[12];
    char stringdata6[12];
    char stringdata7[13];
    char stringdata8[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS_t qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "SkinnedPlaylistControl"
        QT_MOC_LITERAL(23, 15),  // "previousClicked"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 11),  // "nextClicked"
        QT_MOC_LITERAL(52, 12),  // "pauseClicked"
        QT_MOC_LITERAL(65, 11),  // "playClicked"
        QT_MOC_LITERAL(77, 11),  // "stopClicked"
        QT_MOC_LITERAL(89, 12),  // "ejectClicked"
        QT_MOC_LITERAL(102, 10)   // "updateSkin"
    },
    "SkinnedPlaylistControl",
    "previousClicked",
    "",
    "nextClicked",
    "pauseClicked",
    "playClicked",
    "stopClicked",
    "ejectClicked",
    "updateSkin"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSkinnedPlaylistControlENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    0,   58,    2, 0x06,    3 /* Public */,
       5,    0,   59,    2, 0x06,    4 /* Public */,
       6,    0,   60,    2, 0x06,    5 /* Public */,
       7,    0,   61,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SkinnedPlaylistControl::staticMetaObject = { {
    QMetaObject::SuperData::link<PixmapWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSkinnedPlaylistControlENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SkinnedPlaylistControl, std::true_type>,
        // method 'previousClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'nextClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pauseClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ejectClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSkin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SkinnedPlaylistControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SkinnedPlaylistControl *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->previousClicked(); break;
        case 1: _t->nextClicked(); break;
        case 2: _t->pauseClicked(); break;
        case 3: _t->playClicked(); break;
        case 4: _t->stopClicked(); break;
        case 5: _t->ejectClicked(); break;
        case 6: _t->updateSkin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SkinnedPlaylistControl::*)();
            if (_t _q_method = &SkinnedPlaylistControl::previousClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SkinnedPlaylistControl::*)();
            if (_t _q_method = &SkinnedPlaylistControl::nextClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SkinnedPlaylistControl::*)();
            if (_t _q_method = &SkinnedPlaylistControl::pauseClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SkinnedPlaylistControl::*)();
            if (_t _q_method = &SkinnedPlaylistControl::playClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SkinnedPlaylistControl::*)();
            if (_t _q_method = &SkinnedPlaylistControl::stopClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SkinnedPlaylistControl::*)();
            if (_t _q_method = &SkinnedPlaylistControl::ejectClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *SkinnedPlaylistControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SkinnedPlaylistControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSkinnedPlaylistControlENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return PixmapWidget::qt_metacast(_clname);
}

int SkinnedPlaylistControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PixmapWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SkinnedPlaylistControl::previousClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SkinnedPlaylistControl::nextClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SkinnedPlaylistControl::pauseClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SkinnedPlaylistControl::playClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SkinnedPlaylistControl::stopClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SkinnedPlaylistControl::ejectClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP

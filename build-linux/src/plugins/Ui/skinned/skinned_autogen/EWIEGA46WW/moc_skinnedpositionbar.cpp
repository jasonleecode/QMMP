/****************************************************************************
** Meta object code from reading C++ file 'skinnedpositionbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/skinned/skinnedpositionbar.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skinnedpositionbar.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS = QtMocHelpers::stringData(
    "SkinnedPositionBar",
    "sliderMoved",
    "",
    "sliderPressed",
    "sliderReleased",
    "setValue",
    "setMaximum",
    "updateSkin"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[19];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[15];
    char stringdata5[9];
    char stringdata6[11];
    char stringdata7[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS_t qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "SkinnedPositionBar"
        QT_MOC_LITERAL(19, 11),  // "sliderMoved"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 13),  // "sliderPressed"
        QT_MOC_LITERAL(46, 14),  // "sliderReleased"
        QT_MOC_LITERAL(61, 8),  // "setValue"
        QT_MOC_LITERAL(70, 10),  // "setMaximum"
        QT_MOC_LITERAL(81, 10)   // "updateSkin"
    },
    "SkinnedPositionBar",
    "sliderMoved",
    "",
    "sliderPressed",
    "sliderReleased",
    "setValue",
    "setMaximum",
    "updateSkin"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSkinnedPositionBarENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       3,    0,   53,    2, 0x06,    3 /* Public */,
       4,    0,   54,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   55,    2, 0x0a,    5 /* Public */,
       6,    1,   58,    2, 0x0a,    7 /* Public */,
       7,    0,   61,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SkinnedPositionBar::staticMetaObject = { {
    QMetaObject::SuperData::link<PixmapWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSkinnedPositionBarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SkinnedPositionBar, std::true_type>,
        // method 'sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'setMaximum'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'updateSkin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SkinnedPositionBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SkinnedPositionBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sliderMoved((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 1: _t->sliderPressed(); break;
        case 2: _t->sliderReleased(); break;
        case 3: _t->setValue((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 4: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->updateSkin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SkinnedPositionBar::*)(qint64 );
            if (_t _q_method = &SkinnedPositionBar::sliderMoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SkinnedPositionBar::*)();
            if (_t _q_method = &SkinnedPositionBar::sliderPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SkinnedPositionBar::*)();
            if (_t _q_method = &SkinnedPositionBar::sliderReleased; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *SkinnedPositionBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SkinnedPositionBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSkinnedPositionBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return PixmapWidget::qt_metacast(_clname);
}

int SkinnedPositionBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PixmapWidget::qt_metacall(_c, _id, _a);
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
void SkinnedPositionBar::sliderMoved(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SkinnedPositionBar::sliderPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SkinnedPositionBar::sliderReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

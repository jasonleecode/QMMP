/****************************************************************************
** Meta object code from reading C++ file 'qsuistatusbar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/qsui/qsuistatusbar.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsuistatusbar.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS = QtMocHelpers::stringData(
    "QSUiStatusBar",
    "onStateChanged",
    "",
    "Qmmp::State",
    "state",
    "onBufferingProgress",
    "percent",
    "onAudioParametersChanged",
    "AudioParameters",
    "ap",
    "onBitrateChanged",
    "bitrate",
    "onElapsedChanged",
    "elapsed",
    "onTrackInfoChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[14];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[6];
    char stringdata5[20];
    char stringdata6[8];
    char stringdata7[25];
    char stringdata8[16];
    char stringdata9[3];
    char stringdata10[17];
    char stringdata11[8];
    char stringdata12[17];
    char stringdata13[8];
    char stringdata14[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS_t qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QSUiStatusBar"
        QT_MOC_LITERAL(14, 14),  // "onStateChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 11),  // "Qmmp::State"
        QT_MOC_LITERAL(42, 5),  // "state"
        QT_MOC_LITERAL(48, 19),  // "onBufferingProgress"
        QT_MOC_LITERAL(68, 7),  // "percent"
        QT_MOC_LITERAL(76, 24),  // "onAudioParametersChanged"
        QT_MOC_LITERAL(101, 15),  // "AudioParameters"
        QT_MOC_LITERAL(117, 2),  // "ap"
        QT_MOC_LITERAL(120, 16),  // "onBitrateChanged"
        QT_MOC_LITERAL(137, 7),  // "bitrate"
        QT_MOC_LITERAL(145, 16),  // "onElapsedChanged"
        QT_MOC_LITERAL(162, 7),  // "elapsed"
        QT_MOC_LITERAL(170, 18)   // "onTrackInfoChanged"
    },
    "QSUiStatusBar",
    "onStateChanged",
    "",
    "Qmmp::State",
    "state",
    "onBufferingProgress",
    "percent",
    "onAudioParametersChanged",
    "AudioParameters",
    "ap",
    "onBitrateChanged",
    "bitrate",
    "onElapsedChanged",
    "elapsed",
    "onTrackInfoChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQSUiStatusBarENDCLASS[] = {

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
       5,    1,   53,    2, 0x08,    3 /* Private */,
       7,    1,   56,    2, 0x08,    5 /* Private */,
      10,    1,   59,    2, 0x08,    7 /* Private */,
      12,    1,   62,    2, 0x08,    9 /* Private */,
      14,    0,   65,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::LongLong,   13,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject QSUiStatusBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQSUiStatusBarENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QSUiStatusBar, std::true_type>,
        // method 'onStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qmmp::State, std::false_type>,
        // method 'onBufferingProgress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onAudioParametersChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const AudioParameters &, std::false_type>,
        // method 'onBitrateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onElapsedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'onTrackInfoChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QSUiStatusBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSUiStatusBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onStateChanged((*reinterpret_cast< std::add_pointer_t<Qmmp::State>>(_a[1]))); break;
        case 1: _t->onBufferingProgress((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->onAudioParametersChanged((*reinterpret_cast< std::add_pointer_t<AudioParameters>>(_a[1]))); break;
        case 3: _t->onBitrateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onElapsedChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->onTrackInfoChanged(); break;
        default: ;
        }
    }
}

const QMetaObject *QSUiStatusBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSUiStatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQSUiStatusBarENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QSUiStatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

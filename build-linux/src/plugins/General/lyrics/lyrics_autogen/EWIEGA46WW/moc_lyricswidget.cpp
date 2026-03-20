/****************************************************************************
** Meta object code from reading C++ file 'lyricswidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/lyrics/lyricswidget.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lyricswidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLyricsWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSLyricsWidgetENDCLASS = QtMocHelpers::stringData(
    "LyricsWidget",
    "onRequestFinished",
    "",
    "QNetworkReply*",
    "reply",
    "on_refreshButton_clicked",
    "on_editButton_clicked",
    "checked",
    "on_providerComboBox_activated",
    "index",
    "loadFromTag",
    "path",
    "loadFromCache",
    "saveToCache",
    "text"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLyricsWidgetENDCLASS_t {
    uint offsetsAndSizes[30];
    char stringdata0[13];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[6];
    char stringdata5[25];
    char stringdata6[22];
    char stringdata7[8];
    char stringdata8[30];
    char stringdata9[6];
    char stringdata10[12];
    char stringdata11[5];
    char stringdata12[14];
    char stringdata13[12];
    char stringdata14[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLyricsWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLyricsWidgetENDCLASS_t qt_meta_stringdata_CLASSLyricsWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "LyricsWidget"
        QT_MOC_LITERAL(13, 17),  // "onRequestFinished"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(47, 5),  // "reply"
        QT_MOC_LITERAL(53, 24),  // "on_refreshButton_clicked"
        QT_MOC_LITERAL(78, 21),  // "on_editButton_clicked"
        QT_MOC_LITERAL(100, 7),  // "checked"
        QT_MOC_LITERAL(108, 29),  // "on_providerComboBox_activated"
        QT_MOC_LITERAL(138, 5),  // "index"
        QT_MOC_LITERAL(144, 11),  // "loadFromTag"
        QT_MOC_LITERAL(156, 4),  // "path"
        QT_MOC_LITERAL(161, 13),  // "loadFromCache"
        QT_MOC_LITERAL(175, 11),  // "saveToCache"
        QT_MOC_LITERAL(187, 4)   // "text"
    },
    "LyricsWidget",
    "onRequestFinished",
    "",
    "QNetworkReply*",
    "reply",
    "on_refreshButton_clicked",
    "on_editButton_clicked",
    "checked",
    "on_providerComboBox_activated",
    "index",
    "loadFromTag",
    "path",
    "loadFromCache",
    "saveToCache",
    "text"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLyricsWidgetENDCLASS[] = {

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
       1,    1,   56,    2, 0x08,    1 /* Private */,
       5,    0,   59,    2, 0x08,    3 /* Private */,
       6,    1,   60,    2, 0x08,    4 /* Private */,
       8,    1,   63,    2, 0x08,    6 /* Private */,
      10,    1,   66,    2, 0x08,    8 /* Private */,
      12,    0,   69,    2, 0x08,   10 /* Private */,
      13,    1,   70,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,   14,

       0        // eod
};

Q_CONSTINIT const QMetaObject LyricsWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSLyricsWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLyricsWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLyricsWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LyricsWidget, std::true_type>,
        // method 'onRequestFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'on_refreshButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_providerComboBox_activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'loadFromTag'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadFromCache'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'saveToCache'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void LyricsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LyricsWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onRequestFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 1: _t->on_refreshButton_clicked(); break;
        case 2: _t->on_editButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_providerComboBox_activated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: { bool _r = _t->loadFromTag((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->loadFromCache();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->saveToCache((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *LyricsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LyricsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLyricsWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LyricsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

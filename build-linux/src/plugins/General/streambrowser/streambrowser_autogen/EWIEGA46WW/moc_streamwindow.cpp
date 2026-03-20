/****************************************************************************
** Meta object code from reading C++ file 'streamwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/General/streambrowser/streamwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'streamwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSStreamWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSStreamWindowENDCLASS = QtMocHelpers::stringData(
    "StreamWindow",
    "showText",
    "",
    "QNetworkReply*",
    "reply",
    "on_updatePushButton_clicked",
    "on_addPushButton_clicked",
    "on_filterLineEdit_textChanged",
    "text",
    "execIceCastMenu",
    "pos",
    "execFavoritesMenu",
    "addToFavorites",
    "createStream",
    "editStream",
    "removeFromFavorites"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSStreamWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[13];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[6];
    char stringdata5[28];
    char stringdata6[25];
    char stringdata7[30];
    char stringdata8[5];
    char stringdata9[16];
    char stringdata10[4];
    char stringdata11[18];
    char stringdata12[15];
    char stringdata13[13];
    char stringdata14[11];
    char stringdata15[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSStreamWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSStreamWindowENDCLASS_t qt_meta_stringdata_CLASSStreamWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "StreamWindow"
        QT_MOC_LITERAL(13, 8),  // "showText"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 14),  // "QNetworkReply*"
        QT_MOC_LITERAL(38, 5),  // "reply"
        QT_MOC_LITERAL(44, 27),  // "on_updatePushButton_clicked"
        QT_MOC_LITERAL(72, 24),  // "on_addPushButton_clicked"
        QT_MOC_LITERAL(97, 29),  // "on_filterLineEdit_textChanged"
        QT_MOC_LITERAL(127, 4),  // "text"
        QT_MOC_LITERAL(132, 15),  // "execIceCastMenu"
        QT_MOC_LITERAL(148, 3),  // "pos"
        QT_MOC_LITERAL(152, 17),  // "execFavoritesMenu"
        QT_MOC_LITERAL(170, 14),  // "addToFavorites"
        QT_MOC_LITERAL(185, 12),  // "createStream"
        QT_MOC_LITERAL(198, 10),  // "editStream"
        QT_MOC_LITERAL(209, 19)   // "removeFromFavorites"
    },
    "StreamWindow",
    "showText",
    "",
    "QNetworkReply*",
    "reply",
    "on_updatePushButton_clicked",
    "on_addPushButton_clicked",
    "on_filterLineEdit_textChanged",
    "text",
    "execIceCastMenu",
    "pos",
    "execFavoritesMenu",
    "addToFavorites",
    "createStream",
    "editStream",
    "removeFromFavorites"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStreamWindowENDCLASS[] = {

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
       1,    1,   74,    2, 0x08,    1 /* Private */,
       5,    0,   77,    2, 0x08,    3 /* Private */,
       6,    0,   78,    2, 0x08,    4 /* Private */,
       7,    1,   79,    2, 0x08,    5 /* Private */,
       9,    1,   82,    2, 0x08,    7 /* Private */,
      11,    1,   85,    2, 0x08,    9 /* Private */,
      12,    0,   88,    2, 0x08,   11 /* Private */,
      13,    0,   89,    2, 0x08,   12 /* Private */,
      14,    0,   90,    2, 0x08,   13 /* Private */,
      15,    0,   91,    2, 0x08,   14 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void, QMetaType::QPoint,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject StreamWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSStreamWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStreamWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSStreamWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StreamWindow, std::true_type>,
        // method 'showText'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'on_updatePushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addPushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_filterLineEdit_textChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'execIceCastMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'execFavoritesMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>,
        // method 'addToFavorites'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createStream'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editStream'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeFromFavorites'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void StreamWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<StreamWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showText((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 1: _t->on_updatePushButton_clicked(); break;
        case 2: _t->on_addPushButton_clicked(); break;
        case 3: _t->on_filterLineEdit_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->execIceCastMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 5: _t->execFavoritesMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 6: _t->addToFavorites(); break;
        case 7: _t->createStream(); break;
        case 8: _t->editStream(); break;
        case 9: _t->removeFromFavorites(); break;
        default: ;
        }
    }
}

const QMetaObject *StreamWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StreamWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStreamWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StreamWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS = QtMocHelpers::stringData(
    "StreamsProxyModel"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS_t qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17)   // "StreamsProxyModel"
    },
    "StreamsProxyModel"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSStreamsProxyModelENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject StreamsProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSortFilterProxyModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSStreamsProxyModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<StreamsProxyModel, std::true_type>
    >,
    nullptr
} };

void StreamsProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *StreamsProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StreamsProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSStreamsProxyModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int StreamsProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP

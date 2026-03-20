/****************************************************************************
** Meta object code from reading C++ file 'skinnedplaylist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Ui/skinned/skinnedplaylist.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skinnedplaylist.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS = QtMocHelpers::stringData(
    "SkinnedPlayList",
    "play",
    "",
    "next",
    "prev",
    "pause",
    "stop",
    "eject",
    "loadPlaylist",
    "savePlaylist",
    "closed",
    "setTime",
    "time",
    "readSettings",
    "showAddMenu",
    "showSubMenu",
    "showSelectMenu",
    "showSortMenu",
    "showPlaylistMenu",
    "updateSkin",
    "deletePlaylist",
    "renamePlaylist",
    "showPlayLists",
    "generateCopySelectedMenu",
    "copySelectedMenuActionTriggered",
    "QAction*",
    "action",
    "onCurrentPlayListChanged",
    "PlayListModel*",
    "current",
    "previous",
    "onListChanged",
    "flags"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS_t {
    uint offsetsAndSizes[66];
    char stringdata0[16];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[5];
    char stringdata5[6];
    char stringdata6[5];
    char stringdata7[6];
    char stringdata8[13];
    char stringdata9[13];
    char stringdata10[7];
    char stringdata11[8];
    char stringdata12[5];
    char stringdata13[13];
    char stringdata14[12];
    char stringdata15[12];
    char stringdata16[15];
    char stringdata17[13];
    char stringdata18[17];
    char stringdata19[11];
    char stringdata20[15];
    char stringdata21[15];
    char stringdata22[14];
    char stringdata23[25];
    char stringdata24[32];
    char stringdata25[9];
    char stringdata26[7];
    char stringdata27[25];
    char stringdata28[15];
    char stringdata29[8];
    char stringdata30[9];
    char stringdata31[14];
    char stringdata32[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS_t qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "SkinnedPlayList"
        QT_MOC_LITERAL(16, 4),  // "play"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 4),  // "next"
        QT_MOC_LITERAL(27, 4),  // "prev"
        QT_MOC_LITERAL(32, 5),  // "pause"
        QT_MOC_LITERAL(38, 4),  // "stop"
        QT_MOC_LITERAL(43, 5),  // "eject"
        QT_MOC_LITERAL(49, 12),  // "loadPlaylist"
        QT_MOC_LITERAL(62, 12),  // "savePlaylist"
        QT_MOC_LITERAL(75, 6),  // "closed"
        QT_MOC_LITERAL(82, 7),  // "setTime"
        QT_MOC_LITERAL(90, 4),  // "time"
        QT_MOC_LITERAL(95, 12),  // "readSettings"
        QT_MOC_LITERAL(108, 11),  // "showAddMenu"
        QT_MOC_LITERAL(120, 11),  // "showSubMenu"
        QT_MOC_LITERAL(132, 14),  // "showSelectMenu"
        QT_MOC_LITERAL(147, 12),  // "showSortMenu"
        QT_MOC_LITERAL(160, 16),  // "showPlaylistMenu"
        QT_MOC_LITERAL(177, 10),  // "updateSkin"
        QT_MOC_LITERAL(188, 14),  // "deletePlaylist"
        QT_MOC_LITERAL(203, 14),  // "renamePlaylist"
        QT_MOC_LITERAL(218, 13),  // "showPlayLists"
        QT_MOC_LITERAL(232, 24),  // "generateCopySelectedMenu"
        QT_MOC_LITERAL(257, 31),  // "copySelectedMenuActionTriggered"
        QT_MOC_LITERAL(289, 8),  // "QAction*"
        QT_MOC_LITERAL(298, 6),  // "action"
        QT_MOC_LITERAL(305, 24),  // "onCurrentPlayListChanged"
        QT_MOC_LITERAL(330, 14),  // "PlayListModel*"
        QT_MOC_LITERAL(345, 7),  // "current"
        QT_MOC_LITERAL(353, 8),  // "previous"
        QT_MOC_LITERAL(362, 13),  // "onListChanged"
        QT_MOC_LITERAL(376, 5)   // "flags"
    },
    "SkinnedPlayList",
    "play",
    "",
    "next",
    "prev",
    "pause",
    "stop",
    "eject",
    "loadPlaylist",
    "savePlaylist",
    "closed",
    "setTime",
    "time",
    "readSettings",
    "showAddMenu",
    "showSubMenu",
    "showSelectMenu",
    "showSortMenu",
    "showPlaylistMenu",
    "updateSkin",
    "deletePlaylist",
    "renamePlaylist",
    "showPlayLists",
    "generateCopySelectedMenu",
    "copySelectedMenuActionTriggered",
    "QAction*",
    "action",
    "onCurrentPlayListChanged",
    "PlayListModel*",
    "current",
    "previous",
    "onListChanged",
    "flags"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSkinnedPlayListENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  158,    2, 0x06,    1 /* Public */,
       3,    0,  159,    2, 0x06,    2 /* Public */,
       4,    0,  160,    2, 0x06,    3 /* Public */,
       5,    0,  161,    2, 0x06,    4 /* Public */,
       6,    0,  162,    2, 0x06,    5 /* Public */,
       7,    0,  163,    2, 0x06,    6 /* Public */,
       8,    0,  164,    2, 0x06,    7 /* Public */,
       9,    0,  165,    2, 0x06,    8 /* Public */,
      10,    0,  166,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,  167,    2, 0x0a,   10 /* Public */,
      13,    0,  170,    2, 0x0a,   12 /* Public */,
      14,    0,  171,    2, 0x08,   13 /* Private */,
      15,    0,  172,    2, 0x08,   14 /* Private */,
      16,    0,  173,    2, 0x08,   15 /* Private */,
      17,    0,  174,    2, 0x08,   16 /* Private */,
      18,    0,  175,    2, 0x08,   17 /* Private */,
      19,    0,  176,    2, 0x08,   18 /* Private */,
      20,    0,  177,    2, 0x08,   19 /* Private */,
      21,    0,  178,    2, 0x08,   20 /* Private */,
      22,    0,  179,    2, 0x08,   21 /* Private */,
      23,    0,  180,    2, 0x08,   22 /* Private */,
      24,    1,  181,    2, 0x08,   23 /* Private */,
      27,    2,  184,    2, 0x08,   25 /* Private */,
      31,    1,  189,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 28, 0x80000000 | 28,   29,   30,
    QMetaType::Void, QMetaType::Int,   32,

       0        // eod
};

Q_CONSTINIT const QMetaObject SkinnedPlayList::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSkinnedPlayListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SkinnedPlayList, std::true_type>,
        // method 'play'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'next'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prev'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'eject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadPlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'savePlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'readSettings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showAddMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showSubMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showSelectMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showSortMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showPlaylistMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateSkin'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deletePlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'renamePlaylist'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showPlayLists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'generateCopySelectedMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'copySelectedMenuActionTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAction *, std::false_type>,
        // method 'onCurrentPlayListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'onListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SkinnedPlayList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SkinnedPlayList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->next(); break;
        case 2: _t->prev(); break;
        case 3: _t->pause(); break;
        case 4: _t->stop(); break;
        case 5: _t->eject(); break;
        case 6: _t->loadPlaylist(); break;
        case 7: _t->savePlaylist(); break;
        case 8: _t->closed(); break;
        case 9: _t->setTime((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 10: _t->readSettings(); break;
        case 11: _t->showAddMenu(); break;
        case 12: _t->showSubMenu(); break;
        case 13: _t->showSelectMenu(); break;
        case 14: _t->showSortMenu(); break;
        case 15: _t->showPlaylistMenu(); break;
        case 16: _t->updateSkin(); break;
        case 17: _t->deletePlaylist(); break;
        case 18: _t->renamePlaylist(); break;
        case 19: _t->showPlayLists(); break;
        case 20: _t->generateCopySelectedMenu(); break;
        case 21: _t->copySelectedMenuActionTriggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 22: _t->onCurrentPlayListChanged((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[2]))); break;
        case 23: _t->onListChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::play; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::next; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::prev; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::pause; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::stop; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::eject; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::loadPlaylist; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::savePlaylist; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SkinnedPlayList::*)();
            if (_t _q_method = &SkinnedPlayList::closed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject *SkinnedPlayList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SkinnedPlayList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSkinnedPlayListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SkinnedPlayList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void SkinnedPlayList::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SkinnedPlayList::next()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SkinnedPlayList::prev()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SkinnedPlayList::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SkinnedPlayList::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void SkinnedPlayList::eject()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void SkinnedPlayList::loadPlaylist()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SkinnedPlayList::savePlaylist()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SkinnedPlayList::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'playlistmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qmmpui/playlistmanager.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistmanager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSPlayListManagerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPlayListManagerENDCLASS = QtMocHelpers::stringData(
    "PlayListManager",
    "currentPlayListChanged",
    "",
    "PlayListModel*",
    "current",
    "previous",
    "selectedPlayListChanged",
    "selected",
    "playListAdded",
    "index",
    "playListRemoved",
    "playListMoved",
    "i",
    "j",
    "playListsChanged",
    "currentTrackRemoved",
    "selectPlayList",
    "model",
    "selectPlayListIndex",
    "selectPlayListName",
    "name",
    "selectNextPlayList",
    "selectPreviousPlayList",
    "activatePlayList",
    "activatePlayListIndex",
    "activateSelectedPlayList",
    "createPlayList",
    "removePlayList",
    "removePlayListIndex",
    "move",
    "clear",
    "clearSelection",
    "removeSelected",
    "removeUnselected",
    "removeTrack",
    "PlayListTrack*",
    "item",
    "invertSelection",
    "selectAll",
    "showDetails",
    "addTracks",
    "QList<PlayListTrack*>",
    "tracks",
    "addPath",
    "path",
    "addPaths",
    "paths",
    "randomizeList",
    "reverseList",
    "sortSelection",
    "PlayListModel::SortMode",
    "mode",
    "sort",
    "addToQueue",
    "removeInvalidTracks",
    "removeDuplicates",
    "refresh",
    "clearQueue",
    "stopAfterSelected",
    "rebuildGroups",
    "writePlayLists",
    "onListChanged",
    "flags",
    "onCurrentTrackRemoved"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlayListManagerENDCLASS_t {
    uint offsetsAndSizes[128];
    char stringdata0[16];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[8];
    char stringdata5[9];
    char stringdata6[24];
    char stringdata7[9];
    char stringdata8[14];
    char stringdata9[6];
    char stringdata10[16];
    char stringdata11[14];
    char stringdata12[2];
    char stringdata13[2];
    char stringdata14[17];
    char stringdata15[20];
    char stringdata16[15];
    char stringdata17[6];
    char stringdata18[20];
    char stringdata19[19];
    char stringdata20[5];
    char stringdata21[19];
    char stringdata22[23];
    char stringdata23[17];
    char stringdata24[22];
    char stringdata25[25];
    char stringdata26[15];
    char stringdata27[15];
    char stringdata28[20];
    char stringdata29[5];
    char stringdata30[6];
    char stringdata31[15];
    char stringdata32[15];
    char stringdata33[17];
    char stringdata34[12];
    char stringdata35[15];
    char stringdata36[5];
    char stringdata37[16];
    char stringdata38[10];
    char stringdata39[12];
    char stringdata40[10];
    char stringdata41[22];
    char stringdata42[7];
    char stringdata43[8];
    char stringdata44[5];
    char stringdata45[9];
    char stringdata46[6];
    char stringdata47[14];
    char stringdata48[12];
    char stringdata49[14];
    char stringdata50[24];
    char stringdata51[5];
    char stringdata52[5];
    char stringdata53[11];
    char stringdata54[20];
    char stringdata55[17];
    char stringdata56[8];
    char stringdata57[11];
    char stringdata58[18];
    char stringdata59[14];
    char stringdata60[15];
    char stringdata61[14];
    char stringdata62[6];
    char stringdata63[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlayListManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlayListManagerENDCLASS_t qt_meta_stringdata_CLASSPlayListManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "PlayListManager"
        QT_MOC_LITERAL(16, 22),  // "currentPlayListChanged"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 14),  // "PlayListModel*"
        QT_MOC_LITERAL(55, 7),  // "current"
        QT_MOC_LITERAL(63, 8),  // "previous"
        QT_MOC_LITERAL(72, 23),  // "selectedPlayListChanged"
        QT_MOC_LITERAL(96, 8),  // "selected"
        QT_MOC_LITERAL(105, 13),  // "playListAdded"
        QT_MOC_LITERAL(119, 5),  // "index"
        QT_MOC_LITERAL(125, 15),  // "playListRemoved"
        QT_MOC_LITERAL(141, 13),  // "playListMoved"
        QT_MOC_LITERAL(155, 1),  // "i"
        QT_MOC_LITERAL(157, 1),  // "j"
        QT_MOC_LITERAL(159, 16),  // "playListsChanged"
        QT_MOC_LITERAL(176, 19),  // "currentTrackRemoved"
        QT_MOC_LITERAL(196, 14),  // "selectPlayList"
        QT_MOC_LITERAL(211, 5),  // "model"
        QT_MOC_LITERAL(217, 19),  // "selectPlayListIndex"
        QT_MOC_LITERAL(237, 18),  // "selectPlayListName"
        QT_MOC_LITERAL(256, 4),  // "name"
        QT_MOC_LITERAL(261, 18),  // "selectNextPlayList"
        QT_MOC_LITERAL(280, 22),  // "selectPreviousPlayList"
        QT_MOC_LITERAL(303, 16),  // "activatePlayList"
        QT_MOC_LITERAL(320, 21),  // "activatePlayListIndex"
        QT_MOC_LITERAL(342, 24),  // "activateSelectedPlayList"
        QT_MOC_LITERAL(367, 14),  // "createPlayList"
        QT_MOC_LITERAL(382, 14),  // "removePlayList"
        QT_MOC_LITERAL(397, 19),  // "removePlayListIndex"
        QT_MOC_LITERAL(417, 4),  // "move"
        QT_MOC_LITERAL(422, 5),  // "clear"
        QT_MOC_LITERAL(428, 14),  // "clearSelection"
        QT_MOC_LITERAL(443, 14),  // "removeSelected"
        QT_MOC_LITERAL(458, 16),  // "removeUnselected"
        QT_MOC_LITERAL(475, 11),  // "removeTrack"
        QT_MOC_LITERAL(487, 14),  // "PlayListTrack*"
        QT_MOC_LITERAL(502, 4),  // "item"
        QT_MOC_LITERAL(507, 15),  // "invertSelection"
        QT_MOC_LITERAL(523, 9),  // "selectAll"
        QT_MOC_LITERAL(533, 11),  // "showDetails"
        QT_MOC_LITERAL(545, 9),  // "addTracks"
        QT_MOC_LITERAL(555, 21),  // "QList<PlayListTrack*>"
        QT_MOC_LITERAL(577, 6),  // "tracks"
        QT_MOC_LITERAL(584, 7),  // "addPath"
        QT_MOC_LITERAL(592, 4),  // "path"
        QT_MOC_LITERAL(597, 8),  // "addPaths"
        QT_MOC_LITERAL(606, 5),  // "paths"
        QT_MOC_LITERAL(612, 13),  // "randomizeList"
        QT_MOC_LITERAL(626, 11),  // "reverseList"
        QT_MOC_LITERAL(638, 13),  // "sortSelection"
        QT_MOC_LITERAL(652, 23),  // "PlayListModel::SortMode"
        QT_MOC_LITERAL(676, 4),  // "mode"
        QT_MOC_LITERAL(681, 4),  // "sort"
        QT_MOC_LITERAL(686, 10),  // "addToQueue"
        QT_MOC_LITERAL(697, 19),  // "removeInvalidTracks"
        QT_MOC_LITERAL(717, 16),  // "removeDuplicates"
        QT_MOC_LITERAL(734, 7),  // "refresh"
        QT_MOC_LITERAL(742, 10),  // "clearQueue"
        QT_MOC_LITERAL(753, 17),  // "stopAfterSelected"
        QT_MOC_LITERAL(771, 13),  // "rebuildGroups"
        QT_MOC_LITERAL(785, 14),  // "writePlayLists"
        QT_MOC_LITERAL(800, 13),  // "onListChanged"
        QT_MOC_LITERAL(814, 5),  // "flags"
        QT_MOC_LITERAL(820, 21)   // "onCurrentTrackRemoved"
    },
    "PlayListManager",
    "currentPlayListChanged",
    "",
    "PlayListModel*",
    "current",
    "previous",
    "selectedPlayListChanged",
    "selected",
    "playListAdded",
    "index",
    "playListRemoved",
    "playListMoved",
    "i",
    "j",
    "playListsChanged",
    "currentTrackRemoved",
    "selectPlayList",
    "model",
    "selectPlayListIndex",
    "selectPlayListName",
    "name",
    "selectNextPlayList",
    "selectPreviousPlayList",
    "activatePlayList",
    "activatePlayListIndex",
    "activateSelectedPlayList",
    "createPlayList",
    "removePlayList",
    "removePlayListIndex",
    "move",
    "clear",
    "clearSelection",
    "removeSelected",
    "removeUnselected",
    "removeTrack",
    "PlayListTrack*",
    "item",
    "invertSelection",
    "selectAll",
    "showDetails",
    "addTracks",
    "QList<PlayListTrack*>",
    "tracks",
    "addPath",
    "path",
    "addPaths",
    "paths",
    "randomizeList",
    "reverseList",
    "sortSelection",
    "PlayListModel::SortMode",
    "mode",
    "sort",
    "addToQueue",
    "removeInvalidTracks",
    "removeDuplicates",
    "refresh",
    "clearQueue",
    "stopAfterSelected",
    "rebuildGroups",
    "writePlayLists",
    "onListChanged",
    "flags",
    "onCurrentTrackRemoved"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlayListManagerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      46,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  290,    2, 0x06,    1 /* Public */,
       6,    2,  295,    2, 0x06,    4 /* Public */,
       8,    1,  300,    2, 0x06,    7 /* Public */,
      10,    1,  303,    2, 0x06,    9 /* Public */,
      11,    2,  306,    2, 0x06,   11 /* Public */,
      14,    0,  311,    2, 0x06,   14 /* Public */,
      15,    0,  312,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    1,  313,    2, 0x0a,   16 /* Public */,
      18,    1,  316,    2, 0x0a,   18 /* Public */,
      19,    1,  319,    2, 0x0a,   20 /* Public */,
      21,    0,  322,    2, 0x0a,   22 /* Public */,
      22,    0,  323,    2, 0x0a,   23 /* Public */,
      23,    1,  324,    2, 0x0a,   24 /* Public */,
      24,    1,  327,    2, 0x0a,   26 /* Public */,
      25,    0,  330,    2, 0x0a,   28 /* Public */,
      26,    1,  331,    2, 0x0a,   29 /* Public */,
      26,    0,  334,    2, 0x2a,   31 /* Public | MethodCloned */,
      27,    1,  335,    2, 0x0a,   32 /* Public */,
      28,    1,  338,    2, 0x0a,   34 /* Public */,
      29,    2,  341,    2, 0x0a,   36 /* Public */,
      30,    0,  346,    2, 0x0a,   39 /* Public */,
      31,    0,  347,    2, 0x0a,   40 /* Public */,
      32,    0,  348,    2, 0x0a,   41 /* Public */,
      33,    0,  349,    2, 0x0a,   42 /* Public */,
      34,    1,  350,    2, 0x0a,   43 /* Public */,
      34,    1,  353,    2, 0x0a,   45 /* Public */,
      37,    0,  356,    2, 0x0a,   47 /* Public */,
      38,    0,  357,    2, 0x0a,   48 /* Public */,
      39,    0,  358,    2, 0x0a,   49 /* Public */,
      40,    1,  359,    2, 0x0a,   50 /* Public */,
      43,    1,  362,    2, 0x0a,   52 /* Public */,
      45,    1,  365,    2, 0x0a,   54 /* Public */,
      47,    0,  368,    2, 0x0a,   56 /* Public */,
      48,    0,  369,    2, 0x0a,   57 /* Public */,
      49,    1,  370,    2, 0x0a,   58 /* Public */,
      52,    1,  373,    2, 0x0a,   60 /* Public */,
      53,    0,  376,    2, 0x0a,   62 /* Public */,
      54,    0,  377,    2, 0x0a,   63 /* Public */,
      55,    0,  378,    2, 0x0a,   64 /* Public */,
      56,    0,  379,    2, 0x0a,   65 /* Public */,
      57,    0,  380,    2, 0x0a,   66 /* Public */,
      58,    0,  381,    2, 0x0a,   67 /* Public */,
      59,    0,  382,    2, 0x0a,   68 /* Public */,
      60,    0,  383,    2, 0x08,   69 /* Private */,
      61,    1,  384,    2, 0x08,   70 /* Private */,
      63,    0,  387,    2, 0x08,   72 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    7,    5,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   17,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   17,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    0x80000000 | 3, QMetaType::QString,   20,
    0x80000000 | 3,
    QMetaType::Void, 0x80000000 | 3,   17,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void, QMetaType::QStringList,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void, 0x80000000 | 50,   51,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   62,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlayListManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlayListManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlayListManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlayListManagerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlayListManager, std::true_type>,
        // method 'currentPlayListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'selectedPlayListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'playListAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'playListRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'playListMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'playListsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentTrackRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'selectPlayListIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'selectPlayListName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'selectNextPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectPreviousPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'activatePlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'activatePlayListIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'activateSelectedPlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createPlayList'
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'createPlayList'
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'removePlayList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel *, std::false_type>,
        // method 'removePlayListIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'move'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeUnselected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'removeTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListTrack *, std::false_type>,
        // method 'invertSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTracks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>,
        // method 'addPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addPaths'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'randomizeList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'reverseList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel::SortMode, std::false_type>,
        // method 'sort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListModel::SortMode, std::false_type>,
        // method 'addToQueue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeInvalidTracks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeDuplicates'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refresh'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearQueue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopAfterSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rebuildGroups'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'writePlayLists'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onCurrentTrackRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlayListManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayListManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentPlayListChanged((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[2]))); break;
        case 1: _t->selectedPlayListChanged((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[2]))); break;
        case 2: _t->playListAdded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->playListRemoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->playListMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->playListsChanged(); break;
        case 6: _t->currentTrackRemoved(); break;
        case 7: _t->selectPlayList((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1]))); break;
        case 8: _t->selectPlayListIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->selectPlayListName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->selectNextPlayList(); break;
        case 11: _t->selectPreviousPlayList(); break;
        case 12: _t->activatePlayList((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1]))); break;
        case 13: _t->activatePlayListIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->activateSelectedPlayList(); break;
        case 15: { PlayListModel* _r = _t->createPlayList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< PlayListModel**>(_a[0]) = std::move(_r); }  break;
        case 16: { PlayListModel* _r = _t->createPlayList();
            if (_a[0]) *reinterpret_cast< PlayListModel**>(_a[0]) = std::move(_r); }  break;
        case 17: _t->removePlayList((*reinterpret_cast< std::add_pointer_t<PlayListModel*>>(_a[1]))); break;
        case 18: _t->removePlayListIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->move((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 20: _t->clear(); break;
        case 21: _t->clearSelection(); break;
        case 22: _t->removeSelected(); break;
        case 23: _t->removeUnselected(); break;
        case 24: _t->removeTrack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->removeTrack((*reinterpret_cast< std::add_pointer_t<PlayListTrack*>>(_a[1]))); break;
        case 26: _t->invertSelection(); break;
        case 27: _t->selectAll(); break;
        case 28: _t->showDetails(); break;
        case 29: _t->addTracks((*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[1]))); break;
        case 30: _t->addPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->addPaths((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 32: _t->randomizeList(); break;
        case 33: _t->reverseList(); break;
        case 34: _t->sortSelection((*reinterpret_cast< std::add_pointer_t<PlayListModel::SortMode>>(_a[1]))); break;
        case 35: _t->sort((*reinterpret_cast< std::add_pointer_t<PlayListModel::SortMode>>(_a[1]))); break;
        case 36: _t->addToQueue(); break;
        case 37: _t->removeInvalidTracks(); break;
        case 38: _t->removeDuplicates(); break;
        case 39: _t->refresh(); break;
        case 40: _t->clearQueue(); break;
        case 41: _t->stopAfterSelected(); break;
        case 42: _t->rebuildGroups(); break;
        case 43: _t->writePlayLists(); break;
        case 44: _t->onListChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 45: _t->onCurrentTrackRemoved(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel* >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel* >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel::SortMode >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel::SortMode >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayListManager::*)(PlayListModel * , PlayListModel * );
            if (_t _q_method = &PlayListManager::currentPlayListChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayListManager::*)(PlayListModel * , PlayListModel * );
            if (_t _q_method = &PlayListManager::selectedPlayListChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayListManager::*)(int );
            if (_t _q_method = &PlayListManager::playListAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayListManager::*)(int );
            if (_t _q_method = &PlayListManager::playListRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlayListManager::*)(int , int );
            if (_t _q_method = &PlayListManager::playListMoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlayListManager::*)();
            if (_t _q_method = &PlayListManager::playListsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PlayListManager::*)();
            if (_t _q_method = &PlayListManager::currentTrackRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *PlayListManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayListManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlayListManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayListManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 46)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 46;
    }
    return _id;
}

// SIGNAL 0
void PlayListManager::currentPlayListChanged(PlayListModel * _t1, PlayListModel * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayListManager::selectedPlayListChanged(PlayListModel * _t1, PlayListModel * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayListManager::playListAdded(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlayListManager::playListRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlayListManager::playListMoved(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayListManager::playListsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void PlayListManager::currentTrackRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP

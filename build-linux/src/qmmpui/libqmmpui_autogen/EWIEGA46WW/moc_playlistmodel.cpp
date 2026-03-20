/****************************************************************************
** Meta object code from reading C++ file 'playlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/qmmpui/playlistmodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistmodel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSPlayListModelENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPlayListModelENDCLASS = QtMocHelpers::stringData(
    "PlayListModel",
    "listChanged",
    "",
    "flags",
    "tracksAdded",
    "QList<PlayListTrack*>",
    "tracks",
    "nameChanged",
    "name",
    "loaderFinished",
    "scrollToRequest",
    "trackIndex",
    "sortingByColumnFinished",
    "column",
    "reverted",
    "currentTrackRemoved",
    "addTrack",
    "PlayListTrack*",
    "track",
    "addTracks",
    "addPath",
    "path",
    "addPaths",
    "paths",
    "insertTrack",
    "index",
    "insertTracks",
    "insertJson",
    "json",
    "insertPath",
    "insertPaths",
    "insertUrls",
    "QList<QUrl>",
    "urls",
    "clear",
    "clearSelection",
    "removeSelected",
    "removeUnselected",
    "removeTrack",
    "i",
    "removeTracks",
    "QList<PlayListItem*>",
    "items",
    "invertSelection",
    "selectAll",
    "showDetails",
    "QWidget*",
    "parent",
    "showDetailsForCurrent",
    "doCurrentVisibleRequest",
    "scrollTo",
    "randomizeList",
    "reverseList",
    "sortSelection",
    "PlayListModel::SortMode",
    "mode",
    "sort",
    "sortByColumn",
    "addToQueue",
    "setQueued",
    "t",
    "removeInvalidTracks",
    "removeDuplicates",
    "refresh",
    "clearQueue",
    "stopAfterSelected",
    "rebuildGroups",
    "updateMetaData",
    "preparePlayState",
    "prepareForShufflePlaying",
    "yes",
    "prepareGroups",
    "enabled",
    "onTaskFinished",
    "startCoverLoader",
    "setCover",
    "img",
    "insertTracksInternal",
    "before"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlayListModelENDCLASS_t {
    uint offsetsAndSizes[158];
    char stringdata0[14];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[12];
    char stringdata5[22];
    char stringdata6[7];
    char stringdata7[12];
    char stringdata8[5];
    char stringdata9[15];
    char stringdata10[16];
    char stringdata11[11];
    char stringdata12[24];
    char stringdata13[7];
    char stringdata14[9];
    char stringdata15[20];
    char stringdata16[9];
    char stringdata17[15];
    char stringdata18[6];
    char stringdata19[10];
    char stringdata20[8];
    char stringdata21[5];
    char stringdata22[9];
    char stringdata23[6];
    char stringdata24[12];
    char stringdata25[6];
    char stringdata26[13];
    char stringdata27[11];
    char stringdata28[5];
    char stringdata29[11];
    char stringdata30[12];
    char stringdata31[11];
    char stringdata32[12];
    char stringdata33[5];
    char stringdata34[6];
    char stringdata35[15];
    char stringdata36[15];
    char stringdata37[17];
    char stringdata38[12];
    char stringdata39[2];
    char stringdata40[13];
    char stringdata41[21];
    char stringdata42[6];
    char stringdata43[16];
    char stringdata44[10];
    char stringdata45[12];
    char stringdata46[9];
    char stringdata47[7];
    char stringdata48[22];
    char stringdata49[24];
    char stringdata50[9];
    char stringdata51[14];
    char stringdata52[12];
    char stringdata53[14];
    char stringdata54[24];
    char stringdata55[5];
    char stringdata56[5];
    char stringdata57[13];
    char stringdata58[11];
    char stringdata59[10];
    char stringdata60[2];
    char stringdata61[20];
    char stringdata62[17];
    char stringdata63[8];
    char stringdata64[11];
    char stringdata65[18];
    char stringdata66[14];
    char stringdata67[15];
    char stringdata68[17];
    char stringdata69[25];
    char stringdata70[4];
    char stringdata71[14];
    char stringdata72[8];
    char stringdata73[15];
    char stringdata74[17];
    char stringdata75[9];
    char stringdata76[4];
    char stringdata77[21];
    char stringdata78[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlayListModelENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlayListModelENDCLASS_t qt_meta_stringdata_CLASSPlayListModelENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "PlayListModel"
        QT_MOC_LITERAL(14, 11),  // "listChanged"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 5),  // "flags"
        QT_MOC_LITERAL(33, 11),  // "tracksAdded"
        QT_MOC_LITERAL(45, 21),  // "QList<PlayListTrack*>"
        QT_MOC_LITERAL(67, 6),  // "tracks"
        QT_MOC_LITERAL(74, 11),  // "nameChanged"
        QT_MOC_LITERAL(86, 4),  // "name"
        QT_MOC_LITERAL(91, 14),  // "loaderFinished"
        QT_MOC_LITERAL(106, 15),  // "scrollToRequest"
        QT_MOC_LITERAL(122, 10),  // "trackIndex"
        QT_MOC_LITERAL(133, 23),  // "sortingByColumnFinished"
        QT_MOC_LITERAL(157, 6),  // "column"
        QT_MOC_LITERAL(164, 8),  // "reverted"
        QT_MOC_LITERAL(173, 19),  // "currentTrackRemoved"
        QT_MOC_LITERAL(193, 8),  // "addTrack"
        QT_MOC_LITERAL(202, 14),  // "PlayListTrack*"
        QT_MOC_LITERAL(217, 5),  // "track"
        QT_MOC_LITERAL(223, 9),  // "addTracks"
        QT_MOC_LITERAL(233, 7),  // "addPath"
        QT_MOC_LITERAL(241, 4),  // "path"
        QT_MOC_LITERAL(246, 8),  // "addPaths"
        QT_MOC_LITERAL(255, 5),  // "paths"
        QT_MOC_LITERAL(261, 11),  // "insertTrack"
        QT_MOC_LITERAL(273, 5),  // "index"
        QT_MOC_LITERAL(279, 12),  // "insertTracks"
        QT_MOC_LITERAL(292, 10),  // "insertJson"
        QT_MOC_LITERAL(303, 4),  // "json"
        QT_MOC_LITERAL(308, 10),  // "insertPath"
        QT_MOC_LITERAL(319, 11),  // "insertPaths"
        QT_MOC_LITERAL(331, 10),  // "insertUrls"
        QT_MOC_LITERAL(342, 11),  // "QList<QUrl>"
        QT_MOC_LITERAL(354, 4),  // "urls"
        QT_MOC_LITERAL(359, 5),  // "clear"
        QT_MOC_LITERAL(365, 14),  // "clearSelection"
        QT_MOC_LITERAL(380, 14),  // "removeSelected"
        QT_MOC_LITERAL(395, 16),  // "removeUnselected"
        QT_MOC_LITERAL(412, 11),  // "removeTrack"
        QT_MOC_LITERAL(424, 1),  // "i"
        QT_MOC_LITERAL(426, 12),  // "removeTracks"
        QT_MOC_LITERAL(439, 20),  // "QList<PlayListItem*>"
        QT_MOC_LITERAL(460, 5),  // "items"
        QT_MOC_LITERAL(466, 15),  // "invertSelection"
        QT_MOC_LITERAL(482, 9),  // "selectAll"
        QT_MOC_LITERAL(492, 11),  // "showDetails"
        QT_MOC_LITERAL(504, 8),  // "QWidget*"
        QT_MOC_LITERAL(513, 6),  // "parent"
        QT_MOC_LITERAL(520, 21),  // "showDetailsForCurrent"
        QT_MOC_LITERAL(542, 23),  // "doCurrentVisibleRequest"
        QT_MOC_LITERAL(566, 8),  // "scrollTo"
        QT_MOC_LITERAL(575, 13),  // "randomizeList"
        QT_MOC_LITERAL(589, 11),  // "reverseList"
        QT_MOC_LITERAL(601, 13),  // "sortSelection"
        QT_MOC_LITERAL(615, 23),  // "PlayListModel::SortMode"
        QT_MOC_LITERAL(639, 4),  // "mode"
        QT_MOC_LITERAL(644, 4),  // "sort"
        QT_MOC_LITERAL(649, 12),  // "sortByColumn"
        QT_MOC_LITERAL(662, 10),  // "addToQueue"
        QT_MOC_LITERAL(673, 9),  // "setQueued"
        QT_MOC_LITERAL(683, 1),  // "t"
        QT_MOC_LITERAL(685, 19),  // "removeInvalidTracks"
        QT_MOC_LITERAL(705, 16),  // "removeDuplicates"
        QT_MOC_LITERAL(722, 7),  // "refresh"
        QT_MOC_LITERAL(730, 10),  // "clearQueue"
        QT_MOC_LITERAL(741, 17),  // "stopAfterSelected"
        QT_MOC_LITERAL(759, 13),  // "rebuildGroups"
        QT_MOC_LITERAL(773, 14),  // "updateMetaData"
        QT_MOC_LITERAL(788, 16),  // "preparePlayState"
        QT_MOC_LITERAL(805, 24),  // "prepareForShufflePlaying"
        QT_MOC_LITERAL(830, 3),  // "yes"
        QT_MOC_LITERAL(834, 13),  // "prepareGroups"
        QT_MOC_LITERAL(848, 7),  // "enabled"
        QT_MOC_LITERAL(856, 14),  // "onTaskFinished"
        QT_MOC_LITERAL(871, 16),  // "startCoverLoader"
        QT_MOC_LITERAL(888, 8),  // "setCover"
        QT_MOC_LITERAL(897, 3),  // "img"
        QT_MOC_LITERAL(901, 20),  // "insertTracksInternal"
        QT_MOC_LITERAL(922, 6)   // "before"
    },
    "PlayListModel",
    "listChanged",
    "",
    "flags",
    "tracksAdded",
    "QList<PlayListTrack*>",
    "tracks",
    "nameChanged",
    "name",
    "loaderFinished",
    "scrollToRequest",
    "trackIndex",
    "sortingByColumnFinished",
    "column",
    "reverted",
    "currentTrackRemoved",
    "addTrack",
    "PlayListTrack*",
    "track",
    "addTracks",
    "addPath",
    "path",
    "addPaths",
    "paths",
    "insertTrack",
    "index",
    "insertTracks",
    "insertJson",
    "json",
    "insertPath",
    "insertPaths",
    "insertUrls",
    "QList<QUrl>",
    "urls",
    "clear",
    "clearSelection",
    "removeSelected",
    "removeUnselected",
    "removeTrack",
    "i",
    "removeTracks",
    "QList<PlayListItem*>",
    "items",
    "invertSelection",
    "selectAll",
    "showDetails",
    "QWidget*",
    "parent",
    "showDetailsForCurrent",
    "doCurrentVisibleRequest",
    "scrollTo",
    "randomizeList",
    "reverseList",
    "sortSelection",
    "PlayListModel::SortMode",
    "mode",
    "sort",
    "sortByColumn",
    "addToQueue",
    "setQueued",
    "t",
    "removeInvalidTracks",
    "removeDuplicates",
    "refresh",
    "clearQueue",
    "stopAfterSelected",
    "rebuildGroups",
    "updateMetaData",
    "preparePlayState",
    "prepareForShufflePlaying",
    "yes",
    "prepareGroups",
    "enabled",
    "onTaskFinished",
    "startCoverLoader",
    "setCover",
    "img",
    "insertTracksInternal",
    "before"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlayListModelENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      55,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  344,    2, 0x06,    1 /* Public */,
       4,    1,  347,    2, 0x06,    3 /* Public */,
       7,    1,  350,    2, 0x06,    5 /* Public */,
       9,    0,  353,    2, 0x06,    7 /* Public */,
      10,    1,  354,    2, 0x06,    8 /* Public */,
      12,    2,  357,    2, 0x06,   10 /* Public */,
      15,    0,  362,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    1,  363,    2, 0x0a,   14 /* Public */,
      19,    1,  366,    2, 0x0a,   16 /* Public */,
      20,    1,  369,    2, 0x0a,   18 /* Public */,
      22,    1,  372,    2, 0x0a,   20 /* Public */,
      24,    2,  375,    2, 0x0a,   22 /* Public */,
      26,    2,  380,    2, 0x0a,   25 /* Public */,
      27,    2,  385,    2, 0x0a,   28 /* Public */,
      29,    2,  390,    2, 0x0a,   31 /* Public */,
      30,    2,  395,    2, 0x0a,   34 /* Public */,
      31,    2,  400,    2, 0x0a,   37 /* Public */,
      34,    0,  405,    2, 0x0a,   40 /* Public */,
      35,    0,  406,    2, 0x0a,   41 /* Public */,
      36,    0,  407,    2, 0x0a,   42 /* Public */,
      37,    0,  408,    2, 0x0a,   43 /* Public */,
      38,    1,  409,    2, 0x0a,   44 /* Public */,
      38,    1,  412,    2, 0x0a,   46 /* Public */,
      40,    1,  415,    2, 0x0a,   48 /* Public */,
      40,    1,  418,    2, 0x0a,   50 /* Public */,
      43,    0,  421,    2, 0x0a,   52 /* Public */,
      44,    0,  422,    2, 0x0a,   53 /* Public */,
      45,    1,  423,    2, 0x0a,   54 /* Public */,
      45,    0,  426,    2, 0x2a,   56 /* Public | MethodCloned */,
      48,    1,  427,    2, 0x0a,   57 /* Public */,
      48,    0,  430,    2, 0x2a,   59 /* Public | MethodCloned */,
      49,    0,  431,    2, 0x0a,   60 /* Public */,
      50,    1,  432,    2, 0x0a,   61 /* Public */,
      51,    0,  435,    2, 0x0a,   63 /* Public */,
      52,    0,  436,    2, 0x0a,   64 /* Public */,
      53,    1,  437,    2, 0x0a,   65 /* Public */,
      56,    1,  440,    2, 0x0a,   67 /* Public */,
      57,    1,  443,    2, 0x0a,   69 /* Public */,
      58,    0,  446,    2, 0x0a,   71 /* Public */,
      59,    1,  447,    2, 0x0a,   72 /* Public */,
      61,    0,  450,    2, 0x0a,   74 /* Public */,
      62,    0,  451,    2, 0x0a,   75 /* Public */,
      63,    0,  452,    2, 0x0a,   76 /* Public */,
      64,    0,  453,    2, 0x0a,   77 /* Public */,
      65,    0,  454,    2, 0x0a,   78 /* Public */,
      66,    0,  455,    2, 0x0a,   79 /* Public */,
      67,    0,  456,    2, 0x0a,   80 /* Public */,
      68,    0,  457,    2, 0x08,   81 /* Private */,
      69,    1,  458,    2, 0x08,   82 /* Private */,
      71,    1,  461,    2, 0x08,   84 /* Private */,
      73,    0,  464,    2, 0x08,   86 /* Private */,
      67,    1,  465,    2, 0x08,   87 /* Private */,
      74,    0,  468,    2, 0x08,   89 /* Private */,
      75,    2,  469,    2, 0x08,   90 /* Private */,
      77,    2,  474,    2, 0x08,   93 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   13,   14,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QStringList,   23,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 17,   25,   18,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,   25,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::QByteArray,   25,   28,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   25,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::QStringList,   25,   23,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 32,   25,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46,   47,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 54,   55,
    QMetaType::Void, 0x80000000 | 54,   55,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   60,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   70,
    QMetaType::Void, QMetaType::Bool,   72,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QImage,   21,   76,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 5,   78,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlayListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlayListModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlayListModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlayListModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlayListModel, std::true_type>,
        // method 'listChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'tracksAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>,
        // method 'nameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loaderFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scrollToRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sortingByColumnFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'currentTrackRemoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListTrack *, std::false_type>,
        // method 'addTracks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>,
        // method 'addPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'addPaths'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'insertTrack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListTrack *, std::false_type>,
        // method 'insertTracks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>,
        // method 'insertJson'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'insertPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'insertPaths'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'insertUrls'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<QUrl> &, std::false_type>,
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
        // method 'removeTracks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListItem*> &, std::false_type>,
        // method 'removeTracks'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>,
        // method 'invertSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'selectAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'showDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDetailsForCurrent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'showDetailsForCurrent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doCurrentVisibleRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'scrollTo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'sortByColumn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addToQueue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setQueued'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListTrack *, std::false_type>,
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
        // method 'updateMetaData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'preparePlayState'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prepareForShufflePlaying'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'prepareGroups'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'onTaskFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateMetaData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QStringList &, std::false_type>,
        // method 'startCoverLoader'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setCover'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QImage &, std::false_type>,
        // method 'insertTracksInternal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<PlayListTrack *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QList<PlayListTrack*> &, std::false_type>
    >,
    nullptr
} };

void PlayListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayListModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->listChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->tracksAdded((*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[1]))); break;
        case 2: _t->nameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->loaderFinished(); break;
        case 4: _t->scrollToRequest((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->sortingByColumnFinished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 6: _t->currentTrackRemoved(); break;
        case 7: _t->addTrack((*reinterpret_cast< std::add_pointer_t<PlayListTrack*>>(_a[1]))); break;
        case 8: _t->addTracks((*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[1]))); break;
        case 9: _t->addPath((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->addPaths((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 11: _t->insertTrack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<PlayListTrack*>>(_a[2]))); break;
        case 12: _t->insertTracks((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[2]))); break;
        case 13: _t->insertJson((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 14: _t->insertPath((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->insertPaths((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 16: _t->insertUrls((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QUrl>>>(_a[2]))); break;
        case 17: _t->clear(); break;
        case 18: _t->clearSelection(); break;
        case 19: _t->removeSelected(); break;
        case 20: _t->removeUnselected(); break;
        case 21: _t->removeTrack((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->removeTrack((*reinterpret_cast< std::add_pointer_t<PlayListTrack*>>(_a[1]))); break;
        case 23: _t->removeTracks((*reinterpret_cast< std::add_pointer_t<QList<PlayListItem*>>>(_a[1]))); break;
        case 24: _t->removeTracks((*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[1]))); break;
        case 25: _t->invertSelection(); break;
        case 26: _t->selectAll(); break;
        case 27: _t->showDetails((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 28: _t->showDetails(); break;
        case 29: _t->showDetailsForCurrent((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 30: _t->showDetailsForCurrent(); break;
        case 31: _t->doCurrentVisibleRequest(); break;
        case 32: _t->scrollTo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->randomizeList(); break;
        case 34: _t->reverseList(); break;
        case 35: _t->sortSelection((*reinterpret_cast< std::add_pointer_t<PlayListModel::SortMode>>(_a[1]))); break;
        case 36: _t->sort((*reinterpret_cast< std::add_pointer_t<PlayListModel::SortMode>>(_a[1]))); break;
        case 37: _t->sortByColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->addToQueue(); break;
        case 39: _t->setQueued((*reinterpret_cast< std::add_pointer_t<PlayListTrack*>>(_a[1]))); break;
        case 40: _t->removeInvalidTracks(); break;
        case 41: _t->removeDuplicates(); break;
        case 42: _t->refresh(); break;
        case 43: _t->clearQueue(); break;
        case 44: _t->stopAfterSelected(); break;
        case 45: _t->rebuildGroups(); break;
        case 46: _t->updateMetaData(); break;
        case 47: _t->preparePlayState(); break;
        case 48: _t->prepareForShufflePlaying((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 49: _t->prepareGroups((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 50: _t->onTaskFinished(); break;
        case 51: _t->updateMetaData((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 52: _t->startCoverLoader(); break;
        case 53: _t->setCover((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QImage>>(_a[2]))); break;
        case 54: _t->insertTracksInternal((*reinterpret_cast< std::add_pointer_t<PlayListTrack*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<PlayListTrack*>>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QUrl> >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< PlayListModel::SortMode >(); break;
            }
            break;
        case 36:
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
            using _t = void (PlayListModel::*)(int );
            if (_t _q_method = &PlayListModel::listChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayListModel::*)(const QList<PlayListTrack*> & );
            if (_t _q_method = &PlayListModel::tracksAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayListModel::*)(const QString & );
            if (_t _q_method = &PlayListModel::nameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayListModel::*)();
            if (_t _q_method = &PlayListModel::loaderFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PlayListModel::*)(int );
            if (_t _q_method = &PlayListModel::scrollToRequest; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PlayListModel::*)(int , bool );
            if (_t _q_method = &PlayListModel::sortingByColumnFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (PlayListModel::*)();
            if (_t _q_method = &PlayListModel::currentTrackRemoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject *PlayListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlayListModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 55)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 55;
    }
    return _id;
}

// SIGNAL 0
void PlayListModel::listChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayListModel::tracksAdded(const QList<PlayListTrack*> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayListModel::nameChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlayListModel::loaderFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PlayListModel::scrollToRequest(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayListModel::sortingByColumnFinished(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void PlayListModel::currentTrackRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP

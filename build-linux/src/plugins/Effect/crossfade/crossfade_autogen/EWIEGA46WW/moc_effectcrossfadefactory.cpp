/****************************************************************************
** Meta object code from reading C++ file 'effectcrossfadefactory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/Effect/crossfade/effectcrossfadefactory.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'effectcrossfadefactory.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS = QtMocHelpers::stringData(
    "EffectCrossfadeFactory"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS_t qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22)   // "EffectCrossfadeFactory"
    },
    "EffectCrossfadeFactory"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSEffectCrossfadeFactoryENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject EffectCrossfadeFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSEffectCrossfadeFactoryENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EffectCrossfadeFactory, std::true_type>
    >,
    nullptr
} };

void EffectCrossfadeFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *EffectCrossfadeFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EffectCrossfadeFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSEffectCrossfadeFactoryENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "EffectFactory"))
        return static_cast< EffectFactory*>(this);
    if (!strcmp(_clname, "EffectFactory/1.0"))
        return static_cast< EffectFactory*>(this);
    return QObject::qt_metacast(_clname);
}

int EffectCrossfadeFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_EffectCrossfadeFactory[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x28,  'o',  'r',  'g',  '.',  'q', 
    'm',  'm',  'p',  '.',  'q',  'm',  'm',  'p', 
    '.',  'E',  'f',  'f',  'e',  'c',  't',  'F', 
    'a',  'c',  't',  'o',  'r',  'y',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '.', 
    '1',  '.',  '0', 
    // "className"
    0x03,  0x76,  'E',  'f',  'f',  'e',  'c',  't', 
    'C',  'r',  'o',  's',  's',  'f',  'a',  'd', 
    'e',  'F',  'a',  'c',  't',  'o',  'r',  'y', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(EffectCrossfadeFactory, EffectCrossfadeFactory, qt_pluginMetaDataV2_EffectCrossfadeFactory)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_EffectCrossfadeFactory[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x28,  'o',  'r',  'g',  '.',  'q', 
    'm',  'm',  'p',  '.',  'q',  'm',  'm',  'p', 
    '.',  'E',  'f',  'f',  'e',  'c',  't',  'F', 
    'a',  'c',  't',  'o',  'r',  'y',  'I',  'n', 
    't',  'e',  'r',  'f',  'a',  'c',  'e',  '.', 
    '1',  '.',  '0', 
    // "className"
    0x03,  0x76,  'E',  'f',  'f',  'e',  'c',  't', 
    'C',  'r',  'o',  's',  's',  'f',  'a',  'd', 
    'e',  'F',  'a',  'c',  't',  'o',  'r',  'y', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(EffectCrossfadeFactory, EffectCrossfadeFactory)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'incdecvolumeoption.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/CommandLineOptions/IncDecVolumeOption/incdecvolumeoption.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'incdecvolumeoption.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS = QtMocHelpers::stringData(
    "IncDecVolumeCommandLineOption"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS_t qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS = {
    {
        QT_MOC_LITERAL(0, 29)   // "IncDecVolumeCommandLineOption"
    },
    "IncDecVolumeCommandLineOption"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSIncDecVolumeCommandLineOptionENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject IncDecVolumeCommandLineOption::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSIncDecVolumeCommandLineOptionENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<IncDecVolumeCommandLineOption, std::true_type>
    >,
    nullptr
} };

void IncDecVolumeCommandLineOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *IncDecVolumeCommandLineOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IncDecVolumeCommandLineOption::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSIncDecVolumeCommandLineOptionENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "CommandLineHandler"))
        return static_cast< CommandLineHandler*>(this);
    if (!strcmp(_clname, "CommandLineHandlerInterface/1.0"))
        return static_cast< CommandLineHandler*>(this);
    return QObject::qt_metacast(_clname);
}

int IncDecVolumeCommandLineOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_IncDecVolumeCommandLineOption[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x2f,  'o',  'r',  'g',  '.',  'q', 
    'm',  'm',  'p',  '.',  'q',  'm',  'm',  'p', 
    'u',  'i',  '.',  'C',  'o',  'm',  'm',  'a', 
    'n',  'd',  'L',  'i',  'n',  'e',  'H',  'a', 
    'n',  'd',  'l',  'e',  'r',  'I',  'n',  't', 
    'e',  'r',  'f',  'a',  'c',  'e',  '.',  '1', 
    '.',  '0', 
    // "className"
    0x03,  0x78,  0x1d,  'I',  'n',  'c',  'D',  'e', 
    'c',  'V',  'o',  'l',  'u',  'm',  'e',  'C', 
    'o',  'm',  'm',  'a',  'n',  'd',  'L',  'i', 
    'n',  'e',  'O',  'p',  't',  'i',  'o',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(IncDecVolumeCommandLineOption, IncDecVolumeCommandLineOption, qt_pluginMetaDataV2_IncDecVolumeCommandLineOption)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_IncDecVolumeCommandLineOption[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x2f,  'o',  'r',  'g',  '.',  'q', 
    'm',  'm',  'p',  '.',  'q',  'm',  'm',  'p', 
    'u',  'i',  '.',  'C',  'o',  'm',  'm',  'a', 
    'n',  'd',  'L',  'i',  'n',  'e',  'H',  'a', 
    'n',  'd',  'l',  'e',  'r',  'I',  'n',  't', 
    'e',  'r',  'f',  'a',  'c',  'e',  '.',  '1', 
    '.',  '0', 
    // "className"
    0x03,  0x78,  0x1d,  'I',  'n',  'c',  'D',  'e', 
    'c',  'V',  'o',  'l',  'u',  'm',  'e',  'C', 
    'o',  'm',  'm',  'a',  'n',  'd',  'L',  'i', 
    'n',  'e',  'O',  'p',  't',  'i',  'o',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(IncDecVolumeCommandLineOption, IncDecVolumeCommandLineOption)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP

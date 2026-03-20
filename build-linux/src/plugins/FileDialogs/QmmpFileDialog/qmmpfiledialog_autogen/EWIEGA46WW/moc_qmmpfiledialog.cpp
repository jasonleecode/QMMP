/****************************************************************************
** Meta object code from reading C++ file 'qmmpfiledialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/FileDialogs/QmmpFileDialog/qmmpfiledialog.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmmpfiledialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS = QtMocHelpers::stringData(
    "QmmpFileDialog"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS_t qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14)   // "QmmpFileDialog"
    },
    "QmmpFileDialog"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmmpFileDialogENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject QmmpFileDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<FileDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmmpFileDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QmmpFileDialog, std::true_type>
    >,
    nullptr
} };

void QmmpFileDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QmmpFileDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmmpFileDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmmpFileDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return FileDialog::qt_metacast(_clname);
}

int QmmpFileDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = FileDialog::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS = QtMocHelpers::stringData(
    "QmmpFileDialogFactory"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS_t qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21)   // "QmmpFileDialogFactory"
    },
    "QmmpFileDialogFactory"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQmmpFileDialogFactoryENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject QmmpFileDialogFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQmmpFileDialogFactoryENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QmmpFileDialogFactory, std::true_type>
    >,
    nullptr
} };

void QmmpFileDialogFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QmmpFileDialogFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QmmpFileDialogFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQmmpFileDialogFactoryENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "FileDialogFactory"))
        return static_cast< FileDialogFactory*>(this);
    if (!strcmp(_clname, "FileDialogFactory/1.0"))
        return static_cast< FileDialogFactory*>(this);
    return QObject::qt_metacast(_clname);
}

int QmmpFileDialogFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_QmmpFileDialogFactory[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x2e,  'o',  'r',  'g',  '.',  'q', 
    'm',  'm',  'p',  '.',  'q',  'm',  'm',  'p', 
    'u',  'i',  '.',  'F',  'i',  'l',  'e',  'D', 
    'i',  'a',  'l',  'o',  'g',  'F',  'a',  'c', 
    't',  'o',  'r',  'y',  'I',  'n',  't',  'e', 
    'r',  'f',  'a',  'c',  'e',  '.',  '1',  '.', 
    '0', 
    // "className"
    0x03,  0x75,  'Q',  'm',  'm',  'p',  'F',  'i', 
    'l',  'e',  'D',  'i',  'a',  'l',  'o',  'g', 
    'F',  'a',  'c',  't',  'o',  'r',  'y', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(QmmpFileDialogFactory, QmmpFileDialogFactory, qt_pluginMetaDataV2_QmmpFileDialogFactory)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_QmmpFileDialogFactory[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x2e,  'o',  'r',  'g',  '.',  'q', 
    'm',  'm',  'p',  '.',  'q',  'm',  'm',  'p', 
    'u',  'i',  '.',  'F',  'i',  'l',  'e',  'D', 
    'i',  'a',  'l',  'o',  'g',  'F',  'a',  'c', 
    't',  'o',  'r',  'y',  'I',  'n',  't',  'e', 
    'r',  'f',  'a',  'c',  'e',  '.',  '1',  '.', 
    '0', 
    // "className"
    0x03,  0x75,  'Q',  'm',  'm',  'p',  'F',  'i', 
    'l',  'e',  'D',  'i',  'a',  'l',  'o',  'g', 
    'F',  'a',  'c',  't',  'o',  'r',  'y', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(QmmpFileDialogFactory, QmmpFileDialogFactory)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP

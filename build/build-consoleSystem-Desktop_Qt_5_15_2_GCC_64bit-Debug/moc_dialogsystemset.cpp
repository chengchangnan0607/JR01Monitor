/****************************************************************************
** Meta object code from reading C++ file 'dialogsystemset.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/UI/dialogsystemset.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogsystemset.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogSystemSet_t {
    QByteArrayData data[10];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogSystemSet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogSystemSet_t qt_meta_stringdata_DialogSystemSet = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DialogSystemSet"
QT_MOC_LITERAL(1, 16, 8), // "powerOff"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "dateSetting"
QT_MOC_LITERAL(4, 38, 11), // "timeSetting"
QT_MOC_LITERAL(5, 50, 13), // "lengthSetting"
QT_MOC_LITERAL(6, 64, 18), // "sensitivitySetting"
QT_MOC_LITERAL(7, 83, 23), // "pressureZeroCalibration"
QT_MOC_LITERAL(8, 107, 14), // "bloodPumpSpeed"
QT_MOC_LITERAL(9, 122, 14) // "powerOffHandle"

    },
    "DialogSystemSet\0powerOff\0\0dateSetting\0"
    "timeSetting\0lengthSetting\0sensitivitySetting\0"
    "pressureZeroCalibration\0bloodPumpSpeed\0"
    "powerOffHandle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogSystemSet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogSystemSet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogSystemSet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->powerOff(); break;
        case 1: _t->dateSetting(); break;
        case 2: _t->timeSetting(); break;
        case 3: _t->lengthSetting(); break;
        case 4: _t->sensitivitySetting(); break;
        case 5: _t->pressureZeroCalibration(); break;
        case 6: _t->bloodPumpSpeed(); break;
        case 7: _t->powerOffHandle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DialogSystemSet::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DialogSystemSet::powerOff)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DialogSystemSet::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogSystemSet.data,
    qt_meta_data_DialogSystemSet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogSystemSet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogSystemSet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogSystemSet.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogSystemSet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DialogSystemSet::powerOff()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

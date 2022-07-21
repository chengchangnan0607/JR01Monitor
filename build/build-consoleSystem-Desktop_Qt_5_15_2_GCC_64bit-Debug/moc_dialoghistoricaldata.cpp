/****************************************************************************
** Meta object code from reading C++ file 'dialoghistoricaldata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/UI/dialoghistoricaldata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialoghistoricaldata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DialogHistoricalData_t {
    QByteArrayData data[14];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DialogHistoricalData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DialogHistoricalData_t qt_meta_stringdata_DialogHistoricalData = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DialogHistoricalData"
QT_MOC_LITERAL(1, 21, 16), // "toChartBloodPump"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "toChartPurgeSystem"
QT_MOC_LITERAL(4, 58, 11), // "timeSetting"
QT_MOC_LITERAL(5, 70, 18), // "searchFinishHandle"
QT_MOC_LITERAL(6, 89, 8), // "rowCount"
QT_MOC_LITERAL(7, 98, 16), // "buttonPlayHandle"
QT_MOC_LITERAL(8, 115, 25), // "buttonPlaybackSpeedHandle"
QT_MOC_LITERAL(9, 141, 15), // "timerPlayUpdate"
QT_MOC_LITERAL(10, 157, 23), // "buttonAmplitudeUpHandle"
QT_MOC_LITERAL(11, 181, 25), // "buttonAmplitudeDownHandle"
QT_MOC_LITERAL(12, 207, 20), // "buttonPeriodUpHandle"
QT_MOC_LITERAL(13, 228, 22) // "buttonPeriodDownHandle"

    },
    "DialogHistoricalData\0toChartBloodPump\0"
    "\0toChartPurgeSystem\0timeSetting\0"
    "searchFinishHandle\0rowCount\0"
    "buttonPlayHandle\0buttonPlaybackSpeedHandle\0"
    "timerPlayUpdate\0buttonAmplitudeUpHandle\0"
    "buttonAmplitudeDownHandle\0"
    "buttonPeriodUpHandle\0buttonPeriodDownHandle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DialogHistoricalData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    1,   72,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    0,   77,    2, 0x0a /* Public */,
      10,    0,   78,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    0,   80,    2, 0x0a /* Public */,
      13,    0,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DialogHistoricalData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DialogHistoricalData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toChartBloodPump(); break;
        case 1: _t->toChartPurgeSystem(); break;
        case 2: _t->timeSetting(); break;
        case 3: _t->searchFinishHandle((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->buttonPlayHandle(); break;
        case 5: _t->buttonPlaybackSpeedHandle(); break;
        case 6: _t->timerPlayUpdate(); break;
        case 7: _t->buttonAmplitudeUpHandle(); break;
        case 8: _t->buttonAmplitudeDownHandle(); break;
        case 9: _t->buttonPeriodUpHandle(); break;
        case 10: _t->buttonPeriodDownHandle(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DialogHistoricalData::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DialogHistoricalData.data,
    qt_meta_data_DialogHistoricalData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DialogHistoricalData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DialogHistoricalData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DialogHistoricalData.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DialogHistoricalData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

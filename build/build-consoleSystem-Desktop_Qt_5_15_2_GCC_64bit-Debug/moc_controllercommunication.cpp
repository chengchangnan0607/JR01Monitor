/****************************************************************************
** Meta object code from reading C++ file 'controllercommunication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/BL/COMM/controllercommunication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controllercommunication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ControllerCommunication_t {
    QByteArrayData data[57];
    char stringdata0[898];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ControllerCommunication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ControllerCommunication_t qt_meta_stringdata_ControllerCommunication = {
    {
QT_MOC_LITERAL(0, 0, 23), // "ControllerCommunication"
QT_MOC_LITERAL(1, 24, 22), // "connectionStatusChange"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 16), // "connectionStatus"
QT_MOC_LITERAL(4, 65, 18), // "recvRealTimeStream"
QT_MOC_LITERAL(5, 84, 5), // "T_RTS"
QT_MOC_LITERAL(6, 90, 18), // "realTimeDataStream"
QT_MOC_LITERAL(7, 109, 19), // "recvPumpSpeedStatus"
QT_MOC_LITERAL(8, 129, 8), // "speedVal"
QT_MOC_LITERAL(9, 138, 32), // "recvControllerStatusActiveFaults"
QT_MOC_LITERAL(10, 171, 18), // "T_ControllerStatus"
QT_MOC_LITERAL(11, 190, 16), // "controllerStatus"
QT_MOC_LITERAL(12, 207, 27), // "recvControllerStatus1Second"
QT_MOC_LITERAL(13, 235, 27), // "recvControllerStatus1Minute"
QT_MOC_LITERAL(14, 263, 29), // "recvControllerStatusHeartbeat"
QT_MOC_LITERAL(15, 293, 16), // "recvPumpSpeedGet"
QT_MOC_LITERAL(16, 310, 11), // "T_PumpSpeed"
QT_MOC_LITERAL(17, 322, 9), // "pumpSpeed"
QT_MOC_LITERAL(18, 332, 25), // "recvControllerPowerStatus"
QT_MOC_LITERAL(19, 358, 13), // "T_PowerStatus"
QT_MOC_LITERAL(20, 372, 11), // "powerStatus"
QT_MOC_LITERAL(21, 384, 18), // "recvActivityLogGet"
QT_MOC_LITERAL(22, 403, 13), // "T_ActivityLog"
QT_MOC_LITERAL(23, 417, 11), // "activityLog"
QT_MOC_LITERAL(24, 429, 18), // "recvControllerInfo"
QT_MOC_LITERAL(25, 448, 16), // "T_ControllerInfo"
QT_MOC_LITERAL(26, 465, 14), // "controllerInfo"
QT_MOC_LITERAL(27, 480, 7), // "recvKey"
QT_MOC_LITERAL(28, 488, 8), // "keyValue"
QT_MOC_LITERAL(29, 497, 18), // "recvPressureSensor"
QT_MOC_LITERAL(30, 516, 16), // "S200RealtimeData"
QT_MOC_LITERAL(31, 533, 10), // "sensorData"
QT_MOC_LITERAL(32, 544, 15), // "recvPurgeSystem"
QT_MOC_LITERAL(33, 560, 17), // "PurgeRealtimeData"
QT_MOC_LITERAL(34, 578, 9), // "purgeDate"
QT_MOC_LITERAL(35, 588, 12), // "recvPowerOff"
QT_MOC_LITERAL(36, 601, 23), // "connectionStatusRefresh"
QT_MOC_LITERAL(37, 625, 18), // "uartRecvDataHandle"
QT_MOC_LITERAL(38, 644, 4), // "data"
QT_MOC_LITERAL(39, 649, 14), // "pumpControlSet"
QT_MOC_LITERAL(40, 664, 13), // "T_PumpControl"
QT_MOC_LITERAL(41, 678, 11), // "pumpControl"
QT_MOC_LITERAL(42, 690, 12), // "pumpSpeedSet"
QT_MOC_LITERAL(43, 703, 12), // "pumpSpeedGet"
QT_MOC_LITERAL(44, 716, 14), // "startLogStream"
QT_MOC_LITERAL(45, 731, 13), // "T_LogDataType"
QT_MOC_LITERAL(46, 745, 10), // "logRequest"
QT_MOC_LITERAL(47, 756, 15), // "numberRequested"
QT_MOC_LITERAL(48, 772, 13), // "stopLogStream"
QT_MOC_LITERAL(49, 786, 16), // "realTimeClockSet"
QT_MOC_LITERAL(50, 803, 9), // "timestamp"
QT_MOC_LITERAL(51, 813, 21), // "controlRealtimeStream"
QT_MOC_LITERAL(52, 835, 8), // "powerOff"
QT_MOC_LITERAL(53, 844, 17), // "purgeExhaustStart"
QT_MOC_LITERAL(54, 862, 16), // "purgeCapacitySet"
QT_MOC_LITERAL(55, 879, 7), // "int16_t"
QT_MOC_LITERAL(56, 887, 10) // "capacityMl"

    },
    "ControllerCommunication\0connectionStatusChange\0"
    "\0connectionStatus\0recvRealTimeStream\0"
    "T_RTS\0realTimeDataStream\0recvPumpSpeedStatus\0"
    "speedVal\0recvControllerStatusActiveFaults\0"
    "T_ControllerStatus\0controllerStatus\0"
    "recvControllerStatus1Second\0"
    "recvControllerStatus1Minute\0"
    "recvControllerStatusHeartbeat\0"
    "recvPumpSpeedGet\0T_PumpSpeed\0pumpSpeed\0"
    "recvControllerPowerStatus\0T_PowerStatus\0"
    "powerStatus\0recvActivityLogGet\0"
    "T_ActivityLog\0activityLog\0recvControllerInfo\0"
    "T_ControllerInfo\0controllerInfo\0recvKey\0"
    "keyValue\0recvPressureSensor\0"
    "S200RealtimeData\0sensorData\0recvPurgeSystem\0"
    "PurgeRealtimeData\0purgeDate\0recvPowerOff\0"
    "connectionStatusRefresh\0uartRecvDataHandle\0"
    "data\0pumpControlSet\0T_PumpControl\0"
    "pumpControl\0pumpSpeedSet\0pumpSpeedGet\0"
    "startLogStream\0T_LogDataType\0logRequest\0"
    "numberRequested\0stopLogStream\0"
    "realTimeClockSet\0timestamp\0"
    "controlRealtimeStream\0powerOff\0"
    "purgeExhaustStart\0purgeCapacitySet\0"
    "int16_t\0capacityMl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ControllerCommunication[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  149,    2, 0x06 /* Public */,
       4,    1,  152,    2, 0x06 /* Public */,
       7,    1,  155,    2, 0x06 /* Public */,
       9,    1,  158,    2, 0x06 /* Public */,
      12,    1,  161,    2, 0x06 /* Public */,
      13,    1,  164,    2, 0x06 /* Public */,
      14,    1,  167,    2, 0x06 /* Public */,
      15,    1,  170,    2, 0x06 /* Public */,
      18,    1,  173,    2, 0x06 /* Public */,
      21,    1,  176,    2, 0x06 /* Public */,
      24,    1,  179,    2, 0x06 /* Public */,
      27,    1,  182,    2, 0x06 /* Public */,
      29,    1,  185,    2, 0x06 /* Public */,
      32,    1,  188,    2, 0x06 /* Public */,
      35,    0,  191,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      36,    0,  192,    2, 0x0a /* Public */,
      37,    1,  193,    2, 0x0a /* Public */,
      39,    1,  196,    2, 0x0a /* Public */,
      42,    1,  199,    2, 0x0a /* Public */,
      43,    0,  202,    2, 0x0a /* Public */,
      44,    2,  203,    2, 0x0a /* Public */,
      48,    1,  208,    2, 0x0a /* Public */,
      49,    1,  211,    2, 0x0a /* Public */,
      51,    1,  214,    2, 0x0a /* Public */,
      52,    0,  217,    2, 0x0a /* Public */,
      53,    0,  218,    2, 0x0a /* Public */,
      54,    1,  219,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::UShort,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::UChar,   28,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   38,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 45, QMetaType::UShort,   46,   47,
    QMetaType::Void, 0x80000000 | 45,   46,
    QMetaType::Void, QMetaType::UInt,   50,
    QMetaType::Void, QMetaType::UChar,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 55,   56,

       0        // eod
};

void ControllerCommunication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ControllerCommunication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionStatusChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->recvRealTimeStream((*reinterpret_cast< T_RTS(*)>(_a[1]))); break;
        case 2: _t->recvPumpSpeedStatus((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 3: _t->recvControllerStatusActiveFaults((*reinterpret_cast< T_ControllerStatus(*)>(_a[1]))); break;
        case 4: _t->recvControllerStatus1Second((*reinterpret_cast< T_ControllerStatus(*)>(_a[1]))); break;
        case 5: _t->recvControllerStatus1Minute((*reinterpret_cast< T_ControllerStatus(*)>(_a[1]))); break;
        case 6: _t->recvControllerStatusHeartbeat((*reinterpret_cast< T_ControllerStatus(*)>(_a[1]))); break;
        case 7: _t->recvPumpSpeedGet((*reinterpret_cast< T_PumpSpeed(*)>(_a[1]))); break;
        case 8: _t->recvControllerPowerStatus((*reinterpret_cast< T_PowerStatus(*)>(_a[1]))); break;
        case 9: _t->recvActivityLogGet((*reinterpret_cast< T_ActivityLog(*)>(_a[1]))); break;
        case 10: _t->recvControllerInfo((*reinterpret_cast< T_ControllerInfo(*)>(_a[1]))); break;
        case 11: _t->recvKey((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 12: _t->recvPressureSensor((*reinterpret_cast< S200RealtimeData(*)>(_a[1]))); break;
        case 13: _t->recvPurgeSystem((*reinterpret_cast< PurgeRealtimeData(*)>(_a[1]))); break;
        case 14: _t->recvPowerOff(); break;
        case 15: _t->connectionStatusRefresh(); break;
        case 16: _t->uartRecvDataHandle((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 17: _t->pumpControlSet((*reinterpret_cast< T_PumpControl(*)>(_a[1]))); break;
        case 18: _t->pumpSpeedSet((*reinterpret_cast< T_PumpSpeed(*)>(_a[1]))); break;
        case 19: _t->pumpSpeedGet(); break;
        case 20: _t->startLogStream((*reinterpret_cast< T_LogDataType(*)>(_a[1])),(*reinterpret_cast< unsigned short(*)>(_a[2]))); break;
        case 21: _t->stopLogStream((*reinterpret_cast< T_LogDataType(*)>(_a[1]))); break;
        case 22: _t->realTimeClockSet((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 23: _t->controlRealtimeStream((*reinterpret_cast< unsigned char(*)>(_a[1]))); break;
        case 24: _t->powerOff(); break;
        case 25: _t->purgeExhaustStart(); break;
        case 26: _t->purgeCapacitySet((*reinterpret_cast< int16_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ControllerCommunication::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::connectionStatusChange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_RTS );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvRealTimeStream)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(unsigned short );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvPumpSpeedStatus)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_ControllerStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvControllerStatusActiveFaults)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_ControllerStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvControllerStatus1Second)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_ControllerStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvControllerStatus1Minute)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_ControllerStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvControllerStatusHeartbeat)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_PumpSpeed );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvPumpSpeedGet)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_PowerStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvControllerPowerStatus)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_ActivityLog );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvActivityLogGet)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(T_ControllerInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvControllerInfo)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(unsigned char );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvKey)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(S200RealtimeData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvPressureSensor)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)(PurgeRealtimeData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvPurgeSystem)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (ControllerCommunication::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ControllerCommunication::recvPowerOff)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ControllerCommunication::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ControllerCommunication.data,
    qt_meta_data_ControllerCommunication,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ControllerCommunication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ControllerCommunication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ControllerCommunication.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ControllerCommunication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void ControllerCommunication::connectionStatusChange(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ControllerCommunication::recvRealTimeStream(T_RTS _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ControllerCommunication::recvPumpSpeedStatus(unsigned short _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ControllerCommunication::recvControllerStatusActiveFaults(T_ControllerStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ControllerCommunication::recvControllerStatus1Second(T_ControllerStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ControllerCommunication::recvControllerStatus1Minute(T_ControllerStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ControllerCommunication::recvControllerStatusHeartbeat(T_ControllerStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ControllerCommunication::recvPumpSpeedGet(T_PumpSpeed _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ControllerCommunication::recvControllerPowerStatus(T_PowerStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ControllerCommunication::recvActivityLogGet(T_ActivityLog _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ControllerCommunication::recvControllerInfo(T_ControllerInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void ControllerCommunication::recvKey(unsigned char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void ControllerCommunication::recvPressureSensor(S200RealtimeData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void ControllerCommunication::recvPurgeSystem(PurgeRealtimeData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void ControllerCommunication::recvPowerOff()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

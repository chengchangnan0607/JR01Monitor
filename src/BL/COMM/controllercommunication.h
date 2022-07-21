#ifndef CONTROLLERCOMMUNICATION_H
#define CONTROLLERCOMMUNICATION_H

#include <QObject>
#include "serialthread.h"
#include "communicationprotocol.h"
#include "../DB/datastoragethread.h"
#include "../../UI/dialogsystemset.h"

class ControllerCommunication : public QObject
{
    Q_OBJECT
public:
    explicit ControllerCommunication(QObject *parent = nullptr);
    void uartOpen();
    void uartSend(QByteArray data);
    void parsingRealTimeStream();
    void parsingControllerStatus();
    void parsingPumpSpeedGet();
    void parsingActivityLogGet();
    void parsingControllerPowerStatus();
    void parsingControllerInfo();

    void controllerStatusGet();
    void controllerPowerStatusGet();
    void controllerInfoGet();

    void muteAlarms();
    void clearAlarms();

    SerialThread *serialThread;
    DataStorageThread *dataStorageThread;

    bool connectionStatus = false;//false = no connection; true = connection;
    int disconnectionCount = 0;

    struct T_RTS realTimeDataStream;
    struct T_ControllerStatus controllerStatus;
    struct T_PumpSpeed pumpSpeed;
    struct T_ActivityLog activityLog;
    struct T_PowerStatus powerStatus;
    struct T_PumpControl pumpControlLast;
    struct T_ControllerInfo controllerInfo;

signals:
    void connectionStatusChange(bool connectionStatus);
    void recvRealTimeStream(T_RTS realTimeDataStream);
    void recvPumpSpeedStatus(unsigned short speedVal);
    void recvControllerStatusActiveFaults(T_ControllerStatus controllerStatus);
    void recvControllerStatus1Second(T_ControllerStatus controllerStatus);
    void recvControllerStatus1Minute(T_ControllerStatus controllerStatus);
    void recvControllerStatusHeartbeat(T_ControllerStatus controllerStatus);
    void recvPumpSpeedGet(T_PumpSpeed pumpSpeed);
    void recvControllerPowerStatus(T_PowerStatus powerStatus);
    void recvActivityLogGet(T_ActivityLog activityLog);
    void recvControllerInfo(T_ControllerInfo controllerInfo);
    void recvKey(unsigned char keyValue);
    void recvPressureSensor(S200RealtimeData sensorData);
    void recvPurgeSystem(PurgeRealtimeData purgeDate);
    void recvPowerOff();
public slots:
    void connectionStatusRefresh();
    void uartRecvDataHandle(QByteArray data);
    void pumpControlSet(T_PumpControl pumpControl);
    void pumpSpeedSet(T_PumpSpeed pumpSpeed);
    void pumpSpeedGet();
    void startLogStream(T_LogDataType logRequest, unsigned short numberRequested);
    void stopLogStream(T_LogDataType logRequest);
    void realTimeClockSet(unsigned int timestamp);
    void controlRealtimeStream(unsigned char data);
    void powerOff();
    void purgeExhaustStart();
    void purgeCapacitySet(int16_t capacityMl);

private:
    bool isOpenUART = 0;//1=open; 0=colse;
    int controllerStatusGetCounter = 0;

protected:
    unsigned char mBuffer[8192];
    int mSize;
    unsigned char mPRBuffer[PR_PACKET_LEN];
};

#endif // CONTROLLERCOMMUNICATION_H

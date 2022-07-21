#include "controllercommunication.h"

ControllerCommunication::ControllerCommunication(QObject *parent) : QObject(parent)
{
    mSize = 0;
    uartOpen();

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ControllerCommunication::connectionStatusRefresh);
    timer->start(100);//100ms

}

void ControllerCommunication::connectionStatusRefresh()
{
    controllerStatusGetCounter += 1;
//    if (controllerStatusGetCounter == 2) {
//        controlRealtimeStream(1);
//    }
//    if (controllerStatusGetCounter > 5) {//0.5s
//        controllerStatusGetCounter = 0;
//        controlRealtimeStream(0);
//        controllerStatusGet();
//        controllerStatusGet();
//        controllerStatusGet();
//        controllerStatusGet();
//        controllerStatusGet();
    if ((controllerStatusGetCounter % 5) == 0) {//0.5s
//        controlRealtimeStream(1);
//        controllerPowerStatusGet();
//        pumpSpeedGet();
//        pumpControlSet(pumpControlLast);
        controllerStatusGet();
    } else if (controllerStatusGetCounter >= 10) {//1s
        controllerStatusGetCounter = 0;
//        controllerStatusGet();
    }

    if ((connectionStatus == false) && (disconnectionCount == 0)) {
        connectionStatus = true;
        emit connectionStatusChange(connectionStatus);
        pumpSpeedGet();
        realTimeClockSet(QDateTime::currentMSecsSinceEpoch()/1000);
    } else if ((connectionStatus == true) && (disconnectionCount > 10)) {
        connectionStatus = false;
        emit connectionStatusChange(connectionStatus);
    }
    disconnectionCount += 1;
}


#ifdef pcDebug
#define uartDevName "/dev/ttyUSB0"
#else
#define uartDevName "/dev/ttymxc3"
#endif
#define baudrate 115200
void ControllerCommunication::uartOpen()
{
    if (isOpenUART == 0) {
        serialThread = new SerialThread(uartDevName, baudrate);
        dataStorageThread = new DataStorageThread();
        if(serialThread->serialPort->isOpen())
        {
            connect(serialThread, &SerialThread::sRecvData, this, &ControllerCommunication::uartRecvDataHandle);
            serialThread->start();
            isOpenUART = 1;
            dataStorageThread->start();
        } else {
            delete serialThread;//call ~serialThread()
            delete dataStorageThread;
        }
    } else {
        serialThread->stop();
        disconnect(serialThread, &SerialThread::sRecvData, this, &ControllerCommunication::uartRecvDataHandle);
        delete serialThread;
        isOpenUART = 0;
        dataStorageThread->stop();
        delete dataStorageThread;
    }
}

void ControllerCommunication::uartRecvDataHandle(QByteArray data)
{
    if (mSize + data.length() >= sizeof(mBuffer)) {
        mSize = 0;
        return ;
    }
    memcpy(mBuffer + mSize, data.data(), data.length());
    mSize += data.length();
    CommunicationProtocol receivedPacket;
    while (mSize > 0) {
        if (!receivedPacket.Unpack(mBuffer, mSize, mPRBuffer, PR_PACKET_LEN)) {
            break;
        }
        disconnectionCount = 0;
        switch (mPRBuffer[TransactionID]) {
            case 0x1e://30
                parsingRealTimeStream();
                break;
            case 0x1f://31
                parsingControllerStatus();
                break;
            case 0x32://50
                parsingControllerInfo();
                break;
            case 0x46://70 PumpSpeedGet
                parsingPumpSpeedGet();
                break;
            case 0x50://80, 活动日志事务(ActivityLogGet) TxOnly,该事务从控制器中检索活动日志。
                parsingActivityLogGet();
                break;
            case 0x5D://93 获取控制器电源状态事务(ControllerPowerStatus)
                parsingControllerPowerStatus();
                break;
            default:
                break;
        }
    }
}

void ControllerCommunication::uartSend(QByteArray data)
{
    if (isOpenUART){
        serialThread->SendData(data);
    }
}

void ControllerCommunication::powerOff()
{
    qDebug()<<"SendData powerOff start:" << QDateTime::currentMSecsSinceEpoch();
    controlRealtimeStream(0x10);//bit4(0=normal; 1=poweroff)
//    for(int i; i < 1000; i++);
    qDebug()<<"SendData powerOff stop:" << QDateTime::currentMSecsSinceEpoch();
    QString str = "poweroff";
    qDebug() << str;
#ifndef pcDebug
    system(str.toLatin1().data());
#endif
}

void ControllerCommunication::parsingRealTimeStream()
{
    if (mPRBuffer[TypePackCounter] == 0) {
        realTimeDataStream.speed = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        emit recvPumpSpeedStatus(realTimeDataStream.speed);
        realTimeDataStream.power = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        realTimeDataStream.flow = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        realTimeDataStream.powerStatus = mPRBuffer[Data6];
        if (realTimeDataStream.powerStatus & 0x08) {//bit3(1=poweroff)
            emit recvPowerOff();
//            powerOff();
        }
        realTimeDataStream.relativeCapacity = mPRBuffer[Data7];
        emit recvRealTimeStream(realTimeDataStream);
//        dataStorageThread->saveRTS(realTimeDataStream);
    } else if (mPRBuffer[TypePackCounter] == 0x01) {
        realTimeDataStream.keyStatus = mPRBuffer[Data0];
        if (realTimeDataStream.keyStatus != 0x00) {
            emit recvKey(realTimeDataStream.keyStatus);
        }
        realTimeDataStream.sensorData.S200Version = mPRBuffer[Data1];
        realTimeDataStream.sensorData.S200CavityLength[0] = mPRBuffer[Data2];
        realTimeDataStream.sensorData.S200CavityLength[1] = mPRBuffer[Data3];
        realTimeDataStream.sensorData.S200CavityLength[2] = mPRBuffer[Data4];
        realTimeDataStream.sensorData.S200Pressure[0] = mPRBuffer[Data5];
        realTimeDataStream.sensorData.S200Pressure[1] = mPRBuffer[Data6];
        realTimeDataStream.sensorData.S200Pressure[2] = mPRBuffer[Data7];
        emit recvPressureSensor(realTimeDataStream.sensorData);
    } else if (mPRBuffer[TypePackCounter] == 0x02) {
        realTimeDataStream.purgeDate.pressure = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        realTimeDataStream.purgeDate.flowRate = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        emit recvPurgeSystem(realTimeDataStream.purgeDate);
        dataStorageThread->saveRTS(realTimeDataStream);
    }
}

void ControllerCommunication::parsingControllerStatus()
{
    if (mPRBuffer[TypePackCounter] == 0x00) {
        controllerStatus.timeStamp =  (mPRBuffer[Data3] << 24) + (mPRBuffer[Data2] << 16) + (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        controllerStatus.activeFaults = (mPRBuffer[Data7] << 24) + (mPRBuffer[Data6] << 16) + (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
//        controllerStatus.activeFaults = (0x11 << 24) + (0x01 << 16) + (0x00 << 8) + 0x01;
        emit recvControllerStatusActiveFaults(controllerStatus);
    } else if (mPRBuffer[TypePackCounter] == 0x01) {
        controllerStatus.average1SecSpeed = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        controllerStatus.average1SecPower = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        controllerStatus.average1SecFlow = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        controllerStatus.activeAlarmAndPumpStatus.muteStatus = (mPRBuffer[Data6] >> 0) & 0x01;
        controllerStatus.activeAlarmAndPumpStatus.activeAlarm = (mPRBuffer[Data6] >> 1) & 0x07;
        controllerStatus.activeAlarmAndPumpStatus.pump_connmode = (mPRBuffer[Data6] >> 4) & 0x03;
        controllerStatus.activeAlarmAndPumpStatus.pump_command = (mPRBuffer[Data6] >> 6) & 0x01;
        controllerStatus.activeAlarmAndPumpStatus.pump_pmcmode = (mPRBuffer[Data6] >> 7) & 0x01;
        controllerStatus.activeAlarmAndPumpStatus.pump_state = (mPRBuffer[Data7] >> 0) & 0x07;
        controllerStatus.activeAlarmAndPumpStatus.intbatt_conn = (mPRBuffer[Data7] >> 3) & 0x01;
        controllerStatus.activeAlarmAndPumpStatus.controller_mode = (mPRBuffer[Data7] >> 4) & 0x0f;
        emit recvControllerStatus1Second(controllerStatus);
    } else if (mPRBuffer[TypePackCounter] == 0x02) {
        controllerStatus.maxpower_pm = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        controllerStatus.minpower_pm = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        controllerStatus.maxflow_pm = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        controllerStatus.minflow_pm = (mPRBuffer[Data7] << 8) + mPRBuffer[Data6];
//        emit recvControllerStatus1Minute(controllerStatus);
    } else if (mPRBuffer[TypePackCounter] == 0x03) {
        controllerStatus.flow_pi = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        controllerStatus.heartbeat = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        controllerStatus.iqCurrent = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        controllerStatus.powerState.wpowerType = mPRBuffer[Data6];
        controllerStatus.powerState.wpowerType = mPRBuffer[Data7];
//        emit recvControllerStatusHeartbeat(controllerStatus);
    } else if (mPRBuffer[TypePackCounter] == 0x04) {
        controllerStatus.powerState.bpowerType = mPRBuffer[Data0];
        controllerStatus.powerState.bpowerType = mPRBuffer[Data1];
    }
}

void ControllerCommunication::parsingControllerInfo()
{
    if (mPRBuffer[TypePackCounter] == 0x00) {
        controllerInfo.primaryVersion.Rev = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        controllerInfo.primaryVersion.Minor = mPRBuffer[Data2];
        controllerInfo.primaryVersion.Major = mPRBuffer[Data3];
// "V" + tFrameData[8].ToString() + "." + tFrameData[7].ToString() + "." + ((ushort)((tFrameData[6] << 8) + tFrameData[5])).ToString();
        controllerInfo.PumpVersion.Rev = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        controllerInfo.PumpVersion.Minor = mPRBuffer[Data6];
        controllerInfo.PumpVersion.Major = mPRBuffer[Data7];
    } else if (mPRBuffer[TypePackCounter] == 0x01) {
        controllerInfo.primaryAppId = (mPRBuffer[Data3] << 24) + (mPRBuffer[Data2] << 16) + (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        controllerInfo.monitorAppId = (mPRBuffer[Data7] << 24) + (mPRBuffer[Data6] << 16) + (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
    } else if (mPRBuffer[TypePackCounter] == 0x02) {
        controllerInfo.controllerSN[13] = mPRBuffer[Data0];
        controllerInfo.controllerSN[12] = mPRBuffer[Data1];
        controllerInfo.controllerSN[11] = mPRBuffer[Data2];
        controllerInfo.controllerSN[10] = mPRBuffer[Data3];
        controllerInfo.controllerSN[9] = mPRBuffer[Data4];
        controllerInfo.controllerSN[8] = mPRBuffer[Data5];
        controllerInfo.controllerSN[7] = mPRBuffer[Data6];
        controllerInfo.controllerSN[6] = mPRBuffer[Data7];
    } else if (mPRBuffer[TypePackCounter] == 0x03) {
        controllerInfo.controllerSN[5] = mPRBuffer[Data0];
        controllerInfo.controllerSN[4] = mPRBuffer[Data1];
        controllerInfo.controllerSN[3] = mPRBuffer[Data2];
        controllerInfo.controllerSN[2] = mPRBuffer[Data3];
        controllerInfo.controllerSN[1] = mPRBuffer[Data4];
        controllerInfo.controllerSN[0] = mPRBuffer[Data5];
        controllerInfo.crc16 = (mPRBuffer[Data7] << 8) + mPRBuffer[Data6];
        emit recvControllerInfo(controllerInfo);
    }
}

void ControllerCommunication::parsingPumpSpeedGet()
{
    if (mPRBuffer[TypePackCounter] == 0x00) {
        pumpSpeed.patientSpeedSetpoint = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        pumpSpeed.patientMinSpeed = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        pumpSpeed.patientMaxSpeed = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        pumpSpeed.powerThreshold = (mPRBuffer[Data7] << 8) + mPRBuffer[Data6];
        emit recvPumpSpeedGet(pumpSpeed);
    }
}

void ControllerCommunication::parsingActivityLogGet()
{
    if (mPRBuffer[TypePackCounter] == 0x00) {
        activityLog.handle = (mPRBuffer[Data3] << 24) + (mPRBuffer[Data2] << 16) + (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        activityLog.aclData.timeStamp = (mPRBuffer[Data7] << 24) + (mPRBuffer[Data6] << 16) + (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
    } else if (mPRBuffer[TypePackCounter] == 0x01) {
        activityLog.aclData.activityId = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        activityLog.aclData.priority = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        activityLog.aclData.errRecId = (mPRBuffer[Data7] << 24) + (mPRBuffer[Data6] << 16) + (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        emit recvActivityLogGet(activityLog);
    } else if (mPRBuffer[TypePackCounter] == 0x02) {
        activityLog.aclData.parameter1 = (mPRBuffer[Data3] << 24) + (mPRBuffer[Data2] << 16) + (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        activityLog.aclData.parameter2 = (mPRBuffer[Data7] << 24) + (mPRBuffer[Data6] << 16) + (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
    } else if (mPRBuffer[TypePackCounter] == 0x03) {
        activityLog.aclData.conMsgId = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        activityLog.aclData.crc16 = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        activityLog.pad = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        activityLog.crc16 = (mPRBuffer[Data7] << 8) + mPRBuffer[Data6];
    }
}

void ControllerCommunication::parsingControllerPowerStatus()
{
    if (mPRBuffer[TypePackCounter] == 0x00) {
        powerStatus.status = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        powerStatus.wpower.type = mPRBuffer[Data2];
        powerStatus.wpower.rc = mPRBuffer[Data3];
        powerStatus.wpower.temperature = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        powerStatus.wpower.cyclecount = (mPRBuffer[Data7] << 8) + mPRBuffer[Data6];
        emit recvControllerPowerStatus(powerStatus);
    } else if (mPRBuffer[TypePackCounter] == 0x01) {
        powerStatus.wpower.voltage = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        powerStatus.wpower.current = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        powerStatus.wpower.status = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        powerStatus.bpower.type = mPRBuffer[Data6];
        powerStatus.bpower.rc = mPRBuffer[Data7];
    } else if (mPRBuffer[TypePackCounter] == 0x02) {
        powerStatus.bpower.temperature = (mPRBuffer[Data1] << 8) + mPRBuffer[Data0];
        powerStatus.bpower.cyclecount = (mPRBuffer[Data3] << 8) + mPRBuffer[Data2];
        powerStatus.bpower.voltage = (mPRBuffer[Data5] << 8) + mPRBuffer[Data4];
        powerStatus.bpower.current = (mPRBuffer[Data7] << 8) + mPRBuffer[Data6];
    }
}

void ControllerCommunication::pumpControlSet(T_PumpControl pumpControl)
{
    char buffer[16] = {0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x03, 0x0D};
    buffer[0] = 0xD0;
    if (pumpControl.Flags == 1) {
        buffer[5] = 0x22;
        buffer[6] = 0x22;
        buffer[13] = 0x99;
        buffer[14] = 0x03;
//        serialThread->SendData(QByteArray(buffer, 16), true);
        uartSend(QByteArray(buffer, 16));
    } else if (pumpControl.Flags == 0) {
        buffer[5] = 0x55;
        buffer[6] = 0x55;
        buffer[13] = 0xBA;
        buffer[14] = 0xC1;
//        serialThread->SendData(QByteArray(buffer, 16), true);
        uartSend(QByteArray(buffer, 16));
    }
//    controlRealtimeStream(1);
//    controlRealtimeStream(1);
    pumpControlLast.Flags = pumpControl.Flags;
}

void ControllerCommunication::pumpSpeedSet(T_PumpSpeed pumpSpeed)
{
    char buffer[16] = {0, 0, 0, 0, 0x01, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[5] = pumpSpeed.patientSpeedSetpoint & 0xFF;
    buffer[6] = (pumpSpeed.patientSpeedSetpoint >> 8) & 0xFF;
//    buffer[7] = pumpSpeed.patientMinSpeed & 0xFF;
//    buffer[8] = (pumpSpeed.patientMinSpeed >> 8) & 0xFF;
//    buffer[9] = pumpSpeed.patientMaxSpeed & 0xFF;
//    buffer[10] = (pumpSpeed.patientMaxSpeed >> 8) & 0xFF;
    buffer[11] = pumpSpeed.powerThreshold & 0xFF;
    buffer[12] = (pumpSpeed.powerThreshold >> 8) & 0xFF;
    CommunicationProtocol sendbuf;
    uint16_t crc16 = sendbuf.Crc16(CRC16_INIT_VALUE, (uint8_t*)&buffer[1], 12);
    buffer[13] = crc16 & 0xFF;
    buffer[14] = (crc16 >> 8) & 0xFF;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::purgeExhaustStart()
{
    char buffer[16] = {0, 0, 0, 0, 0, 0x01, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[4] = 0x8C;
    buffer[13] = 0x79;
    buffer[14] = 0xEF;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::purgeCapacitySet(int16_t capacityMl)
{
    char buffer[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[4] = 0x8D;
    buffer[5] = capacityMl & 0xFF;
    buffer[6] = (capacityMl >> 8) & 0xFF;
    CommunicationProtocol sendbuf;
    uint16_t crc16 = sendbuf.Crc16(CRC16_INIT_VALUE, (uint8_t*)&buffer[1], 12);
    buffer[13] = crc16 & 0xFF;
    buffer[14] = (crc16 >> 8) & 0xFF;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::realTimeClockSet(unsigned int timestamp)//当前时间时间戳
{
    char buffer[16] = {0x0, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[5] = timestamp & 0xFF;
    buffer[6] = (timestamp >> 8) & 0xFF;
    buffer[7] = (timestamp >> 16) & 0xFF;
    buffer[8] = (timestamp >> 24) & 0xFF;
    CommunicationProtocol sendbuf;
    uint16_t crc16 = sendbuf.Crc16(CRC16_INIT_VALUE, (uint8_t*)&buffer[1], 12);
    buffer[13] = crc16 & 0xFF;
    buffer[14] = (crc16 >> 8) & 0xFF;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::controlRealtimeStream(unsigned char data)
{
    char buffer[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x0D};
    buffer[0] = 0xD0;
    buffer[4] = 0x16;
    buffer[5] = data;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    if (data & 0x1) {
        buffer[5] |= 0x01;//1 -启用实时流

    } else {
        buffer[5] &= 0xFE;//0 -禁用实时流
    }
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::startLogStream(T_LogDataType logRequest, unsigned short numberRequested)
{
    char buffer[16] = {0, 0, 0, 0, 0x1A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x0D};
    buffer[0] = 0xD0;
    buffer[5] = logRequest;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    if ((logRequest & 0x7FF) < LOG_TYPE_NUM) {
        buffer[5] = logRequest;            //日志类型
        buffer[7] = numberRequested & 0xFF;//请求的记录数
        buffer[8] = (numberRequested >> 8) & 0xFF;
        CommunicationProtocol sendbuf;
        uint16_t crc16 = sendbuf.Crc16(CRC16_INIT_VALUE, (uint8_t*)&buffer[1], 12);
        buffer[13] = crc16 & 0xFF;
        buffer[14] = (crc16 >> 8) & 0xFF;
        uartSend(QByteArray(buffer, 16));
    }
}

void ControllerCommunication::stopLogStream(T_LogDataType logRequest)
{
    char buffer[16] = {0, 0, 0, 0, 0x1A, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x0D};
    buffer[0] = 0xD0;
    buffer[3] = 0x80;
    buffer[5] = logRequest;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    if ((logRequest & 0x7FF) < LOG_TYPE_NUM) {
        buffer[5] = logRequest;            //日志类型
        CommunicationProtocol sendbuf;
        uint16_t crc16 = sendbuf.Crc16(CRC16_INIT_VALUE, (uint8_t*)&buffer[1], 12);
        buffer[13] = crc16 & 0xFF;
        buffer[14] = (crc16 >> 8) & 0xFF;
        uartSend(QByteArray(buffer, 16));
    }
}

void ControllerCommunication::pumpSpeedGet()
{
    char buffer[16] = {0, 0, 0, 0, 0x46, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::controllerStatusGet()
{
    char buffer[16] = {0, 0, 0, 0, 0x1f, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::controllerInfoGet()
{
    char buffer[16] = {0x00, 0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::controllerPowerStatusGet()
{
    char buffer[16] = {0, 0, 0, 0, 0x5D, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::muteAlarms()
{
    char buffer[16] = {0, 0, 0, 0, 0x15, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    uartSend(QByteArray(buffer, 16));
}

void ControllerCommunication::clearAlarms()
{
    char buffer[16] = {0, 0, 0, 0, 0x14, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x00, 0x0D};
    buffer[0] = 0xD0;
    buffer[13] = 0x82;
    buffer[14] = 0x83;
    uartSend(QByteArray(buffer, 16));
}

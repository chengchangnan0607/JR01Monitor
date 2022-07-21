#include "serialthread.h"

SerialThread::SerialThread(char *name, int baud_rate, QObject *parent) : QThread(parent)
{
    qDebug() << "SerialThread father Thread ID:" << currentThreadId();
    serialPortName = name;
    baudRate = baud_rate;
    if (serialPortInit() != true) {
        return;
    }
    mRun = true;
    moveToThread(this);
}

SerialThread::~SerialThread() {
    mRun = false;
    quit();
    wait();
}

void SerialThread::stop() {
    mRun = false;
    serialPort->clear();
    serialPort->close();
}

bool SerialThread::serialPortInit() {
    QSerialPortInfo info(serialPortName);
    serialPort = new QSerialPort(info,this);
//    serialPort = new QSerialPort(info);
    serialPort->setPortName(serialPortName);
    if(serialPort->isOpen())//如果串口已经打开了 先给他关闭了
    {
        serialPort->clear();
        serialPort->close();
    }
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setBaudRate(baudRate);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qWarning() << "open serial port fail:" << serialPortName << "baud:" << baudRate << serialPort->error();
        return false;
    }
    serialPort->readAll();  // 清空数据
    qInfo() << "open serial success:" << serialPortName << "baud:" << baudRate;
    return true;
}

void SerialThread::run() {

    while (mRun) {
//        bool haveData = serialPort->waitForReadyRead(50); //读取数据,50ms
        bool haveData = serialPort->waitForReadyRead(0); //读取数据
        if (haveData) {
            QByteArray data = serialPort->readAll();
            if (data.length() > 0) {
                //        qDebug()<<"receive data:" << data.toHex();
                //        qDebug() << "data.length = " << data.length();
                emit sRecvData(data);     //数据处理
//                interval = QDateTime::currentMSecsSinceEpoch() - lastTime;
//                lastTime = QDateTime::currentMSecsSinceEpoch();
//                packNumber += 1;
//                if ((interval > 31) || (interval < 29)) {
////                vectorInteveval.append(interval);
//                    qDebug()  << QString::number(packNumber) << QString::number(interval);
//                }
            }
        }

        QByteArray send;                                 //发送数据
        getSendData(send);
        if (send.size()>0) {

//            qDebug() << QDateTime::currentMSecsSinceEpoch() << "SendData data:" << send.toHex();
            serialPort->write(send);
//            qint64 length = serialPort->write(send);
//            qDebug() << QDateTime::currentMSecsSinceEpoch() << "write length:" << QString::number(length);
        }
    }
}

void SerialThread::SendData(QByteArray data) {
    if (data.size() > 0) {
//        qDebug()<<"SendData start:" << QDateTime::currentMSecsSinceEpoch();
//        serialPort->write(data);
//        qDebug()<<"SendData stop:" << QDateTime::currentMSecsSinceEpoch();
        QMutexLocker locker(&mSendMutex);
        mSendData.append(data);//存入
    }
}

void SerialThread::getSendData(QByteArray &data) {
    if (mSendData.length() > 0) {
        QMutexLocker locker(&mSendMutex);
        data = mSendData[0];
        mSendData.pop_front();//移除
    }
}

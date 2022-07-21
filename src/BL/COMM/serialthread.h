#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QMutex>
#include <QtSerialPort>

class SerialThread : public QThread
{
    Q_OBJECT
public:
    explicit SerialThread(char *name, int baud_rate, QObject *parent = nullptr);
    virtual ~SerialThread();

    void SendData(QByteArray data);
    void stop();

    QSerialPort  *serialPort;

signals:
    void sRecvData(QByteArray data);

protected:
    bool serialPortInit();
    void run();
    void getSendData(QByteArray &data);

    QString serialPortName;
    int baudRate;

    bool mRun;

private:
    qint64 lastTime = 0;
    int interval = 0;
    int packNumber = 0;

    QMutex mSendMutex;
    QVector<QByteArray> mSendData;
};

#endif // SERIALTHREAD_H

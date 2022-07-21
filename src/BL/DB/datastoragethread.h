#ifndef DATASTORAGETHREAD_H
#define DATASTORAGETHREAD_H

#include <QThread>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <QDebug>
#include <QMutex>
#include "../COMM/communicationprotocol.h"
#include "database.h"

struct PumpRecord {
    int speed;
    int power;
    int flow;
    float pressuremmHg;
    int purgeFlow;
    int purgePressure;
    long long timeStamp;
};

class DataStorageThread : public QThread
{
    Q_OBJECT
public:
    explicit DataStorageThread(QObject *parent = nullptr);
    virtual ~DataStorageThread();
    void stop();
    void openTable(QString tableName);

    bool getPumpRecord(PumpRecord &pumpRecord);

    bool mRun;

    QSqlTableModel* modelHistoryData;
    QVector<PumpRecord> savePumpRecord;
    int currentDateTable;
protected:

    void run();

public slots:
    void saveRTS(T_RTS realTimeDataStream);
    void createTable();
private:
    QMutex mutexHistoryData;
};

#endif // DATASTORAGETHREAD_H

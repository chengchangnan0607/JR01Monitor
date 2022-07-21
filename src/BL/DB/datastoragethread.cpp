#include "datastoragethread.h"

DataStorageThread::DataStorageThread(QObject *parent) : QThread(parent)
{
    qDebug() << "DataStorageThread father Thread ID:" << currentThreadId();
//    connectionStatus = false;
    mRun = true;
    mutexOperateDatabase.lock();
    openTable(todayBloodBumpHistoryTable);
    mutexOperateDatabase.unlock();
    moveToThread(this);
}

DataStorageThread::~DataStorageThread() {
    mRun = false;
    quit();
    wait();
}

void DataStorageThread::stop() {
    mRun = false;
}

void DataStorageThread::run() {
    qDebug() << "DataStorageThread Thread ID:" << currentThreadId();
    PumpRecord pumpRecord;
    mutexOperateDatabase.lock();
    modelHistoryData->select();
    mutexOperateDatabase.unlock();
    while (mRun) {
        if (getPumpRecord(pumpRecord) == true) {      //数据库操作
            mutexOperateDatabase.lock();
            QSqlRecord record = modelHistoryData->record(0);
            record.setValue("speed", pumpRecord.speed);
            record.setValue("power", pumpRecord.power);
            record.setValue("flow", pumpRecord.flow);
            record.setValue("pressuremmHg", pumpRecord.pressuremmHg);
            record.setValue("purgeFlow", pumpRecord.purgeFlow);
            record.setValue("purgePressure", pumpRecord.purgePressure);
            record.setValue("timeStamp", pumpRecord.timeStamp);
            modelHistoryData->insertRecord(-1, record);//末尾插入
            if ((modelHistoryData->rowCount() % 256) == 0) {
                qDebug() <<"DataStorageThread ID:" <<currentThreadId() << "start: "<< QString::number(QDateTime::currentMSecsSinceEpoch());
                modelHistoryData->database().transaction();//开始事务操作
                if (modelHistoryData->submitAll()) {       //提交所有被修改的数据到数据库中
                    modelHistoryData->database().commit(); //提交成功，事务将真正修改数据库数据
                } else {
                    modelHistoryData->database().rollback();//提交失败，事务回滚
                }
                qDebug() << "end:     " << QString::number(QDateTime::currentMSecsSinceEpoch());
            }
            mutexOperateDatabase.unlock();
        }
        msleep(10);
    }
}

void DataStorageThread::openTable(QString tableName)
{
    qDebug() << "Open Table : "<< tableName;
//    mutexOperateDatabase.lock();
    modelHistoryData = new QSqlTableModel(this);
    modelHistoryData->setTable(tableName);
    qDebug() << "modelHistoryData" << modelHistoryData->lastError();
    modelHistoryData->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelHistoryData->setSort(6, Qt::AscendingOrder); //timeStamp属性，即第6列，AscendingOrder升序排列,Qt::DescendingOrder为降序排序
//    modelHistoryData->select();
    modelHistoryData->setHeaderData(0, Qt::Horizontal, QString("转速"));
    modelHistoryData->setHeaderData(1, Qt::Horizontal, QString("功率"));
    modelHistoryData->setHeaderData(2, Qt::Horizontal, QString("流量"));
    modelHistoryData->setHeaderData(3, Qt::Horizontal, QString("压力"));
    modelHistoryData->setHeaderData(4, Qt::Horizontal, QString("冲洗流量"));
    modelHistoryData->setHeaderData(5, Qt::Horizontal, QString("冲洗压力"));
    modelHistoryData->setHeaderData(6, Qt::Horizontal, QString("时间戳"));
//    while(modelHistoryData->canFetchMore()){
//        modelHistoryData->fetchMore();
//    }
//    qDebug() << "rowCount is " << QString::number(modelHistoryData->rowCount());
//    mutexOperateDatabase.unlock();
}

//void DataStorageThread::closeTable()
//{
//    delete modelHistoryData;
//    modelHistoryData = NULL;
//}

bool DataStorageThread::getPumpRecord(PumpRecord &pumpRecord)
{
    if (savePumpRecord.length() > 0) {
        QMutexLocker locker(&mutexHistoryData);
        pumpRecord = savePumpRecord[0];
        savePumpRecord.pop_front();
//        qDebug()<<"getPumpRecord true Thread ID:" <<currentThreadId();
        return true;
    } else {
//        qDebug()<<"getPumpRecord flase Thread ID:" <<currentThreadId();
        return false;
    }
}



void DataStorageThread::saveRTS(T_RTS realTimeDataStream)
{
    createTable();
    PumpRecord pumpRecord;
    pumpRecord.speed = realTimeDataStream.speed;
    pumpRecord.power = realTimeDataStream.power;
    pumpRecord.flow = realTimeDataStream.flow;
    CommunicationProtocol temp;
    pumpRecord.pressuremmHg = temp.calculatePressure(realTimeDataStream.sensorData);
    pumpRecord.purgeFlow = realTimeDataStream.purgeDate.flowRate;
    pumpRecord.purgePressure = realTimeDataStream.purgeDate.pressure;
    pumpRecord.timeStamp = QDateTime::currentMSecsSinceEpoch();
    QMutexLocker locker(&mutexHistoryData);
    savePumpRecord.append(pumpRecord);
}

void DataStorageThread::createTable()
{
    QString dateStr = QDate::currentDate().toString("yyyyMMdd");
    if (!todayBloodBumpHistoryTable.contains(dateStr)) {
        mutexOperateDatabase.lock();
        todayBloodBumpHistoryTable = "historyData_" + dateStr;
        QSqlQuery queryBloodPumpHistoryData(dbLog);
        QString tableStr = "create table historyData_" + dateStr + "(speed int, power int, flow int, pressuremmHg float, purgeFlow int, purgePressure int, timeStamp long long)";
        queryBloodPumpHistoryData.exec(tableStr);
        bloodBumpTables = dbLog.tables(QSql::Tables);
        modelHistoryData->setTable(todayBloodBumpHistoryTable);
        modelHistoryData->select();
        mutexOperateDatabase.unlock();
    }
}

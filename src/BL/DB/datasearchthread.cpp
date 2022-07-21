#include "datasearchthread.h"

DataSearchThread::DataSearchThread(QObject *parent) : QThread(parent)
{
    qDebug() << "DataSearchThread2 father Thread ID:" << currentThreadId();
    mutexOperateDatabase.lock();
    openTable(todayBloodBumpHistoryTable);
    currentOpenHistoryTable = todayBloodBumpHistoryTable;
    mutexOperateDatabase.unlock();
    mRun = true;
    moveToThread(this);
}

DataSearchThread::~DataSearchThread() {
    mRun = false;
    quit();
    wait();
}

void DataSearchThread::stop() {
    mRun = false;
}
void DataSearchThread::run()
{
    qDebug() << "DataSearchThread2 Thread ID:" << currentThreadId();
    while (mRun) {
        QString conditionValue = getSearchValue();
        if (conditionValue != "") {
            qDebug() << conditionValue  << "start: " << QString::number(QDateTime::currentMSecsSinceEpoch());
            mutexOperateDatabase.lock();
            modelHistoryData->setFilter(conditionValue);
            modelHistoryData->select();
            while(modelHistoryData->canFetchMore()){
                 modelHistoryData->fetchMore();
            }
            rowCount = modelHistoryData->rowCount();
            mutexOperateDatabase.unlock();
            qDebug() << "end: "<< QString::number(QDateTime::currentMSecsSinceEpoch());
            emit dataSearchFinish(rowCount);
        }
        msleep(100);
    }
}

bool DataSearchThread::openTable(QString tableName)
{
    bloodBumpTables = dbLog.tables(QSql::Tables);
    for (int i = 0; i < bloodBumpTables.size(); i++) {
        if (bloodBumpTables[i] == tableName) {
            qDebug() << "Open Table : "<< tableName;
            modelHistoryData = new QSqlTableModel(this);
            modelHistoryData->setTable(tableName);
            modelHistoryData->setEditStrategy(QSqlTableModel::OnManualSubmit);
            modelHistoryData->setSort(6, Qt::AscendingOrder); //timeStamp属性，即第6列，AscendingOrder升序排列,Qt::DescendingOrder为降序排序

            modelHistoryData->setHeaderData(0, Qt::Horizontal, QString("转速"));
            modelHistoryData->setHeaderData(1, Qt::Horizontal, QString("功率"));
            modelHistoryData->setHeaderData(2, Qt::Horizontal, QString("流量"));
            modelHistoryData->setHeaderData(3, Qt::Horizontal, QString("压力"));
            modelHistoryData->setHeaderData(4, Qt::Horizontal, QString("冲洗流量"));
            modelHistoryData->setHeaderData(5, Qt::Horizontal, QString("冲洗压力"));
            modelHistoryData->setHeaderData(6, Qt::Horizontal, QString("时间戳"));
            return true;
        }
    }
    qDebug() << "Open Table " << tableName << " fail! " << "bloodBumpTables size is " <<bloodBumpTables.size();
    return false;
}

QString DataSearchThread::getSearchValue()
{
    QString conditionValue;
    if (ConditionValues.length() > 0) {
        QMutexLocker locker(&mutexHistoryData);
        conditionValue = ConditionValues.last();//如果有多个，就只取最后一个
        ConditionValues.clear();
    } else {
        conditionValue = "";
    }
    return(conditionValue);
}

void DataSearchThread::search(QString tableName, QString conditionValue)
{
    if (currentOpenHistoryTable != tableName) {
        mutexOperateDatabase.lock();
        modelHistoryData->setTable(tableName);
        currentOpenHistoryTable = tableName;
        mutexOperateDatabase.unlock();
    }
    QMutexLocker locker(&mutexHistoryData);
    ConditionValues.append(conditionValue);
}

#ifndef DATASEARCHTHREAD_H
#define DATASEARCHTHREAD_H

#include <QThread>
#include <QSqlTableModel>
#include <QDateTime>
#include <QDebug>
#include <QMutex>
#include "database.h"

class DataSearchThread : public QThread
{
    Q_OBJECT
public:
    explicit DataSearchThread(QObject *parent = nullptr);
    virtual ~DataSearchThread();

    void stop();
    bool openTable(QString tableName);
    void search(QString tableName, QString conditionValue);
    QString getSearchValue();

    bool mRun;

    QSqlTableModel* modelHistoryData;
    QVector<QString> ConditionValues;
    unsigned int rowCount = 0;

signals:
    void dataSearchFinish(unsigned int rowCount);

protected:

    void run();

private:
    QMutex mutexHistoryData;
    QString currentOpenHistoryTable;
};

#endif // DATASEARCHTHREAD_H

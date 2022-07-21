#include "database.h"

QMutex mutexOperateDatabase;
QSqlDatabase dbLog;
QStringList bloodBumpTables;
QString todayBloodBumpHistoryTable;

bool createConnection()
{
    qDebug() << "Available Database drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString dvr, drivers) {
        qDebug() << dvr;
    }

    dbLog = QSqlDatabase::addDatabase("QSQLITE");
    dbLog.setDatabaseName("bloodPump.db");
    qDebug() << "dbLog coonectionName is "<< dbLog.connectionName();
    if (!dbLog.open()) {
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
            QObject::tr("Unable to establish a database connection.\n"
                        "This example needs SQLite support. Please read "
                        "the Qt SQL driver documentation for information how "
                        "to build it.\n\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }
    QSqlQuery queryBloodPumpHistoryData(dbLog);
    bloodBumpTables = dbLog.tables(QSql::Tables);
    todayBloodBumpHistoryTable = "";
    QString dateStr = QDate::currentDate().toString("yyyyMMdd");
    for (int i = 0; i < bloodBumpTables.size(); i++) {
        qDebug() << bloodBumpTables[i];
        if (bloodBumpTables[i] == "historyData_" + dateStr) {
            todayBloodBumpHistoryTable = bloodBumpTables[i];
            break;
        }
    }
    qDebug() << "bloodBumpTables size is " << bloodBumpTables.size();
    if (todayBloodBumpHistoryTable == "") {
        QString tableStr = "create table historyData_" + dateStr + "(speed int, power int, flow int, pressuremmHg float, purgeFlow int, purgePressure int, timeStamp long long)";
        queryBloodPumpHistoryData.exec(tableStr);
        bloodBumpTables = dbLog.tables(QSql::Tables);
        todayBloodBumpHistoryTable = "historyData_" + dateStr;
    }
    qDebug() << "todayBloodBumpHistoryTable is " << todayBloodBumpHistoryTable << ", bloodBumpTables size is " << bloodBumpTables.size();
    qDebug() << "Database created successfully";
    return true;
}

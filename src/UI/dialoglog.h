#ifndef DIALOGLOG_H
#define DIALOGLOG_H

#include <QDialog>
#include <QStandardItemModel>
#include "../BL/COMM/controllercommunication.h"

namespace Ui {
class DialogLog;
}

class DialogLog : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLog(QWidget *parent = nullptr);
    ~DialogLog();
    void startActivityLog();
    void stopActivityLog();
    void addActiveFaults(T_AclIndex actFault);
    bool isExistsFaults(T_AclIndex actFault);
    void addActiveEvents(T_AclIndex actEvent);
    bool isExistsEvents(T_AclIndex actEvent);

    QStandardItemModel *alarmModel;
    QStandardItemModel *eventModel;

private:
    Ui::DialogLog *ui;

signals:
    void startLogStream(T_LogDataType logRequest, unsigned short numberRequested);
    void stopLogStream(T_LogDataType logRequest);

public slots:
    void displayActivityLog(T_ActivityLog activityLog);
    void buttonAlarmHandle();
    void buttonEventHandle();
};

#endif // DIALOGLOG_H

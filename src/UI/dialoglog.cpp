#include "dialoglog.h"
#include "ui_dialoglog.h"

DialogLog::DialogLog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog);
//    setStyleSheet("QDialog{background: blue;}");

    alarmModel = new QStandardItemModel();
    alarmModel->setHorizontalHeaderItem(0, new QStandardItem("优先级"));
    alarmModel->setHorizontalHeaderItem(1, new QStandardItem("报警日志"));
    alarmModel->setHorizontalHeaderItem(2, new QStandardItem("发生时间"));
    alarmModel->setHorizontalHeaderItem(3, new QStandardItem("解决方法"));

    eventModel = new QStandardItemModel();
    eventModel->setHorizontalHeaderItem(0, new QStandardItem("优先级"));
    eventModel->setHorizontalHeaderItem(1, new QStandardItem("事件日志"));
    eventModel->setHorizontalHeaderItem(2, new QStandardItem("发生时间"));
    eventModel->setHorizontalHeaderItem(3, new QStandardItem("解决方法"));

    ui->tableView->setModel(alarmModel);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);//设置表头信息居中
    ui->tableView->setColumnWidth(0,80);			//参数：列号，宽度
    ui->tableView->setColumnWidth(1,185);
    ui->tableView->setColumnWidth(2,210);
    ui->tableView->setColumnWidth(3,200);
//    ui->tableView->verticalHeader()->hide(); //隐藏行头
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);//设置表格选中时为整行选中
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格的单元为只读属性，即不能编辑
//    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);//设置单选
//    ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection); //设置多选

//    alarmModel->setItem(0, 0, new QStandardItem("高"));
//    alarmModel->setItem(0, 1, new QStandardItem("泵连接失败"));
//    alarmModel->setItem(0, 2, new QStandardItem("2022-05-17 23:45:06"));
//    alarmModel->setItem(0, 3, new QStandardItem("请连接泵"));
//    alarmModel->setItem(1, 0, new QStandardItem("中"));
//    alarmModel->setItem(1, 1, new QStandardItem("泵流量超出范围"));
//    alarmModel->setItem(1, 2, new QStandardItem("2022-05-17 23:45:06"));
//    alarmModel->setItem(1, 3, new QStandardItem("请尽快联系医院"));
//    alarmModel->setItem(2, 0, new QStandardItem("低"));
//    alarmModel->setItem(2, 1, new QStandardItem("未设置时钟"));
//    alarmModel->setItem(2, 2, new QStandardItem("2022-05-17 23:45:06"));
//    alarmModel->setItem(2, 3, new QStandardItem("请设置时钟"));

    connect(ui->pushButton_Alarm, &QPushButton::clicked, this, &DialogLog::buttonAlarmHandle);
    connect(ui->pushButton_Event, &QPushButton::clicked, this, &DialogLog::buttonEventHandle);
    connect(ui->pushButton_Close, &QPushButton::clicked, this, &DialogLog::accept);
}

DialogLog::~DialogLog()
{
    delete ui;
}

void DialogLog::startActivityLog()
{
    emit startLogStream(LOG_TYPE_ACT, 0x7D0);
}

void DialogLog::stopActivityLog()
{
    emit stopLogStream(LOG_TYPE_ACT);
}

void DialogLog::displayActivityLog(T_ActivityLog activityLog)
{
    if (activityLog.aclData.activityId & 0x800) {     //事件日志
        T_AclIndex actEvent;
        actEvent.activityId = activityLog.aclData.activityId & 0x7ff;
        actEvent.timeStamp = activityLog.aclData.timeStamp;
        addActiveEvents(actEvent);
    } else {                                          //报警日志
        T_AclIndex actFault;
        actFault.activityId = activityLog.aclData.activityId & 0x7ff;
        actFault.timeStamp = activityLog.aclData.timeStamp;
//        if (activityLog.aclData.activityId & 0x8000) {//报警置位事件Fault_Set
//            addActiveFaults(actFault, 1);
//        } else {                                      //报警清除事件Fault_Clear
//            addActiveFaults(actFault, 0);
//        }
        addActiveFaults(actFault);
    }
}

bool DialogLog::isExistsFaults(T_AclIndex actFault)
{
    for (int i = 0; i < alarmModel->rowCount(); i++) {
        if ((alarmModel->item(i, 1)->text() == faults[actFault.activityId][1]) && (alarmModel->item(i, 2)->text() == QDateTime::fromTime_t(actFault.timeStamp).toString("yyyy-MM-dd hh:mm:ss"))) {
            return (true);
        }
    }
    return (false);
}

bool DialogLog::isExistsEvents(T_AclIndex actEvent)
{
    for (int i = 0; i < eventModel->rowCount(); i++) {
        if ((eventModel->item(i, 1)->text() == events[actEvent.activityId]) && (eventModel->item(i, 2)->text() == QDateTime::fromTime_t(actEvent.timeStamp).toString("yyyy-MM-dd hh:mm:ss"))) {
            return (true);
        }
    }
    return (false);
}

//void AlarmWindow::addActiveFaults(T_AclIndex actFault, bool flagSetClear)//1=Set; 0=Clear
void DialogLog::addActiveFaults(T_AclIndex actFault)
{
    bool isExistsFault = isExistsFaults(actFault);
    if (isExistsFault == false) {
        QString StatusPriority = faults[actFault.activityId][0];
        QStandardItem *item0 = new QStandardItem(StatusPriority);
        if (StatusPriority == "高") {
            item0->setData(QVariant(QColor(Qt::red)), Qt::ForegroundRole);
        } else if (StatusPriority == "中") {
            item0->setData(QVariant(QColor(Qt::darkYellow)), Qt::ForegroundRole);
        } else if (StatusPriority == "低") {
            item0->setData(QVariant(QColor(Qt::cyan)), Qt::ForegroundRole);
        }
        int rowCount = alarmModel->rowCount();
        alarmModel->setItem(rowCount, 0, item0);
        QStandardItem *item1 = new QStandardItem(faults[actFault.activityId][1]);
        alarmModel->setItem(rowCount, 1, item1);
        QDateTime dateTime = QDateTime::fromTime_t(actFault.timeStamp);
        QStandardItem *item2 = new QStandardItem(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
        alarmModel->setItem(rowCount, 2, item2);
        QStandardItem *item3 = new QStandardItem(faults[actFault.activityId][2]);
        alarmModel->setItem(rowCount, 3, item3);
        alarmModel->sort(2, Qt::DescendingOrder);
    }
}

void DialogLog::addActiveEvents(T_AclIndex actEvent)
{
    bool isExistsEvent = isExistsEvents(actEvent);
    if (isExistsEvent == false)
    {
        int rowCount = eventModel->rowCount();
        QStandardItem *item1 = new QStandardItem(events[actEvent.activityId]);
        eventModel->setItem(rowCount, 1, item1);
        QDateTime dateTime = QDateTime::fromTime_t(actEvent.timeStamp);
        QStandardItem *item2 = new QStandardItem(dateTime.toString("yyyy-MM-dd hh:mm:ss"));
        eventModel->setItem(rowCount, 2, item2);
        eventModel->sort(2, Qt::DescendingOrder);
    }
}

void DialogLog::buttonAlarmHandle()
{
    ui->label->setText("报警日志显示");
    ui->tableView->setModel(alarmModel);
}

void DialogLog::buttonEventHandle()
{
    ui->label->setText("事件日志显示");
    ui->tableView->setModel(eventModel);
}

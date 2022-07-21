#include "dialoghistoricaldatatimeset.h"
#include "ui_dialoghistoricaldatatimeset.h"

DialogHistoricalDataTimeSet::DialogHistoricalDataTimeSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistoricalDataTimeSet)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog);
//    setStyleSheet("QDialog{background: gray;}");

    connect(ui->pushButton_StartTime, &QPushButton::clicked, this, &DialogHistoricalDataTimeSet::startTimeSetting);
    connect(ui->pushButton_EndTime, &QPushButton::clicked, this, &DialogHistoricalDataTimeSet::endTimeSetting);
    connect(ui->pushButton_SamplingPeriod, &QPushButton::clicked, this, &DialogHistoricalDataTimeSet::samplingRateSetting);
    connect(ui->pushButton_Cancel, &QPushButton::clicked, this, &DialogHistoricalDataTimeSet::reject);
    connect(ui->pushButton_OK, &QPushButton::clicked, this, &DialogHistoricalDataTimeSet::accept);
    QStringList levels;
    int index = bloodBumpTables.size() - 1;
    for (int i = 0; i < bloodBumpTables.size(); i++) {
        if (bloodBumpTables[i].contains("historyData_")) {
            levels << bloodBumpTables[index - i].mid(12);
        }
    }
    ui->comboBox_Date->addItems(levels);
}

DialogHistoricalDataTimeSet::~DialogHistoricalDataTimeSet()
{
    delete ui;
}

void DialogHistoricalDataTimeSet::readSetupVal(struct historyDataParameters *parameters)
{
    QString dateStr = ui->comboBox_Date->currentText();
    parameters->dateStr = dateStr;

    QString startTimeStr = ui->pushButton_StartTime->text();
    if ((startTimeStr.length() == 5) && (startTimeStr[2] == ':')) {
        QString hourStr = startTimeStr.mid(0, 2);
        startHourInt = hourStr.toInt();
        QString minuteStr = startTimeStr.mid(3, 2);
        startMinuteInt = minuteStr.toInt();
    } else {
        startHourInt = startMinuteInt = 0;
    }

//    QString startDateTimeStr = dateStr + " " + startTimeStr + ":00";
    QString startDateTimeStr = dateStr + " " + QString::number(startHourInt).sprintf("%02d", startHourInt) + ":" + QString::number(startMinuteInt).sprintf("%02d", startMinuteInt) + ":00";
    QDateTime startDateTime = QDateTime::fromString(startDateTimeStr, "yyyyMMdd hh:mm:ss");
    parameters->startTimeStampVal = startDateTime.toTime_t();

    QString endTimeStr = ui->pushButton_EndTime->text();
    if ((endTimeStr.length() == 5) && (endTimeStr[2] == ':')) {
        QString hourStr = endTimeStr.mid(0, 2);
        endHourInt = hourStr.toInt();
        QString minuteStr = endTimeStr.mid(3, 2);
        endMinuteInt = minuteStr.toInt();
    } else {
        endHourInt = endMinuteInt = 0;
    }

    QString endDateTimeStr = dateStr + " " + QString::number(endHourInt).sprintf("%02d", endHourInt) + ":" + QString::number(endMinuteInt).sprintf("%02d", endMinuteInt) + ":00";
    QDateTime endDateTime = QDateTime::fromString(endDateTimeStr, "yyyyMMdd hh:mm:ss");
    parameters->endTimeStampVal = endDateTime.toTime_t();

    parameters->samplingPeriod = samplingPeriod;
}

void DialogHistoricalDataTimeSet::startTimeSetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("格式:hhmm,如12时03分:1203");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        if (dateStr.length() == 4) {
            QString hourStr = dateStr.mid(0, 2);
            startHourInt = hourStr.toInt();
            QString minuteStr = dateStr.mid(2, 2);
            startMinuteInt = minuteStr.toInt();
            QString secondStr = dateStr.mid(4, 2);
            if ((startHourInt < 24) && (startMinuteInt < 60)) {
                ui->pushButton_StartTime->setText(hourStr + ":" + minuteStr );
            } else {
                qDebug() << "输入时间格式不正确";
                startHourInt = startMinuteInt = 0;
            }
        } else {
            qDebug() << "输入时间格式不正确";
            startHourInt = startMinuteInt = 0;
        }
    }
    delete digitalInput;
}

void DialogHistoricalDataTimeSet::endTimeSetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("格式:hhmm,如12时03分:1203");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        if (dateStr.length() == 4) {
            QString hourStr = dateStr.mid(0, 2);
            endHourInt = hourStr.toInt();
            QString minuteStr = dateStr.mid(2, 2);
            endMinuteInt = minuteStr.toInt();
            QString secondStr = dateStr.mid(4, 2);
            if ((endHourInt < 24) && (endMinuteInt < 60)) {
                ui->pushButton_EndTime->setText(hourStr + ":" + minuteStr );
            } else {
                qDebug() << "输入时间格式不正确";
            }
        } else {
            qDebug() << "输入时间格式不正确";
        }
    }
    delete digitalInput;
}

void DialogHistoricalDataTimeSet::samplingRateSetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("单位毫秒，最小值30,最大值3600000");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        if (dateStr.toInt() > 3600000) {
            samplingPeriod = 3600000;
        } else {
            samplingPeriod = dateStr.toInt();
        }
        ui->pushButton_SamplingPeriod->setText(QString::number(samplingPeriod));
    }
    delete digitalInput;
}

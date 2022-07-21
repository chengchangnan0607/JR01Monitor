#include "dialogsystemset.h"
#include "ui_dialogsystemset.h"

DialogSystemSet::DialogSystemSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSystemSet)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog);
//    setStyleSheet("QDialog{background: gray;}");
    setStyleSheet("QDialog{background: rgb(238, 238, 236);}");
    ui->pushButton_Date->setText(dateTimeSetVal.toString("yyyy-MM-dd"));
    ui->pushButton_Time->setText(dateTimeSetVal.toString("hh:mm:ss"));
    connect(ui->pushButton_Date, &QPushButton::clicked, this, &DialogSystemSet::dateSetting);
    connect(ui->pushButton_Time, &QPushButton::clicked, this, &DialogSystemSet::timeSetting);
    connect(ui->pushButton_CavityLength, &QPushButton::clicked, this, &DialogSystemSet::lengthSetting);
    connect(ui->pushButton_Sensitivity, &QPushButton::clicked, this, &DialogSystemSet::sensitivitySetting);
    connect(ui->pushButton_Calibration, &QPushButton::clicked, this, &DialogSystemSet::pressureZeroCalibration);
    connect(ui->pushButton_BPSpeed, &QPushButton::clicked, this, &DialogSystemSet::bloodPumpSpeed);
    connect(ui->pushButton_PowerOff, &QPushButton::clicked, this, &DialogSystemSet::powerOffHandle);
    connect(ui->pushButton_Cancel, &QPushButton::clicked, this, &DialogSystemSet::reject);
    connect(ui->pushButton_OK, &QPushButton::clicked, this, &DialogSystemSet::accept);
    QString Version = softVersion;
    ui->label_SystemVersion->setText("应用版本: " + Version);
}

DialogSystemSet::~DialogSystemSet()
{
    delete ui;
}

void DialogSystemSet::setSpeed(unsigned short speedVal)
{
    ui->pushButton_BPSpeed->setText(QString::number(speedVal));
}

void DialogSystemSet::dateSetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("格式:yyyyMMdd,如2022年5月17日:20220517");
    digitalInput->disableButton_p(false);
//    Qt::WindowFlags flags = digitalInput->windowFlags();
//    setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
    digitalInput->setModal(true);
//    digitalInput->show();
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        if (dateStr.length() == 8) {
            QString yearStr = dateStr.mid(0, 4);
            yearInt = yearStr.toInt();
            QString monthStr = dateStr.mid(4, 2);
            monthInt = monthStr.toInt();
            QString dayStr = dateStr.mid(6, 2);
            dayInt = dayStr.toInt();
            if ((monthInt > 0) && (monthInt < 13) && (dayInt > 0) && (dayInt < 32)) {
                ui->pushButton_Date->setText(yearStr + "-" + monthStr + "-" + dayStr);
                dateTimeSetVal.addYears(yearInt);
                dateTimeSetVal.addMonths(monthInt);
                dateTimeSetVal.addDays(dayInt);
            } else {
                qDebug() << "输入日期格式不正确";
            }
        } else {
            qDebug() << "输入日期格式不正确";
        }
    }
    delete digitalInput;
}

void DialogSystemSet::timeSetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("格式:hhmmss,如12时03分17秒:120317");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        if (dateStr.length() == 6) {
            QString hourStr = dateStr.mid(0, 2);
            hourInt = hourStr.toInt();
            QString minuteStr = dateStr.mid(2, 2);
            minuteInt = minuteStr.toInt();
            QString secondStr = dateStr.mid(4, 2);
            secondInt = secondStr.toInt();
            if ((hourInt < 24) && (minuteInt < 60) && (secondInt < 60)) {
                ui->pushButton_Time->setText(hourStr + ":" + minuteStr + ":" + secondStr);
                QTime time(hourInt, minuteInt, secondInt);
                dateTimeSetVal.setTime(time);
            } else {
                qDebug() << "输入时间格式不正确";
            }
        } else {
            qDebug() << "输入时间格式不正确";
        }
    }
    delete digitalInput;
}

void DialogSystemSet::sensitivitySetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("光纤压力传感器:灵敏度");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        sensitivity = dateStr.toInt();
        ui->pushButton_Sensitivity->setText(dateStr);
    }
    delete digitalInput;
}

void DialogSystemSet::lengthSetting()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("光纤压力传感器:初始腔长");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        cavityLength = dateStr.toInt();
        ui->pushButton_CavityLength->setText(dateStr);
    }
    delete digitalInput;
}

void DialogSystemSet::pressureZeroCalibration()
{
    QMessageBox calibrationMsgBox(this);
    calibrationMsgBox.setWindowTitle("光纤压力传感器:压力校零");
    QPushButton* yes = calibrationMsgBox.addButton("是",QMessageBox::ActionRole);
    QPushButton* no = calibrationMsgBox.addButton("否",QMessageBox::ActionRole);
    calibrationMsgBox.setText("<font size='14' color='black'> 确认将当前压力设为零？ </font>");
    calibrationMsgBox.setStyleSheet(
        "QPushButton {"
                        "background-color: #89AFDE;"
                        " border-style: outset;"
                        " border-width: 2px;"
                        " border-radius: 10px;"
                        " border-color: beige;"
                        " font: bold 24px;"
                        " min-width: 100;"
                        " min-height: 51;"
                        "}"
    );
    calibrationMsgBox.setMaximumSize(512, 384);
    calibrationMsgBox.setMinimumSize(512, 384);
//    calibrationMsgBox.setStyleSheet("background-color: rgb(136, 138, 133)");
//    calibrationMsgBox.setStyleSheet("background-color: white");
    calibrationMsgBox.exec();
    if(calibrationMsgBox.clickedButton() == yes) {
        qDebug() << "pressureZeroCalibration yes ....";
    } else if(calibrationMsgBox.clickedButton() == no) {
        qDebug() << "pressureZeroCalibration no !";
    }
}

void DialogSystemSet::bloodPumpSpeed()
{
    DialogInputNumber *digitalInput = new DialogInputNumber(this);
    digitalInput->setWindowTitle("血泵电机转速设置最高50000转");
    digitalInput->disableButton_p(false);
    digitalInput->setModal(true);
    if (digitalInput->exec() == QDialog::Accepted) {
        QString dateStr = digitalInput->inputValStr();
        if (dateStr.toInt() > 50000) {
            bpSpeed = 50000;
            ui->pushButton_BPSpeed->setText(QString::number(50000));
        } else {
            bpSpeed = dateStr.toInt();
            ui->pushButton_BPSpeed->setText(dateStr);
        }
    }
    delete digitalInput;
}

void DialogSystemSet::powerOffHandle()
{
    QMessageBox powerOffMsgBox(this);
    powerOffMsgBox.setWindowTitle("关机对话框");
    QPushButton* yes = powerOffMsgBox.addButton("是",QMessageBox::ActionRole);
    QPushButton* no = powerOffMsgBox.addButton("否",QMessageBox::ActionRole);
    powerOffMsgBox.setText("<font size='14' color='black'> 确认关机？ </font>");
    powerOffMsgBox.setStyleSheet(
        "QPushButton {"
                        "background-color:#89AFDE;"
                        " border-style: outset;"
                        " border-width: 2px;"
                        " border-radius: 10px;"
                        " border-color: beige;"
                        " font: bold 24px;"
                        " min-width: 100;"
                        " min-height: 51;"
                        "}"
    );
    powerOffMsgBox.setMaximumSize(512, 384);
    powerOffMsgBox.setMinimumSize(512, 384);
//    powerOffMsgBox.setStyleSheet("background-color: rgb(136, 138, 133)");
//    powerOffMsgBox.showFullScreen();
    powerOffMsgBox.exec();
    if(powerOffMsgBox.clickedButton() == yes) {
        emit powerOff();
        qDebug() << "power off ....";
    } else if(powerOffMsgBox.clickedButton() == no) {
        qDebug() << "no power off !";
    }
}

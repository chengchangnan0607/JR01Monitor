#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    createUI();
    createCommunication();
    qDebug() << "Communication connection succeeded";
//    installationGuide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createUI()
{
    ui->setupUi(this);
//    ui->stackedWidget->setCurrentIndex(1);
    initStatusBar();
    initChartBloodPump();
    initChartPurgeSystem();
    initAlarmInformation();
    chartView_Up = ui->widget_UpPump;                          //1.获取画布
    chartView_Down = ui->widget_DownPump;
    toChartBloodPump();

    connect(ui->pushButton_Pump, &QPushButton::clicked, this, &MainWindow::toChartBloodPump);
    connect(ui->pushButton_Purge, &QPushButton::clicked, this, &MainWindow::toChartPurgeSystem);

    QStringList levels;
    //    10000  15000   20000   25000   30000    35000  40000   45000   50000   55000   60000
//    levels << "P0" << "P1" << "P2" << "P3" << "P4" << "P5" << "P6" << "P7" << "P8" << "P9";
//    ui->comboBox_BPSpeed->addItems(levels);
    connect(ui->pushButton_NewSurgery, &QPushButton::clicked, this, &MainWindow::newSurgery);
    connect(ui->pushButton_HistoryPump, &QPushButton::clicked, this, &MainWindow::historicalData);
    connect(ui->pushButton_HistoryPurge, &QPushButton::clicked, this, &MainWindow::historicalData);
    connect(ui->pushButton_Log, &QPushButton::clicked, this, &MainWindow::logDisplay);
    connect(ui->pushButton_Back, &QPushButton::clicked, this, &MainWindow::back);
    connect(ui->pushButton_Set, &QPushButton::clicked, this, &MainWindow::systemSettings);
    connect(ui->pushButton_PumpStart, &QPushButton::clicked, this, &MainWindow::buttonMotorStartHandle);
    connect(ui->pushButton_PumpStop, &QPushButton::clicked, this, &MainWindow::buttonMotorStopHandle);

    qDebug() << "UI creater succeeded";
}

void MainWindow::newSurgery()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::initStatusBar()
{
    secondTimer = new QTimer(this);
    connect(secondTimer, &QTimer::timeout, this, &MainWindow::showDateTime);
    secondTimer->start(1000);
    showDateTime();

//    ui->label_PowerBoardConnectStatus->setFont(QFont("Ubuntu", 14));
//    setStatus(false);

//    powerStatus = new Battery();
//    ui->horizontalLayout_Battery->addWidget(powerStatus);

//    supplyPlug = new SupplyPlug();
//    ui->horizontalLayout_Supply->addWidget(supplyPlug);
}

void MainWindow::setStatus(bool status)
{
    connectionStatusPower = status;
    if (status == true) {
//        ui->label_PowerBoardConnectStatus->setStyleSheet ("color: green;");
//        ui->label_PowerBoardConnectStatus->setText("已连接");
    } else {
//        ui->label_PowerBoardConnectStatus->setStyleSheet ("color: red;");
//        ui->label_PowerBoardConnectStatus->setText("未连接");
    }
}

void MainWindow::showDateTime()
{
    QDateTime dateTime = QDateTime::currentDateTime();
    ui->label_DateTime->setText(dateTime.toString("yyyy-MM-dd hh:mm:ss ddd"));
//    int speed = 0;
//    if (dataSpeed.length() > 0) {
//        speed = dataSpeed[dataSpeed.length() - 1];
//    }

//    if (connectionStatusPower && connectionStatusMotor) {
//        if (speed > 0) {
//            ui->pushButton_PumpStart->setChecked(true);
//        } else {
//            ui->pushButton_PumpStop->setChecked(true);
//        }
//    } else {
//        ui->pushButton_PumpStop->setChecked(true);
//    }
}

void MainWindow::back()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::logDisplay()
{
    dialogLog = new DialogLog(this);
    connect(controllerCommunication, &ControllerCommunication::recvActivityLogGet, dialogLog, &DialogLog::displayActivityLog);
    connect(dialogLog, &DialogLog::startLogStream, controllerCommunication, &ControllerCommunication::startLogStream);
    connect(dialogLog, &DialogLog::stopLogStream, controllerCommunication, &ControllerCommunication::stopLogStream);
    dialogLog->startActivityLog();
    dialogLog->setWindowTitle("报警/事件日志");
    dialogLog->setModal(true);
    if (dialogLog->exec() == QDialog::Accepted ) {
        qDebug() << "dialogLog OK ....";
    } else {
        qDebug() << "dialogLog Cancel";
    }
    dialogLog->stopActivityLog();
    disconnect(controllerCommunication, &ControllerCommunication::recvActivityLogGet, dialogLog, &DialogLog::displayActivityLog);
    disconnect(dialogLog, &DialogLog::startLogStream, controllerCommunication, &ControllerCommunication::startLogStream);
    disconnect(dialogLog, &DialogLog::stopLogStream, controllerCommunication, &ControllerCommunication::stopLogStream);
    delete dialogLog;
}

void MainWindow::speedSetup(unsigned short speedVal)
{
    T_PumpSpeed pumpSpeedSetVal;
    pumpSpeedSetVal.patientSpeedSetpoint = speedVal;
    emit pumpSpeedSet(pumpSpeedSetVal);
    usleep(100000);//100ms
    emit pumpSpeedGet();
}

void MainWindow::displayPumpSpeedGet(T_PumpSpeed pumpSpeedGet)
{
    pumpSpeed.patientSpeedSetpoint = pumpSpeedGet.patientSpeedSetpoint;
    if (pumpSpeedGet.patientMinSpeed != 0) {
        pumpSpeed.patientMinSpeed = pumpSpeedGet.patientMinSpeed;
    }
    if (pumpSpeedGet.patientMaxSpeed != 0) {
        pumpSpeed.patientMaxSpeed = pumpSpeedGet.patientMaxSpeed;
    }
}

void MainWindow::systemSettings()
{
    DialogSystemSet *dialogSystemSet = new DialogSystemSet(this);
    dialogSystemSet->setWindowTitle("系统信息/设置");
    connect(dialogSystemSet, &DialogSystemSet::powerOff, controllerCommunication, &ControllerCommunication::powerOff);
    dialogSystemSet->setSpeed(pumpSpeed.patientSpeedSetpoint);
    dialogSystemSet->setModal(true);
    if (dialogSystemSet->exec() == QDialog::Accepted ) {
        speedSetup(dialogSystemSet->bpSpeed);
//        QString dateTimeStr = QString::number(dialogSystemSet->monthInt) + QString::number(dialogSystemSet->dayInt) + QString::number(dialogSystemSet->hourInt) + QString::number(dialogSystemSet->minuteInt) + QString::number(dialogSystemSet->yearInt);
//        QString str = "date " + dateTimeStr + " && hwclock -w";
        QString str = "date " + dialogSystemSet->dateTimeSetVal.toString("MMddhhmmyyyy") + " && hwclock -w";
        system(str.toLatin1().data());// date 021710452016 && hwclock -w && date;MMddhhmmyyyy
        emit realTimeClockSet(QDateTime::currentMSecsSinceEpoch()/1000);//unix secs past 1-Jan-70
    } else {
        qDebug() << "dialogHistory Cancel";
    }
    delete dialogSystemSet;
}

void MainWindow::historicalData()
{
//    if (ui->pushButton_History->isChecked()) {
//        dialogHistoricalData = new DialogHistoricalData(this);
//        dialogHistoricalData->setWindowTitle("历史数据");
//        dialogHistoricalData->setModal(true);
//        if (dialogHistoricalData->exec() == QDialog::Accepted) {
//            qDebug() << "dialogHistoricalData OK ....";
//        } else {
//            qDebug() << "dialogHistoricalData Cancel";
//        }
//        ui->pushButton_History->setChecked(false);
//        delete dialogHistoricalData;
//    } else {
//        if (dialogHistoricalData != NULL) {
//            delete dialogHistoricalData;
//        }
//    }
}

void MainWindow::initChartBloodPump()
{
    chart_BloodMotor.addSeries(&lineSeriesBloodFlow);
    chart_BloodMotor.addSeries(&lineSeriesBloodPower);
    chart_BloodMotor.addSeries(&lineSeriesBloodSpeed);
    chart_BloodMotor.createDefaultAxes();
    chart_BloodMotor.legend()->hide();
//    chart_BloodMotor.setBackgroundVisible(false);
    chart_BloodMotor.axisX()->setRange(0, timeRange);
    chart_BloodMotor.axisY()->setRange(0, motorMax);
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart_BloodMotor.axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%d");
    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart_BloodMotor.axes(Qt::Horizontal).first());
    Q_ASSERT(axisX);
    axisX->setLabelFormat("%d");

    chart_BloodPressure.addSeries(&lineSeriesBloodPressure);
    chart_BloodPressure.createDefaultAxes();
    chart_BloodPressure.legend()->hide();
    chart_BloodPressure.axisX()->setRange(0, timeRange);
    chart_BloodPressure.axisY()->setRange(0, pressureMax);
    QValueAxis *axisYP = qobject_cast<QValueAxis*>(chart_BloodPressure.axes(Qt::Vertical).first());
    Q_ASSERT(axisYP);
    axisYP->setLabelFormat("%d");
    QValueAxis *axisXP = qobject_cast<QValueAxis*>(chart_BloodPressure.axes(Qt::Horizontal).first());
    Q_ASSERT(axisXP);
    axisXP->setLabelFormat("%d");
}

void MainWindow::initChartPurgeSystem()
{
    chart_PurgeFlow.addSeries(&lineSeriesPurgeFlow);
    chart_PurgeFlow.createDefaultAxes();
    chart_PurgeFlow.legend()->hide();
    chart_PurgeFlow.axisX()->setRange(0, purgeTimeRange);
    chart_PurgeFlow.axisY()->setRange(0, purgeFlowMax);
//    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart_PurgeFlow.axes(Qt::Vertical).first());
//    Q_ASSERT(axisY);
//    axisY->setLabelFormat("%d");
    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart_PurgeFlow.axes(Qt::Horizontal).first());
    Q_ASSERT(axisX);
    axisX->setLabelFormat("%d");

    chart_PurgePressure.addSeries(&lineSeriesPurgePressure);
    chart_PurgePressure.createDefaultAxes();
    chart_PurgePressure.legend()->hide();
    chart_PurgePressure.axisX()->setRange(0, purgeTimeRange);
    chart_PurgePressure.axisY()->setRange(0, purgePressureMax);
    QValueAxis *axisYP = qobject_cast<QValueAxis*>(chart_PurgePressure.axes(Qt::Vertical).first());
    Q_ASSERT(axisYP);
    axisYP->setLabelFormat("%d");
    QValueAxis *axisXP = qobject_cast<QValueAxis*>(chart_PurgePressure.axes(Qt::Horizontal).first());
    Q_ASSERT(axisXP);
    axisXP->setLabelFormat("%d");
}

void MainWindow::toChartBloodPump()
{
    ui->stackedWidget_Curve->setCurrentIndex(0);
    ui->stackedWidget_Value->setCurrentIndex(0);

    chartView_Up->setChart(&chart_BloodMotor);                  //2.展示坐标对象（将坐标对象放到画布上）
    chartView_Up->setRenderHint(QPainter::Antialiasing);        //设置抗锯齿
//    chartView_Up->chart()->legend()->hide();                    //掩藏曲线名称

    chartView_Down->setChart(&chart_BloodPressure);
    chartView_Down->setRenderHint(QPainter::Antialiasing);
//    chartView_Down->chart()->legend()->hide();
}

void MainWindow::toChartPurgeSystem()
{
    ui->stackedWidget_Curve->setCurrentIndex(1);
    ui->stackedWidget_Value->setCurrentIndex(1);

    chartView_Up->setChart(&chart_PurgeFlow);
    chartView_Up->setRenderHint(QPainter::Antialiasing);
//    chartView_Up->chart()->legend()->hide();

    chartView_Down->setChart(&chart_PurgePressure);
    chartView_Down->setRenderHint(QPainter::Antialiasing);
//    chartView_Down->chart()->legend()->hide();
}

void MainWindow::createCommunication()
{
    controllerCommunication = new ControllerCommunication();

//    connect(controllerCommunication, &ControllerCommunication::recvControllerStatus1Second, centralDisplayArea->alarmWindow, &AlarmWindow::displayMuteStatus);
//    connect(controllerCommunication, &ControllerCommunication::recvActivityLogGet, dialogLog, &DialogLog::displayActivityLog);
    connect(controllerCommunication, &ControllerCommunication::connectionStatusChange, this, &MainWindow::setStatus);
//    connect(controllerCommunication, &ControllerCommunication::recvRealTimeStream, powerStatus, &Battery::displayBatteryStatus);
//    connect(controllerCommunication, &ControllerCommunication::recvRealTimeStream, supplyPlug, &SupplyPlug::displaySupplyStatus);
    connect(controllerCommunication, &ControllerCommunication::recvRealTimeStream, this, &MainWindow::displayRTS);
    connect(controllerCommunication, &ControllerCommunication::recvPressureSensor, this, &MainWindow::displayPressureSensor);
    connect(controllerCommunication, &ControllerCommunication::recvPurgeSystem, this, &MainWindow::displayPurgeSystem);
//    connect(controllerCommunication, &ControllerCommunication::recvControllerInfo, centralDisplayArea->informations, &Informations::displayValue);
    connect(controllerCommunication, &ControllerCommunication::recvPumpSpeedGet, this, &MainWindow::displayPumpSpeedGet);
//    connect(controllerCommunication, &ControllerCommunication::recvPumpSpeedStatus, centralDisplayArea->preferences->setupMotor, &SetupMotor::displaySpeed);
//    connect(controllerCommunication, &ControllerCommunication::recvKey, this, &MainWindow::keyHandle);

    connect(controllerCommunication, &ControllerCommunication::recvControllerStatus1Second, this, &MainWindow::recvActiveAlarm);
    connect(controllerCommunication, &ControllerCommunication::recvControllerStatusActiveFaults, this, &MainWindow::recvActiveFaults);

//    connect(centralDisplayArea, &CentralDisplayArea::keyLedStatusIndicate, controllerCommunication, &ControllerCommunication::controlRealtimeStream);
//    connect(centralDisplayArea->alarmWindow, &AlarmWindow::muteAlarms, controllerCommunication, &ControllerCommunication::muteAlarms);
//    connect(dialogLog, &DialogLog::startLogStream, controllerCommunication, &ControllerCommunication::startLogStream);
//    connect(dialogLog, &DialogLog::stopLogStream, controllerCommunication, &ControllerCommunication::stopLogStream);
    connect(this, &MainWindow::pumpControlSet, controllerCommunication, &ControllerCommunication::pumpControlSet);
    connect(this, &MainWindow::pumpSpeedSet, controllerCommunication, &ControllerCommunication::pumpSpeedSet);
    connect(this, &MainWindow::pumpSpeedGet, controllerCommunication, &ControllerCommunication::pumpSpeedGet);
    connect(this, &MainWindow::realTimeClockSet, controllerCommunication, &ControllerCommunication::realTimeClockSet);

    connect(controllerCommunication, &ControllerCommunication::recvPowerOff, this, &MainWindow::powerOffHandle);
}

#define speedMin 10000
#define speedMax 60000
#define unitVal ((speedMax - speedMin)/10);

void MainWindow::displayRTS(T_RTS realTimeDataStream)
{//流量功率压力已连接未连接
    int speedLevel = (realTimeDataStream.speed - speedMin)/unitVal;
    if (speedLevel > 9) {
        speedLevel = 9;
    }
//    ui->comboBox_BPSpeed->setCurrentIndex(speedLevel);                     //速度
    ui->label_FlowPump->setText(QString::number(realTimeDataStream.flow));   //流量
    QString powerStr = QString::number(realTimeDataStream.power/1000) + "." + QString::number((realTimeDataStream.power/100)%10);
    ui->label_Current->setText(powerStr); //功率

    QString connectStr;//bit[7:4]=UART5(sensor)\4(purge)\3(motor)\2(bluetooth) connect status:1=connect,0=disconnect
//    if (realTimeDataStream.powerStatus & 0x80) {
//        connectStr = "已连接";
//    } else {
//        connectStr = "未连接";
//    }
//    ui->label_BPConnectStatus->setText(connectStr);
    if (realTimeDataStream.powerStatus & 0x40) {
        connectionStatusPurge = true;
        connectStr = "已连接";
        ui->label_ConnectIconPurge->setStyleSheet("color:green;");
        ui->label_ConnectWordsPurge->setStyleSheet("color:green;");
    } else {
        connectionStatusPurge = false;
        connectStr = "未连接";
        ui->label_ConnectIconPurge->setStyleSheet("color:red;");
        ui->label_ConnectWordsPurge->setStyleSheet("color:red;");
    }
    ui->label_ConnectWordsPurge->setText(connectStr);

    if (realTimeDataStream.powerStatus & 0x20) {
        connectionStatusMotor = true;
        connectStr = "已连接";
        ui->label_ConnectIconPump->setStyleSheet("color:green;");
        ui->label_ConnectWordsPump->setStyleSheet("color:green;");
    } else {
        connectionStatusMotor = false;
        connectStr = "未连接";
        ui->label_ConnectIconPump->setStyleSheet("color:red;");
        ui->label_ConnectWordsPump->setStyleSheet("color:red;");
    }
    ui->label_ConnectWordsPump->setText(connectStr);


    dataFlow << realTimeDataStream.flow;
    dataPower << realTimeDataStream.power;
    dataSpeed << realTimeDataStream.speed;
    if (dataFlow.size() > timeRange + 1) {// 数据个数超过了指定值，则删除最先接收到的数据
        dataFlow.removeFirst();
        dataPower.removeFirst();
        dataSpeed.removeFirst();
    }
    if (isVisible()) {// 界面被隐藏后就没有必要绘制数据的曲线了
        lineSeriesBloodFlow.replace(createCurveKnots(dataFlow));
        lineSeriesBloodPower.replace(createCurveKnots(dataPower));
        lineSeriesBloodSpeed.replace(createCurveKnots(dataSpeed));
    }
}

QList<QPointF> MainWindow::createCurveKnots(QList<int> data) {
    QList<QPointF> knots; // 曲线上的点

    for (int i = 0; i < data.size(); i++) {// 生成数据对应曲线上的点
        knots << QPointF(i, data[i]);
    }
    return knots;
}

void MainWindow::displayPressureSensor(S200RealtimeData sensorData)
{
    CommunicationProtocol temp;
    float pressuremmHg = temp.calculatePressure(sensorData);
    ui->label_PressurePump->setText(QString::number(pressuremmHg, 'f', 3));   //压力

    dataPressure << pressuremmHg;
    if (dataPressure.size() > timeRange + 1) {
        dataPressure.removeFirst();
    }
    if (isVisible()) {
        lineSeriesBloodPressure.replace(createCurveKnotsFloat(dataPressure));
    }
}

QList<QPointF> MainWindow::createCurveKnotsFloat(QList<float> data) {
    QList<QPointF> knots;

    for (int i = 0; i < data.size(); i++) {
        knots << QPointF(i, data[i]);
    }
    return knots;
}

void MainWindow::displayPurgeSystem(PurgeRealtimeData purgeData)
{
    if (purgeData.flowRate != 0) {
        QString flowStr = QString::number(purgeData.flowRate/10) + "." + QString::number(purgeData.flowRate%10);
        ui->label_FlowPurge->setText(flowStr);     //流量
    } else {
        ui->label_FlowPurge->setText("***");     //流量
    }
    dataPurgeFlow << (purgeData.flowRate)/10.0;
    if (dataPurgeFlow.size() > purgeTimeRange + 1) {
        dataPurgeFlow.removeFirst();
    }
    if (isVisible()) {
        lineSeriesPurgeFlow.replace(createCurveKnotsFloat(dataPurgeFlow));
    }

    ui->label_PressurePurge->setText(QString::number(purgeData.pressure)); //压力
    dataPurgePressure << purgeData.pressure;
    if (dataPurgePressure.size() > purgeTimeRange + 1) {
        dataPurgePressure.removeFirst();
    }
    if (isVisible()) {
        lineSeriesPurgePressure.replace(createCurveKnots(dataPurgePressure));
    }
}

void MainWindow::buttonMotorStartHandle()
{
    if (connectionStatusPower && connectionStatusMotor) {
        QMessageBox motorStartMsgBox(this);
        motorStartMsgBox.setWindowTitle("血泵控制");
        QPushButton* yes = motorStartMsgBox.addButton("是",QMessageBox::ActionRole);
        QPushButton* no = motorStartMsgBox.addButton("否",QMessageBox::ActionRole);
        motorStartMsgBox.setText("<font size='14' color='black'> 确认启动血泵？ </font>");
        motorStartMsgBox.setStyleSheet(
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
        motorStartMsgBox.setMaximumSize(512, 384);
        motorStartMsgBox.setMinimumSize(512, 384);
        motorStartMsgBox.exec();
        if(motorStartMsgBox.clickedButton() == yes) {
            pumpControl.Flags = 1;
            emit pumpControlSet(pumpControl);
        } else if(motorStartMsgBox.clickedButton() == no) {

        }
    }
}

void MainWindow::buttonMotorStopHandle()
{
    if (connectionStatusPower && connectionStatusMotor) {
        QMessageBox motorStartMsgBox(this);
        motorStartMsgBox.setWindowTitle("血泵控制");
        QPushButton* yes = motorStartMsgBox.addButton("是",QMessageBox::ActionRole);
        QPushButton* no = motorStartMsgBox.addButton("否",QMessageBox::ActionRole);
        motorStartMsgBox.setText("<font size='14' color='black'> 确认停止血泵？ </font>");
        motorStartMsgBox.setStyleSheet(
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
        motorStartMsgBox.setMaximumSize(512, 384);
        motorStartMsgBox.setMinimumSize(512, 384);
        motorStartMsgBox.exec();
        if(motorStartMsgBox.clickedButton() == yes) {
            pumpControl.Flags = 0;
            emit pumpControlSet(pumpControl);
        } else if(motorStartMsgBox.clickedButton() == no) {

        }
    }
}

void MainWindow::initAlarmInformation()
{
    imageActiveAlarm = new QImage;
    imageActiveAlarm->load(":/Image/Alarm_None.png");
    ui->label_AlarmLED->setAlignment(Qt::AlignCenter);
    ui->label_AlarmLED->setScaledContents(true);
    ui->label_AlarmLED->setPixmap(QPixmap::fromImage(*imageActiveAlarm));

    ui->label_AlarmInfo1->setText("无活动报警");
//    ui->label_AlarmInfo1->setStyleSheet ("border-width: 1px; border-style: solid; border-color: black; color: green;");
    ui->label_AlarmInfo1->setStyleSheet ("color: green;");
    ui->label_AlarmInfo2->setText("");
    ui->label_AlarmInfo3->setText("");

    timerAlarmLEDRefresh = new QTimer(this);
    connect(timerAlarmLEDRefresh, &QTimer::timeout, this, &MainWindow::displayAlarmLED);

    timerAlarmInformationRefresh = new QTimer(this);
    connect(timerAlarmInformationRefresh, &QTimer::timeout, this, &MainWindow::displayActiveFaults);
    timerAlarmInformationRefresh->start(3000);//5s
}


#define LED_HIGH_FLASH_CYCLE   250
#define LED_MID_FLASH_CYCLE    1000
void MainWindow::recvActiveAlarm(T_ControllerStatus controllerStatus)
{
    activeAlarm = controllerStatus.activeAlarmAndPumpStatus.activeAlarm;
    switch (activeAlarm) {
        case ACTIVE_ALARM_NO_ALARM:
            imageActiveAlarm->load(":/Image/Alarm_None.png");
            timerAlarmLEDRefresh->stop();
            break;
        case ACTIVE_ALARM_YELLOW_LOW_SYSSTATUS:
            imageActiveAlarm->load(":/Image/Alarm_Low.png");
            timerAlarmLEDRefresh->stop();
            break;
        case ACTIVE_ALARM_YELLOW_SYSSTATUS:
            imageActiveAlarm->load(":/Image/Alarm_Mid.png");
            timerAlarmLEDRefresh->start(LED_MID_FLASH_CYCLE);
            break;
        case ACTIVE_ALARM_RED_SYSSTATUS:
            imageActiveAlarm->load(":/Image/Alarm.png");
            timerAlarmLEDRefresh->start(LED_HIGH_FLASH_CYCLE);
            break;
    default:
            break;
    }
    ui->label_AlarmLED->setPixmap(QPixmap::fromImage(*imageActiveAlarm));
}

void MainWindow::faultsBitToID(unsigned int activeFaults)
{
    activeFaultsID.clear();
    for (unsigned char i = 0; i < FCAUSE_MAX; i++) {
        if (activeFaults & (1 << i)) {
            activeFaultsID.append(i);
        }
    }
}

void MainWindow::recvActiveFaults(T_ControllerStatus controllerStatus)
{
    activeFaults = controllerStatus.activeFaults;
    faultsBitToID(activeFaults);
//    currentDisplayFaultID = 0;
}

QString MainWindow::setFontColor(E_ActiveFaults currentDisplayFaultID)
{
    QString styleSheet = "";
    switch (currentDisplayFaultID) {
        case FCAUSE_DRIVELINE_DISCONNECTED:
        case FCAUSE_PUMP_ID_FAULT:
        case FCAUSE_VADCTRL_RED_FAULT:
        case FCAUSE_PUMP_POSITION_FAULT:
        case FCAUSE_PURGE_SYSTEM_BUBBLE:
        case FCAUSE_PURGE_SYSTEM_BLOCK:
        case FCAUSE_PURGE_SYSTEM_LEAK:
        case FCAUSE_PURGE_SYSTEM_DOOR_OPEN:
            styleSheet =  "color: red;";
            break;
        case FCAUSE_INFUSION_BAG_TOO_LOW:
        case FCAUSE_PURGE_SYSTEM_FAULT:
        case FCAUSE_PIPE_REPLACE_PERIOD:
        case FCAUSE_PIPE_REPLACE_TIMEOUT:
        case FCAUSE_CONSOLE_OVER_TEMP:
        case FCAUSE_BATTERY_FAULT:
        case FCAUSE_BATTERY_LOW:
        case FCAUSE_BATTERY_TOO_LOW:
        case FCAUSE_OPTICAL_FIBER_FAULT:
            styleSheet =  "color: rgb(193, 125, 17);";
            break;
        case FCAUSE_INFUSION_BAG_LOW:
        case FCAUSE_STORAGE_SPACE_NOT_ENOUGH:
            styleSheet = "color: green;";
            break;
        default:
            break;
    }
    return styleSheet;
}

void MainWindow::displayActiveFaults()
{
    if (activeFaultsID.size() > 0) {
        if (activeFaultsID.size() == 1) {
            ui->label_AlarmInfo1->setText("1." + faults[activeFaultsID.value(0)][faultItemInformation]);
            ui->label_AlarmInfo1->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(0)));
            ui->label_AlarmInfo2->setText("");
            ui->label_AlarmInfo3->setText("");
        } else if (activeFaultsID.size() == 2) {
            ui->label_AlarmInfo1->setText("1." + faults[activeFaultsID.value(0)][faultItemInformation]);
            ui->label_AlarmInfo1->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(0)));
            ui->label_AlarmInfo2->setText("2." + faults[activeFaultsID.value(1)][faultItemInformation]);
            ui->label_AlarmInfo2->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(1)));
            ui->label_AlarmInfo3->setText("");
        } else if (activeFaultsID.size() == 3) {
            ui->label_AlarmInfo1->setText("1." + faults[activeFaultsID.value(0)][faultItemInformation]);
            ui->label_AlarmInfo1->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(0)));
            ui->label_AlarmInfo2->setText("2." + faults[activeFaultsID.value(1)][faultItemInformation]);
            ui->label_AlarmInfo2->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(1)));
            ui->label_AlarmInfo3->setText("3." + faults[activeFaultsID.value(2)][faultItemInformation]);
            ui->label_AlarmInfo3->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(2)));
        } else {
            ui->label_AlarmInfo1->setText(QString::number(currentDisplayFaultID % activeFaultsID.length() + 1) + "." + faults[activeFaultsID.value(currentDisplayFaultID % activeFaultsID.length())][faultItemInformation]);
            ui->label_AlarmInfo1->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value(currentDisplayFaultID % activeFaultsID.length())));
            ui->label_AlarmInfo2->setText(QString::number((currentDisplayFaultID + 1) % activeFaultsID.length() + 1) + "."  + faults[activeFaultsID.value((currentDisplayFaultID + 1) % activeFaultsID.length())][faultItemInformation]);
            ui->label_AlarmInfo2->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value((currentDisplayFaultID + 1) % activeFaultsID.length())));
            ui->label_AlarmInfo3->setText(QString::number((currentDisplayFaultID + 2) % activeFaultsID.length() + 1) + "."  + faults[activeFaultsID.value((currentDisplayFaultID + 2) % activeFaultsID.length())][faultItemInformation]);
            ui->label_AlarmInfo3->setStyleSheet(setFontColor((E_ActiveFaults)activeFaultsID.value((currentDisplayFaultID + 2) % activeFaultsID.length())));
            currentDisplayFaultID = (currentDisplayFaultID + 1) % activeFaultsID.length();
        }
    } else {
        ui->label_AlarmInfo1->setText("无活动报警");
        ui->label_AlarmInfo1->setStyleSheet ("color: green;");
        ui->label_AlarmInfo2->setText("");
        ui->label_AlarmInfo3->setText("");
    }
}

void MainWindow::displayAlarmLED()
{
    static bool flag = 0;
    if (flag) {
        flag = 0;
        imageActiveAlarm->load(":/Image/Alarm_Clear.png");
    } else {
        flag = 1;
        if (activeAlarm == ACTIVE_ALARM_RED_SYSSTATUS) {
            imageActiveAlarm->load(":/Image/Alarm.png");
        } else if (activeAlarm == ACTIVE_ALARM_YELLOW_SYSSTATUS) {
            imageActiveAlarm->load(":/Image/Alarm_Mid.png");
        }
    }
    ui->label_AlarmLED->setPixmap(QPixmap::fromImage(*imageActiveAlarm));
}

void MainWindow::powerOffHandle()
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
    powerOffMsgBox.exec();
    if(powerOffMsgBox.clickedButton() == yes) {
        qDebug() << "power off ....";
        controllerCommunication->powerOff();
    } else if(powerOffMsgBox.clickedButton() == no) {
        qDebug() << "no power off !";
    }
}

void MainWindow::installationGuide()
{
    QMessageBox selectEnter(QMessageBox::Question, "安装指南","是否进入安装指南?");
    QPushButton* Yes = selectEnter.addButton("是", QMessageBox::ActionRole);
    QPushButton* No = selectEnter.addButton("否", QMessageBox::ActionRole);

    selectEnter.setMaximumSize(512, 384);
    selectEnter.setMinimumSize(512, 384);
    selectEnter.exec();
    if(selectEnter.clickedButton() == Yes) {
        DialogStepPages *stepPage = new DialogStepPages();
        connect(stepPage, &DialogStepPages::purgeExhaustStart, controllerCommunication, &ControllerCommunication::purgeExhaustStart);
        connect(stepPage, &DialogStepPages::capacitySet, controllerCommunication, &ControllerCommunication::purgeCapacitySet);
        stepPage->setWindowTitle("安装指南");
        stepPage->setModal(true);
        if (stepPage->exec() == DialogStepPages::Accepted) {
            qDebug() << "installation finish";
        } else {
            qDebug() << "installation cancel";
        }
        disconnect(stepPage, &DialogStepPages::purgeExhaustStart, controllerCommunication, &ControllerCommunication::purgeExhaustStart);
        disconnect(stepPage, &DialogStepPages::capacitySet, controllerCommunication, &ControllerCommunication::purgeCapacitySet);
        delete stepPage;
    }
}

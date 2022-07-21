#include "dialoghistoricaldata.h"
#include "ui_dialoghistoricaldata.h"

DialogHistoricalData::DialogHistoricalData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHistoricalData)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog);
//    setStyleSheet("QDialog{background: blue;}");

    initChartBloodPump();
    initChartPurgeSystem();
    chartView_Up = ui->widget_Up;                          //1.获取画布
    chartView_Down = ui->widget_Down;
    toChartBloodPump();

    connect(ui->pushButton_BloodPump, &QPushButton::clicked, this, &DialogHistoricalData::toChartBloodPump);
    connect(ui->pushButton_PurgeSystem, &QPushButton::clicked, this, &DialogHistoricalData::toChartPurgeSystem);
    connect(ui->pushButton_TimeSet, &QPushButton::clicked, this, &DialogHistoricalData::timeSetting);
    connect(ui->pushButton_Close, &QPushButton::clicked, this, &DialogHistoricalData::accept);
    connect(ui->pushButton_Play, &QPushButton::clicked, this, &DialogHistoricalData::buttonPlayHandle);
    connect(ui->pushButton_PlaybackSpeed, &QPushButton::clicked, this, &DialogHistoricalData::buttonPlaybackSpeedHandle);
    connect(ui->pushButton_AmplitudeUp, &QPushButton::clicked, this, &DialogHistoricalData::buttonAmplitudeUpHandle);
    connect(ui->pushButton_AmplitudeDown, &QPushButton::clicked, this, &DialogHistoricalData::buttonAmplitudeDownHandle);
    connect(ui->pushButton_CycleUp, &QPushButton::clicked, this, &DialogHistoricalData::buttonPeriodUpHandle);
    connect(ui->pushButton_CycleDown, &QPushButton::clicked, this, &DialogHistoricalData::buttonPeriodDownHandle);

    dataSearchThread = new DataSearchThread();
    connect(dataSearchThread, &DataSearchThread::dataSearchFinish, this, &DialogHistoricalData::searchFinishHandle);
    dataSearchThread->start();

    timerPlay = new QTimer(this);
    connect(timerPlay, &QTimer::timeout, this, &DialogHistoricalData::timerPlayUpdate);
}

DialogHistoricalData::~DialogHistoricalData()
{
    delete ui;
}

void DialogHistoricalData::initChartBloodPump()
{
    lineSeriesBloodFlow.setName("流量");
    lineSeriesBloodPower.setName("功率");
    lineSeriesBloodSpeed.setName("速度");
    chart_BloodMotor.addSeries(&lineSeriesBloodFlow);
    chart_BloodMotor.addSeries(&lineSeriesBloodPower);
    chart_BloodMotor.addSeries(&lineSeriesBloodSpeed);
    chart_BloodMotor.createDefaultAxes();
    chart_BloodMotor.axisX()->setRange(0, timeRange);
    chart_BloodMotor.axisY()->setRange(0, motorMax);
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart_BloodMotor.axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%d");
    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart_BloodMotor.axes(Qt::Horizontal).first());
    Q_ASSERT(axisX);
    axisX->setLabelFormat("%d");

    lineSeriesBloodPressure.setName("压力");
    chart_BloodPressure.addSeries(&lineSeriesBloodPressure);
    chart_BloodPressure.createDefaultAxes();
    chart_BloodPressure.axisX()->setRange(0, timeRange);
    chart_BloodPressure.axisY()->setRange(0, pressureMax);
    QValueAxis *axisYP = qobject_cast<QValueAxis*>(chart_BloodPressure.axes(Qt::Vertical).first());
    Q_ASSERT(axisYP);
    axisYP->setLabelFormat("%d");
    QValueAxis *axisXP = qobject_cast<QValueAxis*>(chart_BloodPressure.axes(Qt::Horizontal).first());
    Q_ASSERT(axisXP);
    axisXP->setLabelFormat("%d");
}

void DialogHistoricalData::initChartPurgeSystem()
{
    lineSeriesPurgeFlow.setName("流量");
    chart_PurgeFlow.addSeries(&lineSeriesPurgeFlow);
    chart_PurgeFlow.createDefaultAxes();
    chart_PurgeFlow.axisX()->setRange(0, purgeTimeRange);
    chart_PurgeFlow.axisY()->setRange(0, purgeFlowMax);
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart_PurgeFlow.axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%d");
    QValueAxis *axisX = qobject_cast<QValueAxis*>(chart_PurgeFlow.axes(Qt::Horizontal).first());
    Q_ASSERT(axisX);
    axisX->setLabelFormat("%d");

    lineSeriesPurgePressure.setName("压力");
    chart_PurgePressure.addSeries(&lineSeriesPurgePressure);
    chart_PurgePressure.createDefaultAxes();
    chart_PurgePressure.axisX()->setRange(0, purgeTimeRange);
    chart_PurgePressure.axisY()->setRange(0, purgePressureMax);
    QValueAxis *axisYP = qobject_cast<QValueAxis*>(chart_PurgePressure.axes(Qt::Vertical).first());
    Q_ASSERT(axisYP);
    axisYP->setLabelFormat("%d");
    QValueAxis *axisXP = qobject_cast<QValueAxis*>(chart_PurgePressure.axes(Qt::Horizontal).first());
    Q_ASSERT(axisXP);
    axisXP->setLabelFormat("%d");
}

void DialogHistoricalData::toChartBloodPump()
{
    currentChart = false;
    chartView_Up->setChart(&chart_BloodMotor);                  //2.展示坐标对象（将坐标对象放到画布上）
    chartView_Up->setRenderHint(QPainter::Antialiasing);        //设置抗锯齿
//    chartView_Up->chart()->legend()->hide();                    //掩藏曲线名称

    chartView_Down->setChart(&chart_BloodPressure);
    chartView_Down->setRenderHint(QPainter::Antialiasing);
//    chartView_Down->chart()->legend()->hide();
}

void DialogHistoricalData::toChartPurgeSystem()
{
    currentChart = true;
    chartView_Up->setChart(&chart_PurgeFlow);
    chartView_Up->setRenderHint(QPainter::Antialiasing);
//    chartView_Up->chart()->legend()->hide();

    chartView_Down->setChart(&chart_PurgePressure);
    chartView_Down->setRenderHint(QPainter::Antialiasing);
//    chartView_Down->chart()->legend()->hide();
}

void DialogHistoricalData::timeSetting()
{
    if (dataSearchFinish) {
        DialogHistoricalDataTimeSet *digitaltimeSetting = new DialogHistoricalDataTimeSet(this);
        digitaltimeSetting->setWindowTitle("历史数据波形显示时间设置");
        digitaltimeSetting->setModal(true);
        if (digitaltimeSetting->exec() == QDialog::Accepted) {
            dataSearchFinish = false;
            digitaltimeSetting->readSetupVal(&parameters);
            samplingPeriod = parameters.samplingPeriod;
            incrementalValue = samplingPeriod / 30;
            disableButtonTimeSet(1);//disable button
            QString conditionValue = "(timeStamp > " + QString::number(parameters.startTimeStampVal*1000) +") and (timeStamp < " + QString::number(parameters.endTimeStampVal*1000) + ")";
            dataSearchThread->search("historyData_" + parameters.dateStr, conditionValue);
        }
        delete digitaltimeSetting;
    }
}

void DialogHistoricalData::searchFinishHandle(unsigned int rowCount)
{
    dataSearchFinish = true;
    rowCountSum = rowCount;
    dataCounter = 0;
    PlayStopFlag = 1;
    foreach(auto item, dataPower) {
        dataPower.removeOne(item);
    }
    foreach(auto item, dataSpeed) {
        dataSpeed.removeOne(item);
    }
    foreach(auto item, dataFlow) {
        dataFlow.removeOne(item);
    }
    foreach(auto item, dataPressure) {
        dataPressure.removeOne(item);
    }
    foreach(auto item, dataPurgeFlow) {
        dataPurgeFlow.removeOne(item);
    }
    foreach(auto item, dataPurgePressure) {
        dataPurgePressure.removeOne(item);
    }
    historyPlay(PlayStopFlag);
}

void DialogHistoricalData::historyPlay(bool startFlag)
{
    if (startFlag) {
        timerPlay->start(samplingPeriod / playbackSpeed);
        ui->pushButton_Play->setText("暂停");
    } else {
        timerPlay->stop();
        ui->pushButton_Play->setText("播放");
    }
}

void DialogHistoricalData::buttonPlayHandle()
{
    if (PlayStopFlag) {  //1=playing; 0=stop
        PlayStopFlag = 0;
        historyPlay(0);
    } else {
        PlayStopFlag = 1;
        historyPlay(1);
    }
}

void DialogHistoricalData::buttonPlaybackSpeedHandle()
{
    switch (playbackSpeed) {
        case 1:  playbackSpeed = 2;
                 break;
        case 2:  playbackSpeed = 5;
                 break;
        case 5:  playbackSpeed = 10;
                 break;
        case 10: playbackSpeed = 20;
                 break;
        case 20: playbackSpeed = 50;
                 break;
        case 50: playbackSpeed = 100;
                 break;
        default: playbackSpeed = 1;
                 break;
    }
    if (playbackSpeed > samplingPeriod) {
        playbackSpeed = 1;
    }
    ui->pushButton_PlaybackSpeed->setText("倍速 x " + QString::number(playbackSpeed));
    historyPlay(PlayStopFlag);
}

void DialogHistoricalData::timerPlayUpdate()
{
    disableButtonTimeSet(0);//enable button
    if (dataCounter < rowCountSum) {
        if (currentChart) {
            displayPurgeSystem(dataCounter);
        } else {
            displayBloodPump(dataCounter);
        }
        dataCounter += incrementalValue;
    } else {
        historyPlay(0);
    }
}

void DialogHistoricalData::disableButtonTimeSet(bool flag)
{
    if (flag == 1) {
        ui->pushButton_TimeSet->setText("装载中...");
        ui->pushButton_TimeSet->setDisabled(1);
    } else {
        ui->pushButton_TimeSet->setText("设置");
        ui->pushButton_TimeSet->setEnabled(1);
    }
}

void DialogHistoricalData::displayBloodPump(unsigned int row)
{
    mutexOperateDatabase.lock();
    dataFlow << dataSearchThread->modelHistoryData->record(row).value("flow").toInt();
    dataPower << dataSearchThread->modelHistoryData->record(row).value("power").toInt();;
    dataSpeed << dataSearchThread->modelHistoryData->record(row).value("speed").toInt();;
    dataPressure << dataSearchThread->modelHistoryData->record(row).value("pressuremmHg").toInt();
    mutexOperateDatabase.unlock();
    if (dataFlow.size() > timeRange + 1) {// 数据个数超过了指定值，则删除最先接收到的数据
        dataFlow.removeFirst();
        dataPower.removeFirst();
        dataSpeed.removeFirst();
        dataPressure.removeFirst();
    }
    if (isVisible()) {// 界面被隐藏后就没有必要绘制数据的曲线了
        lineSeriesBloodFlow.replace(createCurveKnots(dataFlow));
        lineSeriesBloodPower.replace(createCurveKnots(dataPower));
        lineSeriesBloodSpeed.replace(createCurveKnots(dataSpeed));
        lineSeriesBloodPressure.replace(createCurveKnotsFloat(dataPressure));
    }
}

void DialogHistoricalData::displayPurgeSystem(unsigned int row)
{
    mutexOperateDatabase.lock();
    dataPurgeFlow << dataSearchThread->modelHistoryData->record(row).value("purgeFlow").toInt();
    dataPurgePressure << dataSearchThread->modelHistoryData->record(row).value("purgePressure").toInt();
    mutexOperateDatabase.unlock();
    if (dataPurgeFlow.size() > purgeTimeRange + 1) {
        dataPurgeFlow.removeFirst();
        dataPurgePressure.removeFirst();
    }
    if (isVisible()) {
        lineSeriesPurgeFlow.replace(createCurveKnots(dataPurgeFlow));
        lineSeriesPurgePressure.replace(createCurveKnots(dataPurgePressure));
    }
}

QList<QPointF> DialogHistoricalData::createCurveKnots(QList<int> data) {
    QList<QPointF> knots; // 曲线上的点

    for (int i = 0; i < data.size(); i++) {// 生成数据对应曲线上的点
        knots << QPointF(i, data[i]);
    }
    return knots;
}


QList<QPointF> DialogHistoricalData::createCurveKnotsFloat(QList<float> data) {
    QList<QPointF> knots;

    for (int i = 0; i < data.size(); i++) {
        knots << QPointF(i, data[i]);
    }
    return knots;
}

void DialogHistoricalData::buttonAmplitudeUpHandle()
{
    if (currentChart == false) {
        motorMax = ampAdd(motorMax);
        chart_BloodMotor.axisY()->setRange(0, motorMax);
        pressureMax = ampAdd(pressureMax);
        chart_BloodPressure.axisY()->setRange(0, pressureMax);
    } else {
        purgeFlowMax = ampAdd(purgeFlowMax);
        chart_PurgeFlow.axisY()->setRange(0, purgeFlowMax);
        purgePressureMax = ampAdd(purgePressureMax);
        chart_PurgePressure.axisY()->setRange(0, purgePressureMax);
    }
}
void DialogHistoricalData::buttonAmplitudeDownHandle()
{
    if (currentChart == false) {
        motorMax = ampSub(motorMax);
        chart_BloodMotor.axisY()->setRange(0, motorMax);
        pressureMax = ampSub(pressureMax);
        chart_BloodPressure.axisY()->setRange(0, pressureMax);
    } else {
        purgeFlowMax = ampSub(purgeFlowMax);
        chart_PurgeFlow.axisY()->setRange(0, purgeFlowMax);
        purgePressureMax = ampSub(purgePressureMax);
        chart_PurgePressure.axisY()->setRange(0, purgePressureMax);
    }
}

int DialogHistoricalData::ampAdd(int ampVal)
{
    int ampNum = ampVal;
    if (ampNum < 10) {                  //0 ~ 9
        ampNum += 1;
    } else if (ampNum < 100) {          //10 ~ 99
        ampNum += 10;
    } else if (ampNum < 1000) {         //100 ~ 999
        ampNum += 100;
    } else if (ampNum < 10000) {        //1000 ~ 9999
        ampNum += 1000;
    } else {
        ampNum += 10000;
    }
    return ampNum;
}

int DialogHistoricalData::ampSub(int ampVal)
{
    int ampNum = ampVal;
    if (ampNum > 10000) {
        ampNum -= 10000;
    } else if (ampNum > 1000) {        //1000 ~ 9999
        ampNum -= 1000;
    } else if (ampNum > 100) {         //100 ~ 999
        ampNum -= 100;
    } else if (ampNum > 10) {          //10 ~ 99
        ampNum -= 10;
    } else if (ampNum > 1)             //1 ~ 9
    {
        ampNum -= 1;
    }
    return ampNum;
}

void DialogHistoricalData::buttonPeriodUpHandle()
{
    if (currentChart == false) {
        timeRange = timeAdd(timeRange);
        chart_BloodMotor.axisX()->setRange(0, timeRange);
        chart_BloodPressure.axisX()->setRange(0, timeRange);
    } else {
        purgeTimeRange = timeAdd(purgeTimeRange);
        chart_PurgeFlow.axisX()->setRange(0, purgeTimeRange);
        chart_PurgePressure.axisX()->setRange(0, purgeTimeRange);
    }
}

void DialogHistoricalData::buttonPeriodDownHandle()
{
    if (currentChart == false) {
        timeRange = timeSub(timeRange);
        chart_BloodMotor.axisX()->setRange(0, timeRange);
        chart_BloodPressure.axisX()->setRange(0, timeRange);
    } else {
        purgeTimeRange = timeSub(purgeTimeRange);
        chart_PurgeFlow.axisX()->setRange(0, purgeTimeRange);
        chart_PurgePressure.axisX()->setRange(0, purgeTimeRange);
    }
}

int DialogHistoricalData::timeAdd(int timeVal)
{
    int timeNum = timeVal;
    if (timeNum < 60) {                  //0 ~ 59 秒
        timeNum += 1;
    } else if (timeNum < (60 * 60)) {    //1 ~ 59 分
        timeNum += 60;
    } else if (timeNum < (60 * 60 * 24)) //1 ~ 24 时
    {
        timeNum += 3600;
    }
    return timeNum;
}

int DialogHistoricalData::timeSub(int timeVal)
{
    int timeNum = timeVal;
    if (timeNum > (60 * 60)) {  //1 ~ 24 时
        timeNum -= 3600;
    } else if (timeNum > (60)) {//1 ~ 59 分
        timeNum -= 60;
    } else if (timeVal > 1)     //1 ~ 59 秒
    {
        timeNum -= 1;
    }
    return timeNum;
}

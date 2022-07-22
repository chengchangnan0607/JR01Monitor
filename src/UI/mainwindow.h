#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QLabel>
#include <QDateTime>
#include <unistd.h>

#include "dialoghistoricaldata.h"
#include "dialogsystemset.h"
#include "dialoglog.h"
#include "../BL/COMM/communicationprotocol.h"
#include "../BL/COMM/controllercommunication.h"
#include "dialogsteppages.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void installationGuide();
    void initStatusBar();
    void initChartBloodPump();
    void initChartPurgeSystem();
    void initAlarmInformation();
    void createUI();
    void writeRTC();

    void createCommunication();

    void switchPage();//页面切换函数

    QString setFontColor(E_ActiveFaults currentDisplayFaultID);
    void faultsBitToID(unsigned int activeFaults);

    QList<QPointF> createCurveKnots(QList<int> data);
    QList<QPointF> createCurveKnotsFloat(QList<float> data);

//    float calculatePressure(S200RealtimeData sensorData);

    void dataReceivedPurge(int value);

    void speedSetup(unsigned short speedVal);

//    SupplyPlug *supplyPlug;
//    Battery *powerStatus;

    QTimer *secondTimer;
//    QDateTimeEdit *dateTimeEdit;

    QChartView *chartView_Up;                   //画布对象
    QChartView *chartView_Down;

    QChart chart_BloodMotor;                    //图表对象
    QChart chart_BloodPressure;
    QLineSeries lineSeriesBloodFlow;
    QLineSeries lineSeriesBloodPressure;
    QLineSeries lineSeriesBloodPower;
    QLineSeries lineSeriesBloodSpeed;
    QVector<QPointF> pointFBloodPower;
    QVector<QPointF> pointFBloodFlow;
    QVector<QPointF> pointFBloodPressure;

    QChart chart_PurgeFlow;
    QChart chart_PurgePressure;
    QLineSeries lineSeriesPurgeFlow;
    QLineSeries lineSeriesPurgePressure;
    QVector<QPointF> pointFPurgeFlow;
    QVector<QPointF> pointFPurgePressure;

    DialogHistoricalData *dialogHistoricalData;

    ControllerCommunication *controllerCommunication;

    QList<int> dataFlow;
    QList<int> dataPower;
    QList<int> dataSpeed;
    QList<float> dataPressure;
    QList<float> dataPurgeFlow;
    QList<int> dataPurgePressure;

    int motorMin = 10000;
    int motorMax = 60000;
    int pressureMax = 1000;
    float purgeFlowMax = 50.0;
    int purgePressureMax = 1500;
    int timeRange = 60;
    int purgeTimeRange = 600;   //60s/1.5s * 15min = 600

    T_PumpControl pumpControl;
    T_PumpSpeed pumpSpeed;

    bool PumpPurgeFlag = true;  // true=Pump; false=Purge
    bool connectionStatusPower = false;
    bool connectionStatusPurge = false;
    bool connectionStatusPressure = false;
    bool connectionStatusMotor = false;

    QTimer *timerAlarmLEDRefresh;
    QTimer *timerAlarmInformationRefresh;

    unsigned short activeAlarm;
    unsigned int activeFaults;
    unsigned char currentDisplayFaultID = 0;
    QVector<unsigned char> activeFaultsID;

    QImage *imageActiveAlarm;

    DialogLog *dialogLog;

private:
    Ui::MainWindow *ui;

signals:
    void pumpControlSet(T_PumpControl pumpControl);
    void pumpSpeedSet(T_PumpSpeed pumpSpeed);
    void pumpSpeedGet();
    void realTimeClockSet(unsigned int timestamp);

public slots:
    void displayPumpSpeedGet(T_PumpSpeed pumpSpeedGet);
    void buttonMotorStartHandle();
    void buttonMotorStopHandle();
    void setStatus(bool status);
    void showDateTime();
    void toChartBloodPump();
    void toChartPurgeSystem();
    void historicalData();
    void logDisplay();
    void newSurgery();
    void back();
    void systemSettings();

    void displayRTS(T_RTS realTimeDataStream);
    void displayPressureSensor(S200RealtimeData sensorData);
    void displayPurgeSystem(PurgeRealtimeData purgeData);

    void recvActiveFaults(T_ControllerStatus controllerStatus);
    void recvActiveAlarm(T_ControllerStatus controllerStatus);
    void displayActiveFaults();
    void displayAlarmLED();
    void powerOffHandle();
private slots:
    void on_pushButton_new_clicked();//新建手术按钮槽函数
    void on_pushButton_step4_prefilled_clicked();//步骤四点击预充槽函数
};
#endif // MAINWINDOW_H

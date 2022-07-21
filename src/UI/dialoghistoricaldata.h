#ifndef DIALOGHISTORICALDATA_H
#define DIALOGHISTORICALDATA_H

#include <QDialog>
#include <QtCharts>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "dialoginputnumber.h"
#include "dialoghistoricaldatatimeset.h"
#include "../BL/DB/datasearchthread.h"
#include "../BL/COMM/communicationprotocol.h"

struct PumpData {
    unsigned short speed;
    unsigned short power;
    unsigned short flow;
    float pressuremmHg;
};

struct PurgeData {
    unsigned short pressure;
    unsigned short flowRate;
};

namespace Ui {
class DialogHistoricalData;
}

class DialogHistoricalData : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHistoricalData(QWidget *parent = nullptr);
    ~DialogHistoricalData();
    void initChartBloodPump();
    void initChartPurgeSystem();
    void historyPlay(bool startFlag);//0=stop; 1=start
    void disableButtonTimeSet(bool flag);//0=enable; 1=disable
    void displayBloodPump(unsigned int row);
    void displayPurgeSystem(unsigned int row);

    int timeAdd(int timeVal);
    int timeSub(int timeVal);
    int ampAdd(int ampVal);
    int ampSub(int ampVal);

    QList<QPointF> createCurveKnots(QList<int> data);
    QList<QPointF> createCurveKnotsFloat(QList<float> data);

    QChartView *chartView_Up;                   //画布对象
    QChartView *chartView_Down;
    QChart chart_BloodMotor;                    //图表对象
    QChart chart_BloodPressure;

    QLineSeries lineSeriesBloodFlow;
    QLineSeries lineSeriesBloodPressure;
    QLineSeries lineSeriesBloodPower;
    QLineSeries lineSeriesBloodSpeed;

    QVector<QPointF> pointFBloodSpeed;
    QVector<QPointF> pointFBloodPower;
    QVector<QPointF> pointFBloodFlow;
    QVector<QPointF> pointFBloodPressure;

    QChart chart_PurgeFlow;
    QChart chart_PurgePressure;
    QLineSeries lineSeriesPurgeFlow;
    QLineSeries lineSeriesPurgePressure;

    QVector<QPointF> pointFPurgeFlow;
    QVector<QPointF> pointFPurgePressure;

    QList<int> dataFlow;                      // 存储业务数据的 list
    QList<int> dataPower;
    QList<int> dataSpeed;
    QList<float> dataPressure;
    QList<int> dataPurgeFlow;
    QList<int> dataPurgePressure;

    int motorMin = 10000;
    int motorMax = 60000;
    int pressureMax = 1000;
    int timeRange = 60;
    int purgeFlowMax = 600;
    int purgePressureMax = 600;
    int purgeTimeRange = 60;
    int samplingPeriod = 30;
    int incrementalValue = 1;
    int playbackSpeed = 1;
    bool PlayStopFlag = 0;//1=playing; 0=stop

    struct historyDataParameters parameters;

    DataSearchThread *dataSearchThread;

    bool dataSearchFinish = true;
    bool currentChart = false; //false = bloodPump; true = purgeSystem.

    QTimer *timerPlay;

    unsigned int rowCountSum = 0;
    unsigned int dataCounter = 0;

private:
    Ui::DialogHistoricalData *ui;

public slots:
    void toChartBloodPump();
    void toChartPurgeSystem();
    void timeSetting();
    void searchFinishHandle(unsigned int rowCount);
    void buttonPlayHandle();
    void buttonPlaybackSpeedHandle();
    void timerPlayUpdate();
    void buttonAmplitudeUpHandle();
    void buttonAmplitudeDownHandle();
    void buttonPeriodUpHandle();
    void buttonPeriodDownHandle();
};

#endif // DIALOGHISTORICALDATA_H

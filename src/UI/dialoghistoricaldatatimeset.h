#ifndef DIALOGHISTORICALDATATIMESET_H
#define DIALOGHISTORICALDATATIMESET_H

#include <QDialog>
#include <QDateTime>
#include "dialoginputnumber.h"
#include "../BL/DB/database.h"
struct historyDataParameters {
    int samplingPeriod;
    qint64 startTimeStampVal;
    qint64 endTimeStampVal;
    QString dateStr;
};

namespace Ui {
class DialogHistoricalDataTimeSet;
}

class DialogHistoricalDataTimeSet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHistoricalDataTimeSet(QWidget *parent = nullptr);
    ~DialogHistoricalDataTimeSet();
    void readSetupVal(struct historyDataParameters *parameters);

    int startHourInt = 0;
    int startMinuteInt = 0;
    int endHourInt = 0;
    int endMinuteInt = 0;
    int samplingPeriod = 30;

private:
    Ui::DialogHistoricalDataTimeSet *ui;

public slots:
    void startTimeSetting();
    void endTimeSetting();
    void samplingRateSetting();
};

#endif // DIALOGHISTORICALDATATIMESET_H

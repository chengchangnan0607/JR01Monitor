#ifndef DIALOGSYSTEMSET_H
#define DIALOGSYSTEMSET_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include "dialoginputnumber.h"

#define softVersion "V0.2.0"
#define pcDebug

namespace Ui {
class DialogSystemSet;
}

class DialogSystemSet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSystemSet(QWidget *parent = nullptr);
    ~DialogSystemSet();
    void setSpeed(unsigned short speedVal);

    int yearInt = 0;
    int monthInt = 0;
    int dayInt = 0;
    int hourInt = 0;
    int minuteInt = 0;
    int secondInt = 0;
    QDateTime dateTimeSetVal = QDateTime::currentDateTime();

    int cavityLength = 0;
    int sensitivity = 0;

    unsigned short bpSpeed = 0;

private:

    Ui::DialogSystemSet *ui;

signals:
    void powerOff();

public slots:
    void dateSetting();
    void timeSetting();
    void lengthSetting();
    void sensitivitySetting();
    void pressureZeroCalibration();
    void bloodPumpSpeed();
    void powerOffHandle();
};

#endif // DIALOGSYSTEMSET_H

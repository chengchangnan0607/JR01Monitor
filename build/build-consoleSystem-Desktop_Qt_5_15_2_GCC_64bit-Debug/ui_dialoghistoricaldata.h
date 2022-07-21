/********************************************************************************
** Form generated from reading UI file 'dialoghistoricaldata.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHISTORICALDATA_H
#define UI_DIALOGHISTORICALDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_DialogHistoricalData
{
public:
    QChartView *widget_Up;
    QChartView *widget_Down;
    QPushButton *pushButton_Close;
    QPushButton *pushButton_BloodPump;
    QPushButton *pushButton_PurgeSystem;
    QPushButton *pushButton_AmplitudeUp;
    QPushButton *pushButton_CycleUp;
    QPushButton *pushButton_AmplitudeDown;
    QPushButton *pushButton_CycleDown;
    QPushButton *pushButton_TimeSet;
    QPushButton *pushButton_PlaybackSpeed;
    QPushButton *pushButton_Play;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DialogHistoricalData)
    {
        if (DialogHistoricalData->objectName().isEmpty())
            DialogHistoricalData->setObjectName(QString::fromUtf8("DialogHistoricalData"));
        DialogHistoricalData->setWindowModality(Qt::ApplicationModal);
        DialogHistoricalData->resize(1024, 600);
        QFont font;
        font.setPointSize(14);
        DialogHistoricalData->setFont(font);
        DialogHistoricalData->setModal(true);
        widget_Up = new QChartView(DialogHistoricalData);
        widget_Up->setObjectName(QString::fromUtf8("widget_Up"));
        widget_Up->setGeometry(QRect(10, 70, 871, 261));
        widget_Up->setFont(font);
        widget_Down = new QChartView(DialogHistoricalData);
        widget_Down->setObjectName(QString::fromUtf8("widget_Down"));
        widget_Down->setGeometry(QRect(10, 330, 871, 261));
        pushButton_Close = new QPushButton(DialogHistoricalData);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(910, 520, 91, 51));
        pushButton_BloodPump = new QPushButton(DialogHistoricalData);
        buttonGroup = new QButtonGroup(DialogHistoricalData);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_BloodPump);
        pushButton_BloodPump->setObjectName(QString::fromUtf8("pushButton_BloodPump"));
        pushButton_BloodPump->setGeometry(QRect(20, 10, 91, 51));
        pushButton_BloodPump->setCheckable(true);
        pushButton_BloodPump->setChecked(true);
        pushButton_PurgeSystem = new QPushButton(DialogHistoricalData);
        buttonGroup->addButton(pushButton_PurgeSystem);
        pushButton_PurgeSystem->setObjectName(QString::fromUtf8("pushButton_PurgeSystem"));
        pushButton_PurgeSystem->setGeometry(QRect(140, 10, 91, 51));
        pushButton_PurgeSystem->setCheckable(true);
        pushButton_AmplitudeUp = new QPushButton(DialogHistoricalData);
        pushButton_AmplitudeUp->setObjectName(QString::fromUtf8("pushButton_AmplitudeUp"));
        pushButton_AmplitudeUp->setGeometry(QRect(910, 70, 91, 51));
        pushButton_CycleUp = new QPushButton(DialogHistoricalData);
        pushButton_CycleUp->setObjectName(QString::fromUtf8("pushButton_CycleUp"));
        pushButton_CycleUp->setGeometry(QRect(910, 210, 91, 51));
        pushButton_AmplitudeDown = new QPushButton(DialogHistoricalData);
        pushButton_AmplitudeDown->setObjectName(QString::fromUtf8("pushButton_AmplitudeDown"));
        pushButton_AmplitudeDown->setGeometry(QRect(910, 140, 91, 51));
        pushButton_CycleDown = new QPushButton(DialogHistoricalData);
        pushButton_CycleDown->setObjectName(QString::fromUtf8("pushButton_CycleDown"));
        pushButton_CycleDown->setGeometry(QRect(910, 280, 91, 51));
        pushButton_TimeSet = new QPushButton(DialogHistoricalData);
        pushButton_TimeSet->setObjectName(QString::fromUtf8("pushButton_TimeSet"));
        pushButton_TimeSet->setGeometry(QRect(540, 10, 91, 51));
        pushButton_PlaybackSpeed = new QPushButton(DialogHistoricalData);
        pushButton_PlaybackSpeed->setObjectName(QString::fromUtf8("pushButton_PlaybackSpeed"));
        pushButton_PlaybackSpeed->setGeometry(QRect(780, 10, 91, 51));
        pushButton_Play = new QPushButton(DialogHistoricalData);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));
        pushButton_Play->setGeometry(QRect(660, 10, 91, 51));

        retranslateUi(DialogHistoricalData);

        QMetaObject::connectSlotsByName(DialogHistoricalData);
    } // setupUi

    void retranslateUi(QDialog *DialogHistoricalData)
    {
        DialogHistoricalData->setWindowTitle(QCoreApplication::translate("DialogHistoricalData", "Dialog", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("DialogHistoricalData", "\345\205\263\351\227\255", nullptr));
        pushButton_BloodPump->setText(QCoreApplication::translate("DialogHistoricalData", "\350\241\200\346\263\265", nullptr));
        pushButton_PurgeSystem->setText(QCoreApplication::translate("DialogHistoricalData", "\345\206\262\346\264\227\346\263\265", nullptr));
        pushButton_AmplitudeUp->setText(QCoreApplication::translate("DialogHistoricalData", "\345\271\205\345\200\274 +", nullptr));
        pushButton_CycleUp->setText(QCoreApplication::translate("DialogHistoricalData", "\345\221\250\346\234\237 +", nullptr));
        pushButton_AmplitudeDown->setText(QCoreApplication::translate("DialogHistoricalData", "\345\271\205\345\200\274 -", nullptr));
        pushButton_CycleDown->setText(QCoreApplication::translate("DialogHistoricalData", "\345\221\250\346\234\237 -", nullptr));
        pushButton_TimeSet->setText(QCoreApplication::translate("DialogHistoricalData", "\350\256\276\347\275\256", nullptr));
        pushButton_PlaybackSpeed->setText(QCoreApplication::translate("DialogHistoricalData", "\345\200\215\351\200\237 x 1", nullptr));
        pushButton_Play->setText(QCoreApplication::translate("DialogHistoricalData", "\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogHistoricalData: public Ui_DialogHistoricalData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHISTORICALDATA_H

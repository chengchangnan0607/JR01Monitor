/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_SelfTest;
    QWidget *page_BootOptions;
    QPushButton *pushButton_NewSurgery;
    QWidget *page_InstallationGuide;
    QWidget *page_MonitoringMain;
    QLabel *label_PumpID;
    QPushButton *pushButton_Speed;
    QLabel *label_AlarmInfo3;
    QStackedWidget *stackedWidget_Curve;
    QWidget *page_CurvePump;
    QPushButton *pushButton_HistoryPump;
    QLabel *label_24;
    QLabel *label_27;
    QLabel *label_31;
    QFrame *line_4;
    QFrame *line_7;
    QFrame *line_8;
    QChartView *widget_DownPump;
    QChartView *widget_UpPump;
    QLabel *label_32;
    QWidget *page_CurvePurge;
    QLabel *label_33;
    QFrame *line_10;
    QPushButton *pushButton_HistoryPurge;
    QLabel *label_34;
    QFrame *line_11;
    QChartView *widget_DownPurge;
    QChartView *widget_UpPurge;
    QLabel *label_35;
    QLabel *label_AlarmInfo2;
    QLabel *label;
    QFrame *line;
    QPushButton *pushButton_Log;
    QStackedWidget *stackedWidget_Value;
    QWidget *page_Value_Pump;
    QLabel *label_36;
    QLabel *label_ConnectWordsPump;
    QLabel *label_ConnectIconPump;
    QLabel *label_FlowPump;
    QLabel *label_Current;
    QLabel *label_PressurePump;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_Speed;
    QWidget *page_ValuePurge;
    QLabel *label_46;
    QLabel *label_ConnectWordsPurge;
    QLabel *label_47;
    QLabel *label_ConnectIconPurge;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_PressurePurge;
    QLabel *label_FlowPurge;
    QLabel *label_Charge;
    QLabel *label_DateTime;
    QLabel *label_AlarmInfo1;
    QPushButton *pushButton_Set;
    QLabel *label_3;
    QLabel *label_StateCharge;
    QLabel *label_5;
    QLabel *label_4;
    QPushButton *pushButton_PumpStop;
    QLabel *label_AlarmLED;
    QLabel *label_Supply;
    QPushButton *pushButton_Back;
    QPushButton *pushButton_PumpStart;
    QPushButton *pushButton_Purge;
    QLabel *label_2;
    QPushButton *pushButton_Pump;
    QWidget *page_HistoricalData;
    QWidget *page_AlarmLog;
    QWidget *page_SystemSetting;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(00, 05, 10);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 1024, 768));
        page_SelfTest = new QWidget();
        page_SelfTest->setObjectName(QString::fromUtf8("page_SelfTest"));
        stackedWidget->addWidget(page_SelfTest);
        page_BootOptions = new QWidget();
        page_BootOptions->setObjectName(QString::fromUtf8("page_BootOptions"));
        pushButton_NewSurgery = new QPushButton(page_BootOptions);
        pushButton_NewSurgery->setObjectName(QString::fromUtf8("pushButton_NewSurgery"));
        pushButton_NewSurgery->setGeometry(QRect(390, 130, 121, 101));
        pushButton_NewSurgery->setStyleSheet(QString::fromUtf8("font: 20pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_NewSurgery->setAutoDefault(false);
        pushButton_NewSurgery->setFlat(false);
        stackedWidget->addWidget(page_BootOptions);
        page_InstallationGuide = new QWidget();
        page_InstallationGuide->setObjectName(QString::fromUtf8("page_InstallationGuide"));
        stackedWidget->addWidget(page_InstallationGuide);
        page_MonitoringMain = new QWidget();
        page_MonitoringMain->setObjectName(QString::fromUtf8("page_MonitoringMain"));
        label_PumpID = new QLabel(page_MonitoringMain);
        label_PumpID->setObjectName(QString::fromUtf8("label_PumpID"));
        label_PumpID->setGeometry(QRect(70, 24, 170, 28));
        QFont font;
        font.setPointSize(20);
        label_PumpID->setFont(font);
        label_PumpID->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton_Speed = new QPushButton(page_MonitoringMain);
        pushButton_Speed->setObjectName(QString::fromUtf8("pushButton_Speed"));
        pushButton_Speed->setGeometry(QRect(879, 530, 121, 100));
        pushButton_Speed->setStyleSheet(QString::fromUtf8("background-image: url(:/ic_\350\275\254\351\200\237\350\256\276\347\275\256card.png);\n"
"background-color: rgb(17, 40, 67);\n"
"font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        label_AlarmInfo3 = new QLabel(page_MonitoringMain);
        label_AlarmInfo3->setObjectName(QString::fromUtf8("label_AlarmInfo3"));
        label_AlarmInfo3->setGeometry(QRect(530, 670, 301, 32));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        label_AlarmInfo3->setFont(font1);
        label_AlarmInfo3->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 30, 50);\n"
"font: 16pt \"Ubuntu\";"));
        stackedWidget_Curve = new QStackedWidget(page_MonitoringMain);
        stackedWidget_Curve->setObjectName(QString::fromUtf8("stackedWidget_Curve"));
        stackedWidget_Curve->setGeometry(QRect(24, 76, 841, 440));
        stackedWidget_Curve->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        stackedWidget_Curve->setInputMethodHints(Qt::ImhNone);
        stackedWidget_Curve->setFrameShape(QFrame::NoFrame);
        stackedWidget_Curve->setFrameShadow(QFrame::Plain);
        stackedWidget_Curve->setLineWidth(0);
        stackedWidget_Curve->setMidLineWidth(0);
        page_CurvePump = new QWidget();
        page_CurvePump->setObjectName(QString::fromUtf8("page_CurvePump"));
        page_CurvePump->setStyleSheet(QString::fromUtf8(""));
        pushButton_HistoryPump = new QPushButton(page_CurvePump);
        pushButton_HistoryPump->setObjectName(QString::fromUtf8("pushButton_HistoryPump"));
        pushButton_HistoryPump->setGeometry(QRect(724, 10, 96, 28));
        pushButton_HistoryPump->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 18pt \"Ubuntu\";"));
        pushButton_HistoryPump->setFlat(true);
        label_24 = new QLabel(page_CurvePump);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(48, 16, 38, 20));
        label_24->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font:14pt \"Ubuntu\";"));
        label_24->setAlignment(Qt::AlignCenter);
        label_27 = new QLabel(page_CurvePump);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(118, 16, 38, 20));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_27->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(page_CurvePump);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(48, 226, 38, 20));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_31->setAlignment(Qt::AlignCenter);
        line_4 = new QFrame(page_CurvePump);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(30, 25, 10, 2));
        line_4->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 144, 255);"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(page_CurvePump);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(100, 25, 10, 2));
        line_7->setStyleSheet(QString::fromUtf8("background-color: rgb(82, 196, 26);"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(page_CurvePump);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(30, 237, 10, 2));
        line_8->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 168, 168);"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        widget_DownPump = new QChartView(page_CurvePump);
        widget_DownPump->setObjectName(QString::fromUtf8("widget_DownPump"));
        widget_DownPump->setGeometry(QRect(20, 254, 801, 181));
        widget_DownPump->setAutoFillBackground(false);
        widget_DownPump->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        widget_UpPump = new QChartView(page_CurvePump);
        widget_UpPump->setObjectName(QString::fromUtf8("widget_UpPump"));
        widget_UpPump->setGeometry(QRect(20, 44, 801, 181));
        QFont font2;
        font2.setPointSize(14);
        widget_UpPump->setFont(font2);
        widget_UpPump->setAutoFillBackground(false);
        widget_UpPump->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        label_32 = new QLabel(page_CurvePump);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(690, 12, 28, 28));
        label_32->setStyleSheet(QString::fromUtf8("image: url(:/ic_\345\216\206\345\217\262\350\256\260\345\275\225.png);"));
        stackedWidget_Curve->addWidget(page_CurvePump);
        page_CurvePurge = new QWidget();
        page_CurvePurge->setObjectName(QString::fromUtf8("page_CurvePurge"));
        page_CurvePurge->setStyleSheet(QString::fromUtf8(""));
        label_33 = new QLabel(page_CurvePurge);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(48, 226, 38, 20));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_33->setAlignment(Qt::AlignCenter);
        line_10 = new QFrame(page_CurvePurge);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(30, 25, 10, 2));
        line_10->setStyleSheet(QString::fromUtf8("background-color: rgb(24, 144, 255);"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        pushButton_HistoryPurge = new QPushButton(page_CurvePurge);
        pushButton_HistoryPurge->setObjectName(QString::fromUtf8("pushButton_HistoryPurge"));
        pushButton_HistoryPurge->setGeometry(QRect(724, 10, 96, 28));
        pushButton_HistoryPurge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 18pt \"Ubuntu\";"));
        pushButton_HistoryPurge->setFlat(true);
        label_34 = new QLabel(page_CurvePurge);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(48, 16, 38, 20));
        label_34->setStyleSheet(QString::fromUtf8("color:rgb(255, 255, 255);\n"
"font:14pt \"Ubuntu\";"));
        label_34->setAlignment(Qt::AlignCenter);
        line_11 = new QFrame(page_CurvePurge);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(30, 237, 10, 2));
        line_11->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 168, 168);"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        widget_DownPurge = new QChartView(page_CurvePurge);
        widget_DownPurge->setObjectName(QString::fromUtf8("widget_DownPurge"));
        widget_DownPurge->setGeometry(QRect(20, 254, 801, 181));
        widget_DownPurge->setAutoFillBackground(false);
        widget_DownPurge->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        widget_UpPurge = new QChartView(page_CurvePurge);
        widget_UpPurge->setObjectName(QString::fromUtf8("widget_UpPurge"));
        widget_UpPurge->setGeometry(QRect(20, 44, 801, 181));
        widget_UpPurge->setFont(font2);
        widget_UpPurge->setAutoFillBackground(false);
        widget_UpPurge->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        label_35 = new QLabel(page_CurvePurge);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(690, 12, 28, 28));
        label_35->setStyleSheet(QString::fromUtf8("image: url(:/ic_\345\216\206\345\217\262\350\256\260\345\275\225.png);"));
        stackedWidget_Curve->addWidget(page_CurvePurge);
        label_AlarmInfo2 = new QLabel(page_MonitoringMain);
        label_AlarmInfo2->setObjectName(QString::fromUtf8("label_AlarmInfo2"));
        label_AlarmInfo2->setGeometry(QRect(530, 640, 301, 32));
        label_AlarmInfo2->setFont(font1);
        label_AlarmInfo2->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 30, 50);\n"
"font: 16pt \"Ubuntu\";"));
        label = new QLabel(page_MonitoringMain);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 24, 28, 28));
        label->setStyleSheet(QString::fromUtf8("image: url(:/img_logo28.png);"));
        line = new QFrame(page_MonitoringMain);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(855, 28, 1, 20));
        line->setStyleSheet(QString::fromUtf8("background-color: rgb(201, 201, 201);"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_Log = new QPushButton(page_MonitoringMain);
        pushButton_Log->setObjectName(QString::fromUtf8("pushButton_Log"));
        pushButton_Log->setGeometry(QRect(879, 644, 121, 100));
        pushButton_Log->setStyleSheet(QString::fromUtf8("background-image: url(:/ic_\346\212\245\350\255\246\346\227\245\345\277\227card.png);\n"
"background-color: rgb(17, 40, 67);\n"
"font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        stackedWidget_Value = new QStackedWidget(page_MonitoringMain);
        stackedWidget_Value->setObjectName(QString::fromUtf8("stackedWidget_Value"));
        stackedWidget_Value->setGeometry(QRect(24, 530, 458, 214));
        stackedWidget_Value->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        page_Value_Pump = new QWidget();
        page_Value_Pump->setObjectName(QString::fromUtf8("page_Value_Pump"));
        page_Value_Pump->setStyleSheet(QString::fromUtf8(""));
        label_36 = new QLabel(page_Value_Pump);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(24, 24, 62, 28));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu\";"));
        label_ConnectWordsPump = new QLabel(page_Value_Pump);
        label_ConnectWordsPump->setObjectName(QString::fromUtf8("label_ConnectWordsPump"));
        label_ConnectWordsPump->setGeometry(QRect(378, 27, 72, 22));
        label_ConnectWordsPump->setStyleSheet(QString::fromUtf8("color: rgb(115, 210, 22);\n"
"font: 16pt \"Ubuntu\";"));
        label_ConnectIconPump = new QLabel(page_Value_Pump);
        label_ConnectIconPump->setObjectName(QString::fromUtf8("label_ConnectIconPump"));
        label_ConnectIconPump->setGeometry(QRect(361, 36, 8, 8));
        label_ConnectIconPump->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);"));
        label_FlowPump = new QLabel(page_Value_Pump);
        label_FlowPump->setObjectName(QString::fromUtf8("label_FlowPump"));
        label_FlowPump->setGeometry(QRect(20, 76, 89, 45));
        label_FlowPump->setStyleSheet(QString::fromUtf8("color: rgb(24, 144, 255);\n"
"font: 32pt \"Ubuntu\";"));
        label_FlowPump->setScaledContents(false);
        label_FlowPump->setAlignment(Qt::AlignCenter);
        label_Current = new QLabel(page_Value_Pump);
        label_Current->setObjectName(QString::fromUtf8("label_Current"));
        label_Current->setGeometry(QRect(130, 76, 89, 45));
        label_Current->setStyleSheet(QString::fromUtf8("color: rgb(82, 196, 26);\n"
"font: 32pt \"Ubuntu\";"));
        label_Current->setScaledContents(false);
        label_Current->setAlignment(Qt::AlignCenter);
        label_PressurePump = new QLabel(page_Value_Pump);
        label_PressurePump->setObjectName(QString::fromUtf8("label_PressurePump"));
        label_PressurePump->setGeometry(QRect(239, 76, 89, 45));
        label_PressurePump->setStyleSheet(QString::fromUtf8("color: rgb(19, 194, 194);\n"
"font: 32pt \"Ubuntu\";"));
        label_PressurePump->setScaledContents(false);
        label_PressurePump->setAlignment(Qt::AlignCenter);
        label_37 = new QLabel(page_Value_Pump);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(422, 94, 10, 10));
        label_37->setStyleSheet(QString::fromUtf8("background-image: url(:/Image/ic-\344\270\213\346\213\211.png);"));
        label_38 = new QLabel(page_Value_Pump);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(0, 131, 114, 30));
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_38->setAlignment(Qt::AlignCenter);
        label_39 = new QLabel(page_Value_Pump);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(115, 131, 114, 30));
        label_39->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_39->setAlignment(Qt::AlignCenter);
        label_40 = new QLabel(page_Value_Pump);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(229, 130, 114, 30));
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_40->setAlignment(Qt::AlignCenter);
        label_41 = new QLabel(page_Value_Pump);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(343, 131, 114, 30));
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_41->setAlignment(Qt::AlignCenter);
        label_42 = new QLabel(page_Value_Pump);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(115, 163, 114, 30));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_42->setAlignment(Qt::AlignCenter);
        label_43 = new QLabel(page_Value_Pump);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(343, 163, 114, 30));
        label_43->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_43->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(page_Value_Pump);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(0, 163, 114, 30));
        label_44->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_44->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(page_Value_Pump);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(229, 163, 114, 30));
        label_45->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_45->setAlignment(Qt::AlignCenter);
        label_Speed = new QLabel(page_Value_Pump);
        label_Speed->setObjectName(QString::fromUtf8("label_Speed"));
        label_Speed->setGeometry(QRect(349, 76, 89, 45));
        label_Speed->setStyleSheet(QString::fromUtf8("color: rgb(250, 173, 20);\n"
"font: 32pt \"Ubuntu\";"));
        label_Speed->setScaledContents(false);
        label_Speed->setAlignment(Qt::AlignCenter);
        stackedWidget_Value->addWidget(page_Value_Pump);
        page_ValuePurge = new QWidget();
        page_ValuePurge->setObjectName(QString::fromUtf8("page_ValuePurge"));
        page_ValuePurge->setStyleSheet(QString::fromUtf8(""));
        label_46 = new QLabel(page_ValuePurge);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(247, 163, 114, 30));
        label_46->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_46->setAlignment(Qt::AlignCenter);
        label_ConnectWordsPurge = new QLabel(page_ValuePurge);
        label_ConnectWordsPurge->setObjectName(QString::fromUtf8("label_ConnectWordsPurge"));
        label_ConnectWordsPurge->setGeometry(QRect(378, 27, 72, 22));
        label_ConnectWordsPurge->setStyleSheet(QString::fromUtf8("color: rgb(115, 210, 22);\n"
"font: 16pt \"Ubuntu\";"));
        label_47 = new QLabel(page_ValuePurge);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(422, 94, 10, 10));
        label_47->setStyleSheet(QString::fromUtf8("background-image: url(:/Image/ic-\344\270\213\346\213\211.png);"));
        label_ConnectIconPurge = new QLabel(page_ValuePurge);
        label_ConnectIconPurge->setObjectName(QString::fromUtf8("label_ConnectIconPurge"));
        label_ConnectIconPurge->setGeometry(QRect(361, 36, 8, 8));
        label_ConnectIconPurge->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 210, 22);"));
        label_48 = new QLabel(page_ValuePurge);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(87, 130, 114, 30));
        label_48->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_48->setAlignment(Qt::AlignCenter);
        label_49 = new QLabel(page_ValuePurge);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(247, 131, 114, 30));
        label_49->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_49->setAlignment(Qt::AlignCenter);
        label_50 = new QLabel(page_ValuePurge);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(24, 24, 81, 28));
        label_50->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20pt \"Ubuntu\";"));
        label_51 = new QLabel(page_ValuePurge);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(87, 163, 114, 30));
        label_51->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu\";"));
        label_51->setAlignment(Qt::AlignCenter);
        label_PressurePurge = new QLabel(page_ValuePurge);
        label_PressurePurge->setObjectName(QString::fromUtf8("label_PressurePurge"));
        label_PressurePurge->setGeometry(QRect(247, 76, 114, 45));
        label_PressurePurge->setStyleSheet(QString::fromUtf8("color: rgb(19, 194, 194);\n"
"font: 32pt \"Ubuntu\";"));
        label_PressurePurge->setScaledContents(false);
        label_PressurePurge->setAlignment(Qt::AlignCenter);
        label_FlowPurge = new QLabel(page_ValuePurge);
        label_FlowPurge->setObjectName(QString::fromUtf8("label_FlowPurge"));
        label_FlowPurge->setGeometry(QRect(87, 76, 114, 45));
        label_FlowPurge->setStyleSheet(QString::fromUtf8("color: rgb(24, 144, 255);\n"
"font: 32pt \"Ubuntu\";"));
        label_FlowPurge->setScaledContents(false);
        label_FlowPurge->setAlignment(Qt::AlignCenter);
        stackedWidget_Value->addWidget(page_ValuePurge);
        label_Charge = new QLabel(page_MonitoringMain);
        label_Charge->setObjectName(QString::fromUtf8("label_Charge"));
        label_Charge->setGeometry(QRect(954, 27, 22, 22));
        label_Charge->setStyleSheet(QString::fromUtf8("image: url(:/ic_\345\205\205\347\224\265\344\270\255.png);"));
        label_DateTime = new QLabel(page_MonitoringMain);
        label_DateTime->setObjectName(QString::fromUtf8("label_DateTime"));
        label_DateTime->setGeometry(QRect(384, 25, 320, 26));
        QFont font3;
        font3.setPointSize(18);
        label_DateTime->setFont(font3);
        label_DateTime->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_AlarmInfo1 = new QLabel(page_MonitoringMain);
        label_AlarmInfo1->setObjectName(QString::fromUtf8("label_AlarmInfo1"));
        label_AlarmInfo1->setGeometry(QRect(530, 610, 301, 32));
        label_AlarmInfo1->setFont(font1);
        label_AlarmInfo1->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 30, 50);\n"
"font: 16pt \"Ubuntu\";"));
        pushButton_Set = new QPushButton(page_MonitoringMain);
        pushButton_Set->setObjectName(QString::fromUtf8("pushButton_Set"));
        pushButton_Set->setGeometry(QRect(813, 25, 25, 25));
        pushButton_Set->setStyleSheet(QString::fromUtf8("background-image: url(:/ic_\350\256\276\347\275\256.png);"));
        pushButton_Set->setFlat(true);
        label_3 = new QLabel(page_MonitoringMain);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(496, 530, 369, 214));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        label_StateCharge = new QLabel(page_MonitoringMain);
        label_StateCharge->setObjectName(QString::fromUtf8("label_StateCharge"));
        label_StateCharge->setGeometry(QRect(876, 26, 64, 22));
        QFont font4;
        font4.setPointSize(16);
        label_StateCharge->setFont(font4);
        label_StateCharge->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_5 = new QLabel(page_MonitoringMain);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 599, 317, 121));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(10, 30, 50);"));
        label_4 = new QLabel(page_MonitoringMain);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(520, 554, 124, 28));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_PumpStop = new QPushButton(page_MonitoringMain);
        pushButton_PumpStop->setObjectName(QString::fromUtf8("pushButton_PumpStop"));
        pushButton_PumpStop->setGeometry(QRect(879, 416, 121, 100));
        pushButton_PumpStop->setStyleSheet(QString::fromUtf8("background-image: url(:/ic_\345\201\234\347\224\250\350\241\200\346\263\265card.png);\n"
"background-color: rgb(17, 40, 67);\n"
"font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        label_AlarmLED = new QLabel(page_MonitoringMain);
        label_AlarmLED->setObjectName(QString::fromUtf8("label_AlarmLED"));
        label_AlarmLED->setGeometry(QRect(807, 548, 34, 34));
        label_AlarmLED->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);\n"
"image: url(:/ic_\346\212\245\350\255\246.png);"));
        label_Supply = new QLabel(page_MonitoringMain);
        label_Supply->setObjectName(QString::fromUtf8("label_Supply"));
        label_Supply->setGeometry(QRect(990, 27, 22, 22));
        label_Supply->setStyleSheet(QString::fromUtf8("image: url(:/ic_\351\223\276\346\216\245\347\224\265\346\272\220.png);"));
        pushButton_Back = new QPushButton(page_MonitoringMain);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));
        pushButton_Back->setGeometry(QRect(771, 24, 25, 25));
        pushButton_Back->setStyleSheet(QString::fromUtf8("background-image: url(:/ic_\350\277\224\345\233\236\346\214\207\345\215\227.png);"));
        pushButton_Back->setFlat(true);
        pushButton_PumpStart = new QPushButton(page_MonitoringMain);
        pushButton_PumpStart->setObjectName(QString::fromUtf8("pushButton_PumpStart"));
        pushButton_PumpStart->setGeometry(QRect(879, 302, 121, 100));
        pushButton_PumpStart->setStyleSheet(QString::fromUtf8("background-image: url(:/\347\237\251\345\275\242\345\244\207\344\273\275 9.png);\n"
"background-color: rgb(17, 40, 67);\n"
"font: 16pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255);"));
        pushButton_Purge = new QPushButton(page_MonitoringMain);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_Purge);
        pushButton_Purge->setObjectName(QString::fromUtf8("pushButton_Purge"));
        pushButton_Purge->setGeometry(QRect(890, 189, 97, 86));
        pushButton_Purge->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255); "));
        pushButton_Purge->setCheckable(true);
        pushButton_Purge->setFlat(true);
        label_2 = new QLabel(page_MonitoringMain);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(879, 79, 121, 209));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);"));
        pushButton_Pump = new QPushButton(page_MonitoringMain);
        buttonGroup->addButton(pushButton_Pump);
        pushButton_Pump->setObjectName(QString::fromUtf8("pushButton_Pump"));
        pushButton_Pump->setGeometry(QRect(890, 90, 97, 86));
        pushButton_Pump->setStyleSheet(QString::fromUtf8("background-color: rgb(17, 40, 67);\n"
"font: 20pt \"Ubuntu\";\n"
"color: rgb(255, 255, 255); "));
        pushButton_Pump->setCheckable(true);
        pushButton_Pump->setChecked(true);
        pushButton_Pump->setAutoDefault(false);
        pushButton_Pump->setFlat(true);
        stackedWidget->addWidget(page_MonitoringMain);
        label_PumpID->raise();
        pushButton_Speed->raise();
        stackedWidget_Curve->raise();
        label->raise();
        line->raise();
        pushButton_Log->raise();
        stackedWidget_Value->raise();
        label_Charge->raise();
        label_DateTime->raise();
        label_3->raise();
        label_StateCharge->raise();
        label_5->raise();
        label_4->raise();
        label_Supply->raise();
        label_AlarmInfo1->raise();
        label_AlarmInfo2->raise();
        label_AlarmInfo3->raise();
        label_AlarmLED->raise();
        pushButton_Set->raise();
        pushButton_Back->raise();
        pushButton_PumpStop->raise();
        pushButton_PumpStart->raise();
        label_2->raise();
        pushButton_Pump->raise();
        pushButton_Purge->raise();
        page_HistoricalData = new QWidget();
        page_HistoricalData->setObjectName(QString::fromUtf8("page_HistoricalData"));
        stackedWidget->addWidget(page_HistoricalData);
        page_AlarmLog = new QWidget();
        page_AlarmLog->setObjectName(QString::fromUtf8("page_AlarmLog"));
        stackedWidget->addWidget(page_AlarmLog);
        page_SystemSetting = new QWidget();
        page_SystemSetting->setObjectName(QString::fromUtf8("page_SystemSetting"));
        stackedWidget->addWidget(page_SystemSetting);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);
        pushButton_NewSurgery->setDefault(true);
        stackedWidget_Curve->setCurrentIndex(1);
        stackedWidget_Value->setCurrentIndex(0);
        pushButton_PumpStart->setDefault(false);
        pushButton_Pump->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_NewSurgery->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\211\213\346\234\257", nullptr));
        label_PumpID->setText(QCoreApplication::translate("MainWindow", "3342 0098 22", nullptr));
        pushButton_Speed->setText(QString());
        label_AlarmInfo3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#4e9a06;\">3.\346\234\252\350\256\276\347\275\256\346\227\266\351\222\237\346\212\245\350\255\246,\350\257\267\350\256\276\347\275\256\346\227\266\351\222\237</span></p></body></html>", nullptr));
        pushButton_HistoryPump->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\346\265\201\351\207\217", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233", nullptr));
        label_32->setText(QString());
        label_33->setText(QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233", nullptr));
        pushButton_HistoryPurge->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\346\265\201\351\207\217", nullptr));
        label_35->setText(QString());
        label_AlarmInfo2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#c4a000;\">2.\346\263\265\346\265\201\351\207\217\350\266\205\350\214\203\345\233\264,\350\257\267\345\260\275\345\277\253\350\201\224\347\263\273\345\214\273\351\231\242</span></p></body></html>", nullptr));
        label->setText(QString());
        pushButton_Log->setText(QString());
        label_36->setText(QCoreApplication::translate("MainWindow", "\350\241\200\346\263\265", nullptr));
        label_ConnectWordsPump->setText(QCoreApplication::translate("MainWindow", "\345\267\262\350\277\236\346\216\245", nullptr));
        label_ConnectIconPump->setText(QString());
        label_FlowPump->setText(QCoreApplication::translate("MainWindow", "46", nullptr));
        label_Current->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        label_PressurePump->setText(QCoreApplication::translate("MainWindow", "66", nullptr));
        label_37->setText(QString());
        label_38->setText(QCoreApplication::translate("MainWindow", "1000~10000", nullptr));
        label_39->setText(QCoreApplication::translate("MainWindow", "1000~10000", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "1000~10000", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "1000~10000", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\265\201mA", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\350\275\254\351\200\237level", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\346\265\201\351\207\217l/min", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233mmHg", nullptr));
        label_Speed->setText(QCoreApplication::translate("MainWindow", "P2", nullptr));
        label_46->setText(QCoreApplication::translate("MainWindow", "\345\216\213\345\212\233mmHg", nullptr));
        label_ConnectWordsPurge->setText(QCoreApplication::translate("MainWindow", "\345\267\262\350\277\236\346\216\245", nullptr));
        label_47->setText(QString());
        label_ConnectIconPurge->setText(QString());
        label_48->setText(QCoreApplication::translate("MainWindow", "10000~10000", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "10000~10000", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "\345\206\262\346\264\227\346\263\265", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "\346\265\201\351\207\217l/min", nullptr));
        label_PressurePurge->setText(QCoreApplication::translate("MainWindow", "66", nullptr));
        label_FlowPurge->setText(QCoreApplication::translate("MainWindow", "46", nullptr));
        label_Charge->setText(QString());
        label_DateTime->setText(QCoreApplication::translate("MainWindow", "2022\345\271\2647\346\234\21011\346\227\245 \346\230\237\346\234\237\344\270\200 14:20", nullptr));
        label_AlarmInfo1->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ef2929;\">1.\346\263\265\350\277\236\346\216\245\345\244\261\350\264\245,\350\257\267\350\277\236\346\216\245\346\263\265</span></p></body></html>", nullptr));
        pushButton_Set->setText(QString());
        label_3->setText(QString());
        label_StateCharge->setText(QCoreApplication::translate("MainWindow", "\345\205\205\347\224\265\344\270\255", nullptr));
        label_5->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\212\245\350\255\246\344\277\241\346\201\257", nullptr));
        pushButton_PumpStop->setText(QString());
        label_AlarmLED->setText(QString());
        label_Supply->setText(QString());
        pushButton_Back->setText(QString());
        pushButton_PumpStart->setText(QString());
        pushButton_Purge->setText(QCoreApplication::translate("MainWindow", "\345\206\262\346\264\227\346\263\265", nullptr));
        label_2->setText(QString());
        pushButton_Pump->setText(QCoreApplication::translate("MainWindow", "\350\241\200\346\263\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

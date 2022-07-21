/********************************************************************************
** Form generated from reading UI file 'dialogsystemset.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSYSTEMSET_H
#define UI_DIALOGSYSTEMSET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogSystemSet
{
public:
    QPushButton *pushButton_PowerOff;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_Date;
    QPushButton *pushButton_Time;
    QPushButton *pushButton_CavityLength;
    QLabel *label_6;
    QPushButton *pushButton_Sensitivity;
    QLabel *label_7;
    QPushButton *pushButton_Calibration;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_8;
    QFrame *line_3;
    QLabel *label_MotorVersion;
    QLabel *label_2;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_19;
    QLabel *label_22;
    QLabel *label_27;
    QLabel *label_PurgeVersion;
    QLabel *label_PowerVersion;
    QLabel *label_SystemVersion;
    QLabel *label_12;
    QPushButton *pushButton_BPSpeed;
    QLabel *label_13;
    QFrame *line_6;

    void setupUi(QDialog *DialogSystemSet)
    {
        if (DialogSystemSet->objectName().isEmpty())
            DialogSystemSet->setObjectName(QString::fromUtf8("DialogSystemSet"));
        DialogSystemSet->setWindowModality(Qt::ApplicationModal);
        DialogSystemSet->resize(919, 490);
        QFont font;
        font.setPointSize(14);
        DialogSystemSet->setFont(font);
        DialogSystemSet->setModal(true);
        pushButton_PowerOff = new QPushButton(DialogSystemSet);
        pushButton_PowerOff->setObjectName(QString::fromUtf8("pushButton_PowerOff"));
        pushButton_PowerOff->setGeometry(QRect(480, 420, 101, 51));
        pushButton_PowerOff->setFont(font);
        label = new QLabel(DialogSystemSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(700, 60, 51, 51));
        label->setFont(font);
        label_3 = new QLabel(DialogSystemSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 70, 51, 31));
        label_3->setFont(font);
        label_4 = new QLabel(DialogSystemSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(480, 190, 101, 31));
        label_4->setFont(font);
        label_5 = new QLabel(DialogSystemSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 250, 71, 31));
        label_5->setFont(font);
        pushButton_Cancel = new QPushButton(DialogSystemSet);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(800, 420, 101, 51));
        pushButton_Cancel->setFont(font);
        pushButton_OK = new QPushButton(DialogSystemSet);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(670, 420, 101, 51));
        pushButton_OK->setFont(font);
        pushButton_Date = new QPushButton(DialogSystemSet);
        pushButton_Date->setObjectName(QString::fromUtf8("pushButton_Date"));
        pushButton_Date->setGeometry(QRect(540, 60, 141, 51));
        pushButton_Time = new QPushButton(DialogSystemSet);
        pushButton_Time->setObjectName(QString::fromUtf8("pushButton_Time"));
        pushButton_Time->setGeometry(QRect(760, 60, 141, 51));
        pushButton_CavityLength = new QPushButton(DialogSystemSet);
        pushButton_CavityLength->setObjectName(QString::fromUtf8("pushButton_CavityLength"));
        pushButton_CavityLength->setGeometry(QRect(580, 180, 101, 51));
        label_6 = new QLabel(DialogSystemSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(690, 190, 41, 31));
        label_6->setFont(font);
        pushButton_Sensitivity = new QPushButton(DialogSystemSet);
        pushButton_Sensitivity->setObjectName(QString::fromUtf8("pushButton_Sensitivity"));
        pushButton_Sensitivity->setGeometry(QRect(580, 240, 101, 51));
        label_7 = new QLabel(DialogSystemSet);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(690, 250, 121, 31));
        label_7->setFont(font);
        pushButton_Calibration = new QPushButton(DialogSystemSet);
        pushButton_Calibration->setObjectName(QString::fromUtf8("pushButton_Calibration"));
        pushButton_Calibration->setGeometry(QRect(760, 180, 141, 51));
        line = new QFrame(DialogSystemSet);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(470, 120, 441, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(DialogSystemSet);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(467, 300, 441, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(DialogSystemSet);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(480, 140, 151, 31));
        label_8->setFont(font);
        line_3 = new QFrame(DialogSystemSet);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(470, 30, 441, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_MotorVersion = new QLabel(DialogSystemSet);
        label_MotorVersion->setObjectName(QString::fromUtf8("label_MotorVersion"));
        label_MotorVersion->setGeometry(QRect(80, 50, 281, 41));
        label_MotorVersion->setFont(font);
        label_2 = new QLabel(DialogSystemSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 0, 41, 41));
        line_4 = new QFrame(DialogSystemSet);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(450, 10, 20, 471));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(DialogSystemSet);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(10, 30, 441, 21));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_10 = new QLabel(DialogSystemSet);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 0, 41, 41));
        label_11 = new QLabel(DialogSystemSet);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(90, 320, 241, 21));
        label_11->setFont(font);
        label_14 = new QLabel(DialogSystemSet);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 60, 41, 21));
        label_14->setFont(font);
        label_19 = new QLabel(DialogSystemSet);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 100, 41, 21));
        label_19->setFont(font);
        label_22 = new QLabel(DialogSystemSet);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 140, 41, 21));
        label_22->setFont(font);
        label_27 = new QLabel(DialogSystemSet);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(20, 170, 41, 41));
        label_27->setFont(font);
        label_PurgeVersion = new QLabel(DialogSystemSet);
        label_PurgeVersion->setObjectName(QString::fromUtf8("label_PurgeVersion"));
        label_PurgeVersion->setGeometry(QRect(80, 90, 281, 41));
        label_PurgeVersion->setFont(font);
        label_PowerVersion = new QLabel(DialogSystemSet);
        label_PowerVersion->setObjectName(QString::fromUtf8("label_PowerVersion"));
        label_PowerVersion->setGeometry(QRect(80, 130, 281, 41));
        label_PowerVersion->setFont(font);
        label_SystemVersion = new QLabel(DialogSystemSet);
        label_SystemVersion->setObjectName(QString::fromUtf8("label_SystemVersion"));
        label_SystemVersion->setGeometry(QRect(80, 170, 281, 41));
        label_SystemVersion->setFont(font);
        label_12 = new QLabel(DialogSystemSet);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(480, 340, 81, 31));
        label_12->setFont(font);
        pushButton_BPSpeed = new QPushButton(DialogSystemSet);
        pushButton_BPSpeed->setObjectName(QString::fromUtf8("pushButton_BPSpeed"));
        pushButton_BPSpeed->setGeometry(QRect(580, 330, 101, 51));
        label_13 = new QLabel(DialogSystemSet);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(690, 340, 61, 31));
        label_13->setFont(font);
        line_6 = new QFrame(DialogSystemSet);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(470, 390, 441, 21));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        retranslateUi(DialogSystemSet);

        QMetaObject::connectSlotsByName(DialogSystemSet);
    } // setupUi

    void retranslateUi(QDialog *DialogSystemSet)
    {
        DialogSystemSet->setWindowTitle(QCoreApplication::translate("DialogSystemSet", "Dialog", nullptr));
        pushButton_PowerOff->setText(QCoreApplication::translate("DialogSystemSet", "\345\205\263\346\234\272", nullptr));
        label->setText(QCoreApplication::translate("DialogSystemSet", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("DialogSystemSet", "\346\227\245\346\234\237", nullptr));
        label_4->setText(QCoreApplication::translate("DialogSystemSet", "\345\210\235\345\247\213\350\205\224\351\225\277", nullptr));
        label_5->setText(QCoreApplication::translate("DialogSystemSet", "\347\201\265\346\225\217\345\272\246", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("DialogSystemSet", "\345\217\226\346\266\210", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("DialogSystemSet", "\347\241\256\345\256\232", nullptr));
        pushButton_Date->setText(QCoreApplication::translate("DialogSystemSet", "2022-05-16", nullptr));
        pushButton_Time->setText(QCoreApplication::translate("DialogSystemSet", "16:22:30", nullptr));
        pushButton_CavityLength->setText(QCoreApplication::translate("DialogSystemSet", "65535", nullptr));
        label_6->setText(QCoreApplication::translate("DialogSystemSet", "nm", nullptr));
        pushButton_Sensitivity->setText(QCoreApplication::translate("DialogSystemSet", "555", nullptr));
        label_7->setText(QCoreApplication::translate("DialogSystemSet", "nm/mmHg", nullptr));
        pushButton_Calibration->setText(QCoreApplication::translate("DialogSystemSet", "\345\216\213\345\212\233\346\240\241\351\233\266", nullptr));
        label_8->setText(QCoreApplication::translate("DialogSystemSet", "\345\205\211\347\272\244\344\274\240\346\204\237\345\231\250\345\217\202\346\225\260", nullptr));
        label_MotorVersion->setText(QCoreApplication::translate("DialogSystemSet", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSystemSet", "\350\256\276\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("DialogSystemSet", "\344\277\241\346\201\257", nullptr));
        label_11->setText(QCoreApplication::translate("DialogSystemSet", "\346\267\261\345\234\263\346\240\270\345\277\203\345\214\273\347\226\227\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270", nullptr));
        label_14->setText(QCoreApplication::translate("DialogSystemSet", "\347\224\265\346\234\272   ", nullptr));
        label_19->setText(QCoreApplication::translate("DialogSystemSet", "\345\206\262\346\264\227 ", nullptr));
        label_22->setText(QCoreApplication::translate("DialogSystemSet", "\347\224\265\346\272\220   ", nullptr));
        label_27->setText(QCoreApplication::translate("DialogSystemSet", "\347\263\273\347\273\237", nullptr));
        label_PurgeVersion->setText(QCoreApplication::translate("DialogSystemSet", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_PowerVersion->setText(QCoreApplication::translate("DialogSystemSet", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_SystemVersion->setText(QCoreApplication::translate("DialogSystemSet", "<html><head/><body><p><br/></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("DialogSystemSet", "\350\241\200\346\263\265\350\275\254\351\200\237", nullptr));
        pushButton_BPSpeed->setText(QCoreApplication::translate("DialogSystemSet", "46000", nullptr));
        label_13->setText(QCoreApplication::translate("DialogSystemSet", "r/pm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSystemSet: public Ui_DialogSystemSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSYSTEMSET_H

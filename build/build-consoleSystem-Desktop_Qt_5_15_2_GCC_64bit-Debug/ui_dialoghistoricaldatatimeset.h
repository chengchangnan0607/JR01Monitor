/********************************************************************************
** Form generated from reading UI file 'dialoghistoricaldatatimeset.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHISTORICALDATATIMESET_H
#define UI_DIALOGHISTORICALDATATIMESET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogHistoricalDataTimeSet
{
public:
    QPushButton *pushButton_EndTime;
    QPushButton *pushButton_OK;
    QLabel *label;
    QPushButton *pushButton_Cancel;
    QLabel *label_3;
    QComboBox *comboBox_Date;
    QLabel *label_2;
    QPushButton *pushButton_StartTime;
    QPushButton *pushButton_SamplingPeriod;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *DialogHistoricalDataTimeSet)
    {
        if (DialogHistoricalDataTimeSet->objectName().isEmpty())
            DialogHistoricalDataTimeSet->setObjectName(QString::fromUtf8("DialogHistoricalDataTimeSet"));
        DialogHistoricalDataTimeSet->setWindowModality(Qt::ApplicationModal);
        DialogHistoricalDataTimeSet->resize(321, 345);
        QFont font;
        font.setPointSize(14);
        DialogHistoricalDataTimeSet->setFont(font);
        DialogHistoricalDataTimeSet->setModal(true);
        pushButton_EndTime = new QPushButton(DialogHistoricalDataTimeSet);
        pushButton_EndTime->setObjectName(QString::fromUtf8("pushButton_EndTime"));
        pushButton_EndTime->setGeometry(QRect(110, 140, 191, 51));
        pushButton_OK = new QPushButton(DialogHistoricalDataTimeSet);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(30, 270, 101, 51));
        pushButton_OK->setFont(font);
        label = new QLabel(DialogHistoricalDataTimeSet);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 81, 31));
        pushButton_Cancel = new QPushButton(DialogHistoricalDataTimeSet);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));
        pushButton_Cancel->setGeometry(QRect(190, 270, 101, 51));
        pushButton_Cancel->setFont(font);
        label_3 = new QLabel(DialogHistoricalDataTimeSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 30, 81, 31));
        comboBox_Date = new QComboBox(DialogHistoricalDataTimeSet);
        comboBox_Date->setObjectName(QString::fromUtf8("comboBox_Date"));
        comboBox_Date->setGeometry(QRect(110, 20, 191, 51));
        QFont font1;
        font1.setPointSize(10);
        comboBox_Date->setFont(font1);
        label_2 = new QLabel(DialogHistoricalDataTimeSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 150, 81, 31));
        pushButton_StartTime = new QPushButton(DialogHistoricalDataTimeSet);
        pushButton_StartTime->setObjectName(QString::fromUtf8("pushButton_StartTime"));
        pushButton_StartTime->setGeometry(QRect(110, 80, 191, 51));
        pushButton_SamplingPeriod = new QPushButton(DialogHistoricalDataTimeSet);
        pushButton_SamplingPeriod->setObjectName(QString::fromUtf8("pushButton_SamplingPeriod"));
        pushButton_SamplingPeriod->setGeometry(QRect(110, 200, 131, 51));
        label_4 = new QLabel(DialogHistoricalDataTimeSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 210, 81, 31));
        label_5 = new QLabel(DialogHistoricalDataTimeSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 210, 41, 31));

        retranslateUi(DialogHistoricalDataTimeSet);

        QMetaObject::connectSlotsByName(DialogHistoricalDataTimeSet);
    } // setupUi

    void retranslateUi(QDialog *DialogHistoricalDataTimeSet)
    {
        DialogHistoricalDataTimeSet->setWindowTitle(QCoreApplication::translate("DialogHistoricalDataTimeSet", "Dialog", nullptr));
        pushButton_EndTime->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "23:59", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\350\265\267\345\247\213\346\227\266\351\227\264", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\345\217\226\346\266\210", nullptr));
        label_3->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\350\241\250\346\240\274\346\227\245\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        pushButton_StartTime->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "00:00", nullptr));
        pushButton_SamplingPeriod->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "30", nullptr));
        label_4->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\351\207\207\346\240\267\345\221\250\346\234\237", nullptr));
        label_5->setText(QCoreApplication::translate("DialogHistoricalDataTimeSet", "\346\257\253\347\247\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogHistoricalDataTimeSet: public Ui_DialogHistoricalDataTimeSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHISTORICALDATATIMESET_H

/********************************************************************************
** Form generated from reading UI file 'dialoginputnumber.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGINPUTNUMBER_H
#define UI_DIALOGINPUTNUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogInputNumber
{
public:
    QPushButton *pushButton_7;
    QPushButton *pushButton_1;
    QPushButton *pushButton_p;
    QPushButton *pushButton_BS;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QPushButton *pushButton_EXIT;
    QPushButton *pushButton_0;
    QPushButton *pushButton_CE;
    QPushButton *pushButton_Enter;

    void setupUi(QDialog *DialogInputNumber)
    {
        if (DialogInputNumber->objectName().isEmpty())
            DialogInputNumber->setObjectName(QString::fromUtf8("DialogInputNumber"));
        DialogInputNumber->setWindowModality(Qt::ApplicationModal);
        DialogInputNumber->resize(343, 361);
        DialogInputNumber->setModal(true);
        pushButton_7 = new QPushButton(DialogInputNumber);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 220, 61, 51));
        pushButton_1 = new QPushButton(DialogInputNumber);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(20, 80, 61, 51));
        pushButton_p = new QPushButton(DialogInputNumber);
        pushButton_p->setObjectName(QString::fromUtf8("pushButton_p"));
        pushButton_p->setGeometry(QRect(100, 290, 61, 51));
        pushButton_BS = new QPushButton(DialogInputNumber);
        pushButton_BS->setObjectName(QString::fromUtf8("pushButton_BS"));
        pushButton_BS->setGeometry(QRect(260, 80, 61, 51));
        pushButton_9 = new QPushButton(DialogInputNumber);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(180, 220, 61, 51));
        pushButton_5 = new QPushButton(DialogInputNumber);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(100, 150, 61, 51));
        pushButton_8 = new QPushButton(DialogInputNumber);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(100, 220, 61, 51));
        pushButton_2 = new QPushButton(DialogInputNumber);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 80, 61, 51));
        pushButton_3 = new QPushButton(DialogInputNumber);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 80, 61, 51));
        pushButton_6 = new QPushButton(DialogInputNumber);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(180, 150, 61, 51));
        lineEdit = new QLineEdit(DialogInputNumber);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 301, 41));
        pushButton_4 = new QPushButton(DialogInputNumber);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 150, 61, 51));
        pushButton_EXIT = new QPushButton(DialogInputNumber);
        pushButton_EXIT->setObjectName(QString::fromUtf8("pushButton_EXIT"));
        pushButton_EXIT->setGeometry(QRect(260, 220, 61, 51));
        pushButton_0 = new QPushButton(DialogInputNumber);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        pushButton_0->setGeometry(QRect(20, 290, 61, 51));
        pushButton_CE = new QPushButton(DialogInputNumber);
        pushButton_CE->setObjectName(QString::fromUtf8("pushButton_CE"));
        pushButton_CE->setGeometry(QRect(260, 150, 61, 51));
        pushButton_Enter = new QPushButton(DialogInputNumber);
        pushButton_Enter->setObjectName(QString::fromUtf8("pushButton_Enter"));
        pushButton_Enter->setGeometry(QRect(180, 290, 141, 51));

        retranslateUi(DialogInputNumber);

        QMetaObject::connectSlotsByName(DialogInputNumber);
    } // setupUi

    void retranslateUi(QDialog *DialogInputNumber)
    {
        DialogInputNumber->setWindowTitle(QCoreApplication::translate("DialogInputNumber", "Dialog", nullptr));
        pushButton_7->setText(QCoreApplication::translate("DialogInputNumber", "7", nullptr));
        pushButton_1->setText(QCoreApplication::translate("DialogInputNumber", "1", nullptr));
        pushButton_p->setText(QCoreApplication::translate("DialogInputNumber", " .", nullptr));
        pushButton_BS->setText(QCoreApplication::translate("DialogInputNumber", "<-BS", nullptr));
        pushButton_9->setText(QCoreApplication::translate("DialogInputNumber", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("DialogInputNumber", "5", nullptr));
        pushButton_8->setText(QCoreApplication::translate("DialogInputNumber", "8", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogInputNumber", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DialogInputNumber", "3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("DialogInputNumber", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("DialogInputNumber", "4", nullptr));
        pushButton_EXIT->setText(QCoreApplication::translate("DialogInputNumber", "EXIT", nullptr));
        pushButton_0->setText(QCoreApplication::translate("DialogInputNumber", "0", nullptr));
        pushButton_CE->setText(QCoreApplication::translate("DialogInputNumber", "CE", nullptr));
        pushButton_Enter->setText(QCoreApplication::translate("DialogInputNumber", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogInputNumber: public Ui_DialogInputNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGINPUTNUMBER_H

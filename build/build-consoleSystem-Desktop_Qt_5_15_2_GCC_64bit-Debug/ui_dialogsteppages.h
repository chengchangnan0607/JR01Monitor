/********************************************************************************
** Form generated from reading UI file 'dialogsteppages.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSTEPPAGES_H
#define UI_DIALOGSTEPPAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogStepPages
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_Pages;
    QPushButton *pushButton_Next;
    QPushButton *pushButton_End;
    QPushButton *pushButton_Back;

    void setupUi(QDialog *DialogStepPages)
    {
        if (DialogStepPages->objectName().isEmpty())
            DialogStepPages->setObjectName(QString::fromUtf8("DialogStepPages"));
        DialogStepPages->resize(400, 300);
        QFont font;
        font.setPointSize(14);
        DialogStepPages->setFont(font);
        gridLayoutWidget = new QWidget(DialogStepPages);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 401, 231));
        gridLayout_Pages = new QGridLayout(gridLayoutWidget);
        gridLayout_Pages->setObjectName(QString::fromUtf8("gridLayout_Pages"));
        gridLayout_Pages->setContentsMargins(0, 0, 0, 0);
        pushButton_Next = new QPushButton(DialogStepPages);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));
        pushButton_Next->setGeometry(QRect(310, 240, 71, 51));
        pushButton_End = new QPushButton(DialogStepPages);
        pushButton_End->setObjectName(QString::fromUtf8("pushButton_End"));
        pushButton_End->setGeometry(QRect(190, 240, 71, 51));
        pushButton_Back = new QPushButton(DialogStepPages);
        pushButton_Back->setObjectName(QString::fromUtf8("pushButton_Back"));
        pushButton_Back->setGeometry(QRect(70, 240, 71, 51));

        retranslateUi(DialogStepPages);

        QMetaObject::connectSlotsByName(DialogStepPages);
    } // setupUi

    void retranslateUi(QDialog *DialogStepPages)
    {
        DialogStepPages->setWindowTitle(QCoreApplication::translate("DialogStepPages", "Dialog", nullptr));
        pushButton_Next->setText(QCoreApplication::translate("DialogStepPages", "\344\270\213\344\270\200\346\255\245", nullptr));
        pushButton_End->setText(QCoreApplication::translate("DialogStepPages", "\347\273\210\346\255\242", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("DialogStepPages", "\344\270\212\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogStepPages: public Ui_DialogStepPages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSTEPPAGES_H

/********************************************************************************
** Form generated from reading UI file 'dialoglog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGLOG_H
#define UI_DIALOGLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DialogLog
{
public:
    QTableView *tableView;
    QPushButton *pushButton_Alarm;
    QLabel *label;
    QPushButton *pushButton_Event;
    QPushButton *pushButton_Close;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DialogLog)
    {
        if (DialogLog->objectName().isEmpty())
            DialogLog->setObjectName(QString::fromUtf8("DialogLog"));
        DialogLog->setWindowModality(Qt::ApplicationModal);
        DialogLog->resize(768, 576);
        QFont font;
        font.setPointSize(14);
        DialogLog->setFont(font);
        DialogLog->setModal(true);
        tableView = new QTableView(DialogLog);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(20, 50, 731, 441));
        pushButton_Alarm = new QPushButton(DialogLog);
        buttonGroup = new QButtonGroup(DialogLog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(pushButton_Alarm);
        pushButton_Alarm->setObjectName(QString::fromUtf8("pushButton_Alarm"));
        pushButton_Alarm->setGeometry(QRect(190, 510, 91, 51));
        pushButton_Alarm->setCheckable(true);
        pushButton_Alarm->setChecked(true);
        label = new QLabel(DialogLog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 161, 31));
        pushButton_Event = new QPushButton(DialogLog);
        buttonGroup->addButton(pushButton_Event);
        pushButton_Event->setObjectName(QString::fromUtf8("pushButton_Event"));
        pushButton_Event->setGeometry(QRect(340, 510, 91, 51));
        pushButton_Event->setCheckable(true);
        pushButton_Close = new QPushButton(DialogLog);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));
        pushButton_Close->setGeometry(QRect(490, 510, 91, 51));

        retranslateUi(DialogLog);

        QMetaObject::connectSlotsByName(DialogLog);
    } // setupUi

    void retranslateUi(QDialog *DialogLog)
    {
        DialogLog->setWindowTitle(QCoreApplication::translate("DialogLog", "Dialog", nullptr));
        pushButton_Alarm->setText(QCoreApplication::translate("DialogLog", "\346\212\245\350\255\246", nullptr));
        label->setText(QCoreApplication::translate("DialogLog", "\346\212\245\350\255\246\346\227\245\345\277\227\346\230\276\347\244\272", nullptr));
        pushButton_Event->setText(QCoreApplication::translate("DialogLog", "\344\272\213\344\273\266", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("DialogLog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogLog: public Ui_DialogLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGLOG_H

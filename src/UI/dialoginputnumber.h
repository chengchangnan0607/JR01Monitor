#ifndef DIALOGINPUTNUMBER_H
#define DIALOGINPUTNUMBER_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class DialogInputNumber;
}

class DialogInputNumber : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInputNumber(QWidget *parent = nullptr);
    ~DialogInputNumber();
    void display(QString);
    QString inputValStr();
    void disableButton_p(bool flag);//true=enable; false=disable

    QString inputString = "";

private:
    Ui::DialogInputNumber *ui;

signals:
    void digitalInput(QString text);
        void connectionStatusChange(bool connectionStatus);
public slots:
    void button0();
    void button1();
    void button2();
    void button3();
    void button4();
    void button5();
    void button6();
    void button7();
    void button8();
    void button9();
    void buttonp();
    void buttonBS();
    void buttonCE();
};

#endif // DIALOGINPUTNUMBER_H

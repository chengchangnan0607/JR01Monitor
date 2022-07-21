#include "dialoginputnumber.h"
#include "ui_dialoginputnumber.h"

DialogInputNumber::DialogInputNumber(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInputNumber)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint);

    connect(ui->pushButton_0, &QPushButton::clicked, this, &DialogInputNumber::button0);
    connect(ui->pushButton_1, &QPushButton::clicked, this, &DialogInputNumber::button1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &DialogInputNumber::button2);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &DialogInputNumber::button3);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &DialogInputNumber::button4);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &DialogInputNumber::button5);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &DialogInputNumber::button6);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &DialogInputNumber::button7);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &DialogInputNumber::button8);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &DialogInputNumber::button9);
    connect(ui->pushButton_p, &QPushButton::clicked, this, &DialogInputNumber::buttonp);
    connect(ui->pushButton_BS, &QPushButton::clicked, this, &DialogInputNumber::buttonBS);
    connect(ui->pushButton_CE, &QPushButton::clicked, this, &DialogInputNumber::buttonCE);
    connect(ui->pushButton_EXIT, &QPushButton::clicked, this, &DialogInputNumber::reject);
    connect(ui->pushButton_Enter, &QPushButton::clicked, this, &DialogInputNumber::accept);
}

DialogInputNumber::~DialogInputNumber()
{
    qDebug() << "DialogInputNumber delete....";
    delete ui;
}

void DialogInputNumber::disableButton_p(bool flag)
{
    ui->pushButton_p->setEnabled(flag);
}

QString DialogInputNumber::inputValStr()
{
    return ui->lineEdit->text();
}

void DialogInputNumber::button0()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"0");
}

void DialogInputNumber::button1()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"1");
}

void DialogInputNumber::button2()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"2");
}

void DialogInputNumber::button3()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"3");
}

void DialogInputNumber::button4()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"4");
}

void DialogInputNumber::button5()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"5");
}

void DialogInputNumber::button6()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"6");
}

void DialogInputNumber::button7()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"7");
}

void DialogInputNumber::button8()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"8");
}

void DialogInputNumber::button9()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+"9");
}

void DialogInputNumber::buttonp()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setText(text+".");
}

void DialogInputNumber::buttonBS()
{
    QString text = ui->lineEdit->text();
    int length = text.length() - 1;
    ui->lineEdit->setText(text.left(length));
}

void DialogInputNumber::buttonCE()
{
    ui->lineEdit->setText("");
}

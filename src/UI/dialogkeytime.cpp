#include "dialogkeytime.h"
#include "ui_dialogkeytime.h"
#include <QBitmap>
#include <QPainter>

Dialogkeytime::Dialogkeytime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogkeytime)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->lineEdit_keyboard_time->setFocus();

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),18,18);
    setMask(bmp);
}

Dialogkeytime::~Dialogkeytime()
{
    delete ui;
}

//设置键盘可用鼠标拖动窗口
void Dialogkeytime::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}
void Dialogkeytime::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

//时间键盘ce槽函数
void Dialogkeytime::on_toolButton_ce_Time_clicked()
{
    ui->lineEdit_keyboard_time->setText("");
}

//时间键盘enter槽函数
void Dialogkeytime::on_toolButton_enter_Time_clicked()
{
    enter = 1;
    edit = ui->lineEdit_keyboard_time->text();
    this->close();
}

//不同键盘
void Dialogkeytime::switchkey1()
{
    ui->stackedWidget_keytime->setCurrentIndex(0);
}
void Dialogkeytime::switchkey2()
{
    ui->stackedWidget_keytime->setCurrentIndex(1);
}
void Dialogkeytime::switchkey3()
{
    ui->stackedWidget_keytime->setCurrentIndex(2);
}
void Dialogkeytime::switchkey4()
{
    ui->stackedWidget_keytime->setCurrentIndex(3);
}

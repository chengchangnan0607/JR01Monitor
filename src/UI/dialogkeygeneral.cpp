#include "dialogkeygeneral.h"
#include "ui_dialogkeygeneral.h"
#include <QBitmap>
#include <QPainter>

Dialogkeygeneral::Dialogkeygeneral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogkeygeneral)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->lineEdit_keyboard_general->setFocus();

    QBitmap bmp(this->size());
    bmp.fill();
    QPainter p(&bmp);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::black);
    p.drawRoundedRect(bmp.rect(),18,18);
    setMask(bmp);
}

Dialogkeygeneral::~Dialogkeygeneral()
{
    delete ui;
}

//通用键盘ce槽函数
void Dialogkeygeneral::on_toolButton_ce_general_clicked()
{
    ui->lineEdit_keyboard_general->setText("");
}

//通用键盘enter槽函数
void Dialogkeygeneral::on_toolButton_enter_general_clicked()
{
    enter = 1;
    edit = ui->lineEdit_keyboard_general->text();
    this->close();
}

//设置键盘可用鼠标拖动窗口
void Dialogkeygeneral::mousePressEvent(QMouseEvent *event)
{
    this->windowPos = this->pos();       // 获得部件当前位置
    this->mousePos = event->globalPos(); // 获得鼠标位置
    this->dPos = mousePos - windowPos;   // 移动后部件所在的位置
}
void Dialogkeygeneral::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() - this->dPos);
}

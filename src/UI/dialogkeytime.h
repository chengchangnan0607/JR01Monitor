#ifndef DIALOGKEYTIME_H
#define DIALOGKEYTIME_H

#include <QDialog>

#include <QLabel>
#include <QEvent>
#include <QtDebug>

#include <QKeyEvent>


#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>
#include <QMainWindow>


namespace Ui {
class Dialogkeytime;
}

class Dialogkeytime : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogkeytime(QWidget *parent = nullptr);
    ~Dialogkeytime();

    //设置键盘可用鼠标拖动窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void switchkey1();
    void switchkey2();
    void switchkey3();
    void switchkey4();

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;

    bool enter=0; //用于记录是否按下enter键，按下--1，未按--0
    QString edit;

private slots:
    void on_toolButton_ce_Time_clicked();//时间键盘ce槽函数
    void on_toolButton_enter_Time_clicked();//时间键盘enter槽函数

private:
    Ui::Dialogkeytime *ui;
};

#endif // DIALOGKEYTIME_H

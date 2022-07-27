#ifndef DIALOGKEYGENERAL_H
#define DIALOGKEYGENERAL_H

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
class Dialogkeygeneral;
}

class Dialogkeygeneral : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogkeygeneral(QWidget *parent = nullptr);
    ~Dialogkeygeneral();

    bool enter=0; //用于记录是否按下enter键，按下--1，未按--0
    QString edit;

    //记录鼠标，窗口位置
    QPoint windowPos;
    QPoint mousePos;
    QPoint dPos;
    //设置键盘可用鼠标拖动窗口
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private slots:
    void on_toolButton_ce_general_clicked();//通用键盘ce槽函数


    void on_toolButton_enter_general_clicked();

private:
    Ui::Dialogkeygeneral *ui;
};

#endif // DIALOGKEYGENERAL_H

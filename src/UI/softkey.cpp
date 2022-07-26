#include "softkey.h"
#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"

softkey::softkey(QWidget *parent) :QToolButton(parent)
{
    connect(this,SIGNAL(clicked(bool)),this,SLOT(button_clicked(bool)));

}
void softkey::button_clicked(bool)
{

    //this->text() ----获得控件上的文本内容，比如，删除
    if(this->text() == "<-BS")
    {
        //定义一个事件，Key_Backspace撤消按钮
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier, this->text());
        //通过postEvent将事件key发送出去给QApplication::focusWidget()，
        //在当前窗口界面中有焦点的控件
        QApplication::postEvent(QApplication::focusWidget(),key);
    }
    else if(this->text()=="Enter")
    {
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,Qt::Key_Enter,Qt::NoModifier);
        QApplication::postEvent(QApplication::focusWidget(),key);
    }
    else if(this->text()=="EXIT")
    {
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,Qt::Key_Escape,Qt::NoModifier);
        QApplication::postEvent(QApplication::focusWidget(),key);
    }
    else if(this->text()=="CE")
    {
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,Qt::Key_ClearGrab,Qt::NoModifier);
        QApplication::postEvent(QApplication::focusWidget(),key);
    }
    else
    {
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,'w',Qt::NoModifier, this->text());
        //通过postEvent将事件key的文本内容发送出去，QApplication::focusWidget()当前窗口中，有光标的
        //控件上
        QApplication::postEvent(QApplication::focusWidget(),key);
    }
}

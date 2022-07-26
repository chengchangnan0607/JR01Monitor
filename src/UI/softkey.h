#ifndef SOFTKEY_H
#define SOFTKEY_H

#include <QWidget>
#include <QLabel>
#include <QEvent>
#include <QtDebug>
#include <QProcess>
#include <QKeyEvent>
#include <QDateTime>
#include <QMouseEvent>
#include <QToolButton>
#include <QMessageBox>
#include <QMainWindow>
#include "mainwindow.h"

class QMainWindow;
class softkey:public QToolButton
{
    Q_OBJECT
public:
    softkey();
    explicit softkey(QWidget *parent = Q_NULLPTR);
public slots:
     void button_clicked(bool);
};

#endif // SOFTKEY_H

#include "dialogsteppages.h"
#include "ui_dialogsteppages.h"

DialogStepPages::DialogStepPages(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStepPages)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog);

    pageStacked = new QStackedWidget(this);

    currentPageIndex = 0;
    ui->gridLayout_Pages->addWidget(pageStacked);
    ui->pushButton_Back->setEnabled(false);

    connect(ui->pushButton_Back, &QPushButton::clicked, this, &DialogStepPages::stepBack);
    connect(ui->pushButton_End, &QPushButton::clicked, this, &DialogStepPages::reject);
    connect(ui->pushButton_Next, &QPushButton::clicked, this, &DialogStepPages::stepNext);
}

DialogStepPages::~DialogStepPages()
{
    delete pageStacked;
    delete ui;
}

void DialogStepPages::setCurrentPage(unsigned char Index)
{
    pageStacked->setCurrentIndex(Index);
}

void DialogStepPages::stepBack()
{
//    if (currentPageIndex > 0) {
//        currentPageIndex -= 1;
//        pageStacked->setCurrentIndex(currentPageIndex);
//        if (currentPageIndex == 0) {
//            ui->pushButton_Back->setEnabled(false);
//        }
//        ui->pushButton_Next->setText("下一步");
//        if (currentPageIndex == 4) {
//            dialogStepPage5->timerExhaust->start(4000);
//            dialogStepPage5->index = 0;
//            dialogStepPage5->resetProgressBar();
//        }
//    }
//    qDebug() << "stepNext";
}

void DialogStepPages::stepNext()
{
//    ui->pushButton_Back->setEnabled(true);
//    if (currentPageIndex < 5 ) {
//        currentPageIndex += 1;
//        pageStacked->setCurrentIndex(currentPageIndex);
//        if (currentPageIndex == 5) {
//            ui->pushButton_Next->setText("完成");
//        }
//        if (currentPageIndex == 4) {
//            emit purgeExhaustStart();
//            dialogStepPage5->timerExhaust->start(1800);//3 minutes = 180000ms, 180000/100 = 1800
//            dialogStepPage5->index = 0;
//            dialogStepPage5->resetProgressBar();
//        }
//    } else {
//        emit capacitySet(dialogStepPage6->fluidCapacity);
//        emit accept();
//    }
//    qDebug() << "stepNext";
}

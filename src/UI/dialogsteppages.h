#ifndef DIALOGSTEPPAGES_H
#define DIALOGSTEPPAGES_H

#include <QDialog>
#include <QStackedWidget>

namespace Ui {
class DialogStepPages;
}

class DialogStepPages : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStepPages(QWidget *parent = nullptr);
    ~DialogStepPages();
    void setCurrentPage(unsigned char Index);

    QStackedWidget *pageStacked;

    unsigned char currentPageIndex;

private:
    Ui::DialogStepPages *ui;

signals:
    void purgeExhaustStart();
    void capacitySet(int16_t capacityMl);

public slots:
    void stepBack();
    void stepNext();
};

#endif // DIALOGSTEPPAGES_H

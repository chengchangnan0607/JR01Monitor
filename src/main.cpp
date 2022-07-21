#include <QApplication>
#include "../qBreakpad/include/QBreakpadHandler.h"
#include "UI/mainwindow.h"
#include "BL/DB/database.h"
#include "UI/dialogsystemset.h"

static const QString buildDateTime()
{
    QString dateTime = "";
    dateTime += __DATE__;
    dateTime += " ";
    dateTime += __TIME__;
    return dateTime;
}

int main(int argc, char *argv[])
{
//    ::signal(SIGSEGV, &TraceInfo);
    
    QApplication a(argc, argv);

    QBreakpadInstance.setDumpPath("crashes"); // 设置生成dump文件路径

    if (!createConnection())
        return EXIT_FAILURE;

    qDebug() << softVersion << "Build Date Time" << buildDateTime();



    MainWindow w;

#ifdef pcDebug
    w.setFixedSize(1024, 768);
    w.show();

#else
    w.showFullScreen();
#endif

    return a.exec();
}

#include "CalendarMap.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));

    CalendarMap *w;
    w = new CalendarMap();
    w->show();



    return a.exec();
}

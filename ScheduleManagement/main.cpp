#include "CalendarMap.h"
#include <QApplication>
#include <QTextCodec>
#include <assert.h>
#include "SqlDb.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
    //QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    CalendarMap *w;\


    w = new CalendarMap();

    w->init_db();

    w->load_memora();


    w->show();



    return a.exec();
}

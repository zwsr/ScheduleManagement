#include "mainwindow.h"
#include "CalendarMap.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CalendarMap *w;
    w = new CalendarMap();
    w->show();
    
    return a.exec();
}

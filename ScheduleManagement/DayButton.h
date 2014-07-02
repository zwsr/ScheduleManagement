#ifndef DAYBUTTON_H
#define DAYBUTTON_H

#include <QPushButton>
#include <QLayout>
#include "CalendarMap.h"

class DayButton : public QPushButton 
{
    Q_OBJECT

private:
    int month;
    int year;
    int day;
public:
    DayButton(QWidget *parent = 0, int y = 0, int m = 0, int d = 0);
    void next_month();
    void next_year();
    void foward_month();
    void foward_year();
    void set_ymd(int y,int m,int d)
    {
        year = y;
        month = m;
        day = d;
        return;
    }
};

#endif // DAYBUTTON_H

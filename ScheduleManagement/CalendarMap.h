#ifndef CALENDARMAP_H
#define CALENDARMAP_H

#include <QWidget>
#include <QPushButton>

class CalendarMap : public QWidget
{
    Q_OBJECT
public:
    CalendarMap(QWidget *parent = 0);
    
signals:
    
public slots:
    //void Day_clicked();
    //void Month_clicked();
    //void Year_clicked();
private:
    int now_month;
    int now_year;
    int now_daydum;

//各种button
    QPushButton day[32];
    QPushButton month[13];
    QPushButton now_monthbutton;
    QPushButton now_yearbutton;
    static const int month_daynum[];
    
};

#endif // CALENDARMAP_H

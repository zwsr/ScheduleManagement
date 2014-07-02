#ifndef CALENDARMAP_H
#define CALENDARMAP_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "DayButton.h"

const int day_button_size = 50;
const int next_button_size= day_button_size;
const int month_button_width = day_button_size * 5;
const int month_button_height = day_button_size;
const int year_button_width = month_button_width;
const int year_button_height = month_button_height * 2;

const int label_size = day_button_size;

const int calendar_window_width = year_button_width;
const int calendar_window_height = year_button_height + month_button_height + day_button_size * 7;

const int main_window_width = calendar_window_width;
const int main_window_height = calendar_window_height;

const double choice_month_button_width = calendar_window_width / 4;
const double choice_month_button_height = calendar_window_height / 3;

class CalendarMap : public QWidget
{
    Q_OBJECT
public:
    CalendarMap(QWidget *parent = 0);
    
signals:
    
public slots:
    void Day_clicked();
    void Month_clicked();
    void Year_clicked();
    void NextMonth_clicked();
    void FowardMonth_clicked();
    void NextYear_clicked();
    void FowardYear_clicked();

private:
    int now_month;
    int now_year;
    int now_daydum;

//各种button

    class DayButton * day[32];
    QPushButton* month[13];
    QPushButton* now_monthbutton;
    QPushButton* now_yearbutton;
    QPushButton* next_month;
    QPushButton* forward_month;
    QPushButton* next_year;
    QPushButton* forward_year;

    QLabel* week_label[7];


    static const int month_daynum[];
    //static const QString weekday_word[7];

    
};

#endif // CALENDARMAP_H

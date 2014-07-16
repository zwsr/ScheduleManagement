#ifndef CALENDARMAP_H
#define CALENDARMAP_H
#include <assert.h>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "DayButton.h"
#include "CalendarTranser.h"
#include "YearInputerDialog.h"
#include "Memorandum.h"
#include "SqlDb.h"

const int init_year = 2014;
const int init_month = 7;
const int init_day = 1;

const QString today_color = "background-color: rgb(89, 241, 100)";
const QString memoday_color = "background-color: rgb(253, 255, 116)";
const QString listday_color = "background-color: rgb(251, 89, 89)";
const QString memolistday_color = "background-color: rgb(255, 179, 59)";

const int day_button_size = 50;
const int next_button_size= day_button_size;
const int month_button_width = day_button_size * 5;
const int month_button_height = day_button_size;
const int year_button_width = month_button_width;
const int year_button_height = month_button_height * 2;

const int memo_list_button_width = day_button_size * 3;
const int memo_list_button_height = 25;

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
    virtual void show();
    virtual void hide();
    bool is_open()
    {
        if (open_flag == 1)
            return true;
        else return false;
    }

    CalendarMap(int yy = 0, int mm = 0, int dd = 0, QWidget *parent = 0,int s_mode = 0);
    void init_db();
    SqlDb* pc_db;
    void load_memora();

    void set_ymd(int yy, int mm, int dd)
    {
        now_year = yy;
        now_month = mm;
        now_day = dd;

        redraw();
        return;
    }
    int nowyear()
    {
        return now_year;
    }
    int nowmonth()
    {
        return now_month;
    }
    int nowday()
    {
        return now_day;
    }

    //static const SqlDb db_pc;
    
signals:
    
public slots:
    virtual void Day_clicked();
    void Month_clicked();
    void SpecifiedMonth_clicked();
    void Year_clicked();
    void NextMonth_clicked();
    void FowardMonth_clicked();
    void NextYear_clicked();
    void FowardYear_clicked();
    void Memora_clicked();

private:
    int selection_mode;
    int open_flag;

    class Memorandum* memora_map;

    int now_month;
    int now_year;
    int now_day;
    int now_daydum;

    class CalendarTranser *transer;

//各种button

    QPushButton* memora_button;

    class DayButton * day[32];
    QPushButton* month[13];
    QPushButton* now_monthbutton;
    QPushButton* now_yearbutton;
    QPushButton* next_month;
    QPushButton* forward_month;
    QPushButton* next_year;
    QPushButton* forward_year;

    QPushButton* memorandum_button;
    QLabel* solar_date;
    QLabel* lunar_date;
    QLabel* festival_label;

    QLabel* week_label[7];


    static const int month_daynum[];
    static const QString weekday_word[7];

//各种layout

    QHBoxLayout *first_floor, *second_floor, *third_floor;
    QVBoxLayout *calendarLayout;
    QGridLayout *detail_daylayout, *month_choice_layout;
    QHBoxLayout *memolist_layout;
    QVBoxLayout *rightbar_layout;
    QHBoxLayout *main_layout;

    //改变year/month后redraw
    void redraw();

    void show_monthchoice_map();
    void show_maincalendar_map();

    //void calendar_diasble();
    //void calendar_enable();
    
};


#endif // CALENDARMAP_H

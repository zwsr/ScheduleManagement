#ifndef MEMORANDUM_H
#define MEMORANDUM_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QtGui>
#include <QLabel>
#include <QLayout>
#include <QTimer>
#include "CalendarMap.h"


class Memorandum : public QWidget
{
    Q_OBJECT

public:
    Memorandum(QWidget* parent = 0,class CalendarMap* prt = 0);
    void set_ymd(int y, int m ,int d);


public slots:
    void addMemora();
    void submitMemora();
    void cancelAdd();
    void nextMemora();
    void previousMemora();
    void editMemora();
    void removeMemora();
    void selectDate();

private:
    enum Mode { NavigationMode, AddingMode, EditingMode };

    CalendarMap* prt_calendarmap;

    CalendarMap* select_datemap;

    QLineEdit* theme_input;
    QTextEdit* maintext_input;
    QLabel* date_label;

    QPushButton* selectdate_button;
    QPushButton* add_button;
    QPushButton* submit_button;
    QPushButton* cancel_button;

    QPushButton* next_button;
    QPushButton* previous_button;

    QPushButton* edit_button;
    QPushButton* remove_button;

    Mode currentMode;

    int now_year;
    int now_month;
    int now_day;

    QString theme;
    QString maintext;
    int m_id;
    int year,month,day;
    int datevalue;

    QString old_theme;
    QString old_maintext;
    int old_m_id;
    int old_year,old_month,old_day;
    int old_datevalue;

    void duplicate_to_old()
    {
        old_theme = theme;
        old_maintext = maintext;
        old_m_id = m_id;
        old_year = year;
        old_month = month;
        old_day = day;
        old_datevalue = datevalue;
    }

    void duplicate_to_new()
    {
        theme = old_theme;
        maintext = old_maintext;
        m_id = old_m_id;
        year = old_year;
        month = old_month;
        day = old_day;
        datevalue = old_datevalue;
    }


    //更新界面
    void update_interface(Mode mode);
    void redraw();


};

#endif // MEMORANDUM_H

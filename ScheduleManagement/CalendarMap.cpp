#include "CalendarMap.h"
const int CalendarMap::month_daynum[] = {
    0,31,28,31,30,31,30,31,31,30,31,30,31
};

//const QString CalendarMap::weekday_word[7] =
//{
//    QObject::tr("日"),QObject::tr("一"),QObject::tr("二"),QObject::tr("三"),QObject::tr("四"),QObject::tr("五"),QObject::tr("六")
//};

CalendarMap::CalendarMap(QWidget *parent) :
    QWidget(parent)
{
    resize(main_window_width,main_window_height);
    now_year = 2014;
    now_month = 6;
    now_daydum = month_daynum[now_month];

    QHBoxLayout *first_floor, *second_floor, *third_floor;
    QVBoxLayout *calendarLayout;
    QGridLayout *detail_daylayout, *month_choice_layout;
    first_floor = new QHBoxLayout;
    second_floor = new QHBoxLayout;
    third_floor = new QHBoxLayout;
    calendarLayout = new QVBoxLayout;
    detail_daylayout = new QGridLayout;
    month_choice_layout = new QGridLayout;


    const QString weekday_word[7] =
    {
        QObject::tr("日"),QObject::tr("一"),QObject::tr("二"),QObject::tr("三"),QObject::tr("四"),QObject::tr("五"),QObject::tr("六")
    };



    for (int i = 0; i <7; i++)
    {
        week_label[i] = new QLabel(this);
        week_label[i]->setText(weekday_word[i]);
        third_floor->addWidget(week_label[i],0,Qt::AlignHCenter);
    }


    now_yearbutton = new QPushButton(this);
    QString year_content;
    year_content.setNum(now_year);
    year_content += QObject::tr("年");
    now_yearbutton->setText(year_content);
    now_yearbutton->setFixedSize(year_button_width,year_button_height);
    now_yearbutton->setFlat(true);

    now_monthbutton = new QPushButton(this);
    QString month_content;
    month_content.setNum(now_month);
    month_content += QObject::tr("月");
    now_monthbutton->setText(month_content);
    now_monthbutton->setFixedSize(month_button_width,month_button_height);
    now_monthbutton->setFlat(true);

    next_month = new QPushButton(this);
    next_month->setText(">");
    next_month->setFixedSize(next_button_size,next_button_size);
    next_month->setFlat(true);

    forward_month = new QPushButton(this);
    forward_month->setText("<");
    forward_month->setFixedSize(next_button_size,next_button_size);
    forward_month->setFlat(true);

    next_year = new QPushButton(this);
    next_year->setText(">");
    next_year->setFixedSize(next_button_size,next_button_size);
    next_year->setFlat(true);

    forward_year = new QPushButton(this);
    forward_year->setText("<");
    forward_year->setFixedSize(next_button_size,next_button_size);
    forward_year->setFlat(true);

    first_floor->addWidget(forward_year);
    first_floor->addWidget(now_yearbutton);
    first_floor->addWidget(next_year);

    second_floor->addWidget(forward_month);
    second_floor->addWidget(now_monthbutton);
    second_floor->addWidget(next_month);

    int row_i,colum_j;
    QString monthbutton_content;
    for (int i = 1; i <= 12 ; i++)
    {
        monthbutton_content.setNum(i);
        month[i] = new QPushButton(this);
        month[i]->setText(monthbutton_content);
        month[i]->setFixedSize((int)choice_month_button_width,(int)choice_month_button_height);
        month[i]->setFlat(true);
        month_choice_layout->addWidget(month[i],row_i,colum_j);
        colum_j++;
        if (colum_j == 4)
        {
            row_i++;
            colum_j = 0;
        }
        month[i]->hide();
    }

    for (int i = 1; i <= 31; i++)
    {
        day[i] = new DayButton(this,now_year,now_month,i);
        day[i]->hide();
    }

    row_i = 0;
    colum_j = 6;
    //colum_j = ToDoFunciton_GetWhichDayOfTheWeek(y,m,d);
    for (int i = 1; i <= month_daynum[now_month];i++)
    {
        day[i]->show();


        detail_daylayout->addWidget(day[i],row_i,colum_j);

        colum_j++;
        if (colum_j == 7)
        {
            colum_j = 0;
            row_i++;
        }

    }

    calendarLayout->addLayout(first_floor);
    calendarLayout->addLayout(second_floor);
    calendarLayout->addLayout(third_floor);
    calendarLayout->addLayout(detail_daylayout);
    calendarLayout->addLayout(month_choice_layout);
    calendarLayout->addStretch();

    setLayout(calendarLayout);
}

void CalendarMap::Day_clicked()
{

}

void CalendarMap::Month_clicked()
{

}

void CalendarMap::Year_clicked()
{

}

void CalendarMap::NextMonth_clicked()
{

}

void CalendarMap::FowardMonth_clicked()
{

}

void CalendarMap::NextYear_clicked()
{

}

void CalendarMap::FowardYear_clicked()
{

}




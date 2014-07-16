#include "CalendarMap.h"
#include "CalendarTranser.h"

//const SqlDb CalendarMap::db_pc(pc_dbname);

const int CalendarMap::month_daynum[] = {
    0,31,28,31,30,31,30,31,31,30,31,30,31
};



const QString CalendarMap::weekday_word[7] =
{
    QObject::tr("日"),QObject::tr("一"),QObject::tr("二"),QObject::tr("三"),QObject::tr("四"),QObject::tr("五"),QObject::tr("六")
};


void CalendarMap::load_memora()
{


        memora_map = new (Memorandum)(0,this);

        memora_map->set_ymd(now_year,now_month,now_day);

        memora_map->hide();

}

CalendarMap::CalendarMap(int yy, int mm, int dd, QWidget *parent, int s_mode) :
    QWidget(parent),selection_mode(s_mode)
{

    resize(main_window_width,main_window_height);
    if (selection_mode)
        setWindowTitle(QObject::tr("选择日期"));
    now_year = init_year;
    now_month = init_month;
    now_day = init_day;

    if (yy != 0)
        now_year = yy;
    if (mm != 0)
        now_month = mm;
    if (dd != 0)
        now_day = dd;

    now_daydum = month_daynum[now_month];

    transer = new CalendarTranser;

    first_floor = new QHBoxLayout;
    second_floor = new QHBoxLayout;
    third_floor = new QHBoxLayout;
    calendarLayout = new QVBoxLayout;
    detail_daylayout = new QGridLayout;
    month_choice_layout = new QGridLayout;

    memolist_layout = new QHBoxLayout;
    rightbar_layout = new QVBoxLayout;
    main_layout = new QHBoxLayout;


    //const QString weekday_word[7] =
    //{
    //    QObject::tr("日"),QObject::tr("一"),QObject::tr("二"),QObject::tr("三"),QObject::tr("四"),QObject::tr("五"),QObject::tr("六")
    //};



    for (int i = 0; i <7; i++)
    {
        week_label[i] = new QLabel(this);
        QString tmp;
        tmp = QObject::tr(weekday_word[i].toLatin1().data());
        week_label[i]->setText(tmp);
        //week_label[i]->setText(weekday_word[i]);
        third_floor->addWidget(week_label[i],0,Qt::AlignHCenter);
    }

    //RightBar

    //topbutton
//    memora_map = new Memorandum;
//    memora_map->set_ymd(now_year,now_month,now_day);
//    memora_map->hide();



    memora_button = new QPushButton(QObject::tr("备忘录"),this);
    memora_button->setToolTip(QObject::tr("查看当前的备忘录"));
    memora_button->setFixedWidth(memo_list_button_width);
    connect(memora_button,SIGNAL(clicked()),this,SLOT(Memora_clicked()));

    memolist_layout->addWidget(memora_button);


    rightbar_layout->addLayout(memolist_layout,Qt::AlignBottom);

    //label
    solar_date = new QLabel(this);
    lunar_date = new QLabel(this);
    festival_label = new QLabel(this);

    solar_date->setText(QObject::tr(transer->getSolarString(now_year,now_month,now_day).toLatin1()));
    lunar_date->setText(QObject::tr(transer->getLunarString(now_year,now_month,now_day).toLatin1()));
    festival_label->setText(QObject::tr(transer->getFestival(now_month,now_day).toLatin1()));


    rightbar_layout->addWidget(solar_date);
    rightbar_layout->addWidget(lunar_date);
    rightbar_layout->addWidget(festival_label);

    //CalenderMap
    now_yearbutton = new QPushButton(this);
    QString year_content;
    year_content.setNum(now_year);
    year_content += QObject::tr("年");
    now_yearbutton->setText(year_content);
    now_yearbutton->setFixedSize(year_button_width,year_button_height);
    now_yearbutton->setFlat(true);
    connect(now_yearbutton,SIGNAL(clicked()),this,SLOT(Year_clicked()));

    now_monthbutton = new QPushButton(this);
    QString month_content;
    month_content.setNum(now_month);
    month_content += QObject::tr("月");
    now_monthbutton->setText(month_content);
    now_monthbutton->setFixedSize(month_button_width,month_button_height);
    now_monthbutton->setFlat(true);
    connect(now_monthbutton,SIGNAL(clicked()),this,SLOT(Month_clicked()));

    next_month = new QPushButton(this);
    next_month->setText(">");
    next_month->setFixedSize(next_button_size,next_button_size);
    next_month->setFlat(true);
    connect(next_month,SIGNAL(clicked()),this,SLOT(NextMonth_clicked()));

    forward_month = new QPushButton(this);
    forward_month->setText("<");
    forward_month->setFixedSize(next_button_size,next_button_size);
    forward_month->setFlat(true);
    connect(forward_month,SIGNAL(clicked()),this,SLOT(FowardMonth_clicked()));

    next_year = new QPushButton(this);
    next_year->setText(">");
    next_year->setFixedSize(next_button_size,next_button_size);
    next_year->setFlat(true);
    connect(next_year,SIGNAL(clicked()),this,SLOT(NextYear_clicked()));

    forward_year = new QPushButton(this);
    forward_year->setText("<");
    forward_year->setFixedSize(next_button_size,next_button_size);
    forward_year->setFlat(true);
    connect(forward_year,SIGNAL(clicked()),this,SLOT(FowardYear_clicked()));

    first_floor->addWidget(forward_year);
    first_floor->addWidget(now_yearbutton);
    first_floor->addWidget(next_year);

    second_floor->addWidget(forward_month);
    second_floor->addWidget(now_monthbutton);
    second_floor->addWidget(next_month);

    int row_i = 0,colum_j = 0;
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
        connect(month[i],SIGNAL(clicked()),this,SLOT(SpecifiedMonth_clicked()));
        month[i]->hide();
    }

    for (int i = 1; i <= 31; i++)
    {
        day[i] = new DayButton(this,now_year,now_month,i);
        connect(day[i],SIGNAL(clicked()),this,SLOT(Day_clicked()));
        day[i]->hide();
    }

    row_i = 0;
    colum_j = transer->getDayOfWeek(now_year,now_month,1);

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
    day[now_day]->setStyleSheet(today_color);
    day[now_day]->setFlat(false);

    calendarLayout->addLayout(first_floor);
    calendarLayout->addLayout(second_floor);
    calendarLayout->addLayout(third_floor);
    calendarLayout->addLayout(detail_daylayout);
    calendarLayout->addLayout(month_choice_layout);
    calendarLayout->addStretch();

    rightbar_layout->addStretch();

    main_layout->addLayout(calendarLayout);
    main_layout->addLayout(rightbar_layout);

    setLayout(main_layout);


    if (selection_mode)
    {
        memora_button->hide();
        festival_label->hide();
        solar_date->hide();
        lunar_date->hide();
    }
}

void CalendarMap::show()
{
    open_flag = 1;
    setVisible(1);
    return;
}

void CalendarMap::hide()
{
    open_flag = 0;
    setVisible(0);
    return;
}

void CalendarMap::init_db()
{
    pc_db = new SqlDb(pc_dbname);
    return;
}


void CalendarMap::Day_clicked()
{
    //To Do    显示农历

    DayButton* clicked_button = static_cast<DayButton*>(sender());
    now_day = clicked_button->getDay();
    redraw();

    if (selection_mode)
        this->hide();
}

void CalendarMap::Month_clicked()
{
    show_monthchoice_map();
}

void CalendarMap::SpecifiedMonth_clicked()
{
    QPushButton* monthbutton = static_cast<QPushButton *>(sender());
    QString button_content = monthbutton->text();
    int month = button_content.toInt();
    now_month = month;
    show_maincalendar_map();
    redraw();
    return;
}

void CalendarMap::Year_clicked()
{
    class YearInputerDialog *dialog;
    dialog = new YearInputerDialog;
    dialog->show();

    if (dialog->exec() == QDialog::Accepted)
    {
        if ((dialog->getNewYearText()).toInt() != 0)
        now_year = (dialog->getNewYearText()).toInt();
        redraw();
        return;
    }
    else
    {
    return;
    }
}

void CalendarMap::NextMonth_clicked()
{
    now_month++;
    if (now_month == 13)
    {
        now_month = 1;
        now_year++;
    }

    redraw();
    return;
}

void CalendarMap::FowardMonth_clicked()
{
    now_month--;
    if (now_month == 0)
    {
        now_month = 12;
        now_year--;
    }

    redraw();
    return;
}

void CalendarMap::NextYear_clicked()
{
    now_year++;
    redraw();
    return;
}

void CalendarMap::FowardYear_clicked()
{
    now_year--;
    redraw();
    return;
}


void CalendarMap::redraw()
{
    now_daydum = month_daynum[now_month];

    if ((now_month == 2)&&(transer->is_leapyear(now_year)))
        now_daydum++;

    QString year_content;
    year_content.setNum(now_year);
    year_content += QObject::tr("年");
    now_yearbutton->setText(year_content);


    QString month_content;
    month_content.setNum(now_month);
    month_content += QObject::tr("月");
    now_monthbutton->setText(month_content);

    for (int i = 1; i <= 31; i++)
    {
        detail_daylayout->removeWidget(day[i]);
        day[i]->hide();
    }

    int row_i = 0;
    int colum_j = transer->getDayOfWeek(now_year,now_month,1);

    for (int i = 1; i <= now_daydum;i++)
    {
        day[i]->setFlat(true);
        day[i]->show();
        day[i]->set_ymd(now_year,now_month,i);

        detail_daylayout->addWidget(day[i],row_i,colum_j);

        colum_j++;
        if (colum_j == 7)
        {
            colum_j = 0;
            row_i++;
        }

    }
    day[now_day]->setStyleSheet(today_color);
    day[now_day]->setFlat(false);

    solar_date->setText(QObject::tr(transer->getSolarString(now_year,now_month,now_day).toLatin1()));
    lunar_date->setText(QObject::tr(transer->getLunarString(now_year,now_month,now_day).toLatin1()));
    festival_label->setText(QObject::tr(transer->getFestival(now_month,now_day).toLatin1()));

    if (!selection_mode)
        memora_map->set_ymd(now_year,now_month,now_day);

    return;
}

void CalendarMap::show_monthchoice_map()
{
    for (int i = 1; i <= 31; i++)
    {
        day[i]->hide();
    }
    now_monthbutton->hide();
    now_yearbutton->hide();
    next_month->hide();
    forward_month->hide();
    next_year->hide();
    forward_year->hide();
    for (int i = 0; i < 7; i++)
        week_label[i]->hide();

    for (int i=1; i <= 12; i++)
        month[i]->show();
    return;
}

void CalendarMap::show_maincalendar_map()
{
    for (int i=1; i <= 12; i++)
        month[i]->hide();

    now_monthbutton->show();
    now_yearbutton->show();
    next_month->show();
    forward_month->show();
    next_year->show();
    forward_year->show();
    for (int i = 0; i < 7; i++)
        week_label[i]->show();

    return;
}

void CalendarMap::Memora_clicked()
{
    memora_map->show();
    return;
}

//Select map

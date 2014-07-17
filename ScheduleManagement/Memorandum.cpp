#include "Memorandum.h"


static QString getSolarStringWithYear(int y, int m, int d)
{
    QString content;
    QString tmp,tmp1,tmp2;
    tmp.setNum(y);
    tmp1.setNum(m);
    tmp2.setNum(d);
    content = "日期:" + tmp + "年" + tmp1 + "月" + tmp2 + "号";
    return content;
}

static int getDatevalue(int y, int m, int d)
{
    return (y * 1200 + m * 100 + d);
}

Memorandum::Memorandum(QWidget *parent, CalendarMap *prt)
    :QWidget(parent)

{

    prt_calendarmap = prt;
    date_label = new QLabel(QObject::tr("日期:无"),this);

    selectdate_button = new QPushButton(QObject::tr("选择日期"),this);
    selectdate_button->hide();
    connect(selectdate_button,SIGNAL(clicked()),this,SLOT(selectDate()));

    QHBoxLayout* datelayout;
    datelayout = new QHBoxLayout;
    datelayout->addWidget(date_label,Qt::AlignBottom);
    datelayout->addWidget(selectdate_button,Qt::AlignBottom|Qt::AlignRight);

    select_datemap = new CalendarMap(prt_calendarmap->nowyear(),prt_calendarmap->nowmonth(),prt_calendarmap->nowday(),0,1);

    QLabel* theme_label = new QLabel(QObject::tr("标题:"),this);
    theme_input = new QLineEdit(this);
    theme_input->setReadOnly(true);
    theme_input->setText(QObject::tr("空"));


    QLabel* main_label = new QLabel(QObject::tr("正文:"),this);
    maintext_input = new QTextEdit(this);
    maintext_input->setReadOnly(true);
    maintext_input->setText(QObject::tr("空"));

    add_button = new QPushButton(QObject::tr("添加"),this);
    add_button->show();
    connect(add_button,SIGNAL(clicked()),this,SLOT(addMemora()));

    submit_button = new QPushButton(QObject::tr("确定"),this);
    submit_button->hide();
    connect(submit_button,SIGNAL(clicked()),this,SLOT(submitMemora()));

    cancel_button = new QPushButton(QObject::tr("取消"),this);
    cancel_button->hide();
    connect(cancel_button,SIGNAL(clicked()),this,SLOT(cancelAdd()));

    next_button = new QPushButton(QObject::tr("下一条"),this);
    next_button->setEnabled(false);
    connect(next_button,SIGNAL(clicked()),this,SLOT(nextMemora()));

    previous_button = new QPushButton(QObject::tr("上一条"),this);
    previous_button->setEnabled(false);
    connect(previous_button,SIGNAL(clicked()),this,SLOT(previousMemora()));


    edit_button = new QPushButton(QObject::tr("编辑"),this);
    edit_button->setEnabled(true);
    connect(edit_button,SIGNAL(clicked()),this,SLOT(editMemora()));

    remove_button = new QPushButton(QObject::tr("删除"),this);
    connect(remove_button,SIGNAL(clicked()),this,SLOT(removeMemora()));




    QVBoxLayout* rightbutton_layout = new QVBoxLayout;
    rightbutton_layout->addWidget(add_button,Qt::AlignTop);
    rightbutton_layout->addWidget(submit_button);
    rightbutton_layout->addWidget(cancel_button);
    rightbutton_layout->addWidget(edit_button);
    rightbutton_layout->addWidget(remove_button);
    rightbutton_layout->addStretch();

    QHBoxLayout* bottonbutton_layout = new QHBoxLayout;
    bottonbutton_layout->addWidget(previous_button);
    bottonbutton_layout->addWidget(next_button);


    QGridLayout* mainlayout = new QGridLayout;
    //mainlayout->addWidget(date_label,0,0,Qt::AlignBottom|Qt::AlignTop);
    //mainlayout->addWidget(selectdate_button,0,2,Qt::AlignBottom|Qt::AlignTop);
    mainlayout->addWidget(theme_label,0,0,Qt::AlignTop);
    mainlayout->addWidget(theme_input,0,1,Qt::AlignTop);
    mainlayout->addWidget(main_label,1,0,Qt::AlignTop);
    mainlayout->addWidget(maintext_input,1,1);

    mainlayout->addLayout(rightbutton_layout,1,2);
    mainlayout->addLayout(bottonbutton_layout,3,1);

    QVBoxLayout* main_mainlayout;
    main_mainlayout = new QVBoxLayout;
    main_mainlayout->addLayout(datelayout);
    main_mainlayout->addLayout(mainlayout);

    setLayout(main_mainlayout);
    setWindowTitle(QObject::tr("备忘录"));

    //初始化next privious 文本  等

    int memo_num = prt_calendarmap->pc_db->memora_size();
    if (memo_num <= 1)
    {
        next_button->setEnabled(false);
        previous_button->setEnabled(false);
    }
    if (memo_num == 0)
    {
        edit_button->setEnabled(false);
        remove_button->setEnabled(false);
        m_id = 0;
    }

    if (memo_num >= 1)
    {
        prt_calendarmap->pc_db->get_lastest_memora(m_id,theme,maintext,year,month,day);
        redraw();
    }
    if (memo_num > 1)
        previous_button->setEnabled(true);
}

void Memorandum::set_ymd(int y, int m ,int d)
{
    now_year =y;
    now_month = m;
    now_day = d;
    select_datemap->set_ymd(now_year,now_month,now_day);
    return;
}

void Memorandum::addMemora()
{
    update_interface(AddingMode);
    duplicate_to_old();
    m_id = 0;
    year = month = day = m_id;
    theme = "";
    maintext = "";
    selectDate();
    return;
}

void Memorandum::submitMemora()
{
    //To do with sqlite  注意每天只能有一个备忘录

    //注意区分addMode还是editMode

    if (currentMode == AddingMode)
    {
        theme = theme_input->text();
        maintext = maintext_input->toPlainText();
        
        //subbmitting to sql
        
        m_id = prt_calendarmap->pc_db->add_memora(theme,maintext,year,month,day);

        if ( m_id != 0 )
        {
            QMessageBox::information(this, QObject::tr("备忘录添加成功"),
             QObject::tr(" 成功给\"%1\"添加了备忘录!").arg(date_label->text()));
        }
    }

    else if (currentMode == EditingMode)
    {
        m_id = old_m_id;
        theme = theme_input->text();
        maintext= maintext_input->toPlainText();
        if (prt_calendarmap->pc_db->change_memora(theme,maintext,m_id))
        {
                QMessageBox::information(this, QObject::tr("备忘录修改成功"),
                 QObject::tr(" 成功修改了\"%1\"的备忘录!").arg(date_label->text()));
        }



    }

    else
    {
        qDebug() << "Nothing do in submminting. ERROR!";
    }



    update_interface(NavigationMode);
//    theme_input->setReadOnly(true);
//    maintext_input->setReadOnly(true);
//    add_button->setEnabled(true);
//    submit_button->hide();
//    cancel_button->hide();

//    next_button->setEnabled(true); //may change
//    previous_button->setEnabled(true); //may change

}

void Memorandum::redraw()
{
    if (m_id == 0)
        date_label->setText(QObject::tr("日期:无"));
    else
        date_label->setText(QObject::tr(getSolarStringWithYear(year,month,day).toLatin1()));

    theme_input->setText(theme);
    maintext_input->setText(maintext);
    return;
}

void Memorandum::cancelAdd()
{
    //恢复上次信息
    duplicate_to_new();
    redraw();



    update_interface(NavigationMode);
//    theme_input->setReadOnly(true);
//    maintext_input->setReadOnly(true);

//    add_button->setEnabled(true);
//    submit_button->hide();
//    cancel_button->hide();

//    next_button->setEnabled(true); //may change
//    previous_button->setEnabled(true); //may change
}

void Memorandum::nextMemora()
{
    //To do with sqlite
    duplicate_to_old();
    if (prt_calendarmap->pc_db->get_next_memora(old_m_id,m_id,theme,maintext,year,month,day))
        qDebug() << "Get next memora";
    else
        qDebug() << "GETNEXTMEMORA ERROR!";
    redraw();
    update_interface(NavigationMode);
    return;
}

void Memorandum::previousMemora()
{
    //To do with sqlite
    duplicate_to_old();
    if (prt_calendarmap->pc_db->get_previous_memora(old_m_id,m_id,theme,maintext,year,month,day))
        qDebug() << "Get next memora";
    else
        qDebug() << "GETNEXTMEMORA ERROR!";
    redraw();
    update_interface(NavigationMode);
    return;
}

void Memorandum::editMemora()
{
    //To do with sqlite
    duplicate_to_old();


    update_interface(EditingMode);
    return;
}

void Memorandum::removeMemora()
{
    //To do with sqlite
    duplicate_to_old();
    int button = QMessageBox::question(this,
                                       QObject::tr("确认删除备忘录"),
                                       QObject::tr("你确定要删除\"%1\"的备忘录吗?").arg(date_label->text()),
                                       QMessageBox::Yes|QMessageBox::No);

    if (button == QMessageBox::Yes)
    {
        if (!prt_calendarmap->pc_db->delete_memora(old_m_id))
            qDebug() << " DELETING ERROR!";
        if (next_button->isEnabled())
        {
            nextMemora();
            return;
        }
        else if (previous_button->isEnabled())
        {
            previousMemora();
            return;
        }
        else
        {
            m_id = 0;
            year = month = day = m_id;
            theme = "";
            maintext = "";
            redraw();
        }
    }

    update_interface(NavigationMode);
}

void Memorandum::update_interface(Mode mode)
{
    currentMode = mode;

    switch (currentMode)
    {
    case AddingMode:
        theme_input->clear();
        maintext_input->clear();
        selectdate_button->show();
    case EditingMode:

        theme_input->setReadOnly(false);
        theme_input->setFocus(Qt::OtherFocusReason);
        maintext_input->setReadOnly(false);

        add_button->setEnabled(false);
        edit_button->setEnabled(false);
        remove_button->setEnabled(false);

        next_button->setEnabled(false);
        previous_button->setEnabled(false);

        submit_button->show();
        cancel_button->show();
        break;
    case NavigationMode:

        selectdate_button->hide();

        theme_input->setReadOnly(true);
        maintext_input->setReadOnly(true);
        add_button->setEnabled(true);
        //to do with sqlite
        edit_button->setEnabled(true);
        remove_button->setEnabled(true);
        next_button->setEnabled(m_id&&prt_calendarmap->pc_db->have_next_memora(m_id));
        previous_button->setEnabled(m_id&&prt_calendarmap->pc_db->have_previous_memora(m_id));

        if (date_label->text() == QObject::tr("日期:无"))
        {
            edit_button->setEnabled(false);
            remove_button->setEnabled(false);
            theme_input->setText(QObject::tr("空"));
            maintext_input->setText(QObject::tr("空"));
        }

        //qDebug() << "Cancel one";
        if (prt_calendarmap->pc_db->is_open())
            qDebug() << "Open success";
        else
            qDebug() << "No open";
        submit_button->hide();
        cancel_button->hide();
        break;
    }
}

void Memorandum::selectDate()
{
    select_datemap->show();

    while (select_datemap->is_open())
    {
        QTime dieTime2 = QTime::currentTime().addMSecs(100);
        while( QTime::currentTime() < dieTime2 )
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
//    if (select_datemap->nowday() == 28)
//        assert(0);
    while (prt_calendarmap->pc_db->is_memora_existed(select_datemap->nowyear(),select_datemap->nowmonth(),select_datemap->nowday()))
    {
        QMessageBox::information(this,QObject::tr("这一天已经有备忘录啦"),
                                 QObject::tr("一天只能有一个备忘录"));

        select_datemap->show();

        while (select_datemap->is_open())
        {
            QTime dieTime2 = QTime::currentTime().addMSecs(100);
            while( QTime::currentTime() < dieTime2 )
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    year = select_datemap->nowyear();
    month = select_datemap->nowmonth();
    day = select_datemap->nowday();
    date_label->setText(QObject::tr(getSolarStringWithYear(year,month,day).toLatin1()));

    qDebug() << "Selection end";
    return;
}

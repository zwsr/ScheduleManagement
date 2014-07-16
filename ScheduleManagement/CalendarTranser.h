#ifndef CALENDARTRANSER_H
#define CALENDARTRANSER_H

#include <iostream>
#include <QString>


//用于日期转换  获得节假日等
class CalendarTranser
{
public:
    CalendarTranser();
    int getDayOfWeek(int y, int m, int d);
    QString getLunarString(int y,int m, int d);
    QString getSolarString(int y,int m,int d);
    QString getSolarStringWithYear(int y, int m ,int d);
    QString getFestival(int m,int d);


    QString getWordMonth(int m)
    {
        return m_nStr1[m] + "月";
    }

    bool is_leapyear(int year)
    {
        if( (year%4==0 &&year%100!=0) || year%400==0 )
            return true;
        else
            return false;
    }

private:
    int lunar_year;
    int lunar_month;
    int lunar_day;

    static const QString solarFestival[];  //节日中文描述
    static const QString m_nStr1[]; //数字的中文描述
    static const QString m_nStr2[]; //数字的中文描述

    //static const int lunar_info[];

    //方法
    QString getLunarDay(int d);

    unsigned char solar_to_lunar(int kp_year,int kp_month,int kp_day);
};

#endif // CALENDARTRANSER_H

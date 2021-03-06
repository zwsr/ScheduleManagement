#include "CalendarTranser.h"



const int lunar_info[] =
{
    0x04bd8,0x04ae0,0x0a570,0x054d5,0x0d260,0x0d950,0x16554,0x056a0,0x09ad0,0x055d2,
    0x04ae0,0x0a5b6,0x0a4d0,0x0d250,0x1d255,0x0b540,0x0d6a0,0x0ada2,0x095b0,0x14977,
    0x04970,0x0a4b0,0x0b4b5,0x06a50,0x06d40,0x1ab54,0x02b60,0x09570,0x052f2,0x04970,
    0x06566,0x0d4a0,0x0ea50,0x06e95,0x05ad0,0x02b60,0x186e3,0x092e0,0x1c8d7,0x0c950,
    0x0d4a0,0x1d8a6,0x0b550,0x056a0,0x1a5b4,0x025d0,0x092d0,0x0d2b2,0x0a950,0x0b557,
    0x06ca0,0x0b550,0x15355,0x04da0,0x0a5b0,0x14573,0x052b0,0x0a9a8,0x0e950,0x06aa0,
    0x0aea6,0x0ab50,0x04b60,0x0aae4,0x0a570,0x05260,0x0f263,0x0d950,0x05b57,0x056a0,
    0x096d0,0x04dd5,0x04ad0,0x0a4d0,0x0d4d4,0x0d250,0x0d558,0x0b540,0x0b6a0,0x195a6,
    0x095b0,0x049b0,0x0a974,0x0a4b0,0x0b27a,0x06a50,0x06d40,0x0af46,0x0ab60,0x09570,  //1980
    0x04af5,0x04970,0x064b0,0x074a3,0x0ea50,0x06b58,0x055c0,0x0ab60,0x096d5,0x092e0,
    0x0c960,0x0d954,0x0d4a0,0x0da50,0x07552,0x056a0,0x0abb7,0x025d0,0x092d0,0x0cab5,  //2004 07552
    0x0a950,0x0b4a0,0x0baa4,0x0ad50,0x055d9,0x04ba0,0x0a5b0,0x15176,0x052b0,0x0a930,
    0x07954,0x06aa0,0x0ad50,0x05b52,0x04b60,0x0a6e6,0x0a4e0,0x0d260,0x0ea65,0x0d530, //2028
    0x05aa0,0x076a3,0x096d0,0x04bd7,0x04ad0,0x0a4d0,0x1d0b6,0x0d250,0x0d520,0x0dd45,
    0x0b5a0,0x056d0,0x055b2,0x049b0,0x0a577,0x0a4b0,0x0aa50,0x1b255,0x06d20,0x0ada0,
    0x14b63
};


const QString CalendarTranser::m_nStr1[]={ //数字的中文描述
 ("日"), ("一"), ("二"), ("三"), ("四"), ("五"), ("六"), ("七"),
 ("八"), ("九"), ("十"), ("十一"), ("十二")
};

const QString CalendarTranser::m_nStr2[]={ //数字的中文描述
 ("初"), ("十"), ("廿"), ("卅"), ("□")
};


const QString CalendarTranser::solarFestival[] =
{
     ("0101*新年元旦"),
     ("0106 中国13亿人口日[2005]"),
     ("0108 周恩来逝世纪念日[1976]"),
     ("0121 列宁逝世纪念日[1924]"),
     ("0127 宋庆龄诞辰纪念日[1893]"),
    //-
     ("0202 世界湿地日[1996]"),
     ("0207 国际声援南非日[1964]"),
     ("0210 世界气象日[1960]"),
     ("0214 西方情人节"),
     ("0215 中国12亿人口日[1995]"),
     ("0219 邓小平逝世纪念日[1997]"),
     ("0221 反对殖民制度斗争日[1949]"),
     ("0224 第三世界青年日"),
     ("0228 世界居住条件调查日"),
    //-
     ("0301 国际海豹日[1983]"),
     ("0303 全国爱耳日[2000]"),
     ("0305 中国青年志愿者服务日[2000] 毛泽东题词“向雷锋同志学习”[1963] 周恩来诞辰纪念日[1898] 斯大林逝世纪念日[1953]"),
     ("0308 国际妇女节[1910]"),
     ("0312 植树节[1979] 孙中山逝世纪念日"),
     ("0314 国际警察日(节) 马克思逝世纪念日[1883]"),
     ("0315 国际消费者权益日[1983]"),
     ("0316 手拉手情系贫困小伙伴全国统一行动日"),
     ("0317 中国国医节[1929] 国际航海日"),
     ("0317 中国国医节[1929] 国际航海日"),
     ("0318 全国科技人才活动日 巴黎公社纪念日[1871]"),
     ("0321 世界睡眠日[2001] 世界儿歌日 世界森林日(林业节)[1972] 消除种族歧视国际日[1976]"),
    // ("0321 世界儿歌日"),
     ("0322 世界水日[1993] 中国水周(3月22日至3月28日)[1988设/1994改]"),
     ("0323 世界气象日[1950]"),
     ("0324 世界防治结核病日[1996]"),
    // ("0325 全国中小学生安全教育日"),
     ("0330 巴勒斯坦国土日"),
    //-
     ("0401 愚人节 全国爱国卫生运动月(四月) 税收宣传月(四月)"),
     ("0402 国际儿童图书日"),
     ("0407 世界卫生日[1950] 1994年卢旺达境内灭绝种族罪行国际反思日[2004]"),
     ("0421 全国企业家活动日[1994]"),
     ("0422 世界地球日[1970] 列宁诞辰纪念日[1870]"),
     ("0423 世界图书和版权日"),
     ("0424 世界青年反对殖民主义日[1957] 亚非新闻工作者日"),
     ("0425 全国预防接种宣传日[1986]"),
     ("0426 世界知识产权日[2001]"),
     ("0427 联谊城日"),
     ("0430 全国交通安全反思日"),
    //-
     ("0501 国际劳动节[1889] 国际示威游行日"),
     ("0503 世界哮喘日"),
     ("0504 中国五四青年节[1939] 五四运动纪念日[1919] 科技传播日"),
     ("0505 碘缺乏病防治日[1994] 马克思诞辰纪念日[1818]"),
     ("0508 世界红十字日[1948] 世界微笑日"),
     ("0512 国际护士节[1912]"),
     ("0515 国际家庭(咨询)日[1994]"),
     ("0517 世界电信日[1969]"),
     ("0518 国际博物馆日"),
     ("0520 全国学生营养日[1990] 全国学生营养日[1990]"),
     ("0522 国际生物多样性日[1994设/2001改]"),
    // ("0523 国际牛奶日"),
     ("0526 世界向人体条件挑战日[1993]"),
     ("0529 宋庆龄逝世纪念日[1981]"),
     ("0530 “五卅”反对帝国主义运动纪念日[1925]"),
     ("0531 世界无烟日[1988]"),
    //-
     ("0601 国际儿童节[1949]"),
     ("0605 世界环境日[1974]"),
     ("0606 全国爱眼日[1996]"),
     ("0611 中国人口日"),
     ("0617 防治荒漠化和干旱日[1995]"),
     ("0620 世界难民日[2001]"),
     ("0622 中国儿童慈善活动日"),
     ("0623 国际奥林匹克日[1894] 世界手球日"),
     ("0625 全国土地日[1991]"),
     ("0626 国际反毒品日[1987] 国际宪章日(联合国宪章日)"),
     ("0630 世界青年联欢节"),
    //-
     ("0701 中国共产党建党日[1921] 香港回归纪念日[1997] 国际建筑日[1985] 亚洲“三十亿人口日”[1988]"),
     ("0702 国际体育记者日"),
     ("0706 朱德逝世纪念日[1976]"),
     ("0707 中国人民抗日战争纪念日[1937]"),
     ("0711 中国航海日[2005] 世界(50亿)人口日[1987]"),
     ("0720 人类首次成功登月[1969]"),
     ("0726 世界语(言)创立日"),
     ("0728 第一次世界大战爆发[1914]"),
     ("0730 非洲妇女日"),
    //-
     ("0801 中国人民解放军建军节[1927]"),
     ("0805 恩格斯逝世纪念日[1895]"),
     ("0806 国际电影节[1932]"),
     ("0808 中国男子节(爸爸节)[1988]"),
     ("0809 世界土著人民国际日[1994]"),
     ("0812 国际青年人日[1999]"),
     ("0813 国际左撇子日[1975设/1976]"),
     ("0815 日本正式宣布无条件投降日[1945] 世界反法西斯战争胜利纪念日[1945]"),
     ("0826 全国律师咨询日[1993]"),
    //-
     ("0903 中国抗日战争胜利纪念日[1945]"),
     ("0908 世界扫盲日[1966] 国际新闻工作者(团结)日[1958]"),
     ("0909 毛泽东逝世纪念日[1976]"),
     ("0910 教师节[1985]"),
     ("0914 世界清洁地球日"),
     ("0916 国际臭氧层保护日[1987]"),
     ("0918 九·一八事变纪念日(中国国耻日)[1931]"),
     ("0920 全国公民道德宣传日[2003] 全国爱牙日[1989]"),
     ("0921 国际和平日(全球停火和非暴力日,2002年以后)[2002]"),
     ("0925 鲁迅诞辰纪念日[1881]"),
     ("0926 (曲阜国际)孔子文化节[1989]"),
     ("0927 世界旅游日[1979]"),
    //-
     ("1001*国庆节[1949] 国际音乐日[1980] 国际敬老日(老人节)[1991]"),
    // ("1001 国际音乐日"),
     ("1002 国际和平(与民主自由)斗争日[1949]"),
     ("1004 世界动物日[1949]"),
     ("1008 全国高血压日[1998] 狮子会世界视觉日[1998]"),
     ("1009 世界邮政日(万国邮联日)[1969]"),
     ("1010 辛亥革命纪念日[1911] 世界精神卫生日[1992] 世界居室卫生日"),
     ("1011 声援南非政治犯日"),
     ("1012 世界(60亿)人口日[1999]"),
     ("1013 中国少年先锋队建队纪念日[1949] 世界保健日 国际教师节 采用格林威治时间为国际标准时间日[1884]"),
     ("1014 世界标准日[1969]"),
     ("1015 国际盲人节(白手杖节)[1984]"),
     ("1016 世界粮食日[1979]"),
     ("1017 世界消除贫困日[1992]"),
     ("1019 鲁迅逝世纪念日[1936]"),
     ("1022 世界传统医药日[1992]"),
     ("1024 联合国日[1945] 世界发展信息日"),
     ("1028 世界“男性健康日”[2000]"),
     ("1031 世界勤俭日"),
    //-
     ("1107 十月社会主义革命纪念日(现俄“和谐和解日”)[1917]"),
     ("1108 中国记者日[2000]"),
     ("1109 全国消防安全宣传教育日[1992]"),
     ("1110 世界青年节[1946]"),
     ("1111 光棍节 国际科学与和平周(本日所属的一周)"),
     ("1112 孙中山诞辰纪念日[1866, 1926定] 刘少奇逝世纪念日[1969]"),
     ("1114 世界糖尿病日[1991]"),
     ("1117 国际大学生节(世界学生节)[1946]"),
     ("1120 世界儿童日[1986]"),
     ("1121 世界问候日[1973] 世界电视日[1996]"),
     ("1124 刘少奇诞辰纪念日[1893]"),
     ("1128 恩格斯诞辰纪念日[1820]"),
     ("1129 国际声援巴勒斯坦人民国际日[1977]"),
    //-
     ("1201 世界艾滋病日[1988] 朱德诞辰纪念日[1886]"),
     ("1202 废除一切形式奴役世界日[1986]"),
     ("1203 世界残疾人日[1992]"),
     ("1204 中国法制宣传日[2001]"),
     ("1205 国际经济和社会发展志愿人员日[1985] 世界弱能人士日"),
     ("1207 国际民航日[纪念1994, 1996定]"),
    // ("1208 国际儿童电视日"),
     ("1209 一二·九运动纪念日[1935] 世界足球日[1995]"),
     ("1210 世界人权日(诺贝尔日)[1950]"),
     ("1211 世界防治哮喘日[1998]"),
     ("1212 西安事变纪念日[1936]"),
     ("1213 南京大屠杀纪念日·勿忘国耻,紧记血泪史![1937]"),
     ("1215 世界强化免疫日"),
     ("1220 澳门回归纪念日[1999]"),
     ("1221 国际篮球日 斯大林诞辰纪念日[1879]"),
     ("1224 平安夜"),
     ("1225 圣诞节"),
     ("1226 毛泽东诞辰纪念日[1893]")
};



QString CalendarTranser::getLunarString(int y, int m, int d)
{
    solar_to_lunar(y,m,d);
    QString content;
    content = "农历:" + getWordMonth(lunar_month) + getLunarDay(lunar_day);
    return content;
}

QString CalendarTranser::getSolarString(int y,int m,int d)
{
    QString content;
    QString tmp,tmp2;
    tmp.setNum(d);
    tmp2.setNum(m);
    content = "今天是:" + tmp2 + "月" + tmp + "号";
    return content;
}

QString CalendarTranser::getSolarStringWithYear(int y, int m, int d)
{
    QString content;
    QString tmp,tmp1,tmp2;
    tmp.setNum(y);
    tmp1.setNum(m);
    tmp2.setNum(d);
    content = "日期:" + tmp + "年" + tmp1 + "月" + tmp2 + "号";
    return content;
}

CalendarTranser::CalendarTranser()
{
}


int CalendarTranser::getDayOfWeek(int y, int m, int d)
{
    int year = y;
    int month = m;
    int day = d;
    if(month==1||month==2)
    {
        month+=12;
        year--;
    }
    int weekNum = (day+1+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
    return weekNum;
}

QString CalendarTranser::getLunarDay(int d)
{
    QString s;
    switch (d)
    {
        case 10:
            s = ("初十");
            break;
        case 20:
            s = ("二十");
            break;
        case 30:
            s = ("三十");
            break;
        default :
            s = m_nStr2[d/10];
        s += m_nStr1[d%10];
    }
    return s;
}

unsigned char get_leap_month(unsigned int lunar_year) //确定是否存在农历的闰月 并返回闰月
{
    return lunar_info[lunar_year-1900]&0xf;
}
//---------------------------------------------
unsigned char get_leap_month_day(unsigned int lunar_year)  //若存在闰月,返回闰月的天数,30?29
{
    if(get_leap_month(lunar_year))
        return(  ( (lunar_info[lunar_year-1900]) & 0x10000 ) ? 30:29 );
    else
        return(0);
}
//---------------------------------------------
unsigned char get_lunar_month_total(unsigned int lunar_year, unsigned char lunar_month) //确定农历当月天数,30?29
{
    return( (lunar_info[lunar_year-1900] & (0x10000>>lunar_month) ) ? 30:29 );
}
//---------------------------------------------
unsigned int get_lunar_year_total(unsigned int lunar_year) // 农历当年总天数,354?355 384 383
 {
    /*sum=12*29 */   //12个月 29天一月
    unsigned int sum=348;
    unsigned int i;
     for(i=0x8000;i>0x8; i>>=1)
         sum+=(lunar_info[lunar_year-1900]&i)?1:0;  //把大月的1加进去
    return(sum+get_leap_month_day(lunar_year));    //判断这年是否有闰月
 }
//---------------------------------------------
//#############################################

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//---------------------------------------------
unsigned int leap(unsigned int year)  //判断是否为闰年
{
    if( (year%4==0 &&year%100!=0) || year%400==0 )
        return 366;
    else
        return 365;
}

//--------------------------------------
unsigned char day(unsigned int year ,unsigned char month) //判断当年当月天数
{
    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        return 31;
    if(month==4||month==6||month==9||month==11)
        return 30;
    if(month==2&&leap(year)==366)
        return 29;
    else
        return 28;
}
//-------------------------------------------
//计算1900.1.1 到  输入年月的天数
unsigned int get_solar_total(unsigned int solar_year, unsigned char solar_month)
{
    unsigned int total;
    unsigned int temp_num;
    total=0;
    for(temp_num=1900;temp_num<solar_year;temp_num++)
        total+=leap(temp_num);
    for(temp_num=1;temp_num<solar_month;temp_num++)
        total+=day(solar_year,temp_num);
    return total;
}

unsigned char CalendarTranser::solar_to_lunar(int kp_year, int kp_month, int kp_day)
{
    unsigned int total_day=0;/*记录农历1900.1.1日到今天相隔的天数 */
    unsigned char run_yue_flag=0,run_yue=0,year_flag=0;

    if(kp_year<1900 || kp_year>2050 || kp_month>12 || kp_month==0 || (kp_year==1900 && kp_month==1) )
        return 0;
    if(kp_day>day(kp_year,kp_month) || kp_day==0)
        return 0;

    total_day=get_solar_total( kp_year, kp_month)+kp_day-30; /* 阳历从1900.1.31(农历1900.1.1)到今天的总天数(减30 实际少了一天)。 */
    lunar_year=1900;
    while(total_day>385) //385大于一年  留出一年多的时间用于条件计算
    {
        total_day-=get_lunar_year_total(lunar_year); //
        lunar_year++;
    }
    if(total_day>get_lunar_year_total(lunar_year))  //排除lunar_year有闰月的情况
    {
        total_day-=get_lunar_year_total(lunar_year);
        lunar_year++;

    }
    run_yue=get_leap_month(lunar_year);  //当前闰哪个月
    if(run_yue)
        run_yue_flag=1; //有闰月则一年为13个月
    else
        run_yue_flag=0;  //没闰月则一年为12个月

    if(total_day==0)   //刚好一年
    {
        lunar_day=get_lunar_month_total(lunar_year,12);
        lunar_month=12;
    }
    else
    {
        lunar_month=1;
        while(lunar_month<=12)
        {
                if( run_yue_flag==1 && lunar_month==(run_yue+1) )  //闰月处理
                {
                        if(total_day>get_leap_month_day(lunar_year))
                        {
                            total_day-=get_leap_month_day(lunar_year);  //该年闰月天数

                        }
                         //lunar_month--;
                         run_yue_flag=0;
                         continue;

                }
                if( total_day> get_lunar_month_total(lunar_year,lunar_month ) )
                {
                        total_day=total_day-get_lunar_month_total(lunar_year,lunar_month);  //该年该月天数
                        lunar_month++;
                }
                else
                {
                    lunar_day=total_day;
                    break;
                }
        }
    }
}

QString CalendarTranser::getFestival(int m, int d)
{
    QString ret = "今天没有节日";
//    QString month,day;
//    if (m<10)
//    {
//        QString tmp;
//        tmp.setNum(m);
//        month = "0" + tmp;
//    }
//    else
//    {
//        month.setNum(m);
//    }
//    if (d<10)
//    {
//        QString tmp;
//        tmp.setNum(d);
//        month = "0" + tmp;
//    }
//    else
//    {
//        day.setNum(d);
//    }
    int MandD = m * 100 + d + 10000;
    QString matcher;
    matcher.setNum(MandD);
    matcher = matcher.right(4);

    QString to_match;
    int i = -1;

    do
    {
        i++;
        to_match = solarFestival[i].left(4);

        if ( matcher == to_match)
        {
            ret = solarFestival[i];
            break;
        }
    }
    while ( solarFestival[i] != "1226 毛泽东诞辰纪念日[1893]");

    return ret;

}



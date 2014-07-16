#include "SqlDb.h"
#include "assert.h"


static int getDatevalue(int y, int m, int d)
{
    return (y * 1200 + m * 100 + d);
}

SqlDb::SqlDb(QString dbname)

{
    //初始化
    db = QSqlDatabase::addDatabase("QSQLITE");    //添加数据库驱动
    db.setDatabaseName(dbname);

    if (!db.open())
    {
        qDebug() << "Sql error!";
        assert(0);
    }

    qDebug() << "DB opening!";

    QSqlQuery query;
    if (query.exec("create table memora(m_id INTEGER PRIMARY KEY,theme varchar(40), maintext TEXT,year INTEGER,month INTEGER,day INTEGER, datevalue INTEGER)"))
    {

        m_num = 0;
    }
    else
    {
        qDebug() << "Memora table existed";
        query.exec("SELECT count(*) FROM memora");
        query.next();
        m_num = query.value(0).toInt();

    }

    if (query.exec("create table list(l_id INTEGER PRIMARY KEY,theme varchar(40), maintext TEXT,year INTEGER,month INTEGER,day INTEGER, datevalue INTEGER, finished INTEGER)"))
    {

        l_num = 0;
    }
    else
    {

        query.exec("SELECT count(*) FROM list");
        query.next();
        l_num = query.value(0).toInt();
    }

}

void SqlDb::closeDB()
{
    db.close();
}

int SqlDb::add_memora(QString theme, QString maintext, int year, int month, int day)
{
    QSqlQuery query;
    query.prepare(QObject::tr("insert into memora (m_id , theme, maintext, year, month, day, datevalue)"
                            "VALUES (NULL, :theme, :maintext, :year, :month, :day, :datevalue)"));

    int datevalue = getDatevalue(year,month,day);

    if (theme == "")
        theme = QObject::tr("无题");

    if (maintext == "")
        maintext = QObject::tr("无正文");

    m_num++;
//    query.bindValue(":m_id", m_num);
    query.bindValue(":theme", theme);
    query.bindValue(":maintext",maintext);
    query.bindValue(":year",year);
    query.bindValue(":month",month);
    query.bindValue(":day",day);
    query.bindValue(":datevalue",datevalue);
    query.exec();

    int newm_id;
    query.prepare("SELECT m_id FROM memora WHERE datevalue = ?");
    query.bindValue(0,datevalue);
    query.exec();
    query.next();
    newm_id = query.value(0).toInt();
    return newm_id;
}

bool SqlDb::delete_memora(int m_id)
{
    QString delete_string;
    delete_string.setNum(m_id);
    delete_string = "DELETE FROM memora WHERE m_id = " + delete_string;
    QSqlQuery query;
    if (query.exec(delete_string))
        return true;
    else
        return false;
}

bool SqlDb::change_memora(QString theme, QString maintext, int m_id)
{
    QSqlQuery query;
    query.prepare("UPDATE memora SET theme = ? , maintext = ? WHERE m_id = ?");
    query.bindValue(0,theme);
    query.bindValue(1,maintext);
    query.bindValue(2,m_id);
    if (query.exec())
        return true;
    else
        return false;
}

bool SqlDb::is_memora_existed(int y, int m, int d)
{
    int datevalue = getDatevalue(y,m,d);
    QSqlQuery query;
    query.prepare("SELECT count(*) FROM memora WHERE datevalue = ?");
    query.bindValue(0,datevalue);
    query.exec();
    query.next();
    int num = query.value(0).toInt();
    if (num == 0)
        return false;
    else
        return true;
}

int SqlDb::memora_size()
{
    QSqlQuery query;
    query.exec("SELECT count(*) FROM memora");
    query.next();
    int num = query.value(0).toInt();
    return num;
}

bool SqlDb::get_lastest_memora(int &m_id, QString &theme, QString &maintext, int &y, int &m, int &d)
{
    QSqlQuery query;
    bool flag;
    if (query.exec("SELECT * FROM memora ORDER BY m_id desc"))
        flag = true;
    else
        flag = false;
    query.next();
    m_id = query.value(0).toInt();
    theme = query.value(1).toString();
    maintext = query.value(2).toString();
    y = query.value(3).toInt();
    m = query.value(4).toInt();
    d = query.value(5).toInt();
    return flag;
}


bool SqlDb::get_next_memora(int oldm_id, int &m_id, QString &theme, QString &maintext, int &y, int &m, int &d)
{
    QSqlQuery query;
    bool flag;
    query.prepare("SELECT * FROM memora WHERE m_id > ? ORDER BY m_id");
    query.bindValue(0,oldm_id);
    if (query.exec())
        flag = true;
    else
        flag = false;
    query.next();
    m_id = query.value(0).toInt();
    theme = query.value(1).toString();
    maintext = query.value(2).toString();
    y = query.value(3).toInt();
    m = query.value(4).toInt();
    d = query.value(5).toInt();
    return flag;
}

bool SqlDb::get_previous_memora(int oldm_id, int &m_id, QString &theme, QString &maintext, int &y, int &m, int &d)
{
    QSqlQuery query;
    bool flag;
    query.prepare("SELECT * FROM memora WHERE m_id < ? ORDER BY m_id desc");
    query.bindValue(0,oldm_id);
    if (query.exec())
        flag = true;
    else
        flag = false;
    query.next();
    m_id = query.value(0).toInt();
    theme = query.value(1).toString();
    maintext = query.value(2).toString();
    y = query.value(3).toInt();
    m = query.value(4).toInt();
    d = query.value(5).toInt();
    return flag;
}

bool SqlDb::have_next_memora(int m_id)
{
    QSqlQuery query;
    query.prepare("SELECT count(*) FROM memora WHERE m_id > ?");
    query.bindValue(0,m_id);
    query.exec();
    query.next();
    int num = query.value(0).toInt();
    if (num == 0)
        return false;
    else
        return true;
}

bool SqlDb::have_previous_memora(int m_id)
{
    QSqlQuery query;
    query.prepare("SELECT count(*) FROM memora WHERE m_id < ?");
    query.bindValue(0,m_id);
    query.exec();
    query.next();
    int num = query.value(0).toInt();
    if (num == 0)
        return false;
    else
        return true;
}


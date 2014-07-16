#ifndef SQLDB_H
#define SQLDB_H

#include <QObject>
//#include <QSqlDatabase>
//#include <QSqlQuery>
//#include <QVariant>
#include <QtSql>


const QString pc_dbname = "ScheduleDb_PC.dat";
const QString android_dbname = "ScheduleDb_Android.dat";

class SqlDb : public QObject
{
    Q_OBJECT
public:
    SqlDb(QString dbname);
    void closeDB();

    int add_memora(QString theme, QString maintext,int year, int month ,int day);
    bool delete_memora(int m_id);
    bool change_memora(QString theme, QString maintext,int m_id);
    int memora_size();
    bool is_memora_existed(int y, int m, int d); //true for exist   false for not exist
    bool have_next_memora(int m_id);
    bool have_previous_memora(int m_id);
    bool get_lastest_memora(int& m_id, QString& theme, QString& maintext, int& y, int& m, int& d);
    bool get_next_memora(int oldm_id,int& m_id, QString& theme, QString& maintext, int& y, int& m, int& d);
    bool get_previous_memora(int oldm_id,int& m_id, QString& theme, QString& maintext, int& y, int& m, int& d);

    bool is_open()
    {
        return db.isOpen();
    }
    
private:
    QSqlDatabase db;
    int m_num;
    int l_num;
    
};

#endif // SQLDB_H

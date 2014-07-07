#ifndef SQLDB_H
#define SQLDB_H

#include <QObject>
#include <QtSql/QSqlDatabase>

class SqlDb : public QObject
{
    Q_OBJECT
public:
    explicit SqlDb(QObject *parent = 0);
    void connectDB();
    void closeDB();
    
signals:
    
public slots:
    QSqlDatabase db;
    
};

#endif // SQLDB_H

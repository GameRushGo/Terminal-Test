#ifndef QSQLITE_H
#define QSQLITE_H
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

#define MAX_NUM 1
class QSQLite
{
public:
    QSQLite();
    void Open();
    void Close();
    void CreatTable();
    int Insert(QString username,QString password,QString name,QString sex,QString tel);
    void Update();
    void AllInfo();
    QString SearchInfo(QString usernameedit);
    void Delete();
    QSqlDatabase database;

};

#endif // QSQLITE_H

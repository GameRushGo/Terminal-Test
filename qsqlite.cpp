#include "qsqlite.h"
#include <qdebug.h>
#include <QString>

QSQLite::QSQLite()
{
    //数据库的初始化
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("UserInfo.db");
    }
}

void QSQLite::Open()
{
    if (!database.open())
    {
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }
}

void QSQLite::Close()
{
    database.close();
}

void QSQLite::CreatTable()//创建表格
{
    QSqlQuery sql_query;
    QString create_sql = "create table admin (id int primary key, username varchar(30), password varchar(30), name varchar(30), sex varchar(30), tel varchar(30))";
    sql_query.prepare(create_sql);
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
}

int QSQLite::Insert(QString username,QString password,QString name,QString sex,QString tel)//插入
{
    QSqlQuery sql_query;
    QString select_max_sql = "select max(id) from admin";
    int max_id = 0;
    sql_query.prepare(select_max_sql);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            max_id = sql_query.value(0).toInt();
            //qDebug() << QString("max id:%1").arg(max_id);
        }
    QString insert_sql = "insert into admin values (?, ?, ?, ?, ?, ?)";
    sql_query.prepare(insert_sql);

    }
    sql_query.addBindValue(max_id+1);
    sql_query.addBindValue(username);
    sql_query.addBindValue(password);
    sql_query.addBindValue(name);
    sql_query.addBindValue(sex);
    sql_query.addBindValue(tel);
    if(!sql_query.exec())
    {
        //qDebug() << sql_query.lastError();
        return 0;
    }
    else
    {
        //qDebug() << "inserted ok !";
        return 1;
    }

}

void QSQLite::Update()//更新
{
    QSqlQuery sql_query;
    QString update_sql = "update admin set name = :name where id = :id";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":name", "Qt");
    sql_query.bindValue(":id", "1");
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "updated!";
    }
}

void QSQLite::AllInfo()//查询所有信息
{
//    QSqlQuery sql_query;
//    QString select_all_sql = "select * from admin";
//    sql_query.prepare(select_all_sql);
//    if(!sql_query.exec())
//    {
//        qDebug()<<sql_query.lastError();
//    }
//    else
//    {
//        while(sql_query.next())
//        {
//            int id = sql_query.value(0).toInt();
//            QString name = sql_query.value(1).toString();
//            QString password = sql_query.value(2).toString();
//            qDebug()<<QString("id:%1    name:%2    password:%3").arg(id).arg(name).arg(password);
//        }
//    }
}


QString QSQLite::SearchInfo(QString usernameedit)//根据用户名查找密码
{
    QSqlQuery sql_query;
    QString sqlpassword;
    QString username;
    int id=0;
    //QString strid = QString::number(id);

    QString select_sql = "select * from admin ";

    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
            {
                id= sql_query.value(0).toInt();
                username = sql_query.value(1).toString();
                if(usernameedit==username){
                    sqlpassword=sql_query.value(2).toString();
                    //qDebug()<<QString("id:%1    name:%2  password:%3").arg(id).arg(name).arg(sqlpassword);
                }

            }

    }
    return sqlpassword;
}

void QSQLite::Delete()
{
//    QSqlQuery sql_query;
//    QString delete_sql = "delete from admin where id = ?";
//    sql_query.prepare(delete_sql);
//    sql_query.addBindValue(0);
//    if(!sql_query.exec())
//    {
//        qDebug()<<sql_query.lastError();
//    }
//    else
//    {
//        qDebug()<<"deleted!";
//    }
}



#include "logindialog.h"
#include "ui_logindialog.h"
#include "qsqlite.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    flag=0;
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}



void LoginDialog::on_pushButton_clicked()//确认登录
{
    QSQLite qsql;
    QString password;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();


    qsql.Open();
    //qsql.AllInfo();
    if(password==qsql.SearchInfo(username))
    {
        flag=1;
        accept();
    }
}

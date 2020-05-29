#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "qsqlite.h"
#include <QMessageBox>


RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_6->setEchoMode(QLineEdit::Password);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_pushButton_clicked()
{
    QSQLite qsql;
    QString username;
    QString password;
    QString name;
    QString surepassword;
    QString sex;
    QString tel;

    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    name =ui->lineEdit_3->text();
    sex =ui->lineEdit_4->text();
    tel =ui->lineEdit_5->text();
    surepassword = ui->lineEdit_6->text();
    if(password==surepassword)
    {
        qsql.Open();
        qsql.CreatTable();
        if(qsql.Insert(username,password,name,sex,tel)){
            accept();
        }else{
            QMessageBox::information(this,tr("Error"),QStringLiteral("注册失败"),QMessageBox::Ok);
        }

    }else{
        QMessageBox::information(this,tr("Error"),QStringLiteral("两次密码不同"),QMessageBox::Ok);
    }
}

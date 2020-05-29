#include "managedialog.h"
#include "ui_managedialog.h"
#include "managedata.h"
#include "qdebug.h"

manageDialog::manageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageDialog)
{
    ui->setupUi(this);
}

manageDialog::~manageDialog()
{
    delete ui;
}

void manageDialog::on_pushButton_clicked()
{
    ManageData manage;
    QList<QString> app_pathread;
    QList<QString> app_path;
    QString str1;
    app_pathread=manage.getAppPath();

    app_path<<ui->lineEdit->text()<<ui->lineEdit_2->text()<<ui->lineEdit_3->text()<<ui->lineEdit_4->text();
    for (int i=0;i<app_pathread.size();i++) {
        if(app_path[i]==NULL){
            app_path[i]=app_pathread[i];
        }
    }
    manage.setAppPath(app_path);
    accept();
}

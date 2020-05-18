#include "testinfodialog.h"
#include "ui_testinfodialog.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "ctesterinfo.h"
#include <qdebug.h>
#include "testeradddialog.h"
#include <QDateTime>


TestInfoDialog::TestInfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestInfoDialog)
{
    ui->setupUi(this);
    infoinit();//表格初始化，将文件的内容读取到窗口
}

TestInfoDialog::~TestInfoDialog()
{
    delete ui;
}

void TestInfoDialog::on_pushButton_clicked()//新增被试
{
    CTesterInfo testerinfo;
    testerinfo.ReadInfo();
    QString name;
    QString age;
    QString date;
    QString type;
    //msg tmp;
    TesterAddDialog testaddinfo;
    testaddinfo.exec();
    if(!testaddinfo.name.isEmpty())
    {
        name=testaddinfo.name;
        age=testaddinfo.age;
        type = testaddinfo.type;
        QDateTime current_date_time =QDateTime::currentDateTime();
        date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
        //qDebug() <<name<<age<<date<<type;
        int rows=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        ui->tableWidget->setItem(rows,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(rows,1,new QTableWidgetItem(age));
        ui->tableWidget->setItem(rows,2,new QTableWidgetItem(date));
        ui->tableWidget->setItem(rows,3,new QTableWidgetItem(type));
        testerinfo.AddInfo(name,age,date,type);
        testerinfo.WirteInfo();
        ui->tableWidget->selectRow(rows);
    }

}


void TestInfoDialog::on_pushButton_3_clicked()//删除被试
{
    int i=0;
    QString name;
    QString age;
    QString date;
    QString type;
    CTesterInfo testerinfo;
    testerinfo.info.clear();
    //选中删除
    QTableWidgetItem * item = ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->tableWidget->removeRow(item->row());

    int rows=ui->tableWidget->rowCount();
    for(i=0;i<rows;i++)
    {
        name=ui->tableWidget->item(i,0)->text();
        age=ui->tableWidget->item(i,1)->text();
        date=ui->tableWidget->item(i,2)->text();
        type=ui->tableWidget->item(i,3)->text();
        //qDebug() <<name<<age<<date<<type;
        testerinfo.AddInfo(name,age,date,type);
    }
    testerinfo.WirteInfo();
}

void TestInfoDialog::infoinit()//初始化
{
    CTesterInfo testerinfo;
    testerinfo.ReadInfo();
    QString name;
    QString age;
    QString date;
    QString type;

    for(int i=0;i<testerinfo.info.size();i++)
    {
        name=testerinfo.info.at(i).name;
        age=QString::number(testerinfo.info.at(i).age);
        date=testerinfo.info.at(i).date;
        type=testerinfo.info.at(i).type;
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(age));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(date));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(type));
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格列自适应窗口，避免右边出现一大块空白
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个
}

void TestInfoDialog::on_pushButton_2_clicked()//修改
{
    int i=0;
    QString name;
    QString age;
    QString date;
    QString type;
    CTesterInfo testerinfo;
    testerinfo.info.clear();

    int rows=ui->tableWidget->rowCount();
    for(i=0;i<rows;i++)
    {
        name=ui->tableWidget->item(i,0)->text();
        age=ui->tableWidget->item(i,1)->text();
        date=ui->tableWidget->item(i,2)->text();
        type=ui->tableWidget->item(i,3)->text();
        //QDateTime current_date_time =QDateTime::currentDateTime();
        //date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
        //qDebug() <<name<<age<<date<<type;
        testerinfo.AddInfo(name,age,date,type);
    }
    testerinfo.WirteInfo();

}

void TestInfoDialog::on_pushButton_4_clicked()
{
    QTableWidgetItem * item = ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    QString name=ui->tableWidget->item(item->row(),0)->text();
    accept();
}

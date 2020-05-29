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
    int group;
    int research;
    QString name;
    QString identity;
    QString tel;
    QString department;
    QString classes;
    float weight;
    float vision;
    //msg tmp;
    TesterAddDialog testaddinfo;
    testaddinfo.exec();
    if(!testaddinfo.name.isEmpty())
    {
        group=testaddinfo.group;
        research=testaddinfo.research;
        name=testaddinfo.name;
        identity=testaddinfo.identity;
        tel = testaddinfo.tel;
        department=testaddinfo.department;
        classes=testaddinfo.classes;
        weight=testaddinfo.weight;
        vision=testaddinfo.vision;

//        QDateTime current_date_time =QDateTime::currentDateTime();
//        date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
//        //qDebug() <<name<<age<<date<<type;
        qDebug() << "addtest:" << group<<research<<name<<identity<<tel<<department<<classes<<weight<<vision;

        QString str;
        str=QString::number(group);
        int rows=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rows);
        str=QString::number(group);
        ui->tableWidget->setItem(rows,0,new QTableWidgetItem(str));
        str=QString::number(research);
        ui->tableWidget->setItem(rows,1,new QTableWidgetItem(str));
        ui->tableWidget->setItem(rows,2,new QTableWidgetItem(name));
        ui->tableWidget->setItem(rows,3,new QTableWidgetItem(identity));
        ui->tableWidget->setItem(rows,4,new QTableWidgetItem(tel));
        ui->tableWidget->setItem(rows,5,new QTableWidgetItem(department));
        ui->tableWidget->setItem(rows,6,new QTableWidgetItem(classes));
        str=QString::number(weight);
        ui->tableWidget->setItem(rows,7,new QTableWidgetItem(str));
        str=QString::number(vision);
        ui->tableWidget->setItem(rows,8,new QTableWidgetItem(str));

        testerinfo.AddInfo(group,research,name,identity,tel, department, classes,weight, vision);
        testerinfo.WirteInfo();
        ui->tableWidget->selectRow(rows);
    }

}


void TestInfoDialog::on_pushButton_3_clicked()//删除被试
{
    int i=0;
//    QString name;
//    QString age;
//    QString date;
//    QString type;
    int group;
    int research;
    QString name;
    QString identity;
    QString tel;
    QString department;
    QString classes;
    float weight;
    float vision;

    CTesterInfo testerinfo;
    testerinfo.info.clear();
    //选中删除
    QTableWidgetItem * item = ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->tableWidget->removeRow(item->row());

    int rows=ui->tableWidget->rowCount();
    for(i=0;i<rows;i++)
    {
        group=ui->tableWidget->item(i,0)->text().toInt();
        research=ui->tableWidget->item(i,1)->text().toInt();
        name=ui->tableWidget->item(i,2)->text();
        identity=ui->tableWidget->item(i,3)->text();
        tel=ui->tableWidget->item(i,4)->text();
        department=ui->tableWidget->item(i,5)->text();
        classes=ui->tableWidget->item(i,6)->text();
        weight=ui->tableWidget->item(i,7)->text().toFloat();
        vision=ui->tableWidget->item(i,8)->text().toFloat();

        //qDebug() <<name<<age<<date<<type;
        testerinfo.AddInfo(group,research,name,identity,
                           tel, department, classes,weight, vision);
    }
    testerinfo.WirteInfo();
}

void TestInfoDialog::infoinit()//初始化
{
    CTesterInfo testerinfo;
    testerinfo.ReadInfo();
    int group;
    int research;
    QString name;
    QString identity;
    QString tel;
    QString department;
    QString classes;
    float weight;
    float vision;

    for(int i=0;i<testerinfo.info.size();i++)
    {
        group=testerinfo.info.at(i).group;
        research=testerinfo.info.at(i).research;
        name=testerinfo.info.at(i).name;
        identity=testerinfo.info.at(i).identity;
        tel=testerinfo.info.at(i).tel;
        department=testerinfo.info.at(i).department;
        classes=testerinfo.info.at(i).classes;
        weight=testerinfo.info.at(i).weight;
        vision=testerinfo.info.at(i).vision;

//        age=QString::number(testerinfo.info.at(i).age);
//        date=testerinfo.info.at(i).date;
//        type=testerinfo.info.at(i).type;
        QString str;
        ui->tableWidget->insertRow(i);
        str=QString::number(group);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(str));
        str=QString::number(research);
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(str));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(identity));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(tel));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(department));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(classes));
        str=QString::number(weight);
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(str));
        str=QString::number(vision);
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(str));
    }
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//表格列自适应窗口，避免右边出现一大块空白
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //整行选中的方式
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //禁止修改
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置为可以选中单个
}

void TestInfoDialog::on_pushButton_2_clicked()//修改
{
    int i=0;
    int group;
    int research;
    QString name;
    QString identity;
    QString tel;
    QString department;
    QString classes;
    float weight;
    float vision;

    CTesterInfo testerinfo;
    testerinfo.info.clear();

    int rows=ui->tableWidget->rowCount();
    for(i=0;i<rows;i++)
    {
        group=ui->tableWidget->item(i,0)->text().toInt();
        research=ui->tableWidget->item(i,1)->text().toInt();
        name=ui->tableWidget->item(i,2)->text();
        identity=ui->tableWidget->item(i,3)->text();
        tel=ui->tableWidget->item(i,4)->text();
        department=ui->tableWidget->item(i,5)->text();
        classes=ui->tableWidget->item(i,6)->text();
        weight=ui->tableWidget->item(i,7)->text().toFloat();
        vision=ui->tableWidget->item(i,8)->text().toFloat();

        //QDateTime current_date_time =QDateTime::currentDateTime();
        //date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
        //qDebug() <<name<<age<<date<<type;
        testerinfo.AddInfo(group,research,name,identity,
                           tel, department, classes,weight, vision);
    }
    testerinfo.WirteInfo();

}

void TestInfoDialog::on_pushButton_4_clicked()//确定按钮
{
    QTableWidgetItem * item = ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    testername=ui->tableWidget->item(item->row(),2)->text();
    accept();

}

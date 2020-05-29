#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testinfodialog.h"
#include "qdebug.h"
#include "QCoreApplication"
#include "logindialog.h"
#include "registerdialog.h"
#include "managedialog.h"
#include "managedata.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    process1=new QProcess;
    process2=new QProcess;
    process3=new QProcess;
    process4=new QProcess;


    ui->setupUi(this);
    setWindowState(Qt::WindowMaximized);
    ui->pushButton_2->hide();
    ui->pushButton_8->setFlat(true);
    ui->pushButton_9->setFlat(true);
}

MainWindow::~MainWindow()
{
    if(process1||process2||process3||process4)
    {
         process1->close();
         process2->close();
         process3->close();
         process4->close();

    }
    delete process1;
    delete process2;
    delete process3;
    delete process4;
    delete ui;
}


void MainWindow::on_pushButton_clicked()//被试选择
{
    TestInfoDialog testinfo;
    testinfo.exec();
    ui->lineEdit->setText(testinfo.testername);
}

void MainWindow::on_pushButton_4_clicked()//手眼协调
{
    ManageData managedate;
    QList<QString> app_path;
    app_path=managedate.getAppPath();
    process1->start(app_path[0]);
}

void MainWindow::on_pushButton_5_clicked()//插针
{
    ManageData managedate;
    QList<QString> app_path;
    app_path=managedate.getAppPath();
    process2->start(app_path[1]);
    //process2->start("F:/QTproject/小游戏/插针/StickPinGame.exe");
}

void MainWindow::on_pushButton_6_clicked()//翻牌
{
    ManageData managedate;
    QList<QString> app_path;
    app_path=managedate.getAppPath();
    process3->start(app_path[2]);
    //process3->start("F:/QTproject/小游戏/翻牌/记忆.exe");
}

void MainWindow::on_pushButton_7_clicked()//声音匹配
{
    ManageData managedate;
    QList<QString> app_path;
    app_path=managedate.getAppPath();
    process2->start(app_path[3]);
    //process4->start("F:/QTproject/小游戏/声音匹配/FanFanLe6.exe");
}

void MainWindow::on_pushButton_8_clicked()//登录
{
    LoginDialog login;
    login.exec();
    if(login.flag==1){
        ui->pushButton_2->show();
        ui->pushButton_8->hide();
        ui->pushButton_9->hide();
    }
}

void MainWindow::on_pushButton_9_clicked()//注册
{
    RegisterDialog registerdialog;
    registerdialog.exec();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    x=ui->centralwidget->x();
    y=ui->centralwidget->y();
    w=ui->centralwidget->width();
    h=ui->centralwidget->height();
    //qDebug()<<x << y<< w<<  h;
    ui->pushButton_8->setGeometry(w+x-120,y+10,40,30);
    ui->pushButton_9->setGeometry(w+x-60,y+10,40,30);
}

void MainWindow::on_pushButton_2_clicked()//管理页
{
    manageDialog manage;
    manage.exec();
}

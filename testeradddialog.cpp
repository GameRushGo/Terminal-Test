#include "testeradddialog.h"
#include "ui_testeradddialog.h"
#include "testinfodialog.h"
#include "qdebug.h"

TesterAddDialog::TesterAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TesterAddDialog)
{
    ui->setupUi(this);
}

TesterAddDialog::~TesterAddDialog()
{
    delete ui;
}

void TesterAddDialog::on_buttonBox_accepted()
{
    //将输在对话框中的信息保存到变量中，然后再父界面通过变量获取
    group = ui->lineEdit->text().toUInt();
    research = ui->lineEdit_2->text().toUInt();
    name = ui->lineEdit_3->text();
    identity = ui->lineEdit_4->text();
    tel = ui->lineEdit_5->text();
    department = ui->lineEdit_6->text();
    classes = ui->lineEdit_7->text();
    weight = ui->lineEdit_8->text().toFloat();
    vision = ui->lineEdit_9->text().toFloat();
    //qDebug()<<group<<research<<name<<identity<<tel<<department<<classes<<weight<<vision;
    accept();
}

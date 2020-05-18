#include "testeradddialog.h"
#include "ui_testeradddialog.h"
#include "testinfodialog.h"

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
    name = ui->lineEdit->text();
    age = ui->lineEdit_2->text();
    type = ui->lineEdit_3->text();
    accept();
}

#ifndef TESTINFODIALOG_H
#define TESTINFODIALOG_H

#include <QDialog>

namespace Ui {
class TestInfoDialog;
}

class TestInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestInfoDialog(QWidget *parent = nullptr);
    ~TestInfoDialog();
    void infoinit();
    void infoupdate();
    QString testername;
private slots:
    void on_pushButton_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

public:
    Ui::TestInfoDialog *ui;
};

#endif // TESTINFODIALOG_H

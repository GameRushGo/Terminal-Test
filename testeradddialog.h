#ifndef TESTERADDDIALOG_H
#define TESTERADDDIALOG_H

#include <QDialog>

namespace Ui {
class TesterAddDialog;
}

class TesterAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TesterAddDialog(QWidget *parent = nullptr);
    ~TesterAddDialog();
    QString name ;
    QString age;
    QString type;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TesterAddDialog *ui;
};

#endif // TESTERADDDIALOG_H

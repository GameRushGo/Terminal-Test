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
    int group;
    int research;
    QString name;
    QString identity;
    QString tel;
    QString department;
    QString classes;
    float weight;
    float vision;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TesterAddDialog *ui;
};

#endif // TESTERADDDIALOG_H

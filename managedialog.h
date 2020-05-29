#ifndef MANAGEDIALOG_H
#define MANAGEDIALOG_H

#include <QDialog>

namespace Ui {
class manageDialog;
}

class manageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit manageDialog(QWidget *parent = nullptr);
    ~manageDialog();
    QList<QString> app_path;

private slots:
    void on_pushButton_clicked();

private:
    Ui::manageDialog *ui;
};

#endif // MANAGEDIALOG_H

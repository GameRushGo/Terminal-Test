/********************************************************************************
** Form generated from reading UI file 'testeradddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTERADDDIALOG_H
#define UI_TESTERADDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TesterAddDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *TesterAddDialog)
    {
        if (TesterAddDialog->objectName().isEmpty())
            TesterAddDialog->setObjectName(QString::fromUtf8("TesterAddDialog"));
        TesterAddDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(TesterAddDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-80, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(TesterAddDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 110, 177, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        layoutWidget_2 = new QWidget(TesterAddDialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 150, 177, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(layoutWidget_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);

        layoutWidget1 = new QWidget(TesterAddDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 70, 177, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(layoutWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(TesterAddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TesterAddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TesterAddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TesterAddDialog);
    } // setupUi

    void retranslateUi(QDialog *TesterAddDialog)
    {
        TesterAddDialog->setWindowTitle(QCoreApplication::translate("TesterAddDialog", "\346\226\260\345\242\236\350\242\253\350\257\225", nullptr));
        label_2->setText(QCoreApplication::translate("TesterAddDialog", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("TesterAddDialog", "\347\261\273\345\236\213\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("TesterAddDialog", "\345\247\223\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TesterAddDialog: public Ui_TesterAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTERADDDIALOG_H

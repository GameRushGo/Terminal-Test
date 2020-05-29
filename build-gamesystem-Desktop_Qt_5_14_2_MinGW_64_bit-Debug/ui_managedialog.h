/********************************************************************************
** Form generated from reading UI file 'managedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEDIALOG_H
#define UI_MANAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_manageDialog
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *manageDialog)
    {
        if (manageDialog->objectName().isEmpty())
            manageDialog->setObjectName(QString::fromUtf8("manageDialog"));
        manageDialog->resize(571, 335);
        groupBox = new QGroupBox(manageDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 521, 231));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 461, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        widget1 = new QWidget(groupBox);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 70, 461, 22));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        widget2 = new QWidget(groupBox);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(20, 110, 461, 22));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(widget2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);

        widget3 = new QWidget(groupBox);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(20, 150, 461, 22));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_4 = new QLineEdit(widget3);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 200, 171, 16));
        pushButton = new QPushButton(manageDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 280, 75, 23));

        retranslateUi(manageDialog);

        QMetaObject::connectSlotsByName(manageDialog);
    } // setupUi

    void retranslateUi(QDialog *manageDialog)
    {
        manageDialog->setWindowTitle(QCoreApplication::translate("manageDialog", "\346\270\270\346\210\217\350\267\257\345\276\204\347\256\241\347\220\206", nullptr));
        groupBox->setTitle(QCoreApplication::translate("manageDialog", "\346\270\270\346\210\217\350\267\257\345\276\204\347\256\241\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("manageDialog", "\346\211\213\347\234\274\345\215\217\350\260\203\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("manageDialog", "\346\217\222    \351\222\210\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("manageDialog", "\347\277\273    \347\211\214\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("manageDialog", "\345\243\260\351\237\263\345\214\271\351\205\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("manageDialog", "\346\263\250\346\204\217\357\274\214\347\233\256\345\275\225\344\271\213\351\227\264\347\224\250\342\200\234/\342\200\235\351\232\224\345\274\200", nullptr));
        pushButton->setText(QCoreApplication::translate("manageDialog", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manageDialog: public Ui_manageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEDIALOG_H

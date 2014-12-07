/********************************************************************************
** Form generated from reading UI file 'account_window.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_WINDOW_H
#define UI_ACCOUNT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AccountWindow
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *AccountWindow)
    {
        if (AccountWindow->objectName().isEmpty())
            AccountWindow->setObjectName(QStringLiteral("AccountWindow"));
        AccountWindow->setEnabled(true);
        AccountWindow->resize(400, 300);
        pushButton = new QPushButton(AccountWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 240, 91, 51));
        QFont font;
        font.setFamily(QStringLiteral("Code Pro Light LC"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setAutoDefault(false);
        pushButton->setDefault(true);
        lineEdit = new QLineEdit(AccountWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 60, 281, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("Code Pro Light LC"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lineEdit->setFont(font1);
        lineEdit_2 = new QLineEdit(AccountWindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(60, 120, 281, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Code Pro Light LC"));
        font2.setPointSize(20);
        lineEdit_2->setFont(font2);
        lineEdit_3 = new QLineEdit(AccountWindow);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(60, 180, 281, 51));
        lineEdit_3->setFont(font2);
        pushButton_2 = new QPushButton(AccountWindow);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 240, 101, 31));
        pushButton_3 = new QPushButton(AccountWindow);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(290, 240, 101, 31));
        pushButton->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        pushButton_2->raise();
        pushButton_3->raise();

        retranslateUi(AccountWindow);

        QMetaObject::connectSlotsByName(AccountWindow);
    } // setupUi

    void retranslateUi(QDialog *AccountWindow)
    {
        AccountWindow->setWindowTitle(QApplication::translate("AccountWindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("AccountWindow", "OK", 0));
        pushButton_2->setText(QApplication::translate("AccountWindow", "Registration", 0));
        pushButton_3->setText(QApplication::translate("AccountWindow", "Login", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountWindow: public Ui_AccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_WINDOW_H

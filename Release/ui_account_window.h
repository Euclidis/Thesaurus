/********************************************************************************
** Form generated from reading UI file 'account_window.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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

QT_BEGIN_NAMESPACE

class Ui_AccountWindow
{
public:

    void setupUi(QDialog *AccountWindow)
    {
        if (AccountWindow->objectName().isEmpty())
            AccountWindow->setObjectName(QStringLiteral("AccountWindow"));
        AccountWindow->resize(400, 300);

        retranslateUi(AccountWindow);

        QMetaObject::connectSlotsByName(AccountWindow);
    } // setupUi

    void retranslateUi(QDialog *AccountWindow)
    {
        AccountWindow->setWindowTitle(QApplication::translate("AccountWindow", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class AccountWindow: public Ui_AccountWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_WINDOW_H

/********************************************************************************
** Form generated from reading UI file 'base_window.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASE_WINDOW_H
#define UI_BASE_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_BaseWindow
{
public:

    void setupUi(QDialog *BaseWindow)
    {
        if (BaseWindow->objectName().isEmpty())
            BaseWindow->setObjectName(QStringLiteral("BaseWindow"));
        BaseWindow->resize(400, 300);

        retranslateUi(BaseWindow);

        QMetaObject::connectSlotsByName(BaseWindow);
    } // setupUi

    void retranslateUi(QDialog *BaseWindow)
    {
        BaseWindow->setWindowTitle(QApplication::translate("BaseWindow", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class BaseWindow: public Ui_BaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASE_WINDOW_H

#ifndef EXCEPTIONWINDOW_H
#define EXCEPTIONWINDOW_H

#include "../basewindow.h"
//#include <QDialog>

namespace Ui {
class ExceptionWindow;
}

class ExceptionWindow : public BaseWindow //QDialog
{
    Q_OBJECT

public:
    explicit ExceptionWindow(QString, QWidget *parent = 0);
    ~ExceptionWindow();

private:
    Ui::ExceptionWindow *ui;

private slots:
    void OK_Click();
};

#endif // EXCEPTIONWINDOW_H

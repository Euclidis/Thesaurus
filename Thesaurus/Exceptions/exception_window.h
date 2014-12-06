#ifndef EXCEPTION_WINDOW_H
#define EXCEPTION_WINDOW_H

#include "../general.h"

namespace Ui {
class ExceptionWindow;
}

class ExceptionWindow : public BaseWindow
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

#endif // EXCEPTION_WINDOW_H

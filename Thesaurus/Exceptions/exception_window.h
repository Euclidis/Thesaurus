#ifndef EXCEPTION_WINDOW_H
#define EXCEPTION_WINDOW_H

#include "../Windows/mesokcancel.h"

namespace Ui {
class ExceptionWindow;
}

class ExceptionWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit ExceptionWindow(QString str);
    ~ExceptionWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ExceptionWindow *ui;
};

#endif // EXCEPTION_WINDOW_H

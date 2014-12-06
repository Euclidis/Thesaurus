#ifndef BASE_WINDOW_H
#define BASE_WINDOW_H

#include <QDialog>

namespace Ui {
class BaseWindow;
}

class BaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

private:
    Ui::BaseWindow *ui;
};

#endif // BASE_WINDOW_H

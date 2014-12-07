#ifndef ACCOUNT_WINDOW_H
#define ACCOUNT_WINDOW_H

#include <QDialog>

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AccountWindow(QWidget *parent = 0);
    ~AccountWindow();

private:
    Ui::AccountWindow *ui;
};

#endif // ACCOUNT_WINDOW_H

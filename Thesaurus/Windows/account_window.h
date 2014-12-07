#ifndef ACCOUNT_WINDOW_H
#define ACCOUNT_WINDOW_H

#include "../carcass.h"

namespace Ui {
class AccountWindow;
}

class AccountWindow : public BaseWindow
{
    Q_OBJECT
public:
    Carcass * carcass;
public:
    explicit AccountWindow(Carcass*);
    ~AccountWindow();

private:
    Ui::AccountWindow *ui;
};

#endif // ACCOUNT_WINDOW_H

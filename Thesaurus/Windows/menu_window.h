#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif

namespace Ui {
class MenuWindow;
}

class MenuWindow : public BaseWindow
{
    Q_OBJECT
public:
    Carcass * carcass;
public:
    explicit MenuWindow(Carcass * _carcass);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;
};

#endif // MENU_WINDOW_H

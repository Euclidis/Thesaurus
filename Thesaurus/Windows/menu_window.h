#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include "../Implementation/menu_abstraction.h"

namespace Ui {
class MenuWindow;
}

class MenuWindow : public BaseWindow, public MenuAbstraction
{
    Q_OBJECT
public:
    explicit MenuWindow(Carcass * _carcass);
    ~MenuWindow();

private:
    Ui::MenuWindow *ui;
    void AccountChange();
    void LearnDirChange();
    void BoxFilling();
    void CreateNewCheckBox(QString str);
signals:
    void WWW_close();
    void LSW_open();
public slots:
    void slot_for_LSW();
};

#endif // MENU_WINDOW_H

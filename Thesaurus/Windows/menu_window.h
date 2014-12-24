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
    Carcass* carcass;
    ~MenuWindow();
public:
    explicit MenuWindow(Carcass * _carcass);

private:
    Ui::MenuWindow *ui;
    void SetAccount();
    void SetDictionaries();
    void BoxFilling();
    void CreateNewCheckBox(QString str);
signals:
    void WWW_open();
    void WWW_close();
    void LSW_open();
public slots:
    void slot_for_LSW();
private slots:
    void on_pushButton_clicked();
};

#endif // MENU_WINDOW_H

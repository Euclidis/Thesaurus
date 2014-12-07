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
    explicit AccountWindow(Carcass*, bool mode = 0);
    ~AccountWindow();
void retranslateUI();


private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void Login();

    void on_pushButton_clicked();

private:
    //void GetUsers();                //заполняет мэп именами и паролями
   //QMap <QString, QString> User;   //имена и пароли пользователей
    Ui::AccountWindow *ui;

};

#endif // ACCOUNT_WINDOW_H

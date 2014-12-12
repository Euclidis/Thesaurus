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

    void on_lineEdit_returnPressed();
    void on_lineEdit_2_returnPressed();
    void on_lineEdit_3_returnPressed();

    void on_lineEdit_textChanged();

    void on_label_clicked();

    void on_OK_Button_clicked();

    void on_LogReg_Button_clicked();

    void on_OK_Button_mouseEnter();

    void on_OK_Button_mouseLeave();

    void on_LogReg_Button_mouseEnter();

    void on_LogReg_Button_mouseLeave();

private:
    void Login();
    bool mode_flag;
    QString UserName;
    QMap <QString, QString> name_pass;             //имена и пароли пользователей
    Ui::AccountWindow *ui;

};

#endif // ACCOUNT_WINDOW_H

#ifndef ACCOUNT_WINDOW_H
#define ACCOUNT_WINDOW_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif
#include "reset_pass_window.h"


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
    void closeEvent(QCloseEvent * close_ev);
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
    void change_timer_flag();

private:
    void Registration();
    void Login();
    bool mode_flag;
    void Login_Anim();
    void Regis_Anim();
    bool is_User_Name_exists_here();
    void InstallFont();

    void RPW_open(QMap<QString, QString> &);
    QString UserName;
    QMap <QString, QString> name_pass;  //имена и пароли пользователей
    QPropertyAnimation *lineedit_anim;
    QPropertyAnimation *lineedit_2_anim;
    QPropertyAnimation *lineedit_3_anim;
    QPropertyAnimation *OK_Butt_anim;
    QTimer *timer_for_anim;
    bool timer_flag = 1;

    ResetPassWindow *RPW = nullptr;
    Ui::AccountWindow *ui;



signals:
    void LSW_open();
    void MW_open();
};

#endif // ACCOUNT_WINDOW_H

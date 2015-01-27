#ifndef ACCOUNT_WINDOW_H
#define ACCOUNT_WINDOW_H

#ifndef ABSTRACTION_AW_H
#include "abstraction_aw.h"
#endif
#include "reset_pass_window.h"


namespace Ui {
class AccountWindow;
}

class AccountWindow : public BaseWindow, public Abstraction_AW
{
    Q_OBJECT
public:
    explicit AccountWindow(Data* _data, bool _mode = 0);
    ~AccountWindow();

private:
    bool flag_anim_finished = true;
    ResetPassWindow *RPW = nullptr;
    QPropertyAnimation *anim_lineedit;
    QPropertyAnimation *anim_lineedit_2;
    QPropertyAnimation *anim_lineedit_3;
    QPropertyAnimation *anim_OK_Butt;

    Ui::AccountWindow *ui;

private:
    virtual void InstallConnect();
    virtual void InstallTexts();
    virtual void InstallFocusWidget();
    virtual void InstallColor();
    virtual void InstallImages();
    virtual void InstallAnimation();

    void Configuration_Registration();
    void Configuration_Login();
    void Login_Anim();
    void Regis_Anim();

    void ColorManagementText();


private slots:
    void SwitchConfiguration();

    void on_lineEdit_returnPressed();
    void on_lineEdit_2_returnPressed();
    void on_lineEdit_3_returnPressed();

    void on_lineEdit_textChanged();
    void OK_Click();
    void OK_Butt_anim_finished();

    void RPW_open_slot();
signals:
    void LSW_open_signal();
    void MW_open_signal();
};

#endif // ACCOUNT_WINDOW_H

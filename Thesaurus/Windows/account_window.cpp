#include "account_window.h"
#include "ui_account_window.h"


//--------------------------------------------------------
//1) Каркасс проверяет, какой пользователь был последним и оставил ли он флаг автовхода
//  а) если да, то запустить окно основного меню, вызывающее запись слов для данного пользователя
//  б) если полбзователь был, а флаг не оставил, то запустить окно логина
//  в) если пользователя небыло, до запустить окно регистрации
//--------------------------------------------------------
void AccountWindow::Login(){
  ui->pushButton_3->hide();
  ui->pushButton_2->show();
  ui->lineEdit_3->hide();

}
void AccountWindow::retranslateUI(){}

//mode 1 - Login
//mode 0 - Registration
AccountWindow::AccountWindow(Carcass* _carcass, bool mode) :
    ui(new Ui::AccountWindow)
{
    ui->setupUi(this);
    carcass = _carcass;
    setFixedSize(400,300);

    if (mode)
    Login();





    retranslateUI();


}

AccountWindow::~AccountWindow()
{
    delete ui;
}

//REGISTRATION
void AccountWindow::on_pushButton_2_clicked()
{
    ui->pushButton_2->hide();
    ui->pushButton_3->show();
    ui->lineEdit_3->show();
}

//LOGIN
void AccountWindow::on_pushButton_3_clicked()
{
    Login();
}

//Enter
void AccountWindow::on_pushButton_clicked()
{





}

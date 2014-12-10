#include "account_window.h"
#include "ui_account_window.h"
#include "../adress_texts.h"


//--------------------------------------------------------
//1) Каркасс проверяет, какой пользователь был последним и оставил ли он флаг автовхода
//  а) если да, то запустить окно основного меню, вызывающее запись слов для данного пользователя
//  б) если полбзователь был, а флаг не оставил, то запустить окно логина
//  в) если пользователя небыло, до запустить окно регистрации
//--------------------------------------------------------
void AccountWindow::Login(){
  mode_flag = true;
  ui->pushButton_3->hide();
  ui->pushButton_2->show();
  ui->lineEdit_3->hide();
  ui->label->hide();



}
void AccountWindow::retranslateUI(){}


//mode 1 - Login
//mode 0 - Registration
AccountWindow::AccountWindow(Carcass* _carcass, bool mode) :
    ui(new Ui::AccountWindow)
{

    ui->setupUi(this);
    carcass = _carcass;
    //--------------------------------------------------------//
    //Допустимые Символы Имении Пароля
    //--------------------------------------------------------//
    ui->lineEdit->setPlaceholderText("user name");
    ui->lineEdit_2->setPlaceholderText("password");
    ui->lineEdit_3->setPlaceholderText("confirm password");
    QRegExp regexp ("[A-Za-z-_0-9]{1,20}");
    QValidator *validator = new QRegExpValidator(regexp, this);
    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    //-------------------------------------------------------

    setFixedSize(400,300);
    mode_flag = mode;
    ui->label->hide();
    if (mode_flag)
    Login();
    GetUsers();
    retranslateUI();


}

AccountWindow::~AccountWindow()
{
    delete ui;
}

//REGISTRATION
void AccountWindow::on_pushButton_2_clicked()
{
    mode_flag = false;
    ui->label->hide();
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

if (mode_flag){
    //
    // LOGIN BLOCK
    //



  }
else if (ui->lineEdit_2->text() == ui->lineEdit_3->text()){
    //REGISTRATION BLOCK
    //
    //

  name_pass.insert(ui->lineEdit->text(), ui->lineEdit_2->text());
  //
  //
  //
  // ЗАПИСЬ В ФАЙЛ
  QFile f(carcass->adr.User);
try
{

   if (f.open(QIODevice::WriteOnly)){

            QDataStream in(&f);
            in << name_pass;
            f.close();
          }
        else throw ex_file_not_open(carcass->adr.User);


}

catch(ex_file_not_open& ex){ex.show();}
  }
//несовпадает пароль
 else {
  ui->label->setText("Passwords do not match");
  ui->label->show();
  ui->lineEdit_2->setFocus();
  }


  //delete (this);



}

void AccountWindow::GetUsers(){

  QFile f(carcass->adr.User);

  try
  {

    if (!f.exists()) throw ex_file_not_found(carcass->adr.User);
    else if (f.open(QIODevice::ReadOnly)){


              QDataStream out(&f);
              out >> name_pass;
              f.close();
            }
          else throw ex_file_not_open(carcass->adr.User);


  }
  catch(ex_file_not_found& ex){ex.show();}
  catch(ex_file_not_open& ex){ex.show();}

}


//----------------------------------------------------------------
// скрывает окошко ошибки при изменении пароля
void AccountWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->label->hide();

}

void AccountWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    ui->label->hide();
}
//---------------------------------------------------------------
// прыжки по объектам используя Ентер
void AccountWindow::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
}

void AccountWindow::on_lineEdit_2_returnPressed()
{
  if (mode_flag == 0) // Registration
    ui->lineEdit_3->setFocus();
        else if (mode_flag == 1)
    on_pushButton_clicked();
}

void AccountWindow::on_lineEdit_3_returnPressed()
{
     on_pushButton_clicked();
}

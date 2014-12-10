#include "account_window.h"
#include "ui_account_window.h"


//--------------------------------------------------------
//1) Каркасс проверяет, какой пользователь был последним и оставил ли он флаг автовхода
//  а) если да, то запустить окно основного меню, вызывающее запись слов для данного пользователя
//  б) если полбзователь был, а флаг не оставил, то запустить окно логина
//  в) если пользователя небыло, до запустить окно регистрации
//--------------------------------------------------------
void AccountWindow::Login(){
  mode_flag = true;
  this->setWindowTitle(tr("Login"));
  ui->pushButton_3->hide();
  ui->pushButton_2->show();
  ui->lineEdit_3->hide();
  QPalette *palette = new QPalette();
  palette->setColor(QPalette::Text,Qt::black);
  ui->lineEdit->setPalette(*palette);
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
    ui->lineEdit->setPlaceholderText(tr("User name"));
    ui->lineEdit_2->setPlaceholderText(tr("Password"));
    ui->lineEdit_3->setPlaceholderText(tr("Confirm password"));
    QRegExp validUserName ("[A-Za-z-_0-9]{1,20}");
    QRegExp validUserPass ("[A-Za-z-_0-9]{0,20}");
    QValidator *validUN = new QRegExpValidator(validUserName, this);
    QValidator *validUP = new QRegExpValidator(validUserPass, this);
    ui->lineEdit->setValidator(validUN);
    ui->lineEdit_2->setValidator(validUP);
    ui->lineEdit_3->setValidator(validUP);
    //----------------READ FILE----------------------------
    if (carcass->ReadFile(carcass->adr.User, name_pass) != Carcass::ReadResult::OK){
        QString mess = tr("Problems reading file ") + carcass->adr.User + tr("\nProgramm will shutdown");
        carcass->message(mess);
        close();
      }
    //-------------------------------------------------------
    setFixedSize(400,300);
    mode_flag = mode;
    if (mode_flag)
    Login();
    else this->setWindowTitle(tr("Registration"));
    retranslateUI();
    ui->lineEdit->setFocus();
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

//REGISTRATION
void AccountWindow::on_pushButton_2_clicked()
{
    mode_flag = false;
    this->setWindowTitle(tr("Registration"));
    ui->pushButton_2->hide();
    ui->pushButton_3->show();
    ui->lineEdit_3->show();
 //setTextColor
    if (name_pass.contains(ui->lineEdit->text()))
{
      QPalette *palette = new QPalette();
      palette->setColor(QPalette::Text,Qt::red);
      ui->lineEdit->setPalette(*palette);
}
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

//=========================================================================================
// LOGIN BLOCK

    if (name_pass.contains(ui->lineEdit->text())){
        if (name_pass[ui->lineEdit->text()] == ui->lineEdit_2->text()){
              carcass->current_account = ui->lineEdit->text();
            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-START--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
              carcass->WWW = new WriteWordsWindow;
              carcass->WWW->show();
            //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-END--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                close();}
        else {
              carcass->message(tr("Incorrect Password"));
              ui->lineEdit_2->setFocus();
              }
         }
    else {
         carcass->message(tr("User is not found"));
         ui->lineEdit->setFocus();
      }
  }
//=========================================================================================
//REGISTRATION BLOCK

else if (name_pass.contains(ui->lineEdit->text())){
    carcass->message(tr("This user name is already in use"));
    ui->lineEdit->setFocus();
  }
else if (ui->lineEdit->text() == ""){

    carcass->message(tr("The user name must contain at least one character"));
    ui->lineEdit_2->setFocus();

  }
else if (ui->lineEdit_2->text() == ui->lineEdit_3->text()){

  name_pass.insert(ui->lineEdit->text(), ui->lineEdit_2->text());
  carcass->current_account = ui->lineEdit->text();
  carcass->WriteFile(carcass->adr.User, name_pass);

  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-START--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  carcass->WWW = new WriteWordsWindow;
  carcass->WWW->show();
  close();
  }
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-END--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//несовпадает пароль
 else {

  carcass->message(tr("Passwords is not match"));
  ui->lineEdit_2->setFocus();
  }
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

void AccountWindow::on_lineEdit_textChanged()
{
  //---------------------Изменение жирности шрифта при вводе имени юзера
  if (ui->lineEdit->text() != ""){
      QFont font(ui->lineEdit->font().family(), 18);
      font.setBold(1);
      ui->lineEdit->setFont(font);
    }
  else {
      QFont font(ui->lineEdit->font().family(), 18);
      font.setBold(0);
      ui->lineEdit->setFont(font);

    }
  //---------------------Изменение жирности шрифта при вводе имени юзера

  //----------------------Цвет текста меняется на красный, если пользователь при регистрации вводит имя, существующее в базе
  if (!mode_flag){
      if (name_pass.contains(ui->lineEdit->text()))
{
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Text,Qt::red);
        ui->lineEdit->setPalette(*palette);
 }
      else {
          QPalette *palette = new QPalette();
          palette->setColor(QPalette::Text,Qt::black);
          ui->lineEdit->setPalette(*palette);
  }
    }

}

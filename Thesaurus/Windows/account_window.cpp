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
  ui->LogReg_Button->setText(tr("Registration"));
  ui->lineEdit_3->hide();
  QPalette *palette = new QPalette();
  palette->setColor(QPalette::Text,Qt::black);
  ui->lineEdit->setPalette(*palette);
  ui->lineEdit->move(ui->lineEdit->x(), ui->lineEdit->y()+20);
  ui->lineEdit_2->move(ui->lineEdit_2->x(), ui->lineEdit_2->y()+20);
  ui->lineEdit_3->move(ui->lineEdit_3->x(), ui->lineEdit_3->y()+20);
  ui->OK_Button->move(ui->OK_Button->x(), ui->OK_Button->y()-20);
}
void AccountWindow::Registration(){
  mode_flag = false;
  this->setWindowTitle(tr("Registration"));
  ui->LogReg_Button->setText(tr("Login"));
  ui->lineEdit_3->show();

//setTextColor
  if (name_pass.contains(UserName))
{
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Text,Qt::red);
    ui->lineEdit->setPalette(*palette);
}
  ui->lineEdit->move(ui->lineEdit->x(), ui->lineEdit->y()-20);
  ui->lineEdit_2->move(ui->lineEdit_2->x(), ui->lineEdit_2->y()-20);
  ui->lineEdit_3->move(ui->lineEdit_3->x(), ui->lineEdit_3->y()-20);
  ui->OK_Button->move(ui->OK_Button->x(), ui->OK_Button->y()+20);
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
        this->deleteLater();

      }
    //-------------------------------------------------------
    setFixedSize(400,300);
    //-------------------------------------------------------
    //Background color
    QPalette p = this->palette();
    QColor backgrColor( 165, 104, 178, 255);
    p.setColor(this->backgroundRole(), backgrColor);
    this->setPalette(p);
    //this->setStyleSheet("background-image: url(data/space2.png)");
    //=======================================================

    //Font Color
    QColor fontColor (255, 243, 255, 255);
    QPalette *Buttons_Color = new QPalette();
    Buttons_Color->setColor(QPalette::WindowText,fontColor);
    ui->OK_Button->setPalette(*Buttons_Color);
    ui->LogReg_Button->setPalette(*Buttons_Color);

    mode_flag = mode;
    if (mode_flag)
    Login();
    else
      Registration();
    ui->lineEdit->setFocus();
}

AccountWindow::~AccountWindow()
{
    delete ui;
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
    on_OK_Button_clicked();
}

void AccountWindow::on_lineEdit_3_returnPressed()
{
    on_OK_Button_clicked();
}

void AccountWindow::on_lineEdit_textChanged()
{

  UserName = ui->lineEdit->text().toLower();
  //---------------------Изменение жирности шрифта при вводе имени юзера
  if (UserName != ""){
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
      if (name_pass.contains(UserName))
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

void AccountWindow::on_label_clicked()
{
    ui->lineEdit->setText("CLICK");
}

void AccountWindow::on_OK_Button_clicked()
{

  if (mode_flag){

  //=========================================================================================
  // LOGIN BLOCK


      if (name_pass.contains(UserName)){
          if (name_pass[UserName] == ui->lineEdit_2->text()){
                carcass->current_account = UserName;
              //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-START--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                carcass->LSW = new LangSelectionWindow;
                carcass->LSW->show();
              //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-END--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                  close();}
          else {
                carcass->message(tr("Incorrect Password"));
                ui->lineEdit_2->setFocus();
                }
           }
      //some MAGIC
      else if (UserName.isEmpty()){

          ui->lineEdit->setFocus();
        }
      else {
           carcass->message(tr("User is not found"));

           ui->lineEdit->setFocus();
        }
    }
  //=========================================================================================
  //REGISTRATION BLOCK

  else if (name_pass.contains(UserName)){
      carcass->message(tr("This user name is already in use"));
      ui->lineEdit->setFocus();
    }
  else if (UserName == ""){

      carcass->message(tr("The user name must contain at least one character"));
      ui->lineEdit_2->setFocus();

    }
  else if (ui->lineEdit_2->text() == ui->lineEdit_3->text()){

    name_pass.insert(UserName, ui->lineEdit_2->text());
    carcass->current_account = UserName;
    carcass->WriteFile(carcass->adr.User, name_pass);
    //Загрузка конфиг-файла QMapAccounts
    carcass->QMapAccounts.insert(carcass->current_accountOS, carcass->current_account);
    carcass->conf_write();
    // create dir and files for new user
    QString path_to_User = carcass->adr.users_dir + carcass->current_account;
    QDir dir(path_to_User);
    if (!dir.exists()){

        dir.mkpath(".");
        carcass->confUser_write(carcass->current_account);
      }
    else {
        carcass->message(tr("Something is wrong!\n Programm will shutdown"));
        close();
      }

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-START--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    carcass->LSW = new LangSelectionWindow;
    carcass->LSW->show();
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



void AccountWindow::on_LogReg_Button_clicked()
{
  if (!mode_flag){
      Login();
    }
  else{

    Registration();

}
}
void AccountWindow::on_OK_Button_mouseEnter()
{
  QFont font(ui->OK_Button->font().family(), 20);
  font.setBold(1);
  ui->OK_Button->setFont(font);
}

void AccountWindow::on_OK_Button_mouseLeave()
{
  QFont font(ui->OK_Button->font().family(), 20);
  font.setBold(0);
  ui->OK_Button->setFont(font);
}

void AccountWindow::on_LogReg_Button_mouseEnter()
{
  QFont font(ui->LogReg_Button->font().family(), 11);
  font.setBold(1);
  ui->LogReg_Button->setFont(font);
}

void AccountWindow::on_LogReg_Button_mouseLeave()
{
  QFont font(ui->LogReg_Button->font().family(), 11);
  font.setBold(0);
  ui->LogReg_Button->setFont(font);
}

#include "account_window.h"
#include "ui_account_window.h"



//--------------------------------------------------------------------------------------------------
//1) Каркасс проверяет, какой пользователь был последним и оставил ли он флаг автовхода
//  а) если да, то запустить окно основного меню, вызывающее запись слов для данного пользователя
//  б) если полбзователь был, а флаг не оставил, то запустить окно логина
//  в) если пользователя небыло, до запустить окно регистрации
//--------------------------------------------------------------------------------------------------
bool AccountWindow::is_User_Name_exists_here(){

  QMap<QString, QString>::const_iterator i = name_pass.constBegin();
  QString username = UserName.toLower();
  while (i != name_pass.constEnd()){

      if (i.key().toLower() == username)
        return 1;
      i++;
    }
  return 0;
}

//Login
void AccountWindow::Login(){
  mode_flag = true;
  this->setWindowTitle(tr("Login"));
  ui->LogReg_Button->setText(tr("Registration"));

    //setTextColor
  QPalette *palette = new QPalette();
  palette->setColor(QPalette::Text,Qt::black);
  ui->lineEdit->setPalette(*palette);

    //add Animation
  Login_Anim();

}
//Registration
void AccountWindow::Registration(){
  mode_flag = false;
  this->setWindowTitle(tr("Registration"));
  ui->LogReg_Button->setText(tr("Login"));
  ui->lineEdit_3->show();

    //setTextColor
  if (is_User_Name_exists_here())
{
    QPalette *palette = new QPalette();
    palette->setColor(QPalette::Text,Qt::red);
    ui->lineEdit->setPalette(*palette);
}
    //add Animation
  Regis_Anim();
}

//Translation
void AccountWindow::retranslateUI(){}

//mode 1 = Login
//mode 0 = Registration
AccountWindow::AccountWindow(Carcass*_carcass, bool mode) :
    ui(new Ui::AccountWindow)
{
    InstallFont();
    ui->setupUi(this);
    carcass = _carcass;
    timer_for_anim = new QTimer;
    connect(timer_for_anim, SIGNAL(timeout()), this, SLOT(change_timer_flag()));

    //--------------------------------------------------------//
    //Read File-----------------------------------------------//
    //--------------------------------------------------------//
    if (carcass->ReadFile(carcass->adr.User, name_pass) != Carcass::ReadResult::OK){
        QString mess = tr("Problems reading file ") + carcass->adr.User + tr("\nProgramm will shutdown");
        carcass->message(mess);
        this->deleteLater();
      }

    //--------------------------------------------------------//
    //Style + Animation---------------------------------------//
    //--------------------------------------------------------//
    setFixedSize(400,300);

    ui->lineEdit->  setFrame(false);
    ui->lineEdit_2->setFrame(false);
    ui->lineEdit_3->setFrame(false);

    lineedit_anim   = new QPropertyAnimation(ui->lineEdit, "pos", this);
    lineedit_2_anim = new QPropertyAnimation(ui->lineEdit_2, "pos", this);
    lineedit_3_anim = new QPropertyAnimation(ui->lineEdit_3, "geometry", this);
    OK_Butt_anim    = new QPropertyAnimation(ui->OK_Button, "pos", this);

    //Background color
    QPalette p = this->palette();
    QColor backgrColor( 165, 104, 178, 255);
    p.setColor(this->backgroundRole(), backgrColor);
    this->setPalette(p);
    //ui->lineEdit_3->setStyleSheet("background-image: url(data/space2.png)")

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

    //--------------------------------------------------------//
    //Допустимые Символы Имении Пароля------------------------//
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

    //-------------------------------------------------------
    //-------------------------------------------------------
//    QMenu m;
//    QList<LangList::StrIco> i;
//    i = carcass->LanguageList->getStrIcoList();
//    m.addAction(*i.at(0).icon, *i.at(0).name);
//    m.addAction(*i.at(1).icon, *i.at(1).name);
//    m.addAction(*i.at(2).icon, *i.at(2).name);
//    m.exec(QCursor::pos());
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

//--------------------------------------------------//
// прыжки по объектам используя Ентер --------------//
//--------------------------------------------------//
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
//--------------------------------------------------//

void AccountWindow::on_lineEdit_textChanged()
{

  UserName = ui->lineEdit->text();
  //Изменение жирности шрифта при вводе имени юзера
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

  //Цвет текста меняется на красный, если пользователь при регистрации вводит имя, существующее в базе
  if (!mode_flag){
      if (is_User_Name_exists_here()){
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

void AccountWindow::RPW_open(QMap<QString, QString>& names){

  RPW = new ResetPassWindow(names, *ui->lineEdit, *carcass);
  RPW->show();
  Login();

}
void AccountWindow::on_label_clicked()
{
  if (!name_pass.isEmpty())
   RPW_open(name_pass);
  else {carcass->message(tr("No users found"));}
}
//****************************************************************************//
//************************* OK Pressed ***************************************//
//****************************************************************************//
void AccountWindow::on_OK_Button_clicked()
{

  if (mode_flag){

  //=========================================================================================
  // LOGIN BLOCK

      if (name_pass.contains(UserName)){
          if (name_pass[UserName] == ui->lineEdit_2->text()){
              if(carcass->CurAccount->Set(UserName, false)){
                  MW_open();
                  close();
              }
              else{
                  carcass->message("some problem during registration");
              }
//                carcass->LDList = new L_D_List(carcass);
//                if (carcass->LDList->LoadFromFile()){
//                  }
//              //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-STARTS--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//                if (carcass->current_learn_dir.knownL == carcass->symb.lang_empty)
//                  emit LSW_open();
//                else
//                  emit MW_open();
//              //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-ENDS--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                  }
          else {
                carcass->message(tr("Incorrect Password"));
                ui->lineEdit_2->setFocus();
                }
           }
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

  else if (is_User_Name_exists_here()){
      carcass->message(tr("This user name is already in use"));
      ui->lineEdit->setFocus();
    }
  else if (UserName.isEmpty()){
      carcass->message(tr("The user name must contain at least one character"));
      ui->lineEdit_2->setFocus();
    }
  else if (ui->lineEdit_2->text() == ui->lineEdit_3->text()){
    name_pass.insert(UserName, ui->lineEdit_2->text());

    if(carcass->CurAccount->Set(UserName, true)){
        MW_open();
        close();
    }
    else{
        carcass->message("some problem during registration");
    }
//    carcass->current_account = UserName;
//    carcass->WriteFile(carcass->adr.User, name_pass);
//    //Загрузка конфиг-файла QMapAccounts
//    carcass->QMapAccounts.insert(carcass->current_accountOS, carcass->current_account);
//    carcass->conf_write();
//    // create dir and files for new user
//    QString path_to_User = carcass->adr.users_dir + UserName.toLower();
//    QDir dir(path_to_User);
//    if (!dir.exists()){
//        dir.mkpath(".");
//        carcass->confUser_write();
//      }
//    else {
//        carcass->message(tr("Something is wrong! File ") + path_to_User + tr(" is already exists\n Programm will shutdown"));

//      }

    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-START--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    }
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<----TEST-END--->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

  //несовпадает пароль
   else {
    carcass->message(tr("Passwords is not match"));
    ui->lineEdit_2->setFocus();
    }
  }
//---------------------------------------------------------------
// Login-Registration Button clicked
void AccountWindow::on_LogReg_Button_clicked()
{
  if (timer_flag){
  this->timer_for_anim->start(520);
  timer_flag = false;
  if (!mode_flag){
      Login();
    }
  else{
    Registration();
      }
     }
}
//---------------------------------------------------------------
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
void AccountWindow::Login_Anim(){

  lineedit_anim->setDuration(500);
  lineedit_anim->setEndValue(QPoint (ui->lineEdit->pos().x(), 80));
  lineedit_anim->setEasingCurve(QEasingCurve::BezierSpline);
  lineedit_anim->start();

  lineedit_2_anim->setDuration(500);
  lineedit_2_anim->setEndValue(QPoint (ui->lineEdit->pos().x(), 140));
  lineedit_2_anim->setEasingCurve(QEasingCurve::BezierSpline);
  lineedit_2_anim->start();

  lineedit_3_anim->setDuration(500);
  lineedit_3_anim->setStartValue(QRect(60,180,281,51));
  lineedit_3_anim->setEndValue(QRect(350,320,0,0));
  lineedit_3_anim->setEasingCurve(QEasingCurve::InCubic);
  lineedit_3_anim->start();


  OK_Butt_anim->setDuration(500);
  OK_Butt_anim->setEndValue(QPoint (ui->OK_Button->pos().x(), 200));
  OK_Butt_anim->setEasingCurve(QEasingCurve::BezierSpline);
  OK_Butt_anim->start();

}
void AccountWindow::Regis_Anim(){

  lineedit_anim->setDuration(500);
  lineedit_anim->setEndValue(QPoint (ui->lineEdit->pos().x(), 60));
  lineedit_anim->setEasingCurve(QEasingCurve::InCubic);
  lineedit_anim->start();

  lineedit_2_anim->setDuration(500);
  lineedit_2_anim->setEndValue(QPoint (ui->lineEdit->pos().x(), 120));
  lineedit_2_anim->setEasingCurve(QEasingCurve::InCubic);
  lineedit_2_anim->start();

  lineedit_3_anim->setDuration(500);
  lineedit_3_anim->setStartValue(QRect(350,270,0,0));
  lineedit_3_anim->setEndValue(QRect(60,180,281,51));
  lineedit_3_anim->setEasingCurve(QEasingCurve::InCubic);
  lineedit_3_anim->start();

  OK_Butt_anim->setDuration(500);
  OK_Butt_anim->setEndValue(QPoint (ui->OK_Button->pos().x(), 240));
  OK_Butt_anim->setEasingCurve(QEasingCurve::InCubic);
  OK_Butt_anim->start();
}

void AccountWindow::InstallFont(){
  QString font;
  font = "Code Pro Light LC.otf";
  QFile res(font);
  if (res.open(QIODevice::ReadOnly) == false){
      QString mess = tr("Font file ") + font + tr(" is not found");
      carcass->message(mess);
    }
  else {
      QFontDatabase::addApplicationFontFromData(res.readAll());
    }


}

void AccountWindow::change_timer_flag(){

  timer_flag = true;
}

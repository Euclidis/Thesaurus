#include "account_window.h"
#include "ui_account_window.h"


//mode 1 = Login
//mode 0 = Registration
AccountWindow::AccountWindow(Data *_data, bool _mode) :
    ui(new Ui::AccountWindow),
    Abstraction_AW(_data, _mode)
{
    ui->setupUi(this);
    setFixedSize(331,345);
    setModal(true);

    InstallConnect();
    InstallTexts();
    InstallFocusWidget();
    InstallColor();
    InstallAnimation();
    InstallImages();

    mode_flag = !_mode;
    SwitchConfiguration();
}



// Инсталляторы
//------------------------------------------------------------------------------------------
void AccountWindow::InstallConnect()
{
    connect(ui->LogReg_Button, SIGNAL(clicked()), SLOT(SwitchConfiguration()));
    connect(ui->OK_Button, SIGNAL(clicked()), SLOT(OK_Click()));
    //RPW_open & label.click
}
//------------------------------------------------------------------------------------------
void AccountWindow::InstallFocusWidget()
{
    ui->lineEdit->setFocus();
}
//------------------------------------------------------------------------------------------
void AccountWindow::InstallTexts()
{
    ui->lineEdit->setPlaceholderText(tr("User name"));
    ui->lineEdit_2->setPlaceholderText(tr("Password"));
    ui->lineEdit_3->setPlaceholderText(tr("Confirm password"));
}
//------------------------------------------------------------------------------------------
void AccountWindow::InstallColor()
{
    ui->OK_Button->setColorScheme("3,101,100,100%", "3,101,100,80%", "255,255,255,100%", "255,255,255,100%");
    ui->LogReg_Button->setColorScheme("232,221,203,100%", "232,221,203,100%", "3,101,100,100%", "3,101,100,80%");
    ui->label->setColorScheme("232,221,203,100%", "232,221,203,100%", "3,101,100,100%", "3,101,100,80%");
    ui->label_2->setStyleSheet("QLabel {color : rgba(3,101,100,100%);}");
}
//------------------------------------------------------------------------------------------
void AccountWindow::InstallImages()
{

}
//------------------------------------------------------------------------------------------
void AccountWindow::InstallAnimation()
{
    anim_lineedit   = new QPropertyAnimation(ui->lineEdit, "pos", this);
    anim_lineedit_2 = new QPropertyAnimation(ui->lineEdit_2, "pos", this);
    anim_lineedit_3 = new QPropertyAnimation(ui->lineEdit_3, "geometry", this);
    anim_OK_Butt    = new QPropertyAnimation(ui->OK_Button, "pos", this);
    connect(anim_OK_Butt, SIGNAL(finished()), SLOT(OK_Butt_anim_finished()));
}
//------------------------------------------------------------------------------------------



// Управление конфигурациями окна
//------------------------------------------------------------------------------------------
void AccountWindow::SwitchConfiguration()
{
    if (flag_anim_finished){
        if (!mode_flag){
            Configuration_Login();
        }
        else{
            Configuration_Registration();
        }
    }
}
//------------------------------------------------------------------------------------------
void AccountWindow::Configuration_Login(){
    mode_flag = true;

    ui->LogReg_Button->setText(tr("Registration"));
    ui->lineEdit_2->setPlaceholderText("");
    ui->lineEdit_3->setPlaceholderText("");

    ColorManagementText();

    Login_Anim();
}
//------------------------------------------------------------------------------------------
void AccountWindow::Configuration_Registration(){
    mode_flag = false;

    ui->LogReg_Button->setText(tr("Login"));
    ui->lineEdit_2->setPlaceholderText("");
    ui->lineEdit_3->setPlaceholderText("");
    ui->lineEdit_3->show();

    ColorManagementText();

    Regis_Anim();
}
//------------------------------------------------------------------------------------------



// прыжки по объектам используя Ентер
//------------------------------------------------------------------------------------------
void AccountWindow::on_lineEdit_returnPressed()
{
    ui->lineEdit_2->setFocus();
}
//------------------------------------------------------------------------------------------
void AccountWindow::on_lineEdit_2_returnPressed()
{
    if (mode_flag)
        OK_Click(); // Login
    else
        ui->lineEdit_3->setFocus();
}
//------------------------------------------------------------------------------------------
void AccountWindow::on_lineEdit_3_returnPressed()
{
    OK_Click();
}
//------------------------------------------------------------------------------------------



// Методы связанные с текстовым полем для логина
//------------------------------------------------------------------------------------------
void AccountWindow::on_lineEdit_textChanged()
{
    UserName = ui->lineEdit->text();
    ColorManagementText();
}
//------------------------------------------------------------------------------------------
void AccountWindow::ColorManagementText()
{
    QPalette p(ui->lineEdit->palette());
    if (!mode_flag && dt->AccountList()->Contains(UserName)){
        p.setColor(QPalette::Text,Qt::red);
        ui->lineEdit->setPalette(p);
        return;
    }
    p.setColor(QPalette::Text,Qt::black);
    ui->lineEdit->setPalette(p);
}
//------------------------------------------------------------------------------------------



// Запуск абстрактных методов
void AccountWindow::OK_Click()
{
    if(UserName.isEmpty()) return;
    if(mode_flag){
        if(!Login(ui->lineEdit_2->text())){
            ui->lineEdit->setFocus();
            return;
        }
    }
    else{
        if(ui->lineEdit_2->text() != ui->lineEdit_3->text()){
            qDebug() << "Пароли не совпадают";
            return;
        }
        if(!Registration(ui->lineEdit_2->text())){
            ui->lineEdit->setFocus();
            return;
        }
    }
    qDebug() << "Very Good!: " << UserName;
}



// анимация
//------------------------------------------------------------------------------------------
void AccountWindow::Login_Anim(){

  anim_lineedit->setDuration(500);
  anim_lineedit->setEndValue(QPoint (ui->lineEdit->pos().x(), 120));
  anim_lineedit->setEasingCurve(QEasingCurve::BezierSpline);
  anim_lineedit->start();

  anim_lineedit_2->setDuration(500);
  anim_lineedit_2->setEndValue(QPoint (ui->lineEdit->pos().x(), 170));
  anim_lineedit_2->setEasingCurve(QEasingCurve::BezierSpline);
  anim_lineedit_2->start();

  anim_lineedit_3->setDuration(500);
  anim_lineedit_3->setStartValue(QRect(30,200,271,40));
  anim_lineedit_3->setEndValue(QRect(30,170,271,0));
  anim_lineedit_3->setEasingCurve(QEasingCurve::InCubic);
  anim_lineedit_3->start();

  anim_OK_Butt->setDuration(500);
  anim_OK_Butt->setEndValue(QPoint (ui->OK_Button->pos().x(), 230));
  anim_OK_Butt->setEasingCurve(QEasingCurve::BezierSpline);
  anim_OK_Butt->start();
}
//------------------------------------------------------------------------------------------
void AccountWindow::Regis_Anim(){

  anim_lineedit->setDuration(500);
  anim_lineedit->setEndValue(QPoint (ui->lineEdit->pos().x(), 100));
  anim_lineedit->setEasingCurve(QEasingCurve::InCubic);
  anim_lineedit->start();

  anim_lineedit_2->setDuration(500);
  anim_lineedit_2->setEndValue(QPoint (ui->lineEdit->pos().x(), 150));
  anim_lineedit_2->setEasingCurve(QEasingCurve::InCubic);
  anim_lineedit_2->start();

  anim_lineedit_3->setDuration(500);
  anim_lineedit_3->setStartValue(QRect(30,170,271,0));
  anim_lineedit_3->setEndValue(QRect(30,200,271,40));
  anim_lineedit_3->setEasingCurve(QEasingCurve::InCubic);
  anim_lineedit_3->start();

  anim_OK_Butt->setDuration(500);
  anim_OK_Butt->setEndValue(QPoint (ui->OK_Button->pos().x(), 250));
  anim_OK_Butt->setEasingCurve(QEasingCurve::InCubic);
  anim_OK_Butt->start();
}
//------------------------------------------------------------------------------------------
void AccountWindow::OK_Butt_anim_finished(){
    flag_anim_finished = true;
    ui->lineEdit_2->setPlaceholderText(tr("Password"));
    ui->lineEdit_3->setPlaceholderText(tr("Confirm password"));
    if(ui->lineEdit_3->height() == 0) ui->lineEdit_3->hide();
    if(mode_flag)
        ui->label_2->setText(tr("Login"));
    else
        ui->label_2->setText(tr("Registration"));
}
//------------------------------------------------------------------------------------------



//деструктор
//------------------------------------------------------------------------------------------
AccountWindow::~AccountWindow()
{

    delete anim_lineedit;
    delete anim_lineedit_2;
    delete anim_lineedit_3;
    delete anim_OK_Butt;

    //if (RPW != nullptr) delete RPW;

    delete ui;
}
//------------------------------------------------------------------------------------------



//void AccountWindow::RPW_open(QMap<QString, QString>& names){
//    if (name_pass.isEmpty()){
//        if (RPW == nullptr)RPW = new ResetPassWindow(names, *ui->lineEdit, *carcass);
//        RPW->show();
//        Configuration_Login();
//    }
//    else{
//        qDebug() << "No users found";
//    }
//}
//Возможно нужен exec()

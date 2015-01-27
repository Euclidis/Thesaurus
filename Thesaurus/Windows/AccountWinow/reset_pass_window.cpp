#include "reset_pass_window.h"
#include "ui_reset_pass_window.h"

ResetPassWindow::ResetPassWindow(Data *_dt, MLineEdit &qle_name, MLineEdit &qle_pas) :
  ui(new Ui::ResetPassWindow), QLE_name(qle_name), QLE_password(qle_pas), dt(_dt)
{
  ui->setupUi(this);
  setModal(true);
  Connector();

  ui->lineEdit->setPlaceholderText("New Password");

  for (int i = 0; i < dt->AccountList()->size(); ++i){
      ui->comboBox->addItem(dt->AccountList()->at(i)->name);
  }
  if(!qle_name.text().isEmpty()){
      if(ui->comboBox->findText(qle_name.text()) > -1) ui->comboBox->setEditText(qle_name.text());
  }
}
//--------------------------------------------------------------------------------------------
void ResetPassWindow::Connector()
{
    connect(ui->label_3, SIGNAL(clicked()), SLOT(AnswerAccepted()));
    connect(ui->label_4, SIGNAL(clicked()), SLOT(AnswerRejected()));
}
//--------------------------------------------------------------------------------------------
void ResetPassWindow::AnswerAccepted()
{
    dt->AccountList()->SelectItem(ui->comboBox->currentText());
    dt->AccountList()->SelectionItem()->SetPassword(ui->lineEdit->text());
    QLE_name.setText(ui->comboBox->currentText());
    QLE_password.setText(ui->lineEdit->text());
    this->close();
}
//--------------------------------------------------------------------------------------------
void ResetPassWindow::AnswerRejected()
{
    this->close();
}
//--------------------------------------------------------------------------------------------
ResetPassWindow::~ResetPassWindow()
{
    delete ui;
}


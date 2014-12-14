#include "reset_pass_window.h"
#include "ui_reset_pass_window.h"

ResetPassWindow::ResetPassWindow() :
  ui(new Ui::ResetPassWindow)
{
  ui->setupUi(this);

  setModal(1);

  //ui->comboBox->addItem();
}

ResetPassWindow::~ResetPassWindow()
{
  delete ui;
}

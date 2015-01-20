#include "reset_pass_window.h"
#include "ui_reset_pass_window.h"

ResetPassWindow::ResetPassWindow(QMap<QString, QString> &AccNames, QLineEdit &NameLine, Carcass &_carcass) :
  ui(new Ui::ResetPassWindow), names(AccNames), CurrName(NameLine), carcass(_carcass)
{
  ui->setupUi(this);

  setModal(1);


  QMap<QString, QString>::const_iterator i = names.constBegin();

  while (i != names.constEnd()) {
      ui->comboBox->addItem(i.key());
      ++i;
  }
}

ResetPassWindow::~ResetPassWindow()
{
  delete ui;
}

void ResetPassWindow::on_buttonBox_accepted()
{
    names.insert(ui->comboBox->currentText(), "");
    carcass.WriteFile(carcass.adr.User, names);
    CurrName.setText(ui->comboBox->currentText());
    this->close();

}

void ResetPassWindow::on_buttonBox_rejected()
{
    this->close();
}

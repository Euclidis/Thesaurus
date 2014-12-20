#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass *_carcass) : LearningDirection(_carcass),
  ui(new Ui::LangSelectionWindow)
{

  ui->setupUi(this);
  Lang_Initializ();

  ui->comboBox->addItems(*Lang);
  ui->comboBox_2->addItems(*Lang);

  ui->comboBox->removeItem(1);
  ui->comboBox_2->removeItem(0);

  KnownLang = ui->comboBox->currentText();
  TargLang  = ui->comboBox_2->currentText();

}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}

void LangSelectionWindow::on_label_3_clicked()
{
  createLD(ui->comboBox->currentText(), ui->comboBox_2->currentText());
  emit WWW_open();
  close();
}


void LangSelectionWindow::on_comboBox_2_activated(const QString &str)
{
  QString temp = ui->comboBox->currentText();
  ui->comboBox->clear();
  ui->comboBox->addItems(*Lang);
  ui->comboBox->removeItem(ui->comboBox->findText(str));
  ui->comboBox->setCurrentIndex(ui->comboBox->findText(temp));
}

void LangSelectionWindow::on_comboBox_activated(const QString &str)
{
  QString temp = ui->comboBox_2->currentText();
  ui->comboBox_2->clear();
  ui->comboBox_2->addItems(*Lang);
  ui->comboBox_2->removeItem(ui->comboBox_2->findText(str));
  ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(temp));
}

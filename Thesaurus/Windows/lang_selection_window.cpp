#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass *_carcass) : LearningDirection(_carcass),
  ui(new Ui::LangSelectionWindow)
{
  ui->setupUi(this);
  Lang_Initializ();
  ui->comboBox->addItems(temp1);
  ui->comboBox_2->addItems(temp2);
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









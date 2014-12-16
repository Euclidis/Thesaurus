#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass *_carcass) :
  ui(new Ui::LangSelectionWindow), carcass(_carcass)
{
  ui->setupUi(this);
  LD = new LearningDirection(carcass);

  QObject::connect(this, SIGNAL(OK_pushed()), LD, SLOT(createLD()));

  ui->comboBox->addItems(LD->temp1);
  ui->comboBox_2->addItems(LD->temp2);
}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}


void LangSelectionWindow::on_label_3_clicked()
{
  LD->TargLang = ui->comboBox->currentText();
  LD->KnownLang = ui->comboBox_2->currentText();
   emit OK_pushed();
   emit WWW_open();
  close();
}


void Connector(){

}









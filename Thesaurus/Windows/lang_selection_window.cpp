#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass *_carcass) : LearningDirection(_carcass),
  ui(new Ui::LangSelectionWindow)
{
  ui->setupUi(this);
  ini_flag = 0;
  Lang_Initializ();

  ui->comboBox->addItems(temp1);
  ui->comboBox_2->addItems(temp2);

  KnownLang = ui->comboBox->currentText();
  TargLang  = ui->comboBox_2->currentText();
  ini_flag = 1;


}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}


void LangSelectionWindow::on_label_3_clicked()
{
  createLD();
  emit WWW_open();
  close();
}

void LangSelectionWindow::on_comboBox_currentTextChanged()
{
  if (ini_flag){

      //ui->comboBox_2->clear();
      choose_avoider(ui->comboBox->currentText(), ui->comboBox_2->currentText());
      //ui->comboBox_2->addItems(temp2);


    }
}
void LangSelectionWindow::on_comboBox_2_currentTextChanged()
{
    if (ini_flag){

        //ui->comboBox->clear();
        choose_avoider(ui->comboBox->currentText(), ui->comboBox_2->currentText());
        //ui->comboBox->addItems(temp1);
      }
}



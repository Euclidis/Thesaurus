#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass * _carcass) :
  ui(new Ui::LangSelectionWindow)
{
  ui->setupUi(this);
  Lang << "English" << "Russian" << "Chines";
  carcass = _carcass;

  ui->comboBox->addItems(Lang);
  ui->comboBox_2->addItems(Lang);
}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}

void LangSelectionWindow::on_label_3_clicked()
{

  carcass->current_language = ui->comboBox->currentText() + "-" + ui->comboBox_2->currentText();
  carcass->confUser_write();



  emit MW_open();
  close();

}


bool LangSelectionWindow::is_Lang_exists(QString * checkLang){

      QStringList LearnDicrectLang;
      if (carcass->ReadFile(carcass->adr.Lang, LearnDicrectLang) == Carcass::ReadResult::OK){
        for (QStringList::iterator i = LearnDicrectLang.begin(); i != LearnDicrectLang.end(); ++i){
          if (*i == checkLang) return 1;
          }
      return 0;
  }
      else {
      QString fileproblems = tr("File ") + carcass->adr.Lang + tr(" can't be read");
      carcass->message(fileproblems);
  }
return 0;
}



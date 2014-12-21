#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass *_carcass) : LearningDirection(_carcass),
  ui(new Ui::LangSelectionWindow)
{

  ui->setupUi(this);
  Lang_Initializ();

  for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
  ui->comboBox->addItem(*carcass->LanguageList->getStrIcoList().at(i).icon, *carcass->LanguageList->getStrIcoList().at(i).name);
  ui->comboBox_2->addItem(*carcass->LanguageList->getStrIcoList().at(i).icon, *carcass->LanguageList->getStrIcoList().at(i).name);
}
  QString cursyslang = QLocale::languageToString(QLocale::system().language());

  if (carcass->LanguageList->getLang(cursyslang)!= nullptr){
      ui->comboBox_2->removeItem(ui->comboBox_2->findText(cursyslang));
      ui->comboBox->removeItem(ui->comboBox->findText(ui->comboBox_2->currentText()));
      ui->comboBox->setCurrentIndex(ui->comboBox->findText(cursyslang));
}
  else {
      ui->comboBox_2->removeItem(0);
      ui->comboBox->removeItem(1);
    }

//  ui->comboBox->removeItem(1);
//  ui->comboBox_2->removeItem(0);

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
  for (int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
      ui->comboBox->addItem(*carcass->LanguageList->getStrIcoList().at(i).icon, *carcass->LanguageList->getStrIcoList().at(i).name);
    }
//  ui->comboBox->addActions(Lang);
  ui->comboBox->removeItem(ui->comboBox->findText(str));
  ui->comboBox->setCurrentIndex(ui->comboBox->findText(temp));
}

void LangSelectionWindow::on_comboBox_activated(const QString &str)
{
  QString temp = ui->comboBox_2->currentText();
  ui->comboBox_2->clear();
  for (int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
      ui->comboBox_2->addItem(*carcass->LanguageList->getStrIcoList().at(i).icon, *carcass->LanguageList->getStrIcoList().at(i).name);
    }
//  ui->comboBox_2->addActions(Lang);
  ui->comboBox_2->removeItem(ui->comboBox_2->findText(str));
  ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(temp));
}

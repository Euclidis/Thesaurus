#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass *_carcass) : LearningDirection(_carcass),
  ui(new Ui::LangSelectionWindow)
{

#define ICON carcass->LanguageList->getStrIcoList().at(i).icon
#define NAME carcass->LanguageList->getStrIcoList().at(i).name

  ui->setupUi(this);
  this->setModal(1);
this->setFixedSize(this->width(), this->height());
  Lang_Initializ();
  QString cursyslang = QLocale::languageToString(QLocale::system().language());

  if (carcass->CurLearnDirList->Get().isEmpty()){
      for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
          ui->comboBox->addItem(*ICON, *NAME);
          ui->comboBox_2->addItem(*ICON, *NAME);
        }
      ui->comboBox_2->removeItem(ui->comboBox_2->findText(cursyslang));
      ui->comboBox->removeItem(ui->comboBox->findText(ui->comboBox_2->currentText()));
      ui->comboBox->setCurrentIndex(ui->comboBox->findText(cursyslang));
    }
  else {
      for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
          ui->comboBox->addItem(*ICON, *NAME);
        }
      ui->comboBox->setCurrentIndex(ui->comboBox->findText(cursyslang));

      for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
          if (*NAME != ui->comboBox->currentText())
            ui->comboBox_2->addItem(*ICON, *NAME);
        }
      for (int n = 0; n < carcass->CurLearnDirList->Get().size(); ++n){
          if (carcass->CurLearnDirList->Get().at(n).knownL == ui->comboBox->currentText())
            ui->comboBox_2->removeItem(ui->comboBox_2->findText(carcass->CurLearnDirList->Get().at(n).targL));

        }

      ui->comboBox->removeItem(ui->comboBox->findText(ui->comboBox_2->currentText()));
    }
}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}
void LangSelectionWindow::accepted(bool result){

  if (result){
        LD templd;
        templd.knownL = ui->comboBox->currentText();
        templd.targL = ui->comboBox_2->currentText();
        carcass->CurLearnDirList->Add(templd);
        close();
    }
  else {

    }

}
void LangSelectionWindow::on_label_3_clicked()
{

  QString mess = (tr("Are you already know ") + ui->comboBox->currentText() + tr(" and want to learn ") + ui->comboBox_2->currentText() + "?");
  carcass->mesOKCancelShow(mess);
//  LD templd;
//  templd.knownL = ui->comboBox->currentText();
//  templd.targL = ui->comboBox_2->currentText();
//  carcass->CurLearnDirList->Add(templd);

  //  //>>>>>>>>>>>>>>>>>>>>>>>>TEST
  //  ui->comboBox->clear();
  //  ui->comboBox_2->clear();

  //      for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
  //      ui->comboBox->addItem(*ICON, *NAME);
  //    }
  //      for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
  //          if (*NAME != ui->comboBox->currentText())
  //      ui->comboBox_2->addItem(*ICON, *NAME);
  //    }
  //      for (int n = 0; n < carcass->CurLearnDirList->Get().size(); ++n){
  //          if (carcass->CurLearnDirList->Get().at(n).knownL == ui->comboBox->currentText())
  //            ui->comboBox_2->removeItem(ui->comboBox_2->findText(carcass->CurLearnDirList->Get().at(n).targL));
  //        }

  //      ui->comboBox->removeItem(ui->comboBox->findText(ui->comboBox_2->currentText()));

  //  ui->textEdit->clear();
  //  QString temp = "";
  //  if (!carcass->CurLearnDirList->Get().isEmpty())
  //    for (int n = 0; n < carcass->CurLearnDirList->Get().size(); ++n){
  //     temp +=(carcass->CurLearnDirList->Get().at(n).knownL + "_" + carcass->CurLearnDirList->Get().at(n).targL + "\n");
  //    }
  //     ui->textEdit->setText(temp);
  //  //>>>>>>>>>>>>>>>>>>>>>>>>TEST

  //  createLD(ui->comboBox->currentText(), ui->comboBox_2->currentText());

//  emit WWW_open();
//  close();
}
void LangSelectionWindow::on_comboBox_2_activated(const QString &combo2_cur_text)
{
  QString temp = ui->comboBox->currentText();
  ui->comboBox->clear();
  for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
      if (*NAME != combo2_cur_text)
        ui->comboBox->addItem(*ICON, *NAME);
    }
  if (!carcass->CurLearnDirList->Get().isEmpty()){
      for (int n = 0; n < carcass->CurLearnDirList->Get().size(); ++n){
          if (carcass->CurLearnDirList->Get().at(n).targL == combo2_cur_text)
            ui->comboBox->removeItem(ui->comboBox->findText(carcass->CurLearnDirList->Get().at(n).knownL));
        }
    }
  if (ui->comboBox->count() == 0){
      carcass->message(tr("This target language are totaly in use"));
      //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> +
    }
  else
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(temp));
}

void LangSelectionWindow::on_comboBox_activated(const QString &combo1_cur_text)
{
  QString temp = ui->comboBox_2->currentText();
  ui->comboBox_2->clear();
  for ( int i = 0; i < carcass->LanguageList->getStrIcoList().size(); ++i){
      if (*NAME != ui->comboBox->currentText())
        ui->comboBox_2->addItem(*ICON, *NAME);
    }
  if (!carcass->CurLearnDirList->Get().isEmpty()){
      for (int n = 0; n < carcass->CurLearnDirList->Get().size(); ++n){
          if (carcass->CurLearnDirList->Get().at(n).knownL == combo1_cur_text)
            ui->comboBox_2->removeItem(ui->comboBox_2->findText(carcass->CurLearnDirList->Get().at(n).targL));
        }
    }
  if (ui->comboBox_2->count() == 0){
      carcass->message(tr("This known language are totaly in use"));
    }
  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> +
  else
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(temp));
}

void LangSelectionWindow::closeEvent(QCloseEvent * close_ev){

  emit close_me(this);
  close_ev->accept();
}

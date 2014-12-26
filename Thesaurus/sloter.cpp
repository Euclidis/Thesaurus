#include "sloter.h"

Sloter::Sloter()
{
    AW = nullptr;
    WWW = nullptr;
    MW = nullptr;
    LSW = nullptr;
    MOCW = nullptr;

    carcass = new Carcass;

    carcass->LanguageList = new LangList(carcass);
    if(!carcass->LanguageList->Initialize()) carcass->message("Error initialize LangList");

    carcass->CurLearnDirList = new CurrentLearnDirList(carcass);
    carcass->CurLearnDir = new CurrentLearnDir(carcass);
    carcass->CurAccount = new CurrentAccount(carcass);

    if(carcass->CurAccount->Initialize()){
        if(carcass->CurAccount->Get() != ""){
            if(carcass->CurAccount->Get_flag_AW_ignore()) MW_show();
            else AW_show(true);
        }
        else{
            AW_show(false);
        }
    }
    else{
        closApp();
    }

    connector();
}

void Sloter::closApp()
{
    carcass->message("Ups!");
    qApp->exit();
}

/*************************************************************************************
                  Коннектор и слот открытия месседжа с двумя кнопками
*************************************************************************************/
void Sloter::connector()
{
    connect(carcass, SIGNAL(mesOKCancelShow(QString)), SLOT(MOCW_show(QString)));
}
void Sloter::MOCW_show(QString str)
{
  if (MOCW == nullptr){
  MOCW = new MesOKCancel(str);
  connect(MOCW, SIGNAL(close_me(BaseWindow*)), SLOT(close_wind(BaseWindow*)));
  connect(MOCW, SIGNAL(MesOKCancelResult(bool)), LSW, SLOT(accepted(bool)));
  //Шаблон для заполнения - связывание сигнала месседжера с двумя кнопками со слотом объекта
  //connect(MOCW, SIGNAL(MesOKCancelResult(bool)), /*some obj*/, /*some SLOT*/);
}
  MOCW->show();
}

/*********************************************************
                    Блок открытия окон
*********************************************************/
void Sloter::AW_show(bool mode)
{
  if (AW == nullptr){
      AW = new AccountWindow(carcass, mode);
      connect(AW, SIGNAL(LSW_open()), SLOT(LSW_show()));
      connect (AW, SIGNAL(MW_open()), SLOT(MW_show()));
      connect (AW, SIGNAL(close_me(BaseWindow*)), SLOT(close_wind(BaseWindow*)));
    }
  AW->show();
}
void Sloter::MW_show()
{
    if(MW == nullptr){
        MW = new MenuWindow(carcass);
        connect(MW, SIGNAL(AW_open_signal()), SLOT(AW_show()));
        connect(MW, SIGNAL(LSW_open_signal()), SLOT(LSW_show()));
        connect(MW, SIGNAL(WWW_open_signal()), SLOT(WWW_show()));
        connect(carcass, SIGNAL(DctList_Add(QString)), MW, SLOT(DctList_Add(QString)));
        connect(carcass, SIGNAL(SetAccount()), MW, SLOT(SetAccount()));
        connect(carcass, SIGNAL(SetLD()), MW, SLOT(SetDictionaries()));
    }
    MW->show();
}
void Sloter::WWW_show()
{
    if(WWW == nullptr){
        WWW = new WriteWordsWindow(carcass);
        connect (WWW, SIGNAL(close_me(BaseWindow*)), SLOT(close_wind(BaseWindow*)));
    }
    WWW->show();
}
void Sloter::LSW_show()
{
  if (LSW == nullptr){
      LSW = new LangSelectionWindow(carcass);
      connect (LSW, SIGNAL(close_me(BaseWindow*)), SLOT(close_wind(BaseWindow*)));
    }
  LSW->show();
}
void Sloter::close_wind(BaseWindow * wind){

  if (wind == WWW) WWW = nullptr;
  else if (wind == AW) AW = nullptr;
  else if (wind == LSW) LSW = nullptr;
  else if (wind == MOCW) MOCW = nullptr;

  delete wind;

}

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
    if(!MOCW){
        MOCW = new MesOKCancel(str);
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
    if(!AW){
        AW = new AccountWindow(carcass, mode);
        connect(AW, SIGNAL(LSW_open()), SLOT(LSW_show()));
        connect (AW, SIGNAL(MW_open()), SLOT(MW_show()));
    }
    AW->show();
}
void Sloter::MW_show()
{
    if(!MW){
        MW = new MenuWindow(carcass);
        connect(MW, SIGNAL(LSW_open()), SLOT(LSW_show()));
        connect(MW, SIGNAL(WWW_open_signal()), SLOT(WWW_show()));
        connect(MW, SIGNAL(WWW_close()), SLOT(WWW_close()));
        connect(carcass, SIGNAL(DctListChange()), MW, SLOT(SetDictionaries()));
        connect(carcass, SIGNAL(Menu_UpDate()), MW, SLOT(SetAccount()));
    }
    MW->show();
}
void Sloter::WWW_show()
{
    if(!WWW){
        WWW = new WriteWordsWindow(carcass);
    }
    WWW->show();
}
void Sloter::LSW_show()
{
    if(!LSW){
        LSW = new LangSelectionWindow(carcass);
    }
//    connect (LSW, SIGNAL(MW_open()), SLOT(MW_show()));

//    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
//    connect (LSW, SIGNAL(WWW_open()), SLOT(WWW_show()));
//    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    LSW->show();
}

/*********************************************************
                    Блок закрытия окон
*********************************************************/
void Sloter::WWW_close()
{
    if(!WWW){}
    else delete WWW;
}

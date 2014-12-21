#include "sloter.h"

Sloter::Sloter()
{
    //Получаем имя пользователя компьютера
    carcass = new Carcass;
    carcass->lang_list = new LangList(carcass);
    if(!carcass->lang_list->Initialize()) carcass->message("ErrorDDDDDDDDDDDDDDDDDDDDDDDDD");

    AW = nullptr;
    WWW = nullptr;
    MW = nullptr;
    LSW = nullptr;
    MOCW = nullptr;

//    bool flag_good = true;
//    Language lg(carcass, flag_good);
//    carcass->current_language = "lang1.lang";
//    if(flag_good){
//        lg.AddNewWord();
//        lg.WriteFile();
//    }
//    else {carcass->message("Error read language");}

    carcass->current_accountOS = qgetenv("USER");
    if (carcass->current_accountOS.isEmpty())
        carcass->current_accountOS = qgetenv("USERNAME");

    //Присваиваем общим переменным стандартные значения
    carcass->current_language_interface = carcass->adr.LangInterface_en;  //>>>>>>>>> Стоит поменять на что-то другое <<<<<<<<//
    carcass->current_L_D = carcass->symb.lang_empty;
    carcass->flag_AWIgnore = false;

    //читаем файл конфигурации и заполняем QMapAccounts
    carcass->conf_read();

    //Проверяем наличие пользователя компьютера в QMapAccounts
    if (carcass->QMapAccounts.isEmpty()){
        AW_show();
    }
    else{
        if (carcass->QMapAccounts.contains(carcass->current_accountOS)){
            carcass->current_account = carcass->QMapAccounts[carcass->current_accountOS];

            //читаем user config
            carcass->confUser_read();
            if(carcass->flag_AWIgnore) MW_show();
            else {
                AW_show(1);
            }
        }
        else {
            AW_show(1);
        }
    }
    connector();
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
    connect (LSW, SIGNAL(MW_open()), SLOT(MW_show()));

    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    connect (LSW, SIGNAL(WWW_open()), SLOT(WWW_show()));
    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    LSW->show();
}


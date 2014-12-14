#include "sloter.h"

Sloter::Sloter()
{
    //Получаем имя пользователя компьютера
    carcass = new Carcass;
    AW = nullptr;
    WWW = nullptr;
    MW = nullptr;
    LSW = nullptr;

    carcass->current_accountOS = qgetenv("USER");
    if (carcass->current_accountOS.isEmpty())
        carcass->current_accountOS = qgetenv("USERNAME");

    //Присваиваем общим переменным стандартные значения
    carcass->current_language_interface = carcass->adr.LangInterface_en;  //>>>>>>>>> Стоит поменять на что-то другое <<<<<<<<//
    carcass->current_language = carcass->symb.lang_empty;
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
            carcass->confUser_read(carcass->current_account);
            if(carcass->flag_AWIgnore) MW = new MenuWindow(carcass);
            else {
                AW_show();
            }
        }
        else {
            AW_show();
        }
    }
}

void Sloter::AW_show(bool mode)
{
    if(!AW){
        AW = new AccountWindow(carcass, mode);
        connect(AW, SIGNAL(LSW_open()), SLOT(LSW_show()));
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
    LSW->show();
}

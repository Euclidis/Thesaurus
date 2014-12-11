#include "carcass.h"
#include "Windows/account_window.h"

Carcass::Carcass()
{
    //Получаем имя пользователя компьютера
    current_accountOS = qgetenv("USER");
    if (current_accountOS.isEmpty())
        current_accountOS = qgetenv("USERNAME");

    //Присваиваем общим переменным стандартные значения
    current_language_interface = adr.LangInterface_en;  //>>>>>>>>> Стоит поменять на что-то другое <<<<<<<<//
    current_language = symb.lang_empty;
    flag_AWIgnore = false;

    //читаем файл конфигурации и заполняем QMapAccounts
    conf_read();

    //Проверяем наличие пользователя компьютера в QMapAccounts
    if (QMapAccounts.isEmpty()){
        AccountWindow *account = new AccountWindow (this);
        account->show();
    }
    else{
        if (QMapAccounts.contains(current_accountOS)){
            current_account = QMapAccounts[current_accountOS];

            //читаем user config
            confUser_read(current_account);
            if(flag_AWIgnore) flag_AWIgnore; //>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Дабавить код запуска меню <<<<<<<//
            else {
                AccountWindow *account = new AccountWindow (this, 1);
                account->show();
            }
        }
        else {
            AccountWindow *account = new AccountWindow (this, 1);
            account->show();
        }
    }
}

void Carcass::conf_write()
{
    WriteResult wr = WriteFile(adr.config, QMapAccounts);
    switch (wr) {
    case WriteResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems writing the file ") + adr.config);
        ex.show();
        message(enumWToQStr(wr));
    }
}
void Carcass::conf_read()
{
    ReadResult rr = ReadFile(adr.config, QMapAccounts);
    switch (rr) {
    case ReadResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.config);
        ex.show();
        message(enumRToQStr(rr));
    }
}
void Carcass::confUser_write(QString str)
{
    QStringList data;
    try
    {
        data << current_language_interface << current_language << (QString::number(flag_AWIgnore));
    }
    catch(...){
        ex_some_show ex(QObject::tr("Problems writing the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
        return;
    }
    WriteResult wr = WriteFile(adr.users_dir + str + adr.user_config, data);
    switch (wr) {
    case WriteResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems writing the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
        message(enumWToQStr(wr));
    }
}
void Carcass::confUser_read(QString str)
{
    QStringList data;
    ReadResult rr = ReadFile(adr.users_dir + str + adr.user_config, data);
    switch (rr) {
    case ReadResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
        message(enumRToQStr(rr));
        return;
    }
    try
    {
        current_language_interface = data.at(0);
        current_language = data.at(1);
        flag_AWIgnore = ((data.at(2) == "0") ? false : true);
    }
    catch(...){
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
    }
}

void Carcass::message(QString str, bool _modal)
{
    MessageWindow* ms = new MessageWindow(str, _modal);
    ms->show();
}

QString Carcass::enumWToQStr (WriteResult wr)
{
    switch (wr) {
    case WriteResult::OK:
        return "OK";
    case WriteResult::Write:
        return "Write";
    case WriteResult::Open:
        return "Open";
    case WriteResult::Copy:
        return "Copy";
    case WriteResult::DelTmpWhileCopy:
        return "DelTmpWhileCopy";
    case WriteResult::DelSource:
        return "DelSource";
    case WriteResult::DelTmp:
        return "DelTmp";
    case WriteResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}

QString Carcass::enumRToQStr (ReadResult rr)
{
    switch (rr) {
    case ReadResult::OK:
        return "OK";
    case ReadResult::DelTmp:
        return "DelTmp";
    case ReadResult::NotFound:
        return "NotFound";
    case ReadResult::Open:
        return "Open";
    case ReadResult::Read:
        return "Read";
    case ReadResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}

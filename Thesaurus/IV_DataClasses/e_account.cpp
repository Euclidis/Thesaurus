#ifndef E_ACCOUNT
#include "e_account.h"
#endif

//-----------------------------------------------------------------------------------------------
Account::Account(AccountParameter &_parameter):
    DataListItem<AccountParameter>(_parameter), LDL(nullptr)
{
    filled = false;
    name = _parameter.name;
    adress = Adr::users_dir + name.toLower()+ Adr::user_conf_file;
    if(LL == nullptr) qDebug() << "Account::Account 1";//****************************** Необходимо исключение
    password = _parameter.password;
    accountsOS = _parameter.accountOS;
    photo_adress = Adr::default_face_file;
    flag_AW_ignore = false;

    QDir dir(Adr::users_dir + name.toLower());
    if(!dir.mkpath("."))
        qDebug() << "Проблема при создании объекта аккаунта, папка для такого аккаунта уже существует";
        //****************************** Необходимо исключение
    if(!WriteFile())
        qDebug() << "Проблема при создании объекта аккаунта, во время записи в файл";
        //****************************** Необходимо исключение
    QFile f(Adr::users_dir + name.toLower() + Adr::ld_list_file);
    if(!f.open(QIODevice::WriteOnly))
        qDebug() << "Проблема при создании объекта аккаунта, во время создания файла для списка направлений";
        //****************************** Необходимо исключение
    f.close();
}
//-----------------------------------------------------------------------------------------------
Account::Account(AccountParameter& _parameter, const QString& _adress) :
    DataListItem<AccountParameter>(_parameter), LDL(nullptr)
{
    filled = false;
    name = _parameter.name;
    adress = _adress;
    if(!ReadFile())
        qDebug() << "Проблема при создании объекта аккаунта, во время чтения из файла настроек";
        //****************************** Необходимо исключение
}
//-----------------------------------------------------------------------------------------------
bool Account::Filling()
{
    if(LDL != nullptr){
        qDebug() << "LDL уже существует, какая-то проблема (Account::Filling)";
        return false;
    }
    LDL = new DataList<LearnDir, LearnDirParameter>(LL, Adr::users_dir + name.toLower() + Adr::ld_list_file);
    filled = true;
    return true;
}
//-----------------------------------------------------------------------------------------------
void Account::Ravage()
{
    if(LDL != nullptr) delete LDL;
    LDL = nullptr;
    filled = false;
}
//-----------------------------------------------------------------------------------------------
bool Account::WriteFile()
{
    RW::WriteResult wr = RW::WriteFile(adress, *this);
    switch (wr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << "Error: " << RW::enumWToQStr(wr) << "  " << adress;
        return false;
    }
}
//-----------------------------------------------------------------------------------------------
bool Account::ReadFile()
{
    RW::ReadResult rr = RW::ReadFile(adress, *this);
    switch (rr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << "Error: " << RW::enumRToQStr(rr) << "  " << adress;
        return false;
    }
}
//-----------------------------------------------------------------------------------------------
QDataStream& operator>> (QDataStream& out, Account& a)
{
    out >> a.password;
    out >> a.accountsOS;
    out >> a.flag_AW_ignore;
    out >> a.photo_adress;

    return out;
}
//-----------------------------------------------------------------------------------------------
QDataStream& operator<< (QDataStream& in, const Account& a)
{
    in << a.password;
    in << a.accountsOS;
    in << a.flag_AW_ignore;
    in << a.photo_adress;
    return in;
}
//-----------------------------------------------------------------------------------------------
bool Account::CheckPassword(const QString& _password)
{
    if(password != _password) return false;
    return true;
}
//-----------------------------------------------------------------------------------------------
bool Account::SetPhoto(const QString& _adress)
{
    if(!filled){
        qDebug() << "filled = false Account (SetPhoto)";
        return false;
    }
    photo_adress = _adress;
    return true;
}
//-----------------------------------------------------------------------------------------------
bool Account::SetFlagAWIgnore(bool _flag_AW_ignore)
{
    if(!filled){
        qDebug() << "filled = false Account (SetFlagAWIgnore)";
        return false;
    }
    flag_AW_ignore = _flag_AW_ignore;
    return true;
}
//-----------------------------------------------------------------------------------------------
bool Account::RenameAccount(const QString& new_name)
{
    if(!filled){
        qDebug() << "filled = false Account (RenameAccount)";
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------
Account::~Account()
{
    Ravage();
}
//-----------------------------------------------------------------------------------------------

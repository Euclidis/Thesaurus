﻿#ifndef ACCOUNT_H
#define ACCOUNT_H

#ifndef LD_H
#include "ld.h"
#endif
class Account;
//-----------------------------------------------------------------------------------------
class AccountParameter
{
public:
    QString name;
    QString password;
    QStringList accountOS;
    const LanguageList* LL;
};
//-----------------------------------------------------------------------------------------
class Account: public DataListItem<AccountParameter>
{
    //*************************************************************************
    //                  Интерфейс
    //*************************************************************************
public:
    //            Данные                             Методы
    DataList<LearnDir,LearnDirParameter>*
                LDL;
    QString     photo_adress;                 bool CheckPassword    (const QString& _password);
                                              bool SetPhoto         (const QString &_adress);
                                              bool SetFlagAWIgnore  (bool _flag_AW_ignore);
                                              bool RenameAccount    (const QString& new_name);
                                              bool SetPassword      (const QString& new_password);

    //*******************************************************************************
protected:
    //            Данные                             Методы
    QString     password;             virtual bool Filling           ();
    QStringList accountsOS;           virtual void Ravage            ();
    bool        flag_AW_ignore;       virtual bool ReadFile          ();
                                      virtual bool WriteFile         ();

public:
    Account(AccountParameter& _parameter);
    Account(AccountParameter& _parameter, const QString& _adress);
    ~Account();
    friend class DataList<Account, AccountParameter>;
    friend QDataStream& operator>> (QDataStream& out, Account& w);
    friend QDataStream& operator<< (QDataStream& in, const Account& w);
};
//-----------------------------------------------------------------------------------------
#endif // ACCOUNT_H


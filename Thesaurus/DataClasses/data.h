#ifndef DATA_H
#define DATA_H

#ifndef ACCOUNT_H
#include "account.h"
#endif

class Data
{
public:
    Data();

    LanguageList* LL();

    DataList<Account, AccountParameter>* AccountList();

    Account* CurrentAccount();

    DataList<LearnDir, LearnDirParameter>* LDList();

    LearnDir* CurrentLD();

private:
    LanguageList* _LL;
    DataList<Account, AccountParameter>* _AccountList;
    Account* _CurrentAccount;
    DataList<LearnDir, LearnDirParameter>* _LDList;
    LearnDir* _CurrentLD;

    void UpDate();
};

#endif // DATA_H


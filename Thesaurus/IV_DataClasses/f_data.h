#ifndef F_DATA
#define F_DATA

#ifndef E_ACCOUNT
#include "e_account.h"
#endif

class Data
{
public:
    LanguageList* LL;
    DataList<Account, AccountParameter>* AccountList;
    Data(){
        LL = new LanguageList;
        AccountList = new DataList<Account, AccountParameter>(LL, Adr::conf_file);
    }
};

#endif // F_DATA


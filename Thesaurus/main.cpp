#include <QApplication>
#include "V_Windows/AccountWinow/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //DataList<Account, AccountParameter> aclist(&LL, Adr::conf_file);
    Data* data = new Data;
    AccountWindow* AW1 = new AccountWindow(data);
    delete AW1;
    AccountWindow* AW2 = new AccountWindow(data);
    delete AW2;
    AccountWindow* AW3 = new AccountWindow(data);
    delete AW3;
    AccountWindow* AW5 = new AccountWindow(data);
    delete AW5;
    AccountWindow* AW6 = new AccountWindow(data);
    delete AW6;
    AccountWindow* AW7 = new AccountWindow(data);
    delete AW7;
    AccountWindow* AW4 = new AccountWindow(data);
    AW4->show();
//    AccountParameter acp;
//    acp.name = "Einstain";
//    acp.LL = data.LL;
//    acp.password = "123";
//    acp.accountOS << "a" << "b";
//    data.AccountList->AddItem(acp);
//    LearnDirParameter ldp;
//    ldp.cur_account = data.AccountList->SelectionItem()->name;
//    ldp.known_lang = data.LL->at(25)->name_eng;
//    ldp.targ_lang = data.LL->at(26)->name_eng;
//    ldp.LL = data.LL;
//    ldp.name = ldp.known_lang + "_" + ldp.targ_lang;
//    data.AccountList->SelectionItem()->LDL->AddItem(ldp);
//    data.AccountList->SelectionItem()->LDL->SelectionItem()->AddDictionary("asdf");
//    QStringList l; l << "1" << "2";
//    Word w("brain", "brein", l, l, "notes");
//    data.AccountList->SelectionItem()->LDL->SelectionItem()->AddWord(w);

    return a.exec();
}

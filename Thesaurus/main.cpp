#include <QApplication>
#include "sloter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sloter sloter;
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

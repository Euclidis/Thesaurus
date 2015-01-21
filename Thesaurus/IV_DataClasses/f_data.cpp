#ifndef F_DATA
#include "f_data.h"
#endif
//--------------------------------------------------------------------------------
Data::Data(){
    _LL = new LanguageList;
    _AccountList = new DataList<Account, AccountParameter>(_LL, Adr::conf_file);
    UpDate();
}
//--------------------------------------------------------------------------------
void Data::UpDate(){
    _CurrentAccount = _AccountList->SelectionItem();
    if(_AccountList->SelectionItem() != nullptr){
        _LDList = _AccountList->SelectionItem()->LDL;
    }
    else{
        _LDList = nullptr;
    }
    if(_LDList != nullptr){
        _CurrentLD = _LDList->SelectionItem();
    }
    else{
        _LDList = nullptr;
    }
}
//--------------------------------------------------------------------------------
LanguageList* Data::LL()
{ return _LL; }

//--------------------------------------------------------------------------------
DataList<Account, AccountParameter>* Data::AccountList()
{ return _AccountList; }

//--------------------------------------------------------------------------------
Account* Data::CurrentAccount()
{ UpDate(); return _CurrentAccount; }

//--------------------------------------------------------------------------------
DataList<LearnDir, LearnDirParameter>* Data::LDList()
{ UpDate(); return _LDList; }

//--------------------------------------------------------------------------------
LearnDir* Data::CurrentLD()
{ UpDate(); return _CurrentLD; }

//--------------------------------------------------------------------------------

#include "menu_abstraction.h"

MenuAbstraction::MenuAbstraction(Carcass* _carcass) :
    carcass(_carcass),
    language(nullptr),
    language_initialized(false)
{

}

bool MenuAbstraction::LanguageInitialize()
{
//    if(!language) delete language;
//    language = new Language(carcass);
//    if(language->Initialize()) {
//        language_initialized = true;
        return true;
//    }
//    else{
//        carcass->message("Меню не может инициализировать словарь");
//        language_initialized = false;
//        return false;
//    }
}

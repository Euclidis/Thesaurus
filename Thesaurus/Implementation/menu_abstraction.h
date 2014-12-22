#ifndef MENU_ABSTRACTION_H
#define MENU_ABSTRACTION_H

#include "../language.h"

class MenuAbstraction
{
protected:
    Carcass* carcass;
    Language* language;
public:
    explicit MenuAbstraction(Carcass* _carcass);
protected:
    bool LanguageInitialize();
protected:
    bool language_initialized;

};

#endif // MENU_ABSTRACTION_H

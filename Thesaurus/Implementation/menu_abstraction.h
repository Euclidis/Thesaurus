#ifndef MENU_ABSTRACTION_H
#define MENU_ABSTRACTION_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif

class MenuAbstraction
{
protected:
    Carcass* carcass;
    CurrentLearnDirList* language;
public:
    explicit MenuAbstraction(Carcass* _carcass);
protected:
    bool LanguageInitialize();
protected:
    bool language_initialized;
};

#endif // MENU_ABSTRACTION_H

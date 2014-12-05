#ifndef CARCASS_H
#define CARCASS_H

#include "adress_texts.h"

class Carcass
{
private:
    QString cur_acc;
    QString cur_lang;

    Adr adr;
    ControlSymbol symb;
public:
    Carcass();
};

#endif // CARCASS_H

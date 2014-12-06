#ifndef ADRESS_TEXTS_H
#define ADRESS_TEXTS_H

#include "general.h"

struct Adr
{
    QString ext = ".conf";
    QString config = "\\settings\\configuration" + ext;
};

struct ControlSymbol
{
    QString line = "⚜";
    QString part = "";
};

#endif // ADRESS_TEXTS_H

#include "language_methods.h"

LanguageMethods::LanguageMethods(Carcass *_carcass, QString _adress, bool &flag_good)
{
    adress = _adress;
    carcass = _carcass;

    date = QDate::currentDate();

    flag_good = true;
    if(!ReadFile(carcass->ReadFile(adress, language))) flag_good = false;
}

bool LanguageMethods::Write()
{
    return true;
}

bool LanguageMethods::AddNewWords(Word& _word)
{
    return true;
}

bool LanguageMethods::ReadFile(Carcass::ReadResult rr)
{
    switch (rr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        return false;
    }
}

#include "language_methods.h"

LanguageMethods::LanguageMethods(Carcass * _carcass, QString _adress, bool &flag_good)
{
    adress = _adress;
    carcass = _carcass;

    date = QDate::currentDate();

    flag_good = true;
//    if(!ReadFile(carcass->ReadFile(adress+carcass->adr.words, words))) flag_good = false;
//    if(!ReadFile(carcass->ReadFile(adress+carcass->adr.transcriptions, transcriptions))) flag_good = false;
//    if(!ReadFile(carcass->ReadFile(adress+carcass->adr.translates, translates))) flag_good = false;
//    if(!ReadFile(carcass->ReadFile(adress+carcass->adr.notes, notes))) flag_good = false;
//    if(!ReadFile(carcass->ReadFile(adress+carcass->adr.dates, dates))) flag_good = false;
//    if(!ReadFile(carcass->ReadFile(adress+carcass->adr.priorities, priorities))) flag_good = false;
}

bool LanguageMethods::Write()
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

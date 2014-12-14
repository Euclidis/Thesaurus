#include "language.h"

Language::Language(Carcass *_carcass, bool &flag_good)
{
    carcass = _carcass;
    adress = carcass->adr.users_dir + /*carcass->current_account*/ + "ard\\lang1.lang"  /* + carcass->current_language*/;

    date = QDate::currentDate();

    flag_good = true;
    if(!ReadFile()) flag_good = false;
}

bool Language::ReadFile()
{
    Carcass::ReadResult rr = carcass->ReadFile(adress, language);
    switch (rr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        carcass->message(carcass->enumRToQStr(rr)+ "  "+ adress);
        return false;
    }
}

bool Language::WriteFile()
{
    Carcass::WriteResult wr = carcass->WriteFile(adress, language);
    switch (wr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        carcass->message(carcass->enumWToQStr(wr) + "  "+ adress);
        return false;
    }
}

bool Language::AddNewWord()
{
    language.words << "word1" << "word2";
    language.transcriptions << "tr1" << "tr2";
    language.notes << "notes1" << "notes2";
    language.priorities << 3.54 << 6.222;
    return true;
}

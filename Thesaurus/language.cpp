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
    Carcass::ReadResult rr = carcass->ReadFile(adress, words);
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
    Carcass::WriteResult wr = carcass->WriteFile(adress, words);
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
    Word w1;
    w1.word = "word1";
    w1.transcription = "tr1";
    w1.note = "note1";
    w1.priority = 3.98;
    Word w2;
    w2.word = "中國";
    w2.transcription = "tr2";
    w2.note = "note2";
    w2.priority = 5.66;

    words << w1 << w2;
    return true;
}

bool Language::contains(QString)
{
    return true;
}

int Language::indexOf(QString)
{
    return true;
}

#include "language.h"

Language::Language(Carcass *_carcass, bool &flag_good)
{
    carcass = _carcass;
    adress = carcass->adr.users_dir + carcass->current_account.toLower() + "\\" + carcass->current_language + carcass->adr.lext;

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
        carcass->message(carcass->enumWToQStr(wr) + "  " + adress);
        return false;
    }
}

void Language::AddNewWord(Word& _word)
{
    int n = indexOf(_word.word);
    if (n < 0) words << _word;
    else words[n] += _word;
}

bool Language::contains(const QString str)
{
    if(!words.isEmpty()){
        QList<Word>::iterator i = words.begin();
        while(i != words.end()){
            if((*i).word == str) return true;
            ++i;
        }
    }
    return false;
}

int Language::indexOf(const QString str)
{
    if(!words.isEmpty()){
        for(int i = 0; i < words.size(); ++i){
            if(words.at(i).word == str) return i;
        }
    }
    return -1;
}

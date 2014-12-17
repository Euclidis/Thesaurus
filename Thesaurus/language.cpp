#include "language.h"

Language::Language(Carcass *_carcass)
{
    carcass = _carcass;
    adress = carcass->adr.users_dir + carcass->current_account.toLower() + "\\" + carcass->current_language + carcass->adr.lext;
    initialized = false;
}

bool Language::Initialize()
{
    if(ReadFile()){
        initialized = true;
        return true;
    }
    else{
        return false;
    }
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
    if(initialized){
        Carcass::WriteResult wr = carcass->WriteFile(adress, words);
        switch (wr) {
        case Carcass::ReadResult::OK:
            return true;
        default:
            carcass->message(carcass->enumWToQStr(wr) + "  " + adress);
            return false;
        }
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
        return false;
    }
}

void Language::AddNewWord(Word& _word)
{
    if(initialized){
        int n = IndexOf(_word.word);
        if (n < 0) words << _word;
        else words[n] += _word;
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
    }
}

bool Language::Contains(const QString str)
{
    if(initialized){
        if(!words.isEmpty()){
            QList<Word>::iterator i = words.begin();
            while(i != words.end()){
                if((*i).word == str) return true;
                ++i;
            }
        }
        return false;
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
        return false;
    }
}

int Language::IndexOf(const QString str)
{
    if (initialized){
        if(!words.isEmpty()){
            for(int i = 0; i < words.size(); ++i){
                if(words.at(i).word == str) return i;
            }
        }
        return -1;
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
        return -1;
    }
}

#include "language.h"

Language::Language(Carcass *_carcass)
{
    carcass = _carcass;
    initialized = false;
}

bool Language::Initialize()
{
    learn_dir = carcass->current_learn_dir;
    if(learn_dir.knownL != carcass->symb.lang_empty){
        adress = carcass->adr.users_dir + carcass->current_account.toLower() + "\\" + carcass->LDList->currentLDname() + carcass->adr.lext;
        if(ReadFile()){
            if(!words.isEmpty()){
                for (int i = 0; i < words.size(); ++i){
                    if(words.at(i).word != carcass->symb.new_dictionary){
                        for (int u = 0; u < words[i].dictionaries.size(); ++u){
                            if(!dictionaries.contains(words[i].dictionaries[u])) dictionaries << words[i].dictionaries[u];
                        }
                    }
                }
                initialized = true;
                return true;
            }
            initialized = true;
            return true;
        }
    }
    else carcass->message("Нет словаря");
    return false;
}

bool Language::ReadFile()
{
    Carcass::ReadResult rr = carcass->ReadFile(adress, words);
    switch (rr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        //carcass->message(carcass->enumRToQStr(rr)+ "  "+ adress);
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
            //carcass->message(carcass->enumWToQStr(wr) + "  " + adress);
            return false;
        }
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
        return false;
    }
}

void Language::AddWord(Word& _word)
{
    if(initialized){
        if(_word.word != ""){
            if(!_word.translates.isEmpty()){
                int n = IndexOf(_word.word);
                if (n < 0) words << _word;
                else words[n] += _word;
                WriteFile();
                QStringList::iterator i = _word.dictionaries.begin();
                while(i != _word.dictionaries.end()){
                    if(!dictionaries.contains(*i)) dictionaries << (*i);
                    ++i;
                }
            }
        }
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
    }
}
void Language::RemoveWord(QString str)
{
    if(initialized){
        str = str.trimmed();
        int n = IndexOf(str);
        if(n > -1){
            if(str != carcass->symb.new_dictionary){
                words.removeAt(n);
                WriteFile();
            }
        }
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
    }
}
bool Language::AddDictionary(QString str)
{
    if(initialized){
        str = str.trimmed();
        if(str != ""){
            if(!dictionaries.contains(str)){
                dictionaries << str;
                QStringList empty;
                empty << str;
                Word w(carcass->symb.new_dictionary, "", empty, empty, "");
                AddWord(w);
                return true;
            }
        }
    }
    else{
        carcass->message("Не инициализированн класс словаря"); //*************** Обработать исключение *************************
    }
    return false;
}
void Language::RemoveDictionary(const QString &str)
{
    if(initialized){

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

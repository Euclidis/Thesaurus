#include "carcass.h"

CurrentLearnDir::CurrentLearnDir(Carcass *_carcass) : carcass(_carcass)
{
    initialized = false;
    learn_dir.knownL = "";
    learn_dir.targL = "";
}

bool CurrentLearnDir::Set (const QString& known, const QString& targ, bool new_LD)
{
    if(known != "" && targ != ""){
        if(!carcass->CurAccount->Get().isEmpty()){
            learn_dir.knownL = known;
            learn_dir.targL = targ;
            if(new_LD){
                if(!Initialize(true)) return false;
            }
            else{
                if(!carcass->CurLearnDirList->Contains(learn_dir)) return false;
                if(!Initialize(false)) return false;
            }
            if(!carcass->confUser_write()) return false;
            carcass->Menu_UpDate();
            return true;
        }
    }
    return false;
}
bool CurrentLearnDir::Initialize(bool new_LD)
{
    adress = carcass->adr.users_dir + carcass->CurAccount->Get().toLower() + "\\" + learn_dir.knownL + "_" + learn_dir.targL + carcass->adr.lext;
    initialized = false;
    if(new_LD){
        words.clear();
        dictionaries.clear();
        if(!WriteFile()) return false;
        initialized = true;
    }
    else{
        if(!ReadFile()) return false;
        if(!words.isEmpty()){
            for (int i = 0; i < words.size(); ++i){
                //if(words.at(i).word != carcass->symb.new_dictionary){
                    for (int u = 0; u < words[i].dictionaries.size(); ++u){
                        if(!dictionaries.contains(words[i].dictionaries[u])) dictionaries << words[i].dictionaries[u];
                    }
                //}
            }
        }
        initialized = true;
        return true;
    }
    return true;
}
bool CurrentLearnDir::Zeroing()
{
    words.clear();
    dictionaries.clear();
    learn_dir.knownL = "";
    learn_dir.targL = "";
    adress = "";
    initialized = false;
    return true;
}

const LD CurrentLearnDir::Get () const
{
    //if(!initialized)carcass->message("Не инициализирован CurLearnDir get");
    return learn_dir;
}

bool CurrentLearnDir::ReadFile()
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
bool CurrentLearnDir::WriteFile()
{
    Carcass::WriteResult wr = carcass->WriteFile(adress, words);
    switch (wr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        //carcass->message(carcass->enumWToQStr(wr) + "  " + adress);
        return false;
    }
}

void CurrentLearnDir::AddWord(Word& _word)
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
        carcass->message("Не инициализированн CurLearnDir AddWord"); //*************** Обработать исключение *************************
    }
}
void CurrentLearnDir::RemoveWord(QString str)
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
        carcass->message("Не инициализированн CurLearnDir RemoveWord"); //*************** Обработать исключение *************************
    }
}
bool CurrentLearnDir::AddDictionary(QString str)
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
                emit carcass->DctListChange();
                return true;
            }
        }
    }
    else{
        carcass->message("Не инициализированн CurLearnDir AddDct"); //*************** Обработать исключение *************************
    }
    return false;
}

void CurrentLearnDir::RemoveDictionary(const QString &str)
{
    if(initialized){

    }
    else{
        carcass->message("Не инициализированн CurLearnDir RemoveDct"); //*************** Обработать исключение *************************
    }
}

bool CurrentLearnDir::Contains(const QString str)
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
        carcass->message("Не инициализированн CurLearnDir Contains"); //*************** Обработать исключение *************************
        return false;
    }
}

int CurrentLearnDir::IndexOf(const QString str)
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
        carcass->message("Не инициализированн CurLearnDir IndexOf"); //*************** Обработать исключение *************************
        return -1;
    }
}

QDataStream& operator>> (QDataStream& out, CurrentLearnDir& cld)
{
    out >> cld.learn_dir;
    cld.Initialize(false);
    return out;
}

QDataStream& operator<< (QDataStream& in, const CurrentLearnDir& cld)
{
    in << cld.learn_dir;
    return in;
}

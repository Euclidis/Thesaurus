#include "carcass.h"

//************************************************************************************************
//                                     CurrentAccount
//************************************************************************************************
CurrentAccount::CurrentAccount(Carcass* _carcass) : carcass(_carcass)
{
    cur_Account = "";
    cur_AccoutOS = "";
    initialized = false;
}
//------------------------------------------------------------------------------------------------
bool CurrentAccount::Initialize ()
{
    if(!initialized){                                           //
        cur_AccoutOS = qgetenv("USER");                         //
        if (cur_AccoutOS.isEmpty())                             //     Запускается только в слотере
            cur_AccoutOS = qgetenv("USERNAME");                 //
                                                                //
        if(!cur_AccoutOS.isEmpty()){                            //   - получаем имя пользователя
            if(ReadFile()){                                     //     компьютера.
                initialized = true;                             //   - считываем список пользователей
                if (!Accounts.isEmpty()){                       //     компьютера и соответствующие им
                    if (Accounts.contains(cur_AccoutOS)){       //     имена аккаунтов тезауруса.
                        if(!Set(Accounts[cur_AccoutOS])){
                            initialized = false;
                            return false;                       //   - Если есть такой пользователь в
                        }
                    }                                           //     спискеи ему соответствует имя
                }                                               //     аккаунта тезауруса, присваиваем:
                return true;                                    //     cur_Account = полученное имя
            }                                                   //
        }                                                       //
        return false;                                           //
    }                                                           //
    else{
        return true;
    }                                           //
}
//------------------------------------------------------------------------------------------------
bool CurrentAccount::Set(const QString& user_name, bool new_account)
{
    if(initialized){
        if(user_name != cur_Account ){
            if(!user_name.isEmpty()){
                cur_Account = user_name;
                Accounts[cur_AccoutOS] = cur_Account;
                if(!WriteFile()) return false;
                if(new_account){
                    QString path = carcass->adr.users_dir
                                 + user_name.toLower();
                    QDir dir(path);
                    dir.mkpath(".");
                    if(!carcass->CurLearnDirList->Zeroing())
                        return false;
                    if(!Set_flag_AW_ignore(false))
                        return false;
                }
                else{
                    if(!carcass->confUser_read())
                        return false;
                }
            }
        }
        return true;
    }
    else{
        carcass->message("Необходимо инициализировать"
                         " класс CurrentAccount Set");
        return false;
    }
}
//------------------------------------------------------------------------------------------------
QString CurrentAccount::Get () const
{
    if(initialized){
        return cur_Account;
    }
    else{
        carcass->message("Необходимо инициализировать"
                         " класс CurrentAccount Get");
        return "";
    }
}
//------------------------------------------------------------------------------------------------
bool CurrentAccount::Set_flag_AW_ignore  (bool _flag)
{
    if(initialized){
        flag_AW_ignore = _flag;
        if(carcass->confUser_write()) return true;
        else return false;
    }
    else{
        carcass->message("Необходимо инициализировать"
                         " класс CurrentAccount Set_flag_AW_ignore");
        return false;
    }
}
//------------------------------------------------------------------------------------------------
bool CurrentAccount::Get_flag_AW_ignore ()
{
    if(initialized){
        return flag_AW_ignore;
    }
    else{
        carcass->message("Необходимо инициализировать"
                         " класс CurrentAccount Get_flag");
        return false;
    }
}
//------------------------------------------------------------------------------------------------
bool CurrentAccount::ReadFile()
{
    QString path = carcass->adr.config;
    Carcass::ReadResult rr = carcass->ReadFile(path, Accounts);
    switch (rr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        ex_some_show ex(QObject::tr("Problems reading file ") + path);
        ex.show();
        return false;
    }
}
//------------------------------------------------------------------------------------------------
bool CurrentAccount::WriteFile()
{
    if(initialized){
        QString path = carcass->adr.config;
        Carcass::WriteResult wr = carcass->WriteFile(path, Accounts);
        switch (wr) {
        case Carcass::WriteResult::OK:
            return true;
        default:
            ex_some_show ex(QObject::tr("Problems writing file ") + path);
            ex.show();
            return false;
        }
    }
    else{
        carcass->message("Необходимо инициализировать"
                         " класс CurrentAccount WriteFile");
        return false;
    }
}

//************************************************************************************************
//                                   CurrentLearnDirList
//************************************************************************************************

CurrentLearnDirList::CurrentLearnDirList(Carcass* _carcass) : carcass(_carcass)
{
}
//------------------------------------------------------------------------------------------------
bool CurrentLearnDirList::Add(const LearnDir& ld)
{
    if(!Contains(ld)){
        if(ld.knownL != "" && ld.targL != "") AllLD << ld;
        if(!carcass->CurLearnDir->Set(ld.knownL, ld.targL, true)) return false;
        if(!carcass->confUser_write()) return false;
    }
    return true;
}
//------------------------------------------------------------------------------------------------
bool CurrentLearnDirList::Zeroing()
{
    AllLD.clear();
    if(carcass->CurLearnDir->Zeroing()) return true;
    else return false;
}
//------------------------------------------------------------------------------------------------
const QList<LD>&  CurrentLearnDirList::Get () const
{
    return AllLD;
}
//------------------------------------------------------------------------------------------------
bool CurrentLearnDirList::Contains (const LearnDir& ld) const
{
    if(!AllLD.isEmpty()){
        for(int i = 0; i < AllLD.size(); ++i){
            if(AllLD.at(i).knownL == ld.knownL && AllLD.at(i).targL == ld.targL) return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------------------------
QDataStream& operator>> (QDataStream& out, LD& obj)
{
    out >> obj.knownL;
    out >> obj.targL;
    return out;
}
//------------------------------------------------------------------------------------------------
QDataStream& operator<< (QDataStream& in, const LD& obj)
{
    in << obj.knownL;
    in << obj.targL;
    return in;
}
//------------------------------------------------------------------------------------------------
QDataStream& operator>> (QDataStream& out, CurrentLearnDirList& obj)
{
    obj.AllLD.clear();
    out >> obj.AllLD;
    return out;
}
//------------------------------------------------------------------------------------------------
QDataStream& operator<< (QDataStream& in, const CurrentLearnDirList& obj)
{
    in << obj.AllLD;
    return in;
}


//************************************************************************************************
//                                           Word
//************************************************************************************************
Word::Word()
{
    date = QDate::currentDate();
    priority = 1;
}
Word::Word(QString _word,
           QString _transcription,
           QStringList &_translates,
           QStringList &_dictionaries,
           QString _note)
{
    date = QDate::currentDate();
    priority = 1;
    word = _word.trimmed();
    transcription = _transcription.trimmed();
    if(!_translates.isEmpty()){
        for(int i = 0; i < _translates.size(); ++i){
            translates << _translates.at(i).trimmed();
        }
    }
    if(!_dictionaries.isEmpty()){
        for(int i = 0; i < _dictionaries.size(); ++i){
            dictionaries << _dictionaries.at(i).trimmed();
        }
    }
    note = _note/*.trimmed()*/;
}
Word& Word::operator+=(const Word& _word)
{
    if(&_word != this){
        if (this->word == _word.word){
            for(int i = 0; i < _word.translates.size(); ++i){
                if(!(this->translates.contains(_word.translates[i]))) this->translates << _word.translates[i];
            }
            for(int i = 0; i < _word.dictionaries.size(); ++i){
                if(!(this->dictionaries.contains(_word.dictionaries[i]))) this->dictionaries << _word.dictionaries[i];
            }
            if(this->note != _word.note) this->note += "\n" + _word.note;
        }
    }
    return *this;
}
QDataStream& operator>>(QDataStream& out, Word& w)
{
    out >> w.word;
    out >> w.transcription;
    out >> w.translates;
    out >> w.dictionaries;
    out >> w.note;
    out >> w.date;
    out >> w.priority;
    return out;
}
QDataStream& operator<<(QDataStream& in, const Word& w)
{
    in << w.word;
    in << w.transcription;
    in << w.translates;
    in << w.dictionaries;
    in << w.note;
    in << w.date;
    in << w.priority;
    return in;
}

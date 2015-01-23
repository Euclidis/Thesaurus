#ifndef LD_H
#include "ld.h"
#endif

//-----------------------------------------------------------------------------------------------
LearnDir::LearnDir(LearnDirParameter &_parameter) :
    DataListItem<LearnDirParameter>(_parameter)
{
    filled = false;
    name = _parameter.name;
    known_lang = _parameter.known_lang;
    targ_lang = _parameter.targ_lang;
    adress = Adr::users_dir + _parameter.cur_account.toLower() + "\\"
           + name + Adr::ext_l;
    if(LL == nullptr) qDebug() << "LearnDir::LearnDir 1";//****************************** Необходимо исключение
    if(!WriteFile()) qDebug() << "Проблема при создании объекта LD, во время записи в файл";
    //****************************** Необходимо исключение
}
//-----------------------------------------------------------------------------------------------
LearnDir::LearnDir(LearnDirParameter& _parameter, const QString& _adress) :
    DataListItem<LearnDirParameter>(_parameter)
{
    filled = false;
    name = _parameter.name;
    adress = _adress;
    if(!ReadFile()) qDebug() << "Проблема при создании объекта LD, во время чтения из файла";
    //****************************** Необходимо исключение
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::Filling()
{
    if(!ReadFile())return false;
    if(!words.isEmpty()){
        dictionaries.clear();
        for (int i = 0; i < words.size(); ++i){
            for (int u = 0; u < words[i].dictionaries.size(); ++u){
                if(!dictionaries.contains(words[i].dictionaries[u])) dictionaries << words[i].dictionaries[u];
            }
        }
    }
    filled = true;
    return true;
}
//-----------------------------------------------------------------------------------------------
void LearnDir::Ravage()
{
    words.clear();
    dictionaries.clear();
    filled = false;
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::WriteFile()
{
    RW::WriteResult wr = RW::WriteFile(adress, *this);
    switch (wr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << "Error: " << RW::enumWToQStr(wr) << "  " << adress;
        return false;
    }
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::ReadFile()
{
    RW::ReadResult rr = RW::ReadFile(adress, *this);
    switch (rr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << "Error: " << RW::enumRToQStr(rr) << "  " << adress;
        return false;
    }
}
//-----------------------------------------------------------------------------------------------
QDataStream& operator>> (QDataStream& out, LearnDir& ld)
{
    out >> ld.known_lang;
    out >> ld.targ_lang;
    out >> ld.words;

    return out;
}
//-----------------------------------------------------------------------------------------------
QDataStream& operator<< (QDataStream& in, const LearnDir& ld)
{
    in << ld.known_lang;
    in << ld.targ_lang;
    in << ld.words;

    return in;
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::AddWord(Word& _word)
{
    if(!filled){
        qDebug() << "filled = false LearnDir (AddWord)";
        return false;
    }
    if(_word.word.isEmpty()) return false;
    if(_word.translates.isEmpty()) return false;
    int n = IndexOf(_word.word);
    if (n < 0){
        words << _word;
    }
    else{
        words[n] += _word;
    }
    for(int i = 0; i < _word.dictionaries.size(); ++i){
        AddDictionary(_word.dictionaries.at(i));
    }
    if(!WriteFile()){
        qDebug() << "Новое слово не сохранилось";
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::RemoveWord(const QString& _word)
{
    if(!filled){
        qDebug() << "filled = false LearnDir (RemoveWord)";
        return false;
    }
    int n = IndexOf(_word);
    if(n < 0) return true;
    if(_word == Symb::new_dictionary){
        qDebug() << "Попытка удалить скрытое служебное слово";
        return false;
    }
    words.removeAt(n);
    if(!WriteFile()){
        qDebug() << "Слово было удалено из списка, но изменения не сохранились";
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::AddDictionary(const QString& dct_name)
{
    if(!filled){
        qDebug() << "filled = false LearnDir (AddDictionary)";
        return false;
    }
    if(dct_name.isEmpty()) return false;
    if(dictionaries.contains(dct_name))return false;
    dictionaries << dct_name;
    QStringList dct_list;
    dct_list << dct_name;
    Word w(Symb::new_dictionary, "", dct_list, dct_list, "");
    if(!AddWord(w)) return false;
    return true;
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::RemoveDictionary(const QString &dct_name)
{
    if(!filled){
        qDebug() << "filled = false LearnDir (RemoveDictionary)";
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------
QVector<int> LearnDir::DictionaryWords (const QString& dct_name)
{
    QVector<int> list;
    if(!filled){
        qDebug() << "filled = false LearnDir (DictionaryWords)";
        return list;
    }
    if(!dictionaries.contains(dct_name))return list;
    for(int i = 0; i < words.size(); ++i){
        if(words.at(i).dictionaries.contains(dct_name)) list << i;
    }
    return list;
}
//-----------------------------------------------------------------------------------------------
bool LearnDir::Contains(const QString& str)
{
    if(!filled){
        qDebug() << "filled = false (LearnDir::Contains)";
        return false;
    }
    for(int i = 0; i < words.size(); ++i){
        if(words.at(i).word == str) return true;
    }
    return false;
}
//-----------------------------------------------------------------------------------------------
int  LearnDir::IndexOf(const QString& str)
{
    if(!filled){
        qDebug() << "filled = false (LearnDir::IndexOf)";
        return false;
    }
    for(int i = 0; i < words.size(); ++i){
        if(words.at(i).word == str) return i;
    }
    return -1;
}
//-----------------------------------------------------------------------------------------------

#ifndef LANGUAGE_METHODS_H
#define LANGUAGE_METHODS_H

#ifndef CARCASS_H
#include "carcass.h"
#endif

class Language
{
//*****************************************
//               INTERFACE
//*****************************************
public:
    QString name;                       //Имя языка
    QList<Word> words;                  //Список слов языка
    QList<QString> dictionaries;        //Спиок словарей
public:
    bool Initialize();                  //Обязательно необходимо вызвать при создании экземпляра класса
    bool Contains(const QString str);
    int  IndexOf(const QString str);
    bool WriteFile();
    bool ReadFile();
    void AddWord(Word &_word);
    void RemoveWord(QString);
    bool AddDictionary(QString);
    void RemoveDictionary(QString);
//-----------------------------------------
public:
    Language(Carcass *_carcass);
//*****************************************

private:
    Carcass* carcass;
    QString adress;
    bool initialized;
};


#endif // LANGUAGE_METHODS_H

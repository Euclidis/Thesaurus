#ifndef LANGUAGE_METHODS_H
#define LANGUAGE_METHODS_H

#ifndef CARCASS_H
#include "carcass.h"
#endif

class Language
{
    //*****************************************
    //               Интерфейс
    //*****************************************
public:
    L_D_List::L_Direct learn_dir;
    QList<Word> words;                  //Список слов языка
    QList<QString> dictionaries;        //Спиок словарей
public:
    bool Initialize();                  //Обязательно необходимо вызвать при создании экземпляра класса

    bool Contains(const QString str);
    int  IndexOf(const QString str);

    void AddWord(Word &_word);
    void RemoveWord(QString);
    bool AddDictionary(QString);
    void RemoveDictionary(const QString&);
    //*****************************************
    //            Служебная часть
    //*****************************************
public:
    Language(Carcass *_carcass);

private:
    Carcass* carcass;
    QString adress;
    bool initialized;
    bool WriteFile();
    bool ReadFile();
    //*****************************************
};


#endif // LANGUAGE_METHODS_H

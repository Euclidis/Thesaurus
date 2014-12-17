#ifndef LANGUAGE_METHODS_H
#define LANGUAGE_METHODS_H

#ifndef CARCASS_H
#include "carcass.h"
#endif

class Language
{
//-----------------------------------------
//INTERFACE
//-----------------------------------------
public:
    QList<Word> words;
public:
    bool Initialize();
    bool Contains(const QString str);
    int  IndexOf(const QString str);
    bool WriteFile();
    bool ReadFile();
    void AddNewWord(Word &_word);
//-----------------------------------------

private:
    Carcass* carcass;
    QString adress;
    bool initialized;

public:
    Language(Carcass *_carcass);
};


#endif // LANGUAGE_METHODS_H

#ifndef LANGUAGE_METHODS_H
#define LANGUAGE_METHODS_H

#include "carcass.h"

class Language
{
//-----------------------------------------
//INTERFACE
//-----------------------------------------
public:
    QString newWord;
    QString newTranscription;
    QStringList newTranslates;
    QStringList newDictionarys;
    QString newNote;
public:
    bool WriteFile();
    bool ReadFile();
    bool AddNewWord();
//-----------------------------------------

private:
    Carcass* carcass;
    QString adress;
    QDate date;

    LanguageForDataStream language;

public:
    Language(Carcass *_carcass, bool &flag_good);

};


#endif // LANGUAGE_METHODS_H

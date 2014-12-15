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
    bool contains(QString);
    int  indexOf(QString);
    bool WriteFile();
    bool ReadFile();
    bool AddNewWord();
//-----------------------------------------

private:
    Carcass* carcass;
    QString adress;
    QDate date;

public:
    Language(Carcass *_carcass, bool &flag_good);
};


#endif // LANGUAGE_METHODS_H

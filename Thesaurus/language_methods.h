#ifndef LANGUAGE_METHODS_H
#define LANGUAGE_METHODS_H

#include "carcass.h"

class LanguageMethods
{
private:
    Carcass* carcass;
    QString adress;
    QDate date;
    Language language;

public:
    LanguageMethods(Carcass *_carcass, QString _adress, bool &flag_good);
    bool Write();
    bool AddNewWords(Word& _word);

private:
    bool ReadFile(Carcass::ReadResult rr);
};

#endif // LANGUAGE_METHODS_H

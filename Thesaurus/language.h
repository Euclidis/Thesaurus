#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "carcass.h"

struct Word
{
    QString word;
    QString transcription;
    QStringList translate;
    QStringList dictionary;
    QString note;
    QDate date;
    double priority;
};

class Language
{
private:
    Carcass * carcass;
    QString adress;
    QDate date;

    QList<QString> words;
    QList<QString> transcriptions;
    //QList<QMultiMap> translates;
    QList<QString> notes;
    QList<QDate> dates;
    QList<double> priorities;
public:
    Language(Carcass * _carcass, QString _adress, bool &flag_good);
    bool Write();

private:
    bool ReadFile(Carcass::ReadResult rr);
};

#endif // LANGUAGE_H

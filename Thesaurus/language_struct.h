#ifndef LANGUAGE_H
#define LANGUAGE_H

#include "exceptions_list.h"

struct Language
{
    QList<QString> words;
    QList<QString> transcriptions;
    QList<QMultiMap<QString, QString>> translates;
    QList<QString> notes;
    QList<QDate> dates;
    QList<double> priorities;
};

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

#endif // LANGUAGE_H

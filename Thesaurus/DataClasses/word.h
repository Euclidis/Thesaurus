#ifndef WORD_H
#define WORD_H

#ifndef ITEMS_H
#include "items.h"
#endif

struct Word
{
    QString word;
    QString transcription;
    QStringList translates;
    QStringList dictionaries;
    QString note;
private:
    QDate date;
    double priority;
public:
    Word();
    Word(QString _word,
         QString _transcription,
         QStringList &_translates,
         QStringList &_dictionaries,
         QString _note);
    Word& operator+= (const Word& _word);
    friend QDataStream& operator>> (QDataStream& out, Word& w);
    friend QDataStream& operator<< (QDataStream& in, const Word& w);
};

#endif // WORD_H


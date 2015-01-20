#ifndef C_WORD
#include "c_word.h"
#endif

//-----------------------------------------------------------------------------------------------
Word::Word()
{
    date = QDate::currentDate();
    priority = 1;
}
Word::Word(QString _word,
           QString _transcription,
           QStringList &_translates,
           QStringList &_dictionaries,
           QString _note)
{
    date = QDate::currentDate();
    priority = 1;
    word = _word.trimmed();
    transcription = _transcription.trimmed();
    for(int i = 0; i < _translates.size(); ++i){
        translates << _translates.at(i).trimmed();
    }
    for(int i = 0; i < _dictionaries.size(); ++i){
        dictionaries << _dictionaries.at(i).trimmed();
    }
    note = _note.trimmed();
}
//-----------------------------------------------------------------------------------------------
Word& Word::operator+=(const Word& _word)
{
    if(&_word == this) return *this;
    if (this->word != _word.word) return *this;

    for(int i = 0; i < _word.translates.size(); ++i){
        if(!(this->translates.contains(_word.translates.at(i)))) this->translates << _word.translates.at(i);
    }
    for(int i = 0; i < _word.dictionaries.size(); ++i){
        if(!(this->dictionaries.contains(_word.dictionaries.at(i)))) this->dictionaries << _word.dictionaries.at(i);
    }
    if(this->note != _word.note) this->note += "\n" + _word.note;
    return *this;
}
//-----------------------------------------------------------------------------------------------
QDataStream& operator>>(QDataStream& out, Word& w)
{
    out >> w.word;
    out >> w.transcription;
    out >> w.translates;
    out >> w.dictionaries;
    out >> w.note;
    out >> w.date;
    out >> w.priority;
    return out;
}
//-----------------------------------------------------------------------------------------------
QDataStream& operator<<(QDataStream& in, const Word& w)
{
    in << w.word;
    in << w.transcription;
    in << w.translates;
    in << w.dictionaries;
    in << w.note;
    in << w.date;
    in << w.priority;
    return in;
}
//-----------------------------------------------------------------------------------------------

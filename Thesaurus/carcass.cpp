#include "carcass.h"

//===============================================================================
//                     Чтение и запись файла конфигурации
//===============================================================================
void Carcass::conf_write()
{
    WriteResult wr = WriteFile(adr.config, QMapAccounts);
    switch (wr) {
    case WriteResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems writing the file ") + adr.config);
        ex.show();
        message(enumWToQStr(wr));
    }
}
void Carcass::conf_read()
{
    ReadResult rr = ReadFile(adr.config, QMapAccounts);
    switch (rr) {
    case ReadResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.config);
        ex.show();
        message(enumRToQStr(rr));
    }
}

//===============================================================================
//                     Чтение и запись файла конфигурации юзера
//===============================================================================
void Carcass::confUser_write()
{
    QStringList data;
    QString str = current_account.toLower();
    try
    {
        data << current_language_interface << current_learn_dir.knownL << current_learn_dir.targL << (QString::number(flag_AWIgnore));
    }
    catch(...){
        ex_some_show ex(QObject::tr("Problems writing the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
        return;
    }
    WriteResult wr = WriteFile(adr.users_dir + str + adr.user_config, data);
    switch (wr) {
    case WriteResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems writing the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
        message(enumWToQStr(wr));
    }
}
void Carcass::confUser_read()
{
    QString str = current_account.toLower();

    QStringList data;
    ReadResult rr = ReadFile(adr.users_dir + str + adr.user_config, data);
    switch (rr) {
    case ReadResult::OK:
        break;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
        message(enumRToQStr(rr));
        return;
    }
    try
    {

          current_language_interface = data.at(0);
          current_learn_dir.knownL = data.at(1);
          current_learn_dir.targL = data.at(2);
          flag_AWIgnore = ((data.at(3) == "0") ? false : true);

    }
    catch(...){
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
    }
}

//===============================================================================
//                                  Месседжи
//===============================================================================
void Carcass::message(QString str, bool _modal)
{
    MessageWindow* ms = new MessageWindow(str, _modal);
    ms->show();
}
void Carcass::mesOKCancel(QString str)
{
    emit mesOKCancelShow(str);
}

//===============================================================================
//              Преобразование enum ReadResult и WriteResult в QString
//===============================================================================
QString Carcass::enumWToQStr (WriteResult wr)
{
    switch (wr) {
    case WriteResult::OK:
        return "OK";
    case WriteResult::Write:
        return "Write";
    case WriteResult::Open:
        return "Open";
    case WriteResult::Copy:
        return "Copy";
    case WriteResult::DelTmpWhileCopy:
        return "DelTmpWhileCopy";
    case WriteResult::DelSource:
        return "DelSource";
    case WriteResult::DelTmp:
        return "DelTmp";
    case WriteResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}
QString Carcass::enumRToQStr (ReadResult rr)
{
    switch (rr) {
    case ReadResult::OK:
        return "OK";
    case ReadResult::DelTmp:
        return "DelTmp";
    case ReadResult::NotFound:
        return "NotFound";
    case ReadResult::Open:
        return "Open";
    case ReadResult::Read:
        return "Read";
    case ReadResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}


//===============================================================================
//                               Методы Word
//===============================================================================
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
    if(!_translates.isEmpty()){
        for(int i = 0; i < _translates.size(); ++i){
            translates << _translates.at(i).trimmed();
        }
    }
    if(!_dictionaries.isEmpty()){
        for(int i = 0; i < _dictionaries.size(); ++i){
            dictionaries << _dictionaries.at(i).trimmed();
        }
    }
    note = _note/*.trimmed()*/;
}
Word& Word::operator+=(const Word& _word)
{
    if(&_word != this){
        if (this->word == _word.word){
            for(int i = 0; i < _word.translates.size(); ++i){
                if(!(this->translates.contains(_word.translates[i]))) this->translates << _word.translates[i];
            }
            for(int i = 0; i < _word.dictionaries.size(); ++i){
                if(!(this->dictionaries.contains(_word.dictionaries[i]))) this->dictionaries << _word.dictionaries[i];
            }
            if(this->note != _word.note) this->note += "\n" + _word.note;
        }
    }
    return *this;
}
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

#include "carcass.h"

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
void Carcass::confUser_write(QString str)
{
    QStringList data;
    try
    {
        data << current_language_interface << current_language << (QString::number(flag_AWIgnore));
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
void Carcass::confUser_read(QString str)
{
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
        current_language = data.at(1);
        flag_AWIgnore = ((data.at(2) == "0") ? false : true);
    }
    catch(...){
        ex_some_show ex(QObject::tr("Problems reading the file ") + adr.users_dir + str + adr.user_config);
        ex.show();
    }
}

void Carcass::message(QString str, bool _modal)
{
    MessageWindow* ms = new MessageWindow(str, _modal);
    ms->show();
}

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

QDataStream& operator>>(QDataStream& out, LanguageForDataStream& lang)
{
    out >> lang.words;
    out >> lang.transcriptions;
    out >> lang.translates;
    out >> lang.dictionaryes;
    out >> lang.notes;
    out >> lang.dates;
    out >> lang.priorities;
    return out;
}

QDataStream& operator<<(QDataStream& in, LanguageForDataStream& lang)
{
    in << lang.words;
    in << lang.transcriptions;
    in << lang.translates;
    in << lang.dictionaryes;
    in << lang.notes;
    in << lang.dates;
    in << lang.priorities;
    return in;
}

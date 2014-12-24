#include "carcass.h"

Carcass::Carcass(){}

//===============================================================================
//                     Чтение и запись файла конфигурации юзера
//===============================================================================
Carcass::confUser_file::confUser_file(Carcass* _carcass) : carcass(_carcass)
{
}

QDataStream& operator>> (QDataStream& out, Carcass::confUser_file& cuf)
{
    out >> *(cuf.carcass->CurLearnDirList);
    out >> *(cuf.carcass->CurLearnDir);
    out >> *(cuf.carcass->CurAccount);
    return out;
}
QDataStream& operator<< (QDataStream& in, const Carcass::confUser_file& cuf)
{
    in << *(cuf.carcass->CurLearnDirList);
    in << *(cuf.carcass->CurLearnDir);
    in << *(cuf.carcass->CurAccount);
    return in;
}

bool Carcass::confUser_write()
{
    if(CurAccount->Get() == "") return false;
    QString path = adr.users_dir + CurAccount->Get().toLower() + adr.user_config ;
    confUser_file f(this);

    WriteResult wr = WriteFile(path, f);
    switch (wr) {
    case WriteResult::OK:
        return true;
    default:
        ex_some_show ex(QObject::tr("Problems writing the file ") + path);
        ex.show();
        message(enumWToQStr(wr));
        return false;
    }
}
bool Carcass::confUser_read()
{
    QString path =adr.users_dir + CurAccount->Get().toLower() + adr.user_config ;
    confUser_file f(this);

    ReadResult rr = ReadFile(path, f);
    switch (rr) {
    case ReadResult::OK:
        return true;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + path);
        ex.show();
        message(enumRToQStr(rr));
        return false;
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

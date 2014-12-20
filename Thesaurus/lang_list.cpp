#include "carcass.h"

LangList::LangList(Carcass *_carcass){
    carcass = _carcass;
    initialized = false;
    if(!WriteFile()) carcass->message("Error");
}

bool LangList::Initialize()
{
    if(ReadFile()){
        initialized = true;
        return true;
    }
    return false;
}

const LangList::Lang* LangList::getLang(QString str)
{
    if(initialized){
        if(!Lang_List.isEmpty()){
            for(int i = 0; i < Lang_List.size(); ++i){
                if(Lang_List.at(i).name_eng == str) return &(Lang_List.at(i));
            }
        }
        return nullptr;
    }
    return nullptr;
}

const QList<LangList::StrIco> LangList::getStrIcoList()
{
    QList<StrIco> tempList;
    if(initialized){
        if(!Lang_List.isEmpty()){
            StrIco temp;
            for(int i = 0; i < Lang_List.size(); ++i){
                temp.icon = &(Lang_List.at(i).ico);
                temp.name = &(Lang_List.at(i).name_eng);
                tempList << temp;
            }
            return tempList;
        }
    }
    return tempList;
}

QDataStream& operator>>(QDataStream& out, LangList::Lang& l)
{
    out >> l.name_eng;
    out >> l.name_native;
    out >> l.ico;
    out >> l.transcript;
    out >> l.keyboard;
    return out;
}
QDataStream& operator<<(QDataStream& in, const LangList::Lang& l)
{
    in << l.name_eng;
    in << l.name_native;
    in << l.ico;
    in << l.transcript;
    in << l.keyboard;
    return in;
}

bool LangList::ReadFile()
{
    Carcass::ReadResult rr = Carcass::ReadFile(carcass->adr.LangList, Lang_List);
    switch (rr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + carcass->adr.LangList);
        ex.show();
        carcass->message(Carcass::enumRToQStr(rr));
    }
    return false;
}
bool LangList::WriteFile()
{
    StrIco temp;
    *(temp.name) = "English";
    temp.icon = new QIcon("C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Res\\settings\\language\\images\\en.png");
    Lang_List << temp;
    *(temp.name) = "Russian";
    temp.icon = new QIcon("C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Res\\settings\\language\\images\\ru.png");
    Lang_List << temp;
    *(temp.name) = "Germany";
    temp.icon = new QIcon("C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Res\\settings\\language\\images\\ger.png");
    Lang_List << temp;

    Carcass::WriteResult wr = carcass->WriteFile(carcass->adr.LangList, Lang_List);
    switch (wr) {
    case Carcass::WriteResult::OK:
        return true;
    default:
        ex_some_show ex(QObject::tr("Problems writing the file ") + carcass->adr.LangList);
        ex.show();
        carcass->message(carcass->enumWToQStr(wr));
    }
    return false;
}

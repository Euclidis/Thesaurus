#include "carcass.h"
#include <QPixmap>

LangList::LangList(Carcass *_carcass){
    carcass = _carcass;
    initialized = false;
    //if(!WriteFile()) carcass->message("Error");
}

bool LangList::Initialize()
{
    if(ReadFile()){
        initialized = true;
        return true;
    }
    return false;
}

const LangList::Lang* LangList::getLang(const QString& str)
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

QList<LangList::StrIco> LangList::getStrIcoList()
{
    QList<StrIco> tempList;
    if(initialized){
        if(!Lang_List.isEmpty()){
            for(int i = 0; i < Lang_List.size(); ++i){
                StrIco temp(&Lang_List.at(i).name_eng, &Lang_List.at(i).ico);
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
    Carcass::ReadResult rr = carcass->ReadFile(carcass->adr.LangList, Lang_List);
    switch (rr) {
    case Carcass::ReadResult::OK:
        return true;
    default:
        ex_some_show ex(QObject::tr("Problems reading the file ") + carcass->adr.LangList);
        ex.show();
        carcass->message(carcass->enumRToQStr(rr));
    }
    return false;
}
bool LangList::WriteFile()
{
    Lang temp;
    temp.name_eng = "English";
    QPixmap p1("C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Res\\settings\\language\\images\\en.png");
    temp.ico.addPixmap(p1);
    Lang_List << temp;
    temp.name_eng = "Russian";
    QPixmap p2("C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Res\\settings\\language\\images\\ru.png");
    temp.ico.addPixmap(p2);
    Lang_List << temp;
    temp.name_eng = "Germany";
    QPixmap p3("C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Res\\settings\\language\\images\\ger.png");
    temp.ico.addPixmap(p3);
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

LangList::StrIco::StrIco(const QString* _name, const QIcon* _icon) : name(_name), icon(_icon)
{

}

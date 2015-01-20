#ifndef D_LANG_LIST
#include "../I_General/d_lang_list.h"
#endif

QDataStream& operator>>(QDataStream& out, Language& l)
{
    out >> l.name_eng;
    out >> l.name_native;
    out >> l.name_reduction;
    out >> l.qm;
    out >> l.ico;
//    out >> l.transcript;
//    out >> l.keyboard;
    return out;
}
QDataStream& operator<<(QDataStream& in, const Language& l)
{
    in << l.name_eng;
    in << l.name_native;
    in << l.name_reduction;
    in << l.qm;
    in << l.ico;
//    in << l.transcript;
//    in << l.keyboard;
    return in;
}

LanguageList::LanguageList(){
    if(!ReadFile()) throw;
}

const Language* LanguageList::at(int language_number) const
{
    if((list.size() > language_number) && !(language_number < 0)) return &list.at(language_number);
    return nullptr;
}

const Language* LanguageList::at(const QString _language) const
{
    for(int i = 0; i < list.size(); ++i){
        if(list.at(i).name_eng == _language) return &list.at(i);
    }
    return nullptr;
}

int LanguageList::size() const
{
    return list.size();
}

bool LanguageList::ReadFile()
{
    RW::ReadResult rr = RW::ReadFile(Adr::lang_list_file, list);
    switch (rr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << (RW::enumRToQStr(rr));
    }
    return false;
}
bool LanguageList::WriteFile()
{
    Language temp;
    QString path = "C:\\Users\\Amir\\Documents\\GitHub\\Thesaurus\\Notes\\images\\L";
    QDir image_directory(path);
    QStringList flagIcons = image_directory.entryList(QDir::Files);
    if (!flagIcons.isEmpty())
    for (int i = 0; i < flagIcons.size(); ++i){
        QPixmap pix(path + "\\" + flagIcons.at(i));
        temp.ico.addPixmap(pix);
        temp.name_eng = flagIcons.at(i).left(flagIcons.at(i).size()-4);
        list << temp;
    }

    RW::WriteResult wr = RW::WriteFile(Adr::lang_list_file, list);
    switch (wr) {
    case RW::WriteResult::OK:
        return true;
    default:
        qDebug() << RW::enumWToQStr(wr);
    }
    return false;
}

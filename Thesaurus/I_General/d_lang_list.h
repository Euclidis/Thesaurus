#ifndef D_LANG_LIST
#define D_LANG_LIST

#ifndef C_READ_WRITE
#include "c_read_write.h"
#endif

struct Language
{
public:
    QString name_eng;
    QString name_native;
    QString name_reduction;
    QString qm;
    QIcon ico;
    //QList<QChar>transcript;
    //int keyboard;
public:
    friend QDataStream& operator>> (QDataStream& out, Language& l);
    friend QDataStream& operator<< (QDataStream& in, const Language& l);
};

class LanguageList
{
public:
    const Language* at(int language_number) const;
    const Language* at(const QString _language) const;
    int size() const;
public:
    LanguageList();
private:
    QList<Language> list;
private:
    bool ReadFile();
    bool WriteFile();
};

#endif // D_LANG_LIST


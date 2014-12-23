#ifndef LANGLIST
#define LANGLIST

#include "exceptions_list.h"

class Carcass;


class LangList{
public:
    struct Lang{                    //
        QString name_eng;           //
        QString name_native;        //
        QIcon ico;                  // Структура для списка языков
        int keyboard;               //
        QList<QChar> transcript;    //
    };                              //
    struct StrIco{                                          //
        StrIco(const QString* _name, const QIcon* _icon);   //
        const QString* name;                                // Структура для списка имен и иконок языков
        const QIcon* icon;                                  //
    };                                                      //
public:
    //***************************************************
    //                   Интерфейс
    //***************************************************
    const Lang*      getLang    (const QString&);
    QList<StrIco> getStrIcoList ();
    bool            Initialize  ();
    //***************************************************
    //                Служебная часть
    //***************************************************
public:
    LangList(Carcass*);
    friend QDataStream& operator>> (QDataStream& out, Lang& l);
    friend QDataStream& operator<< (QDataStream& in, const Lang& l);
private:
    Carcass* carcass;
    QList<Lang> Lang_List;
    bool initialized;
private:
    bool ReadFile();
    bool WriteFile();
    //***************************************************
};

#endif // LANGLIST


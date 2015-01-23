#ifndef ITEMS_H
#define ITEMS_H

#ifndef LISTS_H
#include "lists.h"
#endif

//*********************************************************************************************
//                            Абстрактный класс пункта для списка
//*********************************************************************************************

template<class T>
class DataListItem
{
public:
    QString name;
    const LanguageList* LL;
    template<class T>
    DataListItem (T& _parameter): LL(_parameter.LL){}
protected:
    QString& GetAdress() {return adress;}
    virtual bool Filling() = 0;
    virtual void Ravage() = 0;
    virtual bool ReadFile() = 0;
    virtual bool WriteFile() = 0;
protected:
    QString adress;
    bool filled;
};

#endif // ITEMS_H


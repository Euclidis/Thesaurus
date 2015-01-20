#ifndef B_ITEMS
#define B_ITEMS

#ifndef A_LISTS_H
#include "a_lists.h"
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

#endif // B_ITEMS


#ifndef A_LISTS_H
#define A_LISTS_H

#ifndef E_BASE_WINDOW_H
#include "../I_General/e_base_window.h"
#endif

//*********************************************************************************************
//                                   Шаблон для списков
//*********************************************************************************************
template<class T, class U>
class DataList
{
    typedef const QString& str;
    //***************************************************************************
    //                  Интерфейс
    //***************************************************************************
public:
    bool   AddItem         (U &_parameter);
    bool   RemoveItem      (str _name);
    bool   SelectItem      (str _name);
    T*     SelectionItem   () const;
    T*     at              (int item_number) const;
    int    size            () const;
    int    IndexOf         (str _name) const;
    bool   Contains        (str _name) const;
    //***************************************************************************
private:
    QList<T*> list;
    int selection_index;
    QString adress;
    const LanguageList* LL;
public:
    DataList(const LanguageList *_LL, str _adress);
    template<class T, class U>
    friend QDataStream& operator>> (QDataStream& out, DataList<T, U>& dl);
    template<class T, class U>
    friend QDataStream& operator<< (QDataStream& in, const DataList<T, U>& dl);
private:
    bool ReadFile();
    bool WriteFile();
    bool AddItemFromFile(const QString &_name, const QString& _adress);
    QString& GetAdressItem(T* t) const;
    bool SelectItemFromFile(str _name);
};

//*********************************************************************************************
//                           Определения ф-й шаблона списков
//*********************************************************************************************

template<class T, class U>
DataList<T, U>::DataList (const LanguageList* _LL, str _adress) :
    LL (_LL)
{
    selection_index = -1;
    adress = _adress;
    if(!ReadFile()) qDebug() << "Ошибка при чтении файла (DataList<T, U>::DataList)";
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::AddItem (U& _parameter)
{
    if(Contains(_parameter.name)) return true;
    try
    {
        T* t = new T(_parameter);
        list << t;
    }
    catch(...){qDebug() << "Exception";}
    if(!Contains(_parameter.name)){
        qDebug() << "аккаунт не добавился в список (DataList<T, U>::AddItem)";
        return false;
    }
    if(SelectItem(list.at(IndexOf(_parameter.name))->name)) return true;
    qDebug() << "Добавленный аккаунт не смог выделиться и будет удален";
    RemoveItem(_parameter.name);
    return false;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::RemoveItem (str _name)
{
    //Работа с selection_index и файлами должна быть проработана где-либо
    if(!WriteFile()){
        qDebug() << "Проблема при записи в файл (AccountList::RemoveItem)";
        return false;
    }
    return false;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::SelectItem (str _name)
{
    if(list.isEmpty())return false;
    int n = IndexOf(_name);
    if(n < 0) return false;
    if(selection_index == n) return true;
    if(selection_index > -1) list.at(selection_index)->Ravage();
    if(!(list.at(n)->Filling())) {
        list.at(n)->Ravage();
        selection_index = -1;
        qDebug() << "Выбранный пунк списка направлений не смог заполниться";
        return false;
    }
    int temp = selection_index;
    selection_index = n;
    if(!WriteFile()){
        selection_index = temp;
        qDebug() << "Проблема при записи в файл (AccountList::SelectItem)";
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
T* DataList<T, U>::SelectionItem() const
{
    if((selection_index > -1) && (selection_index < list.size())) return list[selection_index];
    return nullptr;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
T *DataList<T, U>::at(int item_number) const
{
    if((item_number > -1) && (item_number < list.size())){
        return list[item_number];
    }
    else return nullptr;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
int DataList<T, U>::size () const
{
    return list.size();
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
int DataList<T, U>::IndexOf(str _name)  const
{
    for(int i = 0; i < list.size(); ++i){
        if(list.at(i)->name == _name) return i;
    }
    return -1;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::Contains (str _name) const
{
    for(int i = 0; i < list.size(); ++i){
        if(list.at(i)->name == _name) return true;
    }
    return false;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::AddItemFromFile(const QString &_name, const QString &_adress)
{
    if(Contains(_name)) return true;
    U u;
    u.name = _name;
    u.LL = LL;
    try
    {
        T* t = new T(u, _adress);
        list << t;
    }
    catch(...){qDebug() << "Exception"; return false;}
    if(!Contains(_name)){
        qDebug() << "аккаунт н едобавился в список (AccountList::AddItem)";
        return false;
    }
    return true;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::SelectItemFromFile(str _name)
{
    if(list.isEmpty())return false;
    int n = IndexOf(_name);
    if(n < 0) return false;
    if(selection_index == n) return true;
    if(selection_index > -1) list.at(selection_index)->Ravage();
    if(!(list.at(n)->Filling())) {
        list.at(n)->Ravage();
        selection_index = -1;
        qDebug() << "1 Выбранный пунк списка направлений не смог заполниться";
        return false;
    }
    selection_index = n;
    return true;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::ReadFile()
{
    RW::ReadResult rr = RW::ReadFile(adress, *this);
    switch (rr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << "Error: " << RW::enumRToQStr(rr) << "  " << adress;
        return false;
    }
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
bool DataList<T, U>::WriteFile()
{
    RW::WriteResult wr = RW::WriteFile(adress, *this);
    switch (wr) {
    case RW::ReadResult::OK:
        return true;
    default:
        qDebug() << "Error: " << RW::enumWToQStr(wr) << "  " << adress;
        return false;
    }
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
QDataStream& operator>> (QDataStream& out, DataList<T, U>& dl)
{
    QMap<QString, QString> map;
    QString selected_item;

    out >> map;
    QMap<QString, QString>::iterator i = map.begin();
    while(i != map.end()){
        dl.AddItemFromFile(i.key(), i.value());
        ++i;
    }
    out >> selected_item;
    dl.SelectItemFromFile(selected_item);

    return out;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
QDataStream& operator<< (QDataStream& in, const DataList<T, U>& dl)
{
    QMap<QString, QString> map;

    for(int i = 0; i < dl.size(); ++i){
        if(dl.at(i) != nullptr){
            map.insert(dl.at(i)->name, dl.GetAdressItem(dl.at(i)));
        }
        else {
            map.insert("", "");
        }
    }
    in << map;
    if(dl.SelectionItem() != nullptr){
        in << dl.SelectionItem()->name;
    }
    else in << "";

    return in;
}
//-----------------------------------------------------------------------------------------------
template<class T, class U>
QString& DataList<T, U>::GetAdressItem(T* t) const
{
    return t->GetAdress();
}

#endif // A_LISTS_H


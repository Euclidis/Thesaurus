#ifndef D_LD_H
#define D_LD_H

#ifndef C_WORD
#include "c_word.h"
#endif
class LearnDir;
//-----------------------------------------------------------------------------------------
class LearnDirParameter
{
public:
    QString name;
    QString known_lang;
    QString targ_lang;
    const LanguageList* LL;
    QString cur_account;
};
//-----------------------------------------------------------------------------------------
class LearnDir : public DataListItem<LearnDirParameter>
{
    //*************************************************
    //                  Интерфейс
    //*************************************************
public:
    //                Данные                      Методы
    QList<Word>      words;                 bool AddWord          (Word &_word);
    QList<QString>   dictionaries;          bool RemoveWord       (const QString& _word);
    QString          known_lang;            bool AddDictionary    (const QString &dct_name);
    QString          targ_lang;             bool RemoveDictionary (const QString&);
                                            bool Contains         (const QString& str);
                                            int  IndexOf          (const QString& str);
                                    QVector<int> DictionaryWords  (const QString&);

    //*************************************************
protected:
    //                Данные                      Методы
                                    virtual bool Filling          ();
                                    virtual void Ravage           ();
                                    virtual bool ReadFile         ();
                                    virtual bool WriteFile        ();
public:
    LearnDir(LearnDirParameter& _parameter);
    LearnDir(LearnDirParameter& _parameter, const QString& _adress);
    friend class DataList<LearnDir, LearnDirParameter>;
    friend QDataStream& operator>> (QDataStream& out, LearnDir& w);
    friend QDataStream& operator<< (QDataStream& in, const LearnDir& w);
};
//-----------------------------------------------------------------------------------------
#endif // D_LD_H


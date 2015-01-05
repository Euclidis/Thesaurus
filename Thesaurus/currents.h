#ifndef CURRENTS
#define CURRENTS

#include "langlist.h"
class Sloter;

class CurrentAccount
{
public:
    CurrentAccount(Carcass*);
public:
    //********************************
    //           Интерфейс
    //********************************


    bool           Set          (const QString&, bool new_account = false);
    QString        Get          () const;
    bool    Set_flag_AW_ignore  (bool);
    bool    Get_flag_AW_ignore  ();
    void    Set_account_photo   (const QString&fileName);

    QPixmap account_photo;

    //********************************
public:
    friend QDataStream& operator>> (QDataStream& out, CurrentAccount&);
    friend QDataStream& operator<< (QDataStream& in, const CurrentAccount&);
    friend class Sloter;
private:
    Carcass* carcass;
    QString cur_Account;
    QString cur_AccoutOS;
    QMap<QString, QString> Accounts;
    bool initialized;
    bool flag_AW_ignore;
private:
    bool WriteFile();
    bool ReadFile();
    bool Initialize ();
};
//*****************************************************************************************************************


class CurrentLearnDir;

class CurrentLearnDirList
{
public:
    CurrentLearnDirList(Carcass*);
public:
    struct LearnDir
    {
        QString knownL;
        QString targL;
        friend QDataStream& operator>> (QDataStream& out, LearnDir&);
        friend QDataStream& operator<< (QDataStream& in, const LearnDir&);
    };
public:
    //**********************************************************************
    //                    Интерфейс
    //**********************************************************************

    bool                    Add     (const LearnDir& ld);
    const QList<LearnDir>&  Get     () const;

    //**********************************************************************
public:
    friend QDataStream& operator>> (QDataStream& out, CurrentLearnDirList&);
    friend QDataStream& operator<< (QDataStream& in, const CurrentLearnDirList&);
    friend class CurrentAccount;
    friend class CurrentLearnDir;
private:
    Carcass* carcass;
    QList<LearnDir> AllLD;
private:
    bool Contains(const LearnDir&) const;
    bool Zeroing();
};
//*****************************************************************************************************************

#ifndef LD
#define LD CurrentLearnDirList::LearnDir
#endif

struct Word
{
    QString word;
    QString transcription;
    QStringList translates;
    QStringList dictionaries;
    QString note;
private:
    QDate date;
    double priority;
public:
    Word();
    Word(QString _word,
         QString _transcription,
         QStringList &_translates,
         QStringList &_dictionaries,
         QString _note);
    Word& operator+= (const Word& _word);
    friend QDataStream& operator>> (QDataStream& out, Word& w);
    friend QDataStream& operator<< (QDataStream& in, const Word& w);
};
//*****************************************************************************************************************


class BaseLearnDir
{
    //*****************************************
    //               Интерфейс
    //*****************************************

public:
    QList<Word> words;
public:

    bool Contains(const QString& str);
    int  IndexOf(const QString& str);

    //*****************************************
    //            Служебная часть
    //*****************************************
public:
    BaseLearnDir(Carcass *_carcass);
protected:
    Carcass* carcass;
    QString adress;
    LD learn_dir;
    bool initialized;
protected:
    bool WriteFile();
    bool ReadFile();
    //*****************************************
};

class CurrentLearnDir : public BaseLearnDir
{
    //*****************************************
    //               Интерфейс
    //*****************************************

public:
    QList<QString> dictionaries;        //Спиок словарей
public:
    //---> Работа с learn_dir
    bool       Set  (const QString& known, const QString& targ, bool new_LD = false);
    const LD   Get  () const;

    //---> Работа с words
    bool AddWord(Word &_word);
    void RemoveWord(QString);

    //---> Работа с dictionaries
    bool AddDictionary(QString);
    void RemoveDictionary(const QString&);

    //*****************************************
    //            Служебная часть
    //*****************************************
public:
    CurrentLearnDir(Carcass *_carcass);
    friend class CurrentLearnDirList;
    friend QDataStream& operator>> (QDataStream& out, CurrentLearnDir&);
    friend QDataStream& operator<< (QDataStream& in, const CurrentLearnDir&);
private:
    bool Initialize(bool new_LD);
    bool Zeroing();
    //*****************************************
};



class OffLineCurrentLearnDir : protected BaseLearnDir
{
    //*****************************************
    //               Интерфейс
    //*****************************************

public:
    Word Translate(const QString& _word);

    //*****************************************
    //            Служебная часть
    //*****************************************
public:
    OffLineCurrentLearnDir(Carcass *_carcass);
private:
    bool Create();                   // Ф-я, необходимая для создания файлов офлайн перевода
    //*****************************************
};
#endif // CURRENTS


#ifndef CARCASS_H
#define CARCASS_H

#include "exceptions_list.h"

class Carcass;

class LangList{
public:
    struct Lang{
        QString name_eng;
        QString name_native;
        QIcon ico;
        int keyboard;
        QList<QChar> transcript;
    };
    struct StrIco{
        QString name;
        QIcon icon;
    };
private:
    Carcass* carcass;
    QList<Lang> Lang_List;
    bool initialized;
public:
    LangList(Carcass*);
    const Lang* getLang(QString);
    const QList<StrIco> getStrIcoList();
    bool Initialize();
    friend QDataStream& operator>> (QDataStream& out, Lang& l);
    friend QDataStream& operator<< (QDataStream& in, const Lang& l);
private:
    bool ReadFile();
    bool WriteFile();
};


class L_D_List{
public:
  
private:
  struct L_Direct{
    QString knownL;
    QString targL;
  };
  QList <LangList::Lang> AllLD;
  
};

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

class Carcass : public QObject
{
Q_OBJECT

public: //метки
    QString current_account;
    QString current_language_interface;
    QString current_language;
    QString current_accountOS;
    LangList* lang_list;
    QMap<QString, QString> QMapAccounts;
    bool flag_AWIgnore;

public: //структуры данных
    Adr adr;                    //структура адресов
    ControlSymbol symb;         //структура символов
    WidgetsTexts wg_tx;         //структура текстов виджетов

//===========================================================
//               методы вывода месседж окон
//===========================================================
signals:
    void mesOKCancelShow(QString);
public:
    void message(QString, bool _modal = true);
    void mesOKCancel(QString str);
//===========================================================

public: //методы записи и чтения файлов
    enum class WriteResult  {OK, Write, Open, Copy, DelTmpWhileCopy, DelSource, DelTmp, RenameTmp};
    enum class ReadResult   {OK, NotFound, Open, Read, DelTmp, RenameTmp};
    enum class OpenWriteAs  {WriteOnly  =   static_cast<OpenWriteAs>(QIODevice::WriteOnly),
                             Append     =   static_cast<OpenWriteAs>(QIODevice::Append)};
    void conf_write();
    void conf_read();
    void confUser_write();
    void confUser_read();

    QString enumWToQStr (WriteResult wr);
    QString enumRToQStr (ReadResult rr);

    template <typename T>
    WriteResult WriteFile (QString AdrFile, T& t,OpenWriteAs flag_Open = OpenWriteAs::WriteOnly)
    {
        QString AdrTemp = AdrFile + adr.EndingTemp;
        QString FileName = AdrFile.section("//", -1);
        QString AdrWriteFile;

        //Открываем один из файлов (с адресом AdrTemp или AdrFile) в зависимости от наличия AdrFile
        //Если флаг в режиме добавления в файл, копируем сурс файл в темп файл
        //-----------------------------------------------------------------------------------------
        if (QFile::exists(AdrFile)) {
            AdrWriteFile = AdrTemp;
            if (flag_Open == OpenWriteAs::Append){
                if (QFile::exists(AdrTemp))
                    if (!QFile::remove(AdrTemp)) return WriteResult::DelTmpWhileCopy;
                if (!QFile::copy(AdrFile, AdrTemp)) return WriteResult::Copy;
            }
        }
        else {
            AdrWriteFile = AdrFile;
        }
        QFile f(AdrWriteFile);
        if(!f.open(static_cast<QIODevice::OpenModeFlag>(flag_Open))) return WriteResult::Open;
        //----------------------------------------------------------------------------------------


        //Записываем информацию в соответствующий файл
        //--------------------------------------------
        try
        {
            QDataStream in(&f);
            in.setVersion(QDataStream::Qt_5_3);
            in << t;
            f.close();
        }
        catch(...) {return WriteResult::Write;}
        //--------------------------------------------


        //Если изначально файл для записи был, удаляем его и переименовываем временный файл
        //---------------------------------------------------------------------------------
        if (AdrWriteFile == AdrTemp){
            if(!QFile::remove(AdrFile)) return WriteResult::DelSource;
            if(!QFile::rename(AdrTemp, FileName)) return WriteResult::RenameTmp;
        }
        //---------------------------------------------------------------------------------


        //Удаляем временный файл, если он есть
        //------------------------------------
        if (QFile::exists(AdrTemp)){
            if(!QFile::remove(AdrTemp)) return WriteResult::DelTmp;
        }
        //------------------------------------

        return WriteResult::OK; //если все успешно прошло
    }

    template <typename T>
    ReadResult ReadFile (QString AdrFile, T& t)
    {
        QString AdrTemp = AdrFile + adr.EndingTemp;
        QString FileName = AdrFile.section("//", -1);
        QString AdrReadFile;

        //Открываем один из файлов (с адресом AdrTemp или AdrFile) в зависимости от наличия AdrFile
        //-----------------------------------------------------------------------------------------
        if (QFile::exists(AdrFile)) AdrReadFile = AdrFile;
        else {
            if (!QFile::exists(AdrTemp)) return ReadResult::NotFound;
            else AdrReadFile = AdrTemp;
        }
        QFile f(AdrReadFile);
        if(!f.open(QIODevice::ReadOnly)) return ReadResult::Open;
        //----------------------------------------------------------------------------------------


        //Записываем информацию в соответствующий файл
        //--------------------------------------------
        try
        {
            QDataStream out(&f);
            out.setVersion(QDataStream::Qt_5_3);
            out >> t;
            f.close();
        }
        catch(...) {return ReadResult::Read;}
        //--------------------------------------------


        //Если изначально файл для записи был, удаляем временный файл, если он есть
        //Если его не было переименовываем временный файл
        //---------------------------------------------------------------------------------
        if (AdrReadFile == AdrFile){
            if (QFile::exists(AdrTemp)){
                if(!QFile::remove(AdrTemp)) return ReadResult::DelTmp;
            }
        }
        else {
            if(!QFile::rename(AdrTemp, FileName)) return ReadResult::RenameTmp;
        }
        //---------------------------------------------------------------------------------

        return ReadResult::OK; //если все успешно прошло
    }

};

#endif // CARCASS_H

#ifndef CARCASS_H
#define CARCASS_H

#include "currents.h"

class Carcass : public QObject
{
Q_OBJECT
public:
    Carcass();

//*************************************************************************************************
//                                        Currents
//*************************************************************************************************

public:
    CurrentLearnDirList* CurLearnDirList;
    CurrentLearnDir* CurLearnDir;
    CurrentAccount* CurAccount;

//*************************************************************************************************
//                                    Структуры данных
//*************************************************************************************************

public:
    Adr adr;                    //структура адресов
    ControlSymbol symb;         //структура символов
    WidgetsTexts wg_tx;         //структура текстов виджетов
    LangList* LanguageList;     //структура списка языков

//*************************************************************************************************
//                                Методы вывода месседж окон
//*************************************************************************************************

signals:
    void mesOKCancelShow(QString);
public:
    void message(QString, bool _modal = true);
    void mesOKCancel(QString str);

//*************************************************************************************************
//                         Ф-и записи и чтения файлов конфигурации
//*************************************************************************************************
private:
    struct confUser_file
    {
        Carcass* carcass;
        confUser_file(Carcass *_carcass);
    };

public:
    bool confUser_write();
    bool confUser_read();

    friend QDataStream& operator>> (QDataStream& out, confUser_file&);
    friend QDataStream& operator<< (QDataStream& in, const confUser_file&);
//*************************************************************************************************
//                         Шаблоны и их вспомогательные компоненты
//*************************************************************************************************

public:

    enum class WriteResult  {OK, Write, Open, Copy, DelTmpWhileCopy, DelSource, DelTmp, RenameTmp};
    enum class ReadResult   {OK, NotFound, Open, Read, DelTmp, RenameTmp};
    enum class OpenWriteAs  {WriteOnly  =   static_cast<OpenWriteAs>(QIODevice::WriteOnly),
                             Append     =   static_cast<OpenWriteAs>(QIODevice::Append)};

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

//*************************************************************************************************
//*************************************************************************************************
signals:
    void SetAccount();
    void SetLD();
    void DctList_Add(QString);
};

#endif // CARCASS_H

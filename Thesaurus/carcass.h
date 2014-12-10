#ifndef CARCASS_H
#define CARCASS_H

#include "adress_texts.h"
#include "exceptions_list.h"
#include "Windows/write_words_window.h"

class Carcass
{

public: //метки
      QString current_account;
      QString current_language_interface;
      QString current_language;
      QString current_dct;

public: //структуры данных
      Adr adr;                    //структура адресов
      ControlSymbol symb;         //структура символов
      WidgetsTexts wg_tx;         //структура текстов виджетов
      WriteWordsWindow *WWW;

public: //методы
    Carcass();

public: //метод вывода месседж окна
    void message(QString, bool _modal = true);

public: //методы записи и чтения файлов
    enum class WriteResult  {OK, Write, Open, Copy, DelTmpWhileCopy, DelSource, DelTmp, RenameTmp};
    enum class ReadResult   {OK, NotFound, Open, Read, DelTmp, RenameTmp};
    enum class OpenWriteAs  {WriteOnly  =   static_cast<OpenWriteAs>(QIODevice::WriteOnly),
                             Append     =   static_cast<OpenWriteAs>(QIODevice::Append)};

    QString enumWToQStr (WriteResult wr)
    {
        switch (wr) {
        case WriteResult::OK:
            return "OK";
        case WriteResult::Write:
            return "Write";
        case WriteResult::Open:
            return "Open";
        case WriteResult::Copy:
            return "Copy";
        case WriteResult::DelTmpWhileCopy:
            return "DelTmpWhileCopy";
        case WriteResult::DelSource:
            return "DelSource";
        case WriteResult::DelTmp:
            return "DelTmp";
        case WriteResult::RenameTmp:
            return "RenameTmp";
        default:
            return "Error";
        }
    }

    QString enumRToQStr (ReadResult rr)
    {
        switch (rr) {
        case ReadResult::OK:
            return "OK";
        case ReadResult::DelTmp:
            return "DelTmp";
        case ReadResult::NotFound:
            return "NotFound";
        case ReadResult::Open:
            return "Open";
        case ReadResult::Read:
            return "Read";
        case ReadResult::RenameTmp:
            return "RenameTmp";
        default:
            return "Error";
        }
    }

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

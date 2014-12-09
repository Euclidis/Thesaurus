#ifndef CARCASS_H
#define CARCASS_H

#include "adress_texts.h"
#include "exceptions_list.h"
#include <QFlag>

class Carcass
{

public: //метки
      QString current_account;            //курируемый аккаунт
      QString current_language_interface;
      QString current_language;           //курируемый язык
      QString current_dct;

public: //структуры данных
      Adr adr;                    //структура адресов
      ControlSymbol symb;         //структура символов
      WidgetsTexts wg_tx;         //структура текстов виджетов

public: //методы
    Carcass();

public: //методы записи и чтения файлов
    enum class WriteResult {OK, CanNotWrite, NotOpen, UnExp, NotDel, NotDelTemp, NotRenameTemp};
    enum class OpenWriteAs {WriteOnly =  static_cast<OpenWriteAs>(QIODevice::WriteOnly),
                            Append = static_cast<OpenWriteAs>(QIODevice::Append)};

    template <typename T>
    WriteResult WriteFile (T& t, QString AdrFile, OpenWriteAs flag_Open = OpenWriteAs::WriteOnly, bool flag_ExShow = true)
    {
        QString AdrTemp = AdrFile + adr.EndingTemp;
        QString FileName = AdrFile.section("//", -1);
        QString AdrWriteFile;

        //Открываем один из файлов (с адресом AdrTemp или AdrFile) в зависимости от наличия AdrFile
        AdrWriteFile = (QFile::exists(AdrFile)) ? AdrTemp : AdrFile;
        QFile f(AdrWriteFile);
        try
        {
            if(!f.open(static_cast<QIODevice::OpenModeFlag>(flag_Open))) throw ex_file_not_open(AdrWriteFile);
        }
        catch(ex_file_not_open ex){
            if(flag_ExShow) ex.show();
            return WriteResult::NotOpen;}
        catch(...) {
            ex_unexpected ex;
            if(flag_ExShow) ex.show();
            return WriteResult::UnExp;}

        //Записываем информацию в соответствующий файл
        QDataStream in(&f);
        in << t;
        f.close();

        //Если изначально файл для записи был, удаляем его и переименовываем временный файл
        QFile file(AdrFile);
        QFile temp(AdrTemp);
        if (AdrWriteFile == AdrTemp){
            if(!file.remove()) return WriteResult::NotDel;
            if(!temp.rename(FileName)) return WriteResult::NotRenameTemp;
        }

        //Удаляем временный файл, если он есть
        if (temp.exists()){
            if(!temp.remove()) return WriteResult::NotDelTemp;
        }

        return WriteResult::OK; //если все успешно прошло
    }

};

#endif // CARCASS_H

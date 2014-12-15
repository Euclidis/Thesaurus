#ifndef ADRESS_TEXTS_H
#define ADRESS_TEXTS_H

#include "base_window.h"

struct Adr
{
    const QString ext = ".conf";          //расширение для файлов
    const QString lext = ".lang";
    const QString config = "settings\\configuration" + ext;
    const QString User = "data\\users\\UsersList" + ext;
    const QString Lang = "data\\users\\LangList" + ext;
    const QString users_dir = "data\\users\\";
    const QString user_config = "\\User" + ext;
    const QString EndingTemp = ".temp";

    const QString LangInterface_en = ":/...";
    const QString LangInterface_ru = ":/...";

    const QString ext_dct = ".dct";
};

struct ControlSymbol
{
    const QString lang_empty = "⚜";       //символ для обозначения в файле конфигурации отсутствия созданных аккаунтов
};

struct WidgetsTexts
{
    const char* const OK = QT_TR_NOOP("OK");
    const char* const Cancel = QT_TR_NOOP("Cancel");
};


#endif // ADRESS_TEXTS_H

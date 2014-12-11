#ifndef ADRESS_TEXTS_H
#define ADRESS_TEXTS_H

#include "general.h"

struct Adr
{
    const QString ext = ".conf";          //расширение для файлов
    const QString config = "settings\\configuration" + ext;
    const QString User = "data\\users\\UsersList" + ext;
    const QString users_dir = "data\\users\\";
    const QString user_config = "configuration" + ext;
    const QString EndingTemp = ".temp";
};

struct ControlSymbol
{
    const QString ac_count_0 = "⚜";       //символ для обозначения в файле конфигурации отсутствия созданных аккаунтов
};

struct WidgetsTexts
{
    const char* const OK = QT_TR_NOOP("OK");
    const char* const Cancel = QT_TR_NOOP("Cancel");
};



#endif // ADRESS_TEXTS_H

#ifndef ADRESS_TEXTS_H
#define ADRESS_TEXTS_H

#include "general.h"

struct Adr
{
    QString ext = ".conf";          //расширение для файлов
    QString config = "\\settings\\configuration" + ext;
    QString User = "\\data\\users\\UsersList" + ext;
};

struct ControlSymbol
{
    QString ac_count_0 = "⚜";       //символ для обозначения в файле конфигурации отсутствия созданных аккаунтов
};

struct WidgetsTexts
{
    const char* const OK = QT_TR_NOOP("OK");
    const char* const Cancel = QT_TR_NOOP("Cancel");
};



#endif // ADRESS_TEXTS_H

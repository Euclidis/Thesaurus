#ifndef ADRESS_TEXTS_H
#define ADRESS_TEXTS_H

#include "general.h"

struct Adr
{
    QString ext = ".conf";          //расширение для файлов
    QString config = "\\settings\\configuration" + ext;
};

struct ControlSymbol
{
    QString ac_count_0 = "⚜";       //символ для обозначения в файле конфигурации отсутствия созданных аккаунтов
};

struct WidgetsTexts
{
    const char* const context = QT_TR_NOOP("WidgetsTexts");     //задает контекст для ф-и QCoreApplication::translate()
    const char* const OK = QT_TRANSLATE_NOOP("WidgetsTexts", "OK");
    const char* const Cancel = QT_TRANSLATE_NOOP("WidgetsTexts", "Cancel");
};



#endif // ADRESS_TEXTS_H

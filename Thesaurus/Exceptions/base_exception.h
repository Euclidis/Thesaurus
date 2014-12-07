#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include "exception_window.h"

class BaseException
{
protected:
    QString text_show;                                             //строка, которую получает конструктор при создании объекта
    const char* const context = QT_TR_NOOP("ExceptionsTexts");     //задает контекст для ф-и QCoreApplication::translate()
public:
    BaseException();
    virtual void show();        //демонстрирует диалоговое окно с текстом text_show
};

#endif // BASEEXCEPTION_H

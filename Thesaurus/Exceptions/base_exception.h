#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include "exception_window.h"

class BaseException
{
protected:
    QString text_show;
public:
    BaseException();
    virtual void show();        //демонстрирует диалоговое окно с текстом text_show
};

#endif // BASEEXCEPTION_H

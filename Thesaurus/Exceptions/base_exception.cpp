#include "base_exception.h"

BaseExceprion::BaseExceprion(QString str_)
{
    str = str_;
}

void BaseExceprion::show()
{
    ExceptionWindow* ex = new ExceptionWindow(str);
    ex->show();
}

QString BaseExceprion::text()
{
    return str;
}

#include "base_exception.h"

BaseException::BaseException()
{
    text_show = "";
}

void BaseException::show()
{
    if (text_show == "") text_show = QObject::tr("An Unexpected Error!");
    ExceptionWindow* ex = new ExceptionWindow(text_show);
    ex->show();
}

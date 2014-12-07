#include "base_exception.h"

BaseException::BaseException()
{
    text_show = "";
}

void BaseException::show()
{
    ExceptionWindow* ex = new ExceptionWindow(text_show);
    ex->show();
}

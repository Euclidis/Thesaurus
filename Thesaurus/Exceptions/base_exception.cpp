#include "base_exception.h"

BaseException::BaseException()
{
    text_show = "";
}

void BaseException::show()
{
    MessageWindow* ex = new MessageWindow(text_show);
    ex->show();
}

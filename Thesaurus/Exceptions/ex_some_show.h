#ifndef EX_SOME_SHOW_H
#define EX_SOME_SHOW_H

#ifndef BASEEXCEPTION_H
#include "base_exception.h"
#endif

class ex_some_show: public BaseException
{
public:
    ex_some_show(QString str);
};

#endif // EX_SOME_SHOW_H

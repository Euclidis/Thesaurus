#ifndef EX_SOME_SHOW_H
#define EX_SOME_SHOW_H

#include "base_exception.h"

class ex_some_show: public BaseException
{
public:
    ex_some_show(QString str);
};

#endif // EX_SOME_SHOW_H

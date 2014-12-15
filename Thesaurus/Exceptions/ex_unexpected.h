#ifndef EX_UNEXPECTED_H
#define EX_UNEXPECTED_H

#ifndef BASEEXCEPTION_H
#include "base_exception.h"
#endif

class ex_unexpected: public BaseException
{
public:
    ex_unexpected();
};

#endif // EX_UNEXPECTED_H

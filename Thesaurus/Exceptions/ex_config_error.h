#ifndef EX_CONFIG_ERROR_H
#define EX_CONFIG_ERROR_H

#ifndef BASEEXCEPTION_H
#include "base_exception.h"
#endif

class ex_config_error: public BaseException
{
private:
    const char* const pre_text_show = QT_TR_NOOP("Error reading file %1. Try running the application again");
public:
    ex_config_error(int error_number, QString adr);
};

#endif // EX_CONFIG_ERROR_H

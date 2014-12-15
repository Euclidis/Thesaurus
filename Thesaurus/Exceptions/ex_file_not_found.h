#ifndef EX_FILE_NOT_FOUND_H
#define EX_FILE_NOT_FOUND_H

#ifndef BASEEXCEPTION_H
#include "base_exception.h"
#endif

class ex_file_not_found: public BaseException
{
private:
    const char* const pre_text_show = QT_TR_NOOP("File %1 not found.");     //прекурсор для text_show базового класса
public:
    ex_file_not_found(QString);
};

#endif // EX_FILE_NOT_FOUND_H

#ifndef EX_FILE_NOT_OPEN_H
#define EX_FILE_NOT_OPEN_H

#ifndef BASEEXCEPTION_H
#include "base_exception.h"
#endif

class ex_file_not_open : public BaseException
{
private:
    const char* const pre_text_show = QT_TR_NOOP("File %1 don't open.");     //прекурсор для text_show базового класса
public:
    ex_file_not_open(QString);
};

#endif // EX_FILE_NOT_OPEN_H

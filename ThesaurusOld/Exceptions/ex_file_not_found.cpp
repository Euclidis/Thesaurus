#include "ex_file_not_found.h"

ex_file_not_found::ex_file_not_found(QString _str)
{
    text_show = QObject::tr(pre_text_show).arg(_str);      //присваивание значения text_show базового класса
}

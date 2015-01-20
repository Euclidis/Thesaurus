#include "ex_file_not_open.h"

ex_file_not_open::ex_file_not_open(QString _str)
{
    text_show = QObject::tr(pre_text_show).arg(_str);      //присваивание значения text_show базового класса
}

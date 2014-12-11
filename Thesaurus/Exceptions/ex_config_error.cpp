#include "ex_config_error.h"

ex_config_error::ex_config_error(int error_number, QString adr)
{
    error_number; //проблема с созданием массива pre_text_show - номер для него
    text_show = QObject::tr(pre_text_show).arg(adr);
}

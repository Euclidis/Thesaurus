#ifndef CARCASS_H
#define CARCASS_H

#include "adress_texts.h"
#include "exceptions_list.h"

class Carcass
{

public: //метки
      QString current_account;            //курируемый аккаунт
      QString current_language_interface;
      QString current_language;           //курируемый язык
      QString current_dct;

public: //структуры данных
      Adr adr;                    //структура адресов
      ControlSymbol symb;         //структура символов
      WidgetsTexts wg_tx;         //структура текстов виджетов

public: //методы
    Carcass();
};

#endif // CARCASS_H

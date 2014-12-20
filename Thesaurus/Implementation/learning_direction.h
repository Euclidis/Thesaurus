#ifndef LEARNING_DIRECTION_H
#define LEARNING_DIRECTION_H

#include "../carcass.h"

class LearningDirection
{

public:
  LearningDirection(Carcass *);

  //временные массивы строк для комбобоксов (чтобы язык не повторялся)
  QStringList temp1;
  QStringList temp2;

  QString KnownLang;
  QString TargLang;

  QString NewDirection;


  Carcass * carcass;
  QStringList Lang;
  QStringList Direction;


  void choose_avoider(QString, QString);
  bool is_Lang_exists(QString);
  void Lang_Initializ();
  void Load_Directions();
  void createLD();

};

#endif // LEARNING_DIRECTION_H

#ifndef LEARNING_DIRECTION_H
#define LEARNING_DIRECTION_H

#include "../carcass.h"

class LearningDirection: public QObject
{
  Q_OBJECT
public:
  LearningDirection(Carcass *);

  //временные массивы строк для комбобоксов (чтобы язык не повторялся)
  QStringList temp1;
  QStringList temp2;

  QString KnownLang;
  QString TargLang;

  QString NewDirection;

private:
   Carcass * carcass;
   QStringList Lang;
   QStringList Direction;

private:
  bool is_Lang_exists(QString *);
  void Lang_Initializ();
  void Load_Directions();

signals:
  //void MW_open();
public slots:
  void createLD();

};

#endif // LEARNING_DIRECTION_H

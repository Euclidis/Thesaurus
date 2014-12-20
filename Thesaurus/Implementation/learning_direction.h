#ifndef LEARNING_DIRECTION_H
#define LEARNING_DIRECTION_H

#include "../carcass.h"

class LearningDirection
{

public:
  LearningDirection(Carcass *);

  //временные массивы строк для комбобоксов (чтобы язык не повторялся)

  QString KnownLang;
  QString TargLang;

  QString NewDirection;

  Carcass * carcass;
  QStringList *Lang;
  QStringList *Direction;

  struct AllLearningDirections{

    QString knownL;
    QString targL;
  };

  QList <AllLearningDirections> AllLD;

  void choose_avoider(QString, QString);
  bool is_Lang_exists(QString);
  void Lang_Initializ();
  void Load_Directions();
  void createLD(const QString &knownL, const QString &targL);

private:
  void LoadAllLD();

};

#endif // LEARNING_DIRECTION_H

#ifndef LEARNING_DIRECTION_H
#define LEARNING_DIRECTION_H

#include "../carcass.h"

class LearningDirection: public QObject
{
  Q_OBJECT
public:
  LearningDirection(Carcass &);
  Carcass * carcass;
  QStringList Lang;


private:
  bool is_Lang_exists(QString *);

signals:
  void MW_open();
};

#endif // LEARNING_DIRECTION_H

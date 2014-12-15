#include "learning_direction.h"

LearningDirection::LearningDirection(Carcass & _car) : carcass(_car)
{
  Lang << "English" << "Russian" << "Chines";
}

bool LearningDirection::is_Lang_exists(QString * checkLang){

      QStringList LearnDicrectLang;
      if (carcass->ReadFile(carcass->adr.Lang, LearnDicrectLang) == Carcass::ReadResult::OK){
        for (QStringList::iterator i = LearnDicrectLang.begin(); i != LearnDicrectLang.end(); ++i){
          if (*i == checkLang) return 1;
          }
      return 0;
  }
      else {
      QString fileproblems = tr("File ") + carcass->adr.Lang + tr(" can't be read");
      carcass->message(fileproblems);
  }
return 0;
}

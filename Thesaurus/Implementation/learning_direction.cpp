#include "learning_direction.h"

LearningDirection::LearningDirection(Carcass * _car) : carcass(_car)
{

}

void LearningDirection::Lang_Initializ(){
  Lang << "English" << "Russian" << "Chines";
  temp1 = temp2 = Lang;
  temp2.removeAt(0);
  temp1.removeAt(1);
}

bool LearningDirection::is_Lang_exists(QString checkLang){

//      QStringList LearnDicrectLang;
//      if (carcass->ReadFile(carcass->adr.Lang, LearnDicrectLang) == Carcass::ReadResult::OK){
//        for (QStringList::iterator i = LearnDicrectLang.begin(); i != LearnDicrectLang.end(); ++i){
//          if (*i == checkLang) return 1;
//          }
//      return 0;
//  }
//      else {
//      QString fileproblems = tr("File ") + carcass->adr.Lang + tr(" can't be read");
//      carcass->message(fileproblems);
//  }
return 0;
}
// Если нет ЛэнгЛиста, то создать его
void LearningDirection::Load_Directions(){

  QFile LangList (carcass->adr.users_dir + carcass->current_account.toLower() + carcass->adr.Lang);

  if (!LangList.exists()){
      LangList.open(QFile::WriteOnly);
      LangList.close();
      NewDirection = TargLang +"-"+ KnownLang;
      carcass->current_language = NewDirection;
      QString str = "";
      carcass->message(carcass->enumWToQStr(carcass->WriteFile(carcass->adr.users_dir + carcass->current_account.toLower() + carcass->adr.Lang, NewDirection)));
      carcass->message(carcass->enumWToQStr(carcass->WriteFile(carcass->adr.users_dir + carcass->current_account.toLower() + "//" + NewDirection + carcass->adr.lext, str )));
    }

}
void LearningDirection::createLD(QString tar, QString know){

  TargLang = tar;
  KnownLang = know;

  Load_Directions();

}


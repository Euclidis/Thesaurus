#include "learning_direction.h"

LearningDirection::LearningDirection(Carcass * _car) : carcass(_car)
{

}

void LearningDirection::Lang_Initializ(){

//      const QList<LangList::StrIco>& tempStrIcoList = carcass->LanguageList->getStrIcoList();
//      for (int i = 0; i < tempStrIcoList.size(); ++i){
////          QAction tempAction(*tempStrIcoList.at(i).name, *tempStrIcoList.at(i).icon);
////      Lang.push_back(tempAction);
//}
//  Direction = new QStringList;
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

//  QFile LangList (carcass->adr.users_dir + carcass->current_account.toLower() + carcass->adr.CurLearnDirList);

//  if (!LangList.exists()){
//      LangList.open(QFile::WriteOnly);
//      LangList.close();

//      carcass->current_learn_dir.knownL = KnownLang;
//      carcass->current_learn_dir.targL = TargLang;
//      carcass->LDList->addNew_L_D(KnownLang, TargLang);

//      QString str = "";
//      carcass->WriteFile(carcass->adr.users_dir + carcass->current_account.toLower() + carcass->adr.CurLearnDirList, carcass->LDList->currentLDname());
//      carcass->WriteFile(carcass->adr.users_dir + carcass->current_account.toLower() + "//" + carcass->LDList->currentLDname() + carcass->adr.lext, str);

//      carcass->LDList->WriteFile();
//    }
//  else {
//      //?>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//    }

}
void LearningDirection::createLD(const QString &knownL, const QString &targL){

  KnownLang = knownL;
  TargLang = targL;

  Load_Directions();

}

void LearningDirection::choose_avoider(QString knownL, QString targetL){

//  if (KnownLang != knownL){

//      KnownLang = knownL;
//      temp2 = Lang;
//      temp2->filter(KnownLang);
//    }
//  else if (TargLang != targetL){
//      TargLang = targetL;
//      temp1 = Lang;
//      temp1->filter(TargLang);
//    }
}
void LearningDirection::LoadAllLD(){



}

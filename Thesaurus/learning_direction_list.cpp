#include "carcass.h"

QDataStream& operator>> (QDataStream& out, L_D_List::L_Direct& ld){
  out >> ld.knownL;
  out >> ld.targL;

  return out;
}

QDataStream& operator<< (QDataStream& in, const L_D_List::L_Direct& ld){
  in << ld.knownL;
  in << ld.targL;

  return in;
}
QStringList& operator<< (QStringList& in, const L_D_List::L_Direct& ld){
  in << ld.knownL;
  in << ld.targL;

  return in;
}
L_D_List::L_D_List(Carcass * _carcass) : carcass(_carcass){
}

bool L_D_List::LoadFromFile() {
  QString path = carcass->adr.users_dir + carcass->current_account.toLower() + carcass->adr.CurLearnDirList;
  QStringList AllLearnDirect;
  Carcass::ReadResult rr = carcass->ReadFile(path, AllLearnDirect);
  switch (rr) {
    case Carcass::ReadResult::OK:
      return true;
    default:
      ex_some_show ex(QObject::tr("Problems reading the file ") + path);
      ex.show();
      carcass->message(carcass->enumRToQStr(rr));
      return false;
    }
  if (carcass->current_learn_dir.knownL != carcass->symb.lang_empty){
 for (int i = 0; i < AllLearnDirect.size()-1; i+=2){
     L_Direct temp;
     temp.knownL = AllLearnDirect.at(i);
     temp.targL = AllLearnDirect.at(i+1);
     AllLD.push_back(temp);
   }
 curLDindex = AllLearnDirect.at(AllLearnDirect.size()-1).toInt();
 carcass->LDList->set_curLD(curLDindex);
    }
  else carcass->message("Problem reading file: " + path);
}


bool L_D_List::WriteFile() {
  if (this->curLDindex != -1){
      QString path = carcass->adr.users_dir + carcass->current_account.toLower() + carcass->adr.CurLearnDirList;
      QStringList AllLearnDirect;
      if (!AllLD.isEmpty()){
          for (int i = 0; i < AllLD.size(); ++i)
            AllLearnDirect << AllLD.at(i);
        }
      AllLearnDirect << QString::number(curLDindex);
      Carcass::WriteResult wr = carcass->WriteFile(path, AllLearnDirect);
      switch (wr) {
      case Carcass::WriteResult::OK:
          return true;
      default:
          ex_some_show ex(QObject::tr("Problems writing the file ") + path);
          ex.show();
          carcass->message(carcass->enumWToQStr(wr));
      }
    }

  return false;

}

const L_D_List::L_Direct* L_D_List::currentLD(){

  if (this->curLDindex != -1){
    return &this->AllLD.at(curLDindex);
    }
  carcass->message("Learning Direction is Empty and has no current LD, Please Create new Learning Direction");
}

bool operator==(const L_D_List::L_Direct& first, const L_D_List::L_Direct& second){

  return (first.knownL == second.knownL && first.targL == second.targL);

}
void L_D_List::set_curLD(const int index){

  carcass->LDList->curLDindex = index;
  carcass->current_learn_dir = AllLD.at(index);

}

void L_D_List::set_curLD(const L_D_List::L_Direct& direction){
  if (!AllLD.isEmpty())
    for (unsigned int i = 0; i < AllLD.size(); ++i)
      if (direction == AllLD.at(i))
        {
            carcass->LDList->curLDindex = i;
          carcass->current_learn_dir = direction;
        }
}

QString L_D_List::currentLDname(){
   if ((!AllLD.isEmpty()) && curLDindex != -1)
  return (AllLD.at(curLDindex).knownL + "_" + AllLD.at(curLDindex).targL);

}

void L_D_List::addNew_L_D(const QString& knownlang, const QString& targlang){
  L_Direct temp;
  temp.knownL = knownlang;
  temp.targL = targlang;

  AllLD.push_back(temp);
  //после создания нового направления, оно сразу будет выбрано как текущее
  set_curLD(AllLD.size()-1);
}

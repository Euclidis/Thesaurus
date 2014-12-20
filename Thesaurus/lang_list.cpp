#include "carcass.h"

LangList::LangList(Carcass *_carcass){
  carcass = _carcass;
//  private:
//  struct Lang{
//    QString name;
//    QIcon ico;
//    int keyboard;
//    QString transcript;
//    QList<Lang> Lang_List;
//  public:
//    LangList(Carcass*);
//    Lang& getLang(QString);

  Lang_List.push_back(Lang("English", QIcon(carcass->adr.)));
  }
LangList::Lang::Lang(QString str, QIcon icon, int kb, QList<QChar> tr){

  this->name = str;
  this->ico = ico;
  this->keyboard = kb;
  transcript = tr;
}

#include "label.h"

Label::Label(QWidget *parent, Qt::WindowFlags f):QLabel(parent,f){}
Label::Label(const QString &text, QWidget *parent, Qt::WindowFlags f):QLabel(text,parent,f){}
Label::~Label(){}

void Label::mousePressEvent(){
    emit clicked();
}
void Label::leaveEvent(QEvent *e)
      {
         emit mouseLeave();
         QLabel::leaveEvent(e);
      }
void Label::enterEvent(QEvent *e)
       {
          emit mouseEnter();
          QLabel::enterEvent(e);
       }

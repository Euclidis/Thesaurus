#ifndef LANG_SELECTION_WINDOW_H
#define LANG_SELECTION_WINDOW_H


#include <QDialog> //удалить после коррекции
//#include "../carcass.h"

namespace Ui {
  class LangSelectionWindow;
}

class LangSelectionWindow : public QDialog//BaseWindow
{
  Q_OBJECT
public:
    //Carcass * carcass;
public:
  explicit LangSelectionWindow(/*Carcass * _carcass*/);
  ~LangSelectionWindow();

private:
  Ui::LangSelectionWindow *ui;
};

#endif // LangSelectionWindow_H

#ifndef LANG_SELECTION_WINDOW_H
#define LANG_SELECTION_WINDOW_H


#include "../Implementation/learning_direction.h"

namespace Ui {
  class LangSelectionWindow;
}

class LangSelectionWindow : public BaseWindow, public LearningDirection
{
  Q_OBJECT
private:

  Ui::LangSelectionWindow *ui;

public:
  LangSelectionWindow(Carcass *_carcass);
  ~LangSelectionWindow();



public slots:
    void on_label_3_clicked();
 signals:
    void MW_open();
    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    void WWW_open();
    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

};

#endif // LangSelectionWindow_H

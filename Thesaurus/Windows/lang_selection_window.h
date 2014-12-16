#ifndef LANG_SELECTION_WINDOW_H
#define LANG_SELECTION_WINDOW_H


#include "../Implementation/learning_direction.h"

namespace Ui {
  class LangSelectionWindow;
}

class LangSelectionWindow : public BaseWindow
{
  Q_OBJECT

public:
  explicit LangSelectionWindow(Carcass *_carcass);
  ~LangSelectionWindow();


LearningDirection *LD;

private:

  Ui::LangSelectionWindow *ui;
  Carcass * carcass;


public:
  void Connector();

public slots:
    void on_label_3_clicked();
 signals:
    void OK_pushed();
    void MW_open();
    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    void WWW_open();
    //TEST>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

};

#endif // LangSelectionWindow_H

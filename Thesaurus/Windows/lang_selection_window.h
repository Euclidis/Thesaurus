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
  explicit LangSelectionWindow();
  ~LangSelectionWindow();

private slots:
    void on_label_3_clicked();

private:

  Ui::LangSelectionWindow *ui;

};

#endif // LangSelectionWindow_H

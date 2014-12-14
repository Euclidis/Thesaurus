#ifndef RESET_PASS_WINDOW_H
#define RESET_PASS_WINDOW_H

#include "../carcass.h"

namespace Ui {
  class ResetPassWindow;
}

class ResetPassWindow : public BaseWindow
{
  Q_OBJECT

public:
  explicit ResetPassWindow();
  ~ResetPassWindow();

private:
  Ui::ResetPassWindow *ui;
};

#endif // RESET_PASS_WINDOW_H

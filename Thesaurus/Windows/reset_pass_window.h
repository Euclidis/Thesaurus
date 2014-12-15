#ifndef RESET_PASS_WINDOW_H
#define RESET_PASS_WINDOW_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif

namespace Ui {
  class ResetPassWindow;
}

class ResetPassWindow : public BaseWindow
{
  Q_OBJECT

public:
  explicit ResetPassWindow(QMap<QString, QString> &, QLineEdit &, Carcass &);

  QMap<QString, QString> &names;
  QLineEdit &CurrName;
  Carcass &carcass;
  ~ResetPassWindow();

private slots:
  void on_buttonBox_accepted();

  void on_buttonBox_rejected();

private:
  Ui::ResetPassWindow *ui;
};

#endif // RESET_PASS_WINDOW_H

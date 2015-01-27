#ifndef RESET_PASS_WINDOW_H
#define RESET_PASS_WINDOW_H

#ifndef START_WINDOWS
#include "../start.h"
#endif

namespace Ui {
  class ResetPassWindow;
}

class ResetPassWindow : public BaseWindow
{
  Q_OBJECT

public:
  explicit ResetPassWindow(Data* _dt, MLineEdit& qle_name, MLineEdit &qle_pas);
  Data* dt;

  QLineEdit &QLE_name;
  QLineEdit &QLE_password;
  ~ResetPassWindow();

private slots:
  void Connector();
  void AnswerAccepted();
  void AnswerRejected();

private:
  Ui::ResetPassWindow *ui;
};

#endif // RESET_PASS_WINDOW_H

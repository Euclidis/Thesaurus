#ifndef LANG_SELECTION_WINDOW_H
#define LANG_SELECTION_WINDOW_H


#include <QDialog>

namespace Ui {
  class LangSelectionWindow;
}

class LangSelectionWindow : public QDialog
{
  Q_OBJECT

public:
  explicit LangSelectionWindow(QWidget *parent = 0);
  ~LangSelectionWindow();

private:
  Ui::LangSelectionWindow *ui;
};

#endif // LangSelectionWindow_H

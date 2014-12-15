#ifndef LANG_SELECTION_WINDOW_H
#define LANG_SELECTION_WINDOW_H


#include "../carcass.h"

namespace Ui {
  class LangSelectionWindow;
}

class LangSelectionWindow : public BaseWindow
{
  Q_OBJECT
public:
    Carcass * carcass;
public:
  explicit LangSelectionWindow(Carcass * _carcass);
  ~LangSelectionWindow();

private slots:
    void on_label_3_clicked();

private:

  QStringList Lang;
  Ui::LangSelectionWindow *ui;

private:
  bool is_Lang_exists(QString *);

signals:
  void MW_open();
};

#endif // LangSelectionWindow_H

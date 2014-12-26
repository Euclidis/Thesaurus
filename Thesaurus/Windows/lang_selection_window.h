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
void closeEvent(QCloseEvent * close_ev);

QString test;

public slots:
    void on_label_3_clicked();
 signals:
    void close_me(BaseWindow*);
    void MW_open();
private slots:
    void accepted(bool);
    void on_comboBox_2_activated(const QString &combo2_cur_text);
    void on_comboBox_activated(const QString &combo1_cur_text);
};

#endif // LangSelectionWindow_H

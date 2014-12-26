#ifndef MESSAGE_WINDOW_H
#define MESSAGE_WINDOW_H

#include "../general.h"

namespace Ui {
class MessageWindow;
}

class MessageWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit MessageWindow(QString, bool _modal = true);
    ~MessageWindow();
  void closeEvent(QCloseEvent * close_ev);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MessageWindow *ui;
};

#endif // MESSAGE_WINDOW_H

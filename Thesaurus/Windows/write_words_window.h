#ifndef WRITE_WORDS_WINDOW_H
#define WRITE_WORDS_WINDOW_H

#include "../carcass.h"

namespace Ui {
class WriteWordsWindow;
}

class WriteWordsWindow : public BaseWindow
{
    Q_OBJECT
public:
    Carcass * carcass;
public:
    explicit WriteWordsWindow(Carcass * _carcass);
    ~WriteWordsWindow();

private slots:
    void on_pushButton_clicked();
    void msOC(bool);

private:
    Ui::WriteWordsWindow *ui;
};

#endif // WRITE_WORDS_WINDOW_H

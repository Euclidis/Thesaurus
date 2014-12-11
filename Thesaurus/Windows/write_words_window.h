#ifndef WRITE_WORDS_WINDOW_H
#define WRITE_WORDS_WINDOW_H

#include <QDialog> // удалить
//#include "../carcass.h"

namespace Ui {
class WriteWordsWindow;
}

class WriteWordsWindow : public QDialog //BaseWindow
{
    Q_OBJECT
public:
    //Carcass * carcass;
public:
    explicit WriteWordsWindow(/*Carcass * _carcass*/);
    ~WriteWordsWindow();

private:
    Ui::WriteWordsWindow *ui;
};

#endif // WRITE_WORDS_WINDOW_H

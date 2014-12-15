#ifndef WRITE_WORDS_WINDOW_H
#define WRITE_WORDS_WINDOW_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif

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


private:
    Ui::WriteWordsWindow *ui;
};

#endif // WRITE_WORDS_WINDOW_H

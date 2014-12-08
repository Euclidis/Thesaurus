#ifndef WRITE_WORDS_WINDOW_H
#define WRITE_WORDS_WINDOW_H

#include <QDialog>

namespace Ui {
class WriteWordsWindow;
}

class WriteWordsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WriteWordsWindow(QWidget *parent = 0);
    ~WriteWordsWindow();

private:
    Ui::WriteWordsWindow *ui;
};

#endif // WRITE_WORDS_WINDOW_H

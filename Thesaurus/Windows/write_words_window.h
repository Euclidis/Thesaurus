#ifndef WRITE_WORDS_WINDOW_H
#define WRITE_WORDS_WINDOW_H

#include "../Implementation/www_realization.h"

namespace Ui {
class WriteWordsWindow;
}

class WriteWordsWindow : public BaseWindow
{
    Q_OBJECT
private:
    Carcass * carcass;
    WWWRealization* realiz;
    QString word;
    QString transcription;
    QStringList translates;
    QString note;
public:
    explicit WriteWordsWindow(Carcass * _carcass);
    ~WriteWordsWindow();
private:
    void connector();

signals:
    void SaveWord(QString _word,
                  QString _transcription,
                  QStringList _translates,
                  QString _note);
private slots:


    void on_pushButton_clicked();

private:
    Ui::WriteWordsWindow *ui;
};

#endif // WRITE_WORDS_WINDOW_H

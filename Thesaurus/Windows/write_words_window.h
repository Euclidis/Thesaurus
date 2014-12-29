#ifndef WRITE_WORDS_WINDOW_H
#define WRITE_WORDS_WINDOW_H

#include "dct_window.h"
#include "../GTA/GTApi.h"
namespace Ui {
class WriteWordsWindow;
}

class WriteWordsWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit WriteWordsWindow(Carcass * _carcass);
    ~WriteWordsWindow();

private:
    Carcass * carcass;
    WWWAbstraction* realiz;
    DctWindow* DW;
    QString word;
    QString transcription;
    QStringList translates;
    QString note;
    GTApi  *gtApi;
private:
    void ConnectRealizator();
    void ConnectWidgets();
    void ConnectDctWindow();
    void TakeTexts();
    void ClearTexts();
    void closeEvent(QCloseEvent * event);
private slots:
    void SaveWord();
    void DW_open();
    void on_pushButton_3_clicked();
    void onTranslationReady(const GTApiTranslation& gtApiTr);
signals:
    void close_me(BaseWindow * me);
private:
    Ui::WriteWordsWindow *ui;
};

#endif // WRITE_WORDS_WINDOW_H

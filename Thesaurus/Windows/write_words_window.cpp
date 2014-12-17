#include "write_words_window.h"
#include "ui_write_words_window.h"


WriteWordsWindow::WriteWordsWindow(Carcass * _carcass) :
    ui(new Ui::WriteWordsWindow)
{
    ui->setupUi(this);
    carcass = _carcass;
    realiz = new WWWRealization(carcass);
    DW = nullptr;
    if(realiz->Initialize()){
        ConnectRealizator();
        ConnectWidgets();
    }
    else{
        //*********** Добавить эксепшн ***************
        deleteLater();
    }
}

void WriteWordsWindow::ConnectRealizator()
{
    connect(realiz, SIGNAL(DctShow()),SLOT(DW_open()));
}

//*******************************************************************
//                 Функции "присоединения" виджетов
//*******************************************************************

//--------Сигналы от виджетов
void WriteWordsWindow::ConnectWidgets()
{
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(SaveWord()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(DW_open()));
}
//--------Функции получения информации от виджетов
void WriteWordsWindow::TakeTexts()
{
    word            = ui->lineEdit->text();
    transcription   = ui->lineEdit_2->text();
    translates      = ui->textEdit->toPlainText().split("\n");
    note            = ui->textEdit_2->toPlainText();
}
//--------Функции работы с дополнительным окном
void WriteWordsWindow::DW_open()
{
    if(!DW) DW = new DctWindow(realiz);
    DW->show();
}
//*******************************************************************
//*******************************************************************


void WriteWordsWindow::SaveWord()
{
    TakeTexts();
    realiz->SaveWord(word, transcription, translates, note);
}

WriteWordsWindow::~WriteWordsWindow()
{
    delete ui;
    delete realiz;
}

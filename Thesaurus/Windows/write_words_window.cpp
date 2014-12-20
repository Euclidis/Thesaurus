#include "write_words_window.h"
#include "ui_write_words_window.h"


WriteWordsWindow::WriteWordsWindow(Carcass * _carcass) :
    ui(new Ui::WriteWordsWindow)
{
    ui->setupUi(this);
    carcass = _carcass;
    realiz = new WWWAbstraction(carcass);
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
//--------Функции для текстовых полей
void WriteWordsWindow::TakeTexts()
{
    word            = ui->lineEdit->text().trimmed();
    transcription   = ui->lineEdit_2->text().trimmed();
    translates      = ui->textEdit->toPlainText().split("\n");
    note            = ui->textEdit_2->toPlainText().trimmed();
}
void WriteWordsWindow::ClearTexts()
{
    ui->lineEdit->setText   ("");
    ui->lineEdit_2->setText ("");
    ui->textEdit->setText   ("");
    ui->textEdit_2->setText ("");
}
//--------Функции работы с дополнительным окном
void WriteWordsWindow::DW_open()
{
    if(!DW) DW = new DctWindow(realiz);
    DW->show();
}
void WriteWordsWindow::closeEvent(QCloseEvent * event)
{
    if(DW) DW->close();
    event->accept();
}
//*******************************************************************
//*******************************************************************


void WriteWordsWindow::SaveWord()
{
    TakeTexts();
    if(realiz->SaveWord(word, transcription, translates, note)) ClearTexts();
}

WriteWordsWindow::~WriteWordsWindow()
{
    delete ui;
    delete realiz;
}

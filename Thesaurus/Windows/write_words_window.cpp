#include "write_words_window.h"
#include "ui_write_words_window.h"


WriteWordsWindow::WriteWordsWindow(Carcass * _carcass) :
    ui(new Ui::WriteWordsWindow)
{
    ui->setupUi(this);
    carcass = _carcass;
}

WriteWordsWindow::~WriteWordsWindow()
{
    delete ui;
}

void WriteWordsWindow::on_pushButton_clicked()
{
    carcass->mesOKCancel("asdf");
}

void WriteWordsWindow::msOC(bool b)
{
    carcass->message(QString::number(b));
}

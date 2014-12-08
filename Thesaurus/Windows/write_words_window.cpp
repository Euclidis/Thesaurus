#include "write_words_window.h"
#include "ui_write_words_window.h"

WriteWordsWindow::WriteWordsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WriteWordsWindow)
{
    ui->setupUi(this);
}

WriteWordsWindow::~WriteWordsWindow()
{
    delete ui;
}

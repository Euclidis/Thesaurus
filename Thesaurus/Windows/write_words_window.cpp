#include "write_words_window.h"
#include "ui_write_words_window.h"


WriteWordsWindow::WriteWordsWindow(Carcass * _carcass) :
    ui(new Ui::WriteWordsWindow)
{
    ui->setupUi(this);
    carcass = _carcass;
    bool flag_good = true;
    realiz = new WWWRealization(carcass, flag_good);
    if(flag_good){
        connector();
        carcass->message("ОК1");
    }
    else{
        //*********** Добавить эксепшн ***************
        deleteLater();
    }
}

WriteWordsWindow::~WriteWordsWindow()
{
    delete ui;
    delete realiz;
}

void WriteWordsWindow::connector()
{
    connect(this, SIGNAL(SaveWord(QString,QString,QStringList,QString)), realiz, SLOT(SaveWord1(QString,QString,QStringList,QString)));
}

void WriteWordsWindow::on_pushButton_clicked()
{
    carcass->message("OK2");
    QString _word = ui->lineEdit->text();
    QString _transcription = ui->lineEdit_2->text();
    QStringList _translates = ui->textEdit->toPlainText().split("\n");
    QString _note = ui->textEdit_2->toPlainText();
    emit SaveWord(_word, _transcription, _translates, _note);
}

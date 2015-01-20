#include "exception_window.h"
#include "ui_exception_window.h"

ExceptionWindow::ExceptionWindow(QString str) :
    ui(new Ui::ExceptionWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText(str);
    ui->pushButton->setText(tr("OK"));
    setModal(true);
}

ExceptionWindow::~ExceptionWindow()
{
    delete ui;
}

void ExceptionWindow::on_pushButton_clicked()
{
    close();
}

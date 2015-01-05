#include "message_window.h"
#include "ui_message_window.h"

MessageWindow::MessageWindow(QString str, bool _modal) :
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText(str);
    ui->pushButton->setText(tr("OK"));
    setModal(_modal);
}

MessageWindow::~MessageWindow()
{
    delete ui;
}
void MessageWindow::on_pushButton_clicked()
{
    close();
}
void MessageWindow::closeEvent(QCloseEvent * close_ev)
{
    delete(this);
    close_ev->accept();
}

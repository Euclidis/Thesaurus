#include "exceptionwindow.h"
#include "ui_exceptionwindow.h"

ExceptionWindow::ExceptionWindow(QString str, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExceptionWindow)
{
    ui->setupUi(this);
    ui->label->setText(str);
    ui->pushButton->setText(QCoreApplication::translate("ExceptionWindow", "OK"));
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(OK_Click()));
    setModal(true);
}

ExceptionWindow::~ExceptionWindow()
{
    delete ui;
}

void ExceptionWindow::OK_Click()
{
    close();
}

#include "exception_window.h"
#include "ui_exception_window.h"

ExceptionWindow::ExceptionWindow(QString str, QWidget *parent) :
    BaseWindow(parent),
    ui(new Ui::ExceptionWindow)
{
    ui->setupUi(this);
    ui->label->setText(str);
    ui->pushButton->setText(tr("OK"));
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

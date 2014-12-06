#include "exceptionwindow.h"
#include "ui_exceptionwindow.h"

ExceptionWindow::ExceptionWindow(QString str, QWidget *parent) :
    BaseWindow(parent)/*QDialog(parent)*/,
    ui(new Ui::ExceptionWindow)
{
    ui->setupUi(this);
    ui->label->setText(str);
    ui->pushButton->setText(QCoreApplication::translate("ExceptionWindow", "OK"));
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(OK_Click()));
    //setWindowModality(Qt::WindowModality); если наследуется от BaseWindow
    //setModal(true); если наследуется от QDialog
}

ExceptionWindow::~ExceptionWindow()
{
    delete ui;
}

void ExceptionWindow::OK_Click()
{
    this->close();
}

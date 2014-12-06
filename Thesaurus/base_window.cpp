#include "base_window.h"
#include "ui_base_window.h"

BaseWindow::BaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

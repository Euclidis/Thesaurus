#include "account_window.h"
#include "ui_account_window.h"

AccountWindow::AccountWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccountWindow)
{
    ui->setupUi(this);
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

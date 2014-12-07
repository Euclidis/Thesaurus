#include "account_window.h"
#include "ui_account_window.h"

AccountWindow::AccountWindow(Carcass* _carcass) :
    ui(new Ui::AccountWindow)
{
    ui->setupUi(this);
    carcass = _carcass;
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

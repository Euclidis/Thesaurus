#include "menu_window.h"
#include "ui_menu_window.h"

MenuWindow::MenuWindow(Carcass * _carcass) :
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    carcass =  _carcass;
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

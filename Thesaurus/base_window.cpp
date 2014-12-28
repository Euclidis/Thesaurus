#include "base_window.h"
#include "ui_base_window.h"

BaseWindow::BaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
    setWindowFlags( Qt::CustomizeWindowHint );
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

#include "dct_window.h"
#include "ui_dct_window.h"

DctWindow::DctWindow(WWWRealization* _realiz, QMap<QString, bool> _DctCheck) :
    ui(new Ui::DctWindow)
{
    ui->setupUi(this);
    realiz = _realiz;
    DctCheck = _DctCheck;
}

DctWindow::~DctWindow()
{
    delete ui;
    delete realiz;
}

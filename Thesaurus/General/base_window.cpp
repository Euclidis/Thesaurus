#ifndef E_BASE_WINDOW_H
#include "base_window.h"
#endif
#include "ui_e_base_window.h"
//------------------------------------------------------------
BaseWindow::BaseWindow() :
    ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
    setWindowFlags( Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    InstallFont();
}
//------------------------------------------------------------
BaseWindow::~BaseWindow()
{
    delete ui;
}
//------------------------------------------------------------
void BaseWindow::InstallFont()
{
    QFile font(":/Resources/Code Pro Light LC.otf");
    if (font.open(QIODevice::ReadOnly)){
        QFontDatabase::addApplicationFontFromData(font.readAll());
    }
    else {
        qDebug() << "Файл шрифтов не открылся или отсутствует";
    }
    font.close();
}
//------------------------------------------------------------
void BaseWindow::closeEvent(QCloseEvent * ev)
{
    emit CloseMe(this);
    ev->accept();
}
//------------------------------------------------------------

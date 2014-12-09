#include "carcass.h"
#include <QApplication>
#include "Windows/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Carcass carcass;
    QString str;
    carcass.message(carcass.enumRToQStr( carcass.ReadFile("godot.txt", str)));
    carcass.message(str);
    return a.exec();
}

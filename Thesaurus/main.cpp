#include "carcass.h"
#include <QApplication>
#include "Windows/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Carcass carcass;
    QString str = "GOOD";
    carcass.WriteFile("Godot.txt", str);

    return a.exec();
}

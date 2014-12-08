#include "carcass.h"
#include <QApplication>
#include "Windows/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Carcass car;
    a.exit();
    return a.exec();
}

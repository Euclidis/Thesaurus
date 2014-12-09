#include "carcass.h"
#include <QApplication>
#include "Windows/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Carcass car;
    QString asd = "Very GOOD";
    car.WriteFile<QString>("doro.txt", asd);

    return a.exec();
}

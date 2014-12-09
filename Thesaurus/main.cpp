#include "carcass.h"
#include <QApplication>
#include "Windows/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Carcass car;
    QString asd = "asdsffffffdfsdf";
    car.WriteFile<QString>(asd, "doro.txt", Carcass::OpenWriteAs::Append , true);

    return a.exec();
}

#include "carcass.h"
#include <QApplication>
#include "Windows/account_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try
    {
        Carcass carcass;
    }
    catch (ex_config_error ex) {ex.show(); qApp->exit();}
    catch(...) {ex_unexpected ex; ex.show(); qApp->exit();}

    return a.exec();
}

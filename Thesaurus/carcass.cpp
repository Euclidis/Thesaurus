#include "carcass.h"
#include "Windows/account_window.h"




Carcass::Carcass()
{
  //configuration file
    QFile f(adr.config);
    try
    {
        if(f.exists()){
            if (f.open(QIODevice::ReadOnly)){
                QStringList config_list;
                QDataStream out(&f);
                out >> config_list;
                f.close();

                if (config_list.size() == 2) {
                cur_acc = config_list.at(0);
                cur_lang = config_list.at(1);
                }
                else throw BaseException();
            }
            else throw ex_file_not_open(adr.config);
        }
        else throw ex_file_not_found(adr.config);
    }
    catch(ex_file_not_found& ex){ex.show();}
    catch(ex_file_not_open& ex){ex.show();}
    catch(...){BaseException ex; ex.show();}

    AccountWindow *account= new AccountWindow (this, 0);
    account->show();




}

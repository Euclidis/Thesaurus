#include "carcass.h"
#include "Windows/account_window.h"

Carcass::Carcass()
{
//    /*Чтение общего файла конфигурации*/
//    bool flag_account = 0;
//    try
//    {
//        QFile f(adr.config);
//        if(!f.exists()) throw ex_file_not_found(adr.config);
//        if (!f.open(QIODevice::ReadOnly)) throw ex_file_not_open(adr.config);
//        QDataStream out(&f);
//        out >> current_account >> flag_account;
//        f.close();
//    }
//    catch(ex_file_not_found& ex) {ex.show();}
//    catch(ex_file_not_open& ex) {ex.show();}
//    catch(...) {BaseException ex; ex.show();}
//    /*-------------------------------------------*/

//    /*Чтение файла конфигурации юзера*/
//    if (current_account != symb.ac_count_0){
//        try
//        {
//            QString path = adr.users_dir + current_account + adr.user_config;
//            QFile f(path);
//            if(!f.exists()) throw ex_file_not_found(path);
//            if (!f.open(QIODevice::ReadOnly)) throw ex_file_not_open(path);
//            QDataStream out(&f);
//            out >> current_language_interface
//                >> current_language
//                >> current_dct;
//            f.close();
//        }
//        catch(ex_file_not_found& ex) {ex.show();}
//        catch(ex_file_not_open& ex) {ex.show();}
//        catch(...) {BaseException ex; ex.show();}
//    }/*-------------------------------*/


    AccountWindow *account= new AccountWindow (this);
    account->show();

}

void Carcass::message(QString str, bool _modal)
{
    MessageWindow* ms = new MessageWindow(str, _modal);
    ms->show();
}

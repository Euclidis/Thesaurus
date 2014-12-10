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

bool Carcass::conf_write(){return true;}
void Carcass::conf_read(){}
void Carcass::confUser_write(){}
void Carcass::confUser_read(){}

QString Carcass::enumWToQStr (WriteResult wr)
{
    switch (wr) {
    case WriteResult::OK:
        return "OK";
    case WriteResult::Write:
        return "Write";
    case WriteResult::Open:
        return "Open";
    case WriteResult::Copy:
        return "Copy";
    case WriteResult::DelTmpWhileCopy:
        return "DelTmpWhileCopy";
    case WriteResult::DelSource:
        return "DelSource";
    case WriteResult::DelTmp:
        return "DelTmp";
    case WriteResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}

QString Carcass::enumRToQStr (ReadResult rr)
{
    switch (rr) {
    case ReadResult::OK:
        return "OK";
    case ReadResult::DelTmp:
        return "DelTmp";
    case ReadResult::NotFound:
        return "NotFound";
    case ReadResult::Open:
        return "Open";
    case ReadResult::Read:
        return "Read";
    case ReadResult::RenameTmp:
        return "RenameTmp";
    default:
        return "Error";
    }
}

void Carcass::message(QString str, bool _modal)
{
    MessageWindow* ms = new MessageWindow(str, _modal);
    ms->show();
}

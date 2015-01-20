#include "abstraction_aw.h"

Abstraction_AW::Abstraction_AW(Data *_data, bool _mode)
{
    dt = _data;
}

Abstraction_AW::~Abstraction_AW()
{

}

bool Abstraction_AW::Login(const QString& _password)
{
    if (dt->AccountList->Contains(UserName)){
        if (dt->AccountList->at(dt->AccountList->IndexOf(UserName))->CheckPassword(_password)){
            if(dt->AccountList->SelectItem(UserName)){
                return true;
            }
            else{
                qDebug() << "some problem during log in";
                return false;
            }
        }
        else {
            qDebug() << "Incorrect Password";
            return false;
        }
    }
    else {
        qDebug() << "User is not found";
        return false;
    }
}

bool Abstraction_AW::Registration(const QString& _password)
{
    if (dt->AccountList->Contains(UserName)){
        qDebug() << "This user name is already in use";
        return false;
    }

    QString AccountOS;
    AccountOS = qgetenv("USER");
    if (AccountOS.isEmpty())
        AccountOS = qgetenv("USERNAME");

    AccountParameter ap;
    ap.name = UserName;
    ap.password = _password;
    ap.accountOS << AccountOS;
    ap.LL = dt->LL;

    if(dt->AccountList->AddItem(ap)) return true;

    qDebug() << "some problem during registration";
    return false;
}

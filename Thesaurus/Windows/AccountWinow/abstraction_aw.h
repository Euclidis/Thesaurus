#ifndef ABSTRACTION_AW_H
#define ABSTRACTION_AW_H

#ifndef START_WINDOWS
#include "../start.h"
#endif

class Abstraction_AW
{
public:
    Abstraction_AW(Data* _data, bool _mode = 0);
    ~Abstraction_AW();
protected:
    Data* dt;
    QString UserName;
    bool mode_flag;
    bool Login(const QString &_password);
    bool Registration(const QString &_password);
};

#endif // ABSTRACTION_AW_H

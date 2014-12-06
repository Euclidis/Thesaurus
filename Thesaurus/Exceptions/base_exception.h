#ifndef BASEEXCEPRION_H
#define BASEEXCEPRION_H

#include "../general.h"
#include "exception_window.h"

class BaseExceprion
{
private:
    QString str;
public:
    BaseExceprion(QString);
    virtual void show();
    virtual QString text();
};

#endif // BASEEXCEPRION_H

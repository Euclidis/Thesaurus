#ifndef MENU_ABSTRACTION_H
#define MENU_ABSTRACTION_H

#include "../language.h"

class MenuAbstraction : public QObject
{
    Q_OBJECT

private:
    Carcass* carcass;
    Language* language;
public:
    explicit MenuAbstraction(Carcass* _carcass);

signals:

public slots:

};

#endif // MENU_ABSTRACTION_H

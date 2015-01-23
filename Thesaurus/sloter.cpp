#include "sloter.h"

Sloter::Sloter(QObject *parent) : QObject(parent)
{
    dt = new Data;
    AW_open();
}

void Sloter::Connector()
{
}

void Sloter::AW_open()
{
    if(AW == nullptr){
        AW = new AccountWindow(dt);
        connect(AW, SIGNAL(MW_open()), SLOT(MW_open()));
    }
    AW->show();
}
void Sloter::MW_open()
{
    if(MW == nullptr) MW = new MenuWindow(dt);
    MW->show();
}
Sloter::~Sloter()
{

}


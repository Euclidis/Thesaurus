#ifndef SLOTER_H
#define SLOTER_H

#ifndef END_WINDOWS
#include "Windows/end.h"
#endif

class Sloter : public QObject
{
    Q_OBJECT
public:
    Data* dt = nullptr;

    explicit Sloter(QObject *parent = 0);
    ~Sloter();
    void Connector();
public:
    AccountWindow* AW = nullptr;
    MenuWindow* MW = nullptr;
signals:

public slots:
    void AW_open();
    void MW_open();
};

#endif // SLOTER_H

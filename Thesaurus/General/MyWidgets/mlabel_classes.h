#ifndef MLABELREFERENCE_H
#define MLABELREFERENCE_H

#ifndef MLABELBASE_H
#include "mlabel_base.h"
#endif

class MLabelButton: public MLabelBase {
Q_OBJECT

public:
    explicit MLabelButton(QWidget *parent = 0) : MLabelBase(parent)
    {
        setAlignment(Qt::AlignCenter);
    }
    ~MLabelButton(){}
};


class MLabelReference: public MLabelBase {
Q_OBJECT

public:
    explicit MLabelReference(QWidget *parent = 0) : MLabelBase(parent){}
    ~MLabelReference(){}
};

#endif // MLABELREFERENCE_H

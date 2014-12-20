#ifndef MENU_ABSTRACTION_H
#define MENU_ABSTRACTION_H

#include <QObject>

class MenuAbstraction : public QObject
{
    Q_OBJECT
public:
    explicit MenuAbstraction(QObject *parent = 0);

signals:

public slots:

};

#endif // MENU_ABSTRACTION_H

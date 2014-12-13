#ifndef LABEL_H
#define LABEL_H

#include "../../general.h"


class Label : public QLabel {
    Q_OBJECT

public:
    Label(QWidget *parent = 0, Qt::WindowFlags f=0);
    Label(const QString &text, QWidget *parent=0, Qt::WindowFlags f=0);
    ~Label();

protected:
    void mousePressEvent();
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);


signals:
    void clicked();
    void mouseLeave();
    void mouseEnter();
};

#endif // LABEL_H

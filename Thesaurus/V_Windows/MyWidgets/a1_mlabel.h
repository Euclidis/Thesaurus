#ifndef MLABEL_H
#define MLABEL_H

#ifndef START
#include "../start.h"
#endif

class MLabel : public QLabel {
    Q_OBJECT

public:
    MLabel(QWidget *parent = 0);
    ~MLabel();

    void setColorScheme (const QString& _color_enter,
                         const QString& _color_leave,
                         const QString& _color_text_enter,
                         const QString &_color_text_leave);
protected:
    bool flag_set_color = false;
    QString color_enter;
    QString color_leave;
    QString color_text_enter;
    QString color_text_leave;
    void mousePressEvent(QMouseEvent *e);
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);


signals:
    void clicked();
    void mouseLeave();
    void mouseEnter();
};

#endif // LABEL_H

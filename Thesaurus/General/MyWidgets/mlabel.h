#ifndef MLABEL_H
#define MLABEL_H

#ifndef START_MYWIDGETS
#include "start.h"
#endif

class MLabel : public QLabel {
    Q_OBJECT
    Q_PROPERTY(QColor color_enter READ getColor_Enter WRITE setColor_Enter DESIGNABLE true)
    Q_PROPERTY(QColor color_leave READ getColor_Leave WRITE setColor_Leave DESIGNABLE true)
    Q_PROPERTY(QColor color_text_enter READ getColor_TextEnter WRITE setColor_TextEnter DESIGNABLE true)
    Q_PROPERTY(QColor color_text_leave READ getColor_TextLeave WRITE setColor_TextLeave DESIGNABLE true)
    Q_PROPERTY(int border_radius READ getBorderRadius WRITE setBorderRadius DESIGNABLE true)

public:
    MLabel(QWidget *parent = 0);
    ~MLabel();

private:
    QColor color_enter = Qt::white;
    QColor color_leave = Qt::white;
    QColor color_text_enter = Qt::black;
    QColor color_text_leave = Qt::black;

    QString c_enter;
    QString c_leave;
    QString c_tx_enter;
    QString c_tx_leave;
    int border_radius;

public:
    void setColor_Enter( QColor c );
    void setColor_Leave( QColor c );
    void setColor_TextEnter( QColor c );
    void setColor_TextLeave( QColor c );
    void setColor_ColorToText(const QColor& c, QString& str);
    void setBorderRadius(int r);

    QColor getColor_Enter();
    QColor getColor_Leave();
    QColor getColor_TextEnter();
    QColor getColor_TextLeave();
    int getBorderRadius();

private:
    void mousePressEvent(QMouseEvent *e);
    virtual void enterEvent(QEvent *e);
    virtual void leaveEvent(QEvent *e);

signals:
    void clicked();
};

#endif // LABEL_H

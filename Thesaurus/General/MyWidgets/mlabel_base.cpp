#ifndef MLABELBASE_H
#include "mlabel_base.h"
#endif

//---------------------------------------------------------------------------------------------
MLabelBase::MLabelBase(QWidget *parent):QLabel(parent)
{
}
//---------------------------------------------------------------------------------------------
MLabelBase::~MLabelBase(){}
//---------------------------------------------------------------------------------------------
void MLabelBase::mousePressEvent(QMouseEvent *e){
    emit clicked();
    QLabel::mousePressEvent(e);
}
//---------------------------------------------------------------------------------------------
void MLabelBase::leaveEvent(QEvent *e)
{
    setStyleSheet("QLabel {"
                  "background-color : " + c_leave + "; "
                  "color : "  + c_tx_leave + "; "
                  "border-radius: " + QString::number(border_radius) + "px; }");
//    QPalette p(this->palette());
//    qDebug() << color_text_leave.name();
//    p.setColor(QPalette::WindowText, color_text_leave);
//    setPalette(p);
    QLabel::leaveEvent(e);
}
//---------------------------------------------------------------------------------------------
void MLabelBase::enterEvent(QEvent *e)
{
    setStyleSheet("QLabel {"
                  "background-color : " + c_enter + "; "
                  "color : "  + c_tx_enter + "; "
                  "border-radius: " + QString::number(border_radius) + "px; }");
//    QPalette p(this->palette());
//    qDebug() << color_text_enter.name();
//    p.setColor(QPalette::WindowText, color_text_enter);
//    setPalette(p);
//    setAutoFillBackground(true);
//    QPalette p(this->palette());
//    p.setColor(QPalette::WindowText, Qt::red);
//    p.setColor(QPalette::Background, Qt::black);
//    setPalette(p);
    QLabel::enterEvent(e);
}
//---------------------------------------------------------------------------------------------
void MLabelBase::setColor_Enter( QColor c )
{
    color_enter  = c;
    setColor_ColorToText(c, c_enter);
}
void MLabelBase::setColor_Leave( QColor c )
{
    color_leave = c;
    setColor_ColorToText(c, c_leave);
}
void MLabelBase::setColor_TextEnter( QColor c )
{
    color_text_enter = c;
    setColor_ColorToText(c, c_tx_enter);
}
void MLabelBase::setColor_TextLeave( QColor c )
{
    color_text_leave = c;
    setColor_ColorToText(c, c_tx_leave);
}
void MLabelBase::setColor_ColorToText(const QColor& c, QString& str)
{
    str = "rgba(" + QString::number(c.red())   + "," +
                    QString::number(c.green()) + "," +
                    QString::number(c.blue())  + "," +
                    QString::number(c.alpha()*(100.0/255.0)) + "%)";
}
void MLabelBase::setBorderRadius(int r)
{
    border_radius = r;
}
//---------------------------------------------------------------------------------------------
QColor MLabelBase::getColor_Enter()
{
    return color_enter;
}
QColor MLabelBase::getColor_Leave()
{
    return color_leave;
}
QColor MLabelBase::getColor_TextEnter()
{
    return color_text_enter;
}
QColor MLabelBase::getColor_TextLeave()
{
    return color_text_leave;
}
int MLabelBase::getBorderRadius()
{
    return border_radius;
}

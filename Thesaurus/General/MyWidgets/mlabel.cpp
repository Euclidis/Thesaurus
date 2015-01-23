#ifndef MLABEL_H
#include "mlabel.h"
#endif

//---------------------------------------------------------------------------------------------
MLabel::MLabel(QWidget *parent):QLabel(parent)
{
    setAlignment(Qt::AlignCenter);
}
//---------------------------------------------------------------------------------------------
MLabel::~MLabel(){}
//---------------------------------------------------------------------------------------------
void MLabel::mousePressEvent(QMouseEvent *e){
    emit clicked();
    QLabel::mousePressEvent(e);
}
//---------------------------------------------------------------------------------------------
void MLabel::leaveEvent(QEvent *e)
{
    setStyleSheet("QLabel {"
                  "background-color : " + c_leave + "; "
                  "color : "  + c_tx_leave + "; "
                  "border-radius: " + QString::number(border_radius) + "px; }");
    QLabel::leaveEvent(e);
}
//---------------------------------------------------------------------------------------------
void MLabel::enterEvent(QEvent *e)
{
    setStyleSheet("QLabel {"
                  "background-color : " + c_enter + "; "
                  "color : "  + c_tx_enter + "; "
                  "border-radius: " + QString::number(border_radius) + "px; }");
//    setAutoFillBackground(true);
//    QPalette p(this->palette());
//    p.setColor(QPalette::WindowText, Qt::red);
//    p.setColor(QPalette::Background, Qt::black);
//    setPalette(p);
    QLabel::enterEvent(e);
}
//---------------------------------------------------------------------------------------------
void MLabel::setColor_Enter( QColor c )
{
    color_enter  = c;
    setColor_ColorToText(c, c_enter);
}
void MLabel::setColor_Leave( QColor c )
{
    color_leave = c;
    setColor_ColorToText(c, c_leave);
}
void MLabel::setColor_TextEnter( QColor c )
{
    color_text_enter = c;
    setColor_ColorToText(c, c_tx_enter);
}
void MLabel::setColor_TextLeave( QColor c )
{
    color_text_leave = c;
    setColor_ColorToText(c, c_tx_leave);
}
void MLabel::setColor_ColorToText(const QColor& c, QString& str)
{
    str = "rgba(" + QString::number(c.red())   + "," +
                    QString::number(c.green()) + "," +
                    QString::number(c.blue())  + "," +
                    QString::number(c.alpha()*(100.0/255.0)) + "%)";
}
void MLabel::setBorderRadius(int r)
{
    border_radius = r;
}
//---------------------------------------------------------------------------------------------
QColor MLabel::getColor_Enter()
{
    return color_enter;
}
QColor MLabel::getColor_Leave()
{
    return color_leave;
}
QColor MLabel::getColor_TextEnter()
{
    return color_text_enter;
}
QColor MLabel::getColor_TextLeave()
{
    return color_text_leave;
}
int MLabel::getBorderRadius()
{
    return border_radius;
}

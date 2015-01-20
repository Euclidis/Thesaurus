#include "a1_mlabel.h"

//---------------------------------------------------------------
MLabel::MLabel(QWidget *parent):QLabel(parent)
{

}
//---------------------------------------------------------------
MLabel::~MLabel(){}
//---------------------------------------------------------------
void MLabel::mousePressEvent(QMouseEvent *e){
    emit clicked();
}
//---------------------------------------------------------------
void MLabel::leaveEvent(QEvent *e)
{
    if(flag_set_color)setStyleSheet("QLabel {"
                                    "background-color : rgba(" + color_leave +
                                    "); color : rgba("  + color_text_leave +
                                    "); border-radius: 5px; }");
    QLabel::leaveEvent(e);
}
//---------------------------------------------------------------
void MLabel::enterEvent(QEvent *e)
{
    if(flag_set_color)setStyleSheet("QLabel {"
                                    "background-color : rgba(" + color_enter +
                                    "); color : rgba("  + color_text_enter +
                                    "); border-radius: 5px; }");
    QLabel::enterEvent(e);
}

void MLabel::setColorScheme (const QString& _color_enter,
                             const QString& _color_leave,
                             const QString& _color_text_enter,
                             const QString& _color_text_leave)
{
    color_enter = _color_enter;
    color_leave = _color_leave;
    color_text_enter = _color_text_enter;
    color_text_leave = _color_text_leave;
    flag_set_color = true;
    setStyleSheet("QLabel {"
                  "background-color : rgba(" + color_leave +
                  "); color : rgba("  + color_text_leave +
                  "); border-radius: 5px; }");
}

#ifndef MSCROLLAREA_H
#include "a3_mscrollarea.h"
#endif

MScrollArea::MScrollArea(QWidget *parent):
    QScrollArea(parent)
{
    v = nullptr;
    w = nullptr;
    this->setFrameStyle(0);
    this->setBackgroundRole(QPalette::Dark);
}


void MScrollArea::AddItem(const QString& item_text)
{
    int i = IndexOf(item_text);
    if (i < 0){

        if(w == nullptr){
            v = new QVBoxLayout;
            v->setSpacing(1);
            v->setContentsMargins(0,0,0,0);
            w = new QWidget(this);
            w->setLayout(v);
            v->addStretch();
        }

        if(list.isEmpty())this->setWidget(w);
        QLineEdit* l = new QLineEdit;
        l->setText(item_text);
        l->setFrame(false);
        l->setReadOnly(true);
        l->installEventFilter(this);
        list << l;
        v->insertWidget(list.size() - 1, l );
    }
}


void MScrollArea::RemoveItem(const QString& item_text)
{
    int i = IndexOf(item_text);
    if (i > -1){
        list.at(i)->close();
        delete list.at(i);
        list.removeAt(i);
    }
}

void MScrollArea::Clear()
{
    if(!list.isEmpty()){
        for(int i = 0; i < list.size(); ++i){
            qDebug() << "ffffF";//
            list.at(i)->close();
            delete list.at(i);
        }
        list.clear();
    }
}


int MScrollArea::IndexOf(const QString& item_text)
{
    if(!list.isEmpty()){
        for(int i = 0; i < list.size(); ++i){
            if(list.at(i)->text() == item_text) return i;
        }
    }
    return -1;
}

bool MScrollArea::eventFilter(QObject * obj, QEvent * e)
{
    if(QLineEdit* l = qobject_cast<QLineEdit*>(obj)){
        if(e->type() == QEvent::MouseButtonPress)
        {
            if(((QMouseEvent*)e)->button() == Qt::MouseButton::LeftButton) emit click_left(l->text());
            else emit click_right(l->text());
            return true;
        }
    }
    return false;
}

MScrollArea::~MScrollArea()
{

}

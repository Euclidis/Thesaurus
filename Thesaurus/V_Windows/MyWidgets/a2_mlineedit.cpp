#ifndef MLINEEDIT_H
#include "a2_mlineedit.h"
#endif

MLineEdit::MLineEdit(QWidget *parent) : QLineEdit(parent)
{
    connect(this, SIGNAL(textChanged(QString)), SLOT(slot_TextChanged(QString)));
    flag_bold_change = false;

    QRegExp reg_exp ("[A-Za-z-_0-9]{1,20}");
    _valide = new QRegExpValidator (reg_exp);
    this->setValidator(_valide);
}

MLineEdit::~MLineEdit()
{
    delete _valide;
}

void MLineEdit::SetBoldChange(bool _flag_bold_change)
{
    flag_bold_change = _flag_bold_change;
}

void MLineEdit::slot_TextChanged(const QString &_text)
{
    if(flag_bold_change){
        QFont font(this->font());
        if(_text.isEmpty())
            font.setBold(0);
        else
            font.setBold(1);
        this->setFont(font);
    }
}

#ifndef MLINEEDIT_H
#define MLINEEDIT_H

#ifndef START
#include "../start.h"
#endif

class MLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MLineEdit(QWidget *parent = 0);
    ~MLineEdit();
    void SetBoldChange(bool _flag_bold_change);
    QRegExpValidator* _valide;
    bool flag_bold_change;
signals:

public slots:
    void slot_TextChanged(const QString& _text);
};

#endif // MLINEEDIT_H

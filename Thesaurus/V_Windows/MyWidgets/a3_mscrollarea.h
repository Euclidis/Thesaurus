#ifndef MSCROLLAREA_H
#define MSCROLLAREA_H

#ifndef START
#include "../start.h"
#endif

class MScrollArea: public QScrollArea
{
    Q_OBJECT

public:
    void AddItem(const QString& item_text);
    void RemoveItem(const QString& item_text);
    void Clear();
signals:
    void click_left(const QString& item_text);
    void click_right(const QString& item_text);

public:
    MScrollArea(QWidget *parent);
    ~MScrollArea();
private:
    QVBoxLayout* v;
    QWidget* w;
    QList<QLineEdit*> list;
private:
    int IndexOf(const QString& item_text);
    bool eventFilter(QObject * obj, QEvent * e);
};

#endif // MSCROLLAREA_H

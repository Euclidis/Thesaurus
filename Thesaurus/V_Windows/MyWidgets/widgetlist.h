#ifndef WIDGETLIST_H
#define WIDGETLIST_H

#ifndef GENERAL_H
#include "../../general.h"
#endif

class WidgetList: public QScrollArea
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
    WidgetList(QWidget *parent);
    ~WidgetList();
private:
    QVBoxLayout* v;
    QWidget* w;
    QList<QLineEdit*> list;
private:
    int IndexOf(const QString& item_text);
    bool eventFilter(QObject * obj, QEvent * e);
};

#endif // WIDGETLIST_H

#ifndef DCT_WINDOW_H
#define DCT_WINDOW_H

#ifndef WWW_REALIZATION_H
#include "../Implementation/www_realization.h"
#endif

namespace Ui {
class DctWindow;
}

class DctWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit DctWindow(WWWAbstraction*);
    ~DctWindow();

private:
    WWWAbstraction* realiz;
private:
    void BoxFilling();
    void CreateNewCheckBox(QString str);
    void mousePressEvent(QMouseEvent *event);
    void ContextMenuShow();
private slots:
    void CheckChange(bool b);
    void AddDictionary();
    void TextShow();

    void on_lineEdit_returnPressed();

private:
    Ui::DctWindow *ui;
};

#endif // DCT_WINDOW_H

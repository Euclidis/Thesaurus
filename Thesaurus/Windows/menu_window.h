#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#ifndef CARCASS_H
#include "../carcass.h"
#endif

namespace Ui {
class MenuWindow;
}

class MenuWindow : public BaseWindow
{
    Q_OBJECT
public:
    explicit MenuWindow(Carcass * _carcass);
    ~MenuWindow();
private:
    Ui::MenuWindow *ui;


private:
    Carcass* carcass;
    QSize PhotoSize;

public:
    void Connector();
    void AddItemToDctList(QString dct_name);
signals:
    void WWW_open_signal();
    void WWW_close();
    void LSW_open();
public slots:
    void SetAccount();
    //void SetLearnDir();
    void SetDictionaries();
    //void SetWordsList();
    void WWW_open_slot();
private:
    void ObjSet_AccountName();
    void ObjSet_AccountPhoto(QPixmap& p);
    void ObjSet_CurLearnDir();
    void DctList_UpDate();
    void DctList_Clear();
};

#endif // MENU_WINDOW_H

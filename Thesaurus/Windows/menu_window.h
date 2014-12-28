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
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor DESIGNABLE true)
public:
    explicit MenuWindow(Carcass * _carcass);
    ~MenuWindow();

  void paintEvent(QPaintEvent *p_ev);
  QColor getLineColor() const;
  void setLineColor( QColor c );

private:
    Ui::MenuWindow *ui;


private:
    Carcass* carcass;
    QSize PhotoSize;
    QColor lineColor = Qt::gray;

    //****************************************
    //       Интерфейс зависимые ф-и
    //****************************************
private:
    void Connector();
private:
    void ObjSet_AccountName();
    void ObjSet_AccountPhoto(QPixmap& p);
    void ObjSet_CurLearnDir(const QString &_LD);
    void DctList_Clear();
    void AddItemToDctList(const QString &dct_name);
private:
    void ObjectsForEvetFilter();
    //*****************************************
    //        Интерфейс независимые ф-и
    //*****************************************
public slots:
    void SetAccount();
    void SetAccountPhoto();
    void SetDictionaries();

    void DctList_UpDate();
    void DctList_Add(const QString& dct_name);
private:
    //----------> Раздел EventFilter
    QObject* Obj_for_photo;
    void InstallEventFilter();
    bool eventFilter(QObject * obj, QEvent * e);
    //********************************************
    //        Ф-и закрытия/открытия окон
    //********************************************
public slots:
    void AW_open_slot();
    void WWW_open_slot();
    void LSW_open_slot();
signals:
    void AW_open_signal();
    void WWW_open_signal();
    void LSW_open_signal();
};

#endif // MENU_WINDOW_H

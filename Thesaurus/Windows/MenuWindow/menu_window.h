#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#ifndef ABSTRACTION_MW_H
#include "abstraction_mw.h"
#endif

namespace Ui {
class MenuWindow;
}

class MenuWindow : public BaseWindow, public Abstraction_MW
{
    Q_OBJECT
//    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor DESIGNABLE true)
public:
    explicit MenuWindow(Data* _data);
    ~MenuWindow();

//    void paintEvent(QPaintEvent *p_ev);
//    QColor getLineColor() const;
//    void setLineColor( QColor c );

private:
    Ui::MenuWindow *ui;


private:
    QSize PhotoSize;
    QColor lineColor = Qt::gray;

private:
    virtual void InstallConnect();
    virtual void InstallTexts();
    virtual void InstallFocusWidget();
    virtual void InstallColor();
    virtual void InstallImages();
    virtual void InstallAnimation();

private:

public slots:
    void SetAccount();
//    void SetDictionaries();
//    void SetWords(const QString &dct_name);

    void DctList_Clear();
    void DctList_UpDate();
    void DctList_Add(const QString& dct_name);
private:
//    QObject* Obj_for_photo;
//    void ObjectsForEvetFilter();
//    void InstallEventFilter();
//    bool eventFilter(QObject * obj, QEvent * e);

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

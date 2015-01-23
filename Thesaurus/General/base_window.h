#ifndef BASE_WINDOW_H
#define BASE_WINDOW_H

#ifndef LANG_LIST
#include "lang_list.h"
#endif



namespace Ui {
class BaseWindow;
}

class BaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BaseWindow();
    ~BaseWindow();

private:
    void InstallFont();
    virtual void InstallConnect(){}
    virtual void InstallTexts(){}
    virtual void InstallFocusWidget(){}
    virtual void InstallColor(){}
    virtual void InstallImages(){}
    virtual void InstallAnimation(){}
    void closeEvent(QCloseEvent * ev);

signals:
    void CloseMe(BaseWindow*);


private:
    Ui::BaseWindow *ui;
};

#endif // BASE_WINDOW_H

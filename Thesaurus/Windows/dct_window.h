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
    explicit DctWindow(WWWRealization*);
    ~DctWindow();

private:
    WWWRealization* realiz;
private:
    void BoxFilling();

private:
    Ui::DctWindow *ui;
};

#endif // DCT_WINDOW_H

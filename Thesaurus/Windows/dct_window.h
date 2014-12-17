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
    explicit DctWindow(WWWRealization*, QMap<QString, bool>);
    ~DctWindow();

private:
    WWWRealization* realiz;
    QMap<QString, bool> DctCheck;

private:
    Ui::DctWindow *ui;
};

#endif // DCT_WINDOW_H

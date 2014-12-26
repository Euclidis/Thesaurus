#ifndef MESOKCANCEL_H
#define MESOKCANCEL_H

#include "message_window.h"

namespace Ui {
class MesOKCancel;
}

class MesOKCancel : public BaseWindow
{
    Q_OBJECT

public:
    explicit MesOKCancel(QString str);
    ~MesOKCancel();
void closeEvent(QCloseEvent*);
signals:
    void MesOKCancelResult(bool);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MesOKCancel *ui;
};

#endif // MESOKCANCEL_H

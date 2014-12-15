#ifndef SLOTER_H
#define SLOTER_H

#include "Windows/account_window.h"
#include "Windows/menu_window.h"
#include "Windows/write_words_window.h"
#include "Windows/lang_selection_window.h"
#include "Implementation/learning_direction.h"
#include "language.h"

class Sloter : public QObject
{
    Q_OBJECT

private:
    Carcass * carcass;
    AccountWindow * AW;
    MenuWindow * MW;
    WriteWordsWindow * WWW;
    LangSelectionWindow * LSW;
    MesOKCancel * MOCW;
public:
    explicit Sloter();

private:
    void connector();

public slots:
    void AW_show(bool mode = 0);
    void MW_show();
    void WWW_show();
    void LSW_show();
    void MOCW_show(QString);

};

#endif // SLOTER_H

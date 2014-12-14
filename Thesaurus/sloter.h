#ifndef SLOTER_H
#define SLOTER_H

#include "Windows/account_window.h"
#include "Windows/menu_window.h"
#include "Windows/write_words_window.h"
#include "Windows/lang_selection_window.h"
#include "language.h"

class Sloter : public QObject
{
    Q_OBJECT

public:
    Carcass * carcass;
    AccountWindow * AW;
    MenuWindow * MW;
    WriteWordsWindow * WWW;
    LangSelectionWindow * LSW;
public:
    explicit Sloter();

signals:

public slots:
    void AW_show(bool mode = 0);
    void MW_show();
    void WWW_show();
    void LSW_show();

};

#endif // SLOTER_H

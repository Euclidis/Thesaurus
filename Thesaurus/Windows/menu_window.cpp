#include "menu_window.h"
#include "ui_menu_window.h"

MenuWindow::MenuWindow(Carcass * _carcass) :
    ui(new Ui::MenuWindow), carcass(_carcass)
{
    ui->setupUi(this);
    PhotoSize.setWidth(81);
    PhotoSize.setHeight(81);
    Connector();
    SetAccount();
    SetDictionaries();
}


//****************************************************************************************************
//             Интерфейс зависимые ф-и. Для того, чтобы легко можно было менять виджеты.
//****************************************************************************************************
void MenuWindow::Connector()                                                //
{                                                                           // Коннектор
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(WWW_open_slot()));      //
}                                                                           //

void MenuWindow::ObjSet_AccountName()                                                //
{                                                                                    //
    ui->label_2->setText(carcass->CurAccount->Get());                                //
}                                                                                    //
void MenuWindow::ObjSet_AccountPhoto(QPixmap& p)                                     //
{                                                                                    //  Лэйблы, принимающие
    ui->label->setPixmap(p);                                                         //  значения
}                                                                                    //
void MenuWindow::ObjSet_CurLearnDir()                                                //
{                                                                                    //
    ui->label_3->setText(carcass->CurLearnDir->Get().knownL                          //
                         + "-" + carcass->CurLearnDir->Get().targL);                 //
}                                                                                    //

void MenuWindow::DctList_Clear()                                                //
{                                                                               //
    delete ui->verticalLayout;                                                  //
    ui->verticalLayout = new QVBoxLayout;                                       //
    ui->verticalLayout->addStretch(1);                                          //
}                                                                               //
void MenuWindow::AddItemToDctList(QString dct_name)                             //
{                                                                               //  Ф-и списка словарей
    QHBoxLayout* h = new QHBoxLayout;                                           //
    QPushButton* c = new QPushButton(dct_name);                                 //
    c->setFlat(true);                                                           //
    //connect(c, SIGNAL(clicked(bool)), SLOT(CheckChange(bool)));               //
    h->addWidget(c);                                                            //
    ui->verticalLayout->insertLayout(ui->verticalLayout->count()-1, h);         //
    ui->scrollArea->widget()->setLayout(ui->verticalLayout);                    //
}                                                                               //
//****************************************************************************************************
//****************************************************************************************************


//****************************************************************************************************
//                                 Интерфейс независимые ф-и
//****************************************************************************************************
void MenuWindow::SetAccount()
{
    QString account_name = carcass->CurAccount->Get();
    if(account_name != ""){
        QPixmap* p;
        if(carcass->CurAccount->account_photo.isNull()){
            p = new QPixmap(carcass->adr.default_face);
        }
        else{
            p = new QPixmap(carcass->CurAccount->account_photo);
        }
        ObjSet_AccountPhoto(p->scaled(PhotoSize));
        delete p;
        ObjSet_AccountName();
    }
}
void MenuWindow::SetDictionaries()
{
    if(carcass->CurLearnDir->Get().knownL != ""){
        ObjSet_CurLearnDir();
        DctList_UpDate();
    }
    else{
        DctList_Clear();
    }
}
void MenuWindow::DctList_UpDate()
{
    DctList_Clear();
    for(int i = 0; i < carcass->CurLearnDir->dictionaries.size(); ++i){
        AddItemToDctList(carcass->CurLearnDir->dictionaries.at(i));
    }
}
void MenuWindow::WWW_open_slot()
{
    if(carcass->CurLearnDir->Get().knownL == "") {
        LD ld;
        ld.knownL = "Russian";
        ld.targL = "English";

        carcass->CurLearnDirList->Add(ld);
        WWW_open_signal();
    }
    else{
        //carcass->CurLearnDir->Set("Russian", "Spain");
        WWW_open_signal();
    }
}

//****************************************************************************************************
//****************************************************************************************************
MenuWindow::~MenuWindow()
{
    delete ui;
}



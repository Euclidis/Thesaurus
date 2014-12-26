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
    ObjectsForEvetFilter();
}


//****************************************************************************************************
//             Интерфейс зависимые ф-и. Для того, чтобы легко можно было менять виджеты.
//****************************************************************************************************
void MenuWindow::Connector()                                                //
{                                                                           // Коннектор
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(WWW_open_slot()));      //
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(LSW_open_slot()));    //
    connect(ui->pushButton_3, SIGNAL(clicked()), SLOT(AW_open_slot()));     //
}                                                                           //

void MenuWindow::ObjSet_AccountName()                                                //
{                                                                                    //
    ui->label_2->setText(carcass->CurAccount->Get());                                //
}                                                                                    //
void MenuWindow::ObjSet_AccountPhoto(QPixmap& p)                                     //
{                                                                                    //  Лэйблы, принимающие
    ui->label->setPixmap(p);                                                         //  значения
}                                                                                    //
void MenuWindow::ObjSet_CurLearnDir(const QString& _LD)                              //
{                                                                                    //
    ui->label_3->setText(_LD);                                                       //
}                                                                                    //

void MenuWindow::DctList_Clear()                                                //
{                                                                               //
    delete ui->verticalLayout;                                                  //
    ui->verticalLayout = new QVBoxLayout;                                       //
    ui->verticalLayout->addStretch(1);                                          //
}                                                                               //
void MenuWindow::AddItemToDctList(const QString& dct_name)                      //
{                                                                               //  Ф-и списка словарей
    QHBoxLayout* h = new QHBoxLayout;                                           //
    QPushButton* c = new QPushButton(dct_name);                                 //
    c->setFlat(true);                                                           //
    //connect(c, SIGNAL(clicked(bool)), SLOT(CheckChange(bool)));               //
    h->addWidget(c);                                                            //
    ui->verticalLayout->insertLayout(ui->verticalLayout->count()-1, h);         //
    ui->scrollArea->widget()->setLayout(ui->verticalLayout);                    //
}                                                                               //

void MenuWindow::ObjectsForEvetFilter()
{
    Obj_for_photo = ui->label;
    InstallEventFilter();
}

//****************************************************************************************************
//****************************************************************************************************


//****************************************************************************************************
//                                 Интерфейс независимые ф-и
//****************************************************************************************************
//---------> Обновления
void MenuWindow::SetAccount()
{
    QString account_name = carcass->CurAccount->Get();
    if(account_name != ""){
        ObjSet_AccountName();
        SetAccountPhoto();
        SetDictionaries();
    }
}
void MenuWindow::SetAccountPhoto()
{
    QPixmap* p;
    if(carcass->CurAccount->account_photo.isNull()){
        p = new QPixmap(carcass->adr.default_face);
    }
    else{
        p = new QPixmap(carcass->CurAccount->account_photo);
    }
    ObjSet_AccountPhoto(p->scaled(PhotoSize, Qt::KeepAspectRatioByExpanding));
    delete p;
}

void MenuWindow::SetDictionaries()
{
    if(carcass->CurLearnDir->Get().knownL != ""){
        ObjSet_CurLearnDir(carcass->CurLearnDir->Get().knownL
                           + "-" + carcass->CurLearnDir->Get().targL);
        DctList_UpDate();
    }
    else{
        ObjSet_CurLearnDir("");
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
void MenuWindow::DctList_Add(const QString& dct_name)
{
    AddItemToDctList(dct_name);
}

//-------------> Ф-и фильтра событий
void MenuWindow::InstallEventFilter()
{
    Obj_for_photo->installEventFilter(this);
}

bool MenuWindow::eventFilter(QObject * obj, QEvent * e)
{
    if(obj == Obj_for_photo){
        switch (e->type()) {
        case QEvent::MouseButtonPress:
            if(((QMouseEvent*)e)->button() == Qt::MouseButton::LeftButton){
                QString fileName = QFileDialog::getOpenFileName(this,
                     tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
                if(!fileName.isEmpty()){
                    carcass->CurAccount->Set_account_photo(fileName);
                    SetAccountPhoto();
                }
                return true;
            }
        }
    }
    return false;
}

//------> Октрытия окон
void MenuWindow::AW_open_slot()
{
    emit AW_open_signal();
}

void MenuWindow::WWW_open_slot()
{
    if(!carcass->CurLearnDirList->Get().isEmpty()) emit WWW_open_signal();
    else{
        carcass->message("Create Lerning Direction");
        emit LSW_open_signal();
    }
}
void MenuWindow::LSW_open_slot()
{
    emit LSW_open_signal();
}

//****************************************************************************************************
//****************************************************************************************************
MenuWindow::~MenuWindow()
{
    delete ui;
}

#include "menu_window.h"
#include "ui_menu_window.h"

MenuWindow::MenuWindow(Carcass * _carcass) :
    ui(new Ui::MenuWindow), carcass(_carcass)
{
    ui->setupUi(this);
    SetAccount();
    SetDictionaries();
}

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
        int w = ui->label->width();
        int h = ui->label->height();
        ui->label->setPixmap(p->scaled(w, h));
        delete p;
        ui->label_2->setText(account_name);
    }
}

void MenuWindow::SetDictionaries()
{
    if(carcass->CurLearnDir->Get().knownL != ""){
        ui->label_3->setText(carcass->CurLearnDir->Get().knownL + " - " + carcass->CurLearnDir->Get().targL);
        delete ui->verticalLayout;
        ui->verticalLayout = new QVBoxLayout;
        ui->verticalLayout->addStretch(1);
        for(int i = 0; i < carcass->CurLearnDir->dictionaries.size(); ++i){
            CreateNewCheckBox(carcass->CurLearnDir->dictionaries.at(i));
        }
    }
}

void MenuWindow::CreateNewCheckBox(QString str)
{
    QHBoxLayout* h = new QHBoxLayout;
    QPushButton* c = new QPushButton(str);
    c->setFlat(true);
    //connect(c, SIGNAL(clicked(bool)), SLOT(CheckChange(bool)));
    h->addWidget(c);
    ui->verticalLayout->insertLayout(ui->verticalLayout->count()-1, h);
    ui->scrollArea->widget()->setLayout(ui->verticalLayout);
}

void MenuWindow::slot_for_LSW()
{

}

MenuWindow::~MenuWindow()
{
    delete ui;
}


void MenuWindow::on_pushButton_clicked()
{
    if(carcass->CurLearnDir->Get().knownL == "") {
        LD ld;
        ld.knownL = "Russian";
        ld.targL = "English";

        carcass->CurLearnDirList->Add(ld);
        WWW_open();
    }
    else{

        carcass->CurLearnDir->Set("Russian", "Spain");
        WWW_open();
    }
}

#include "menu_window.h"
#include "ui_menu_window.h"

MenuWindow::MenuWindow(Carcass * _carcass) :
    ui(new Ui::MenuWindow), MenuAbstraction(_carcass)
{
    ui->setupUi(this);
    if(carcass->current_learn_dir.knownL != carcass->symb.lang_empty){
        LanguageInitialize();
        WWW_close();
    }
    else{
        LSW_open();
        carcass->message(tr("Create a Learning Direction"));
    }
    AccountChange();
}

void MenuWindow::AccountChange()
{
    if(carcass->current_account != ""){
        QPixmap* p;
        if(carcass->account_photo.isNull()){
            p = new QPixmap(carcass->adr.default_face);
        }
        else{
            p = new QPixmap(carcass->account_photo);
        }
        int w = ui->label->width();
        int h = ui->label->height();
        ui->label->setPixmap(p->scaled(w, h));
        delete p;
        ui->label_2->setText(carcass->current_account);
    }
}

void MenuWindow::LearnDirChange()
{
    if(carcass->current_learn_dir.knownL != carcass->symb.lang_empty && carcass->current_learn_dir.knownL != ""){
        ui->label_3->setText(language->learn_dir.knownL + " - " + language->learn_dir.targL);
        delete ui->verticalLayout;
        ui->verticalLayout = new QVBoxLayout;
        ui->verticalLayout->addStretch(1);
        for(int i = 0; i < language->dictionaries.size(); ++i){
            CreateNewCheckBox(language->dictionaries.at(i));
        }
    }
}

void MenuWindow::CreateNewCheckBox(QString str)
{
    QHBoxLayout* h = new QHBoxLayout;
    //QPushButton* c = new QPushButton(str);
    //connect(c, SIGNAL(clicked(bool)), SLOT(CheckChange(bool)));
    //h->addWidget(c);
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


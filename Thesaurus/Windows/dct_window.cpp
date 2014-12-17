#include "dct_window.h"
#include "ui_dct_window.h"

DctWindow::DctWindow(WWWRealization* _realiz) :
    ui(new Ui::DctWindow)
{
    ui->setupUi(this);
    realiz = _realiz;


}

//********************************************************************
//                            INTERFACE
//********************************************************************
void DctWindow::BoxFilling()
{
    QVBoxLayout* v = new QVBoxLayout;
    ui->scrollArea->widget()->setLayout(v);

//    QMap<QString, bool>::iterator i = realiz->DctCheck.begin();
//    while(i != realiz->DctCheck.end()){

//    }

//    int n = realiz->DctCheck.size();
//    QHBoxLayout* h[n];
//    QCheckBox* c[n];
//    for(int i = 0; i < n; ++i){
//        h[i] = new QHBoxLayout;
//        c[i] = new QCheckBox(QString::number(i));
//        h[i]->addWidget(c[i]);
//        v->addLayout(h[i]);
//    }
}

//********************************************************************

DctWindow::~DctWindow()
{
    delete ui;
    delete realiz;
}

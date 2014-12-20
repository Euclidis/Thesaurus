#include "dct_window.h"
#include "ui_dct_window.h"

DctWindow::DctWindow(WWWAbstraction* _realiz) :
    ui(new Ui::DctWindow)
{
    ui->setupUi(this);
    realiz = _realiz;
    BoxFilling();
}

//********************************************************************
//                            CheckBoxes
//********************************************************************
void DctWindow::BoxFilling()
{
    for(int i = 0; i < realiz->language->dictionaries.size(); ++i){
        CreateNewCheckBox(realiz->language->dictionaries.at(i));
    }
    ui->lineEdit->hide();
}
void DctWindow::CreateNewCheckBox(QString str)
{
    QHBoxLayout* h = new QHBoxLayout;
    QCheckBox* c = new QCheckBox(str);
    connect(c, SIGNAL(clicked(bool)), SLOT(CheckChange(bool)));
    h->addWidget(c);
    ui->verticalLayout->insertLayout(ui->verticalLayout->count()-1, h);
    ui->scrollArea->widget()->setLayout(ui->verticalLayout);
}
void DctWindow::CheckChange(bool b)
{
    if(QCheckBox* c = qobject_cast<QCheckBox*>(sender()))
    {
        if(b) realiz->addDctCheck(c->text());
        else realiz->removeDctCheck(c->text());
    }
}
//********************************************************************
//                 Цепь ф-й добавления нового словаря
//********************************************************************

//------> Вызов контекстного меню
void DctWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        ContextMenuShow();
    } else {
        QDialog::mousePressEvent(event);
    }
}

//------> Вызов текстового поля
void DctWindow::TextShow()
{
    ui->lineEdit->show();
    ui->lineEdit->setFocus();
    ui->scrollArea->setEnabled(false);
}

//------> Исчезновение текстового поля и вызов ф-и добавление нового словаря
void DctWindow::on_lineEdit_returnPressed()
{
    AddDictionary();
    ui->lineEdit->setText("");
    ui->lineEdit->hide();
    ui->scrollArea->setEnabled(true);
}

//------> Добавление нового словаря
void DctWindow::AddDictionary()
{
    QString str = ui->lineEdit->text().trimmed();
    if(str != ""){
        if(realiz->AddDictionary(str))
            CreateNewCheckBox(str);
    }
}


//********************************************************************
//                        Контекстное меню
//********************************************************************
void DctWindow::ContextMenuShow()
{
    QMenu m;
    m.addAction(tr("Add a Dictionary"), this, SLOT(TextShow()));
    m.exec(QCursor::pos());
}

//********************************************************************

DctWindow::~DctWindow()
{
    delete ui;
}

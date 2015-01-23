#include "menu_window.h"
#include "ui_menu_window.h"
#include <QStandardItemModel>

MenuWindow::MenuWindow(Data *_data) :
    ui(new Ui::MenuWindow), Abstraction_MW(_data)
{
    ui->setupUi(this);
    PhotoSize.setWidth(81);
    PhotoSize.setHeight(81);

    InstallConnect();
    InstallTexts();
    InstallFocusWidget();
    InstallColor();
    InstallAnimation();
    InstallImages();

    SetAccount();
    //ObjectsForEvetFilter();
}


void MenuWindow::InstallConnect()
{
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(WWW_open_slot()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(LSW_open_slot()));
    connect(ui->pushButton_3, SIGNAL(clicked()), SLOT(AW_open_slot()));
}
void MenuWindow::InstallTexts()
{

}
void MenuWindow::InstallFocusWidget()
{

}
void MenuWindow::InstallColor()
{

}
void MenuWindow::InstallImages()
{

}
void MenuWindow::InstallAnimation()
{

}




void MenuWindow::DctList_Clear()
{
    ui->scrollArea->Clear();
}
void MenuWindow::DctList_UpDate()
{
    DctList_Clear();
    if(dt->CurrentLD() != nullptr){
        foreach (QString i, dt->CurrentLD()->dictionaries) {
            DctList_Add(i);
        }
    }
}
void MenuWindow::DctList_Add(const QString& dct_name)
{
    ui->scrollArea->AddItem(dct_name);
}







void MenuWindow::SetAccount()
{
    if(dt->CurrentAccount() != nullptr){
        ui->label_2->setText(dt->CurrentAccount()->name);
        QPixmap pix(dt->CurrentAccount()->photo_adress);
        ui->label->setPixmap(pix.scaled(PhotoSize, Qt::KeepAspectRatioByExpanding));
    }
    if(dt->CurrentLD() != nullptr){
        ui->label_3->setText(dt->CurrentLD()->name);
    }
}


//void MenuWindow::SetDictionaries()
//{
//    if(carcass->CurLearnDir->Get().knownL != ""){
//        ObjSet_CurLearnDir(carcass->CurLearnDir->Get().knownL
//                           + "-" + carcass->CurLearnDir->Get().targL);
//        DctList_UpDate();
//        if(!carcass->CurLearnDir->dictionaries.isEmpty()) SetWords(carcass->CurLearnDir->dictionaries.at(0));
//    }
//    else{
//        ObjSet_CurLearnDir("");
//        DctList_Clear();
//    }
//}

//void MenuWindow::SetWords(const QString& dct_name)
//{

//}



////-------------> Ф-и фильтра событий
//void MenuWindow::InstallEventFilter()
//{
//    Obj_for_photo->installEventFilter(this);
//}
//void MenuWindow::ObjectsForEvetFilter()
//{
//    Obj_for_photo = ui->label;
//    InstallEventFilter();
//}
//bool MenuWindow::eventFilter(QObject * obj, QEvent * e)
//{
//    if(obj == Obj_for_photo){
//        switch (e->type()) {
//        case QEvent::MouseButtonPress:
//            if(((QMouseEvent*)e)->button() == Qt::MouseButton::LeftButton){
//                QString fileName = QFileDialog::getOpenFileName(this,
//                     tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));
//                if(!fileName.isEmpty()){
//                    carcass->CurAccount->Set_account_photo(fileName);
//                    SetAccountPhoto();
//                }
//                return true;
//            }
//        }
//    }
//    return false;
//}




void MenuWindow::AW_open_slot()
{
    emit AW_open_signal();
}
void MenuWindow::WWW_open_slot()
{
    if(dt->CurrentLD() == nullptr){
        emit WWW_open_signal();
    }
    else{
        qDebug() << "Создайте направление";
    }
}
void MenuWindow::LSW_open_slot()
{
    emit LSW_open_signal();
}

////****************************************************************************************************
////****************************************************************************************************
MenuWindow::~MenuWindow()
{
    delete ui;
}
//void MenuWindow::setLineColor( QColor c )
//{
//    lineColor = c;
//}

//QColor MenuWindow::getLineColor() const
//{
//    return lineColor;
//}

//void MenuWindow::paintEvent(QPaintEvent *p_ev)
//{
//    QPainter painter(this);
//    painter.setPen(QPen(getLineColor(), 1,Qt::SolidLine, Qt::RoundCap));
//    painter.drawLine(ui->scrollArea->geometry().x()-1, ui->scrollArea->geometry().y(), ui->scrollArea->geometry().x()-1, this->height());
//    painter.drawLine(ui->scrollArea->geometry().x()+ui->scrollArea->geometry().width()+3, ui->scrollArea->geometry().y(), ui->scrollArea->geometry().x()+ui->scrollArea->geometry().width()+3, this->height());
//    painter.drawLine(0, ui->scrollArea->geometry().y()-1, this->width(), ui->scrollArea->geometry().y()-1 );
//     //painter.drawLine(ui->scrollArea->geometry().x(), (c->geometry().y()+c->geometry().height()), ui->scrollArea->geometry().x()+ui->scrollArea->geometry().width(), (c->geometry().y()+c->geometry().height()));
//}

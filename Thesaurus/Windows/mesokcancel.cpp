#include "mesokcancel.h"
#include "ui_mesokcancel.h"

MesOKCancel::MesOKCancel(QString str) :
    ui(new Ui::MesOKCancel)
{
    ui->setupUi(this);
    ui->textEdit->setText(str);
    ui->textEdit->setFrameStyle(false);
    ui->pushButton->setText(tr("OK"));
    ui->pushButton_2->setText(tr("Cancel"));
    setModal(true);
}
void MesOKCancel::closeEvent(QCloseEvent* close_ev){

  emit close_me(this);
  close_ev->accept();
}
MesOKCancel::~MesOKCancel()
{
    delete ui;
}

void MesOKCancel::on_pushButton_clicked()
{
  emit MesOKCancelResult(true);
 close();
}

void MesOKCancel::on_pushButton_2_clicked()
{
  emit MesOKCancelResult(false);
  close();
}


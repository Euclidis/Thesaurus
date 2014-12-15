#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow() :
  ui(new Ui::LangSelectionWindow)
{
  ui->setupUi(this);
}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}

void LangSelectionWindow::on_label_3_clicked()
{
}









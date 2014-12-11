#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"


LangSelectionWindow::LangSelectionWindow(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::LangSelectionWindow)
{
  ui->setupUi(this);
}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}

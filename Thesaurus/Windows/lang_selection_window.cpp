#include "lang_selection_window.h"
#include "ui_lang_selection_window.h"

LangSelectionWindow::LangSelectionWindow(Carcass * _carcass) :
  ui(new Ui::LangSelectionWindow)
{
  ui->setupUi(this);
  carcass = _carcass;
}

LangSelectionWindow::~LangSelectionWindow()
{
  delete ui;
}

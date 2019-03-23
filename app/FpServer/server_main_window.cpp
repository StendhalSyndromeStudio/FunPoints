#include "server_main_window.h"
#include "ui_server_main_window.h"

ServerMainWindow::ServerMainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::ServerMainWindow)
{
  ui->setupUi(this);
}

ServerMainWindow::~ServerMainWindow()
{
  delete ui;
}

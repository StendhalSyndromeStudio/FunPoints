#ifndef SERVER_MAIN_WINDOW_H
#define SERVER_MAIN_WINDOW_H

#include <QMainWindow>
#include <impl/server/fp_server.h>

namespace Ui {
  class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
  Q_OBJECT
  Ui::ServerMainWindow *ui;
  FpServer    *serv;
public:
  explicit ServerMainWindow(QWidget *parent = nullptr);
  ~ServerMainWindow();

private:
};

#endif // SERVER_MAIN_WINDOW_H

#ifndef SERVER_MAIN_WINDOW_H
#define SERVER_MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
  class ServerMainWindow;
}

class ServerMainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit ServerMainWindow(QWidget *parent = nullptr);
  ~ServerMainWindow();

private:
  Ui::ServerMainWindow *ui;
};

#endif // SERVER_MAIN_WINDOW_H

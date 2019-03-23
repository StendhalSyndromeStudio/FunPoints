#include "server_main_window.h"
#include "ui_server_main_window.h"

ServerMainWindow::ServerMainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::ServerMainWindow)
  , serv ( new FpServer() )
{
  ui->setupUi(this);

  connect( serv,    &FpServer::connectedClient,
           [this](FpServerClient *client){
    ui->log->append( tr ( "Подключился клиент: %1:%2" )
                     .arg( client->tcpClient()->socket()->peerAddress().toString() )
                     .arg( client->tcpClient()->socket()->peerPort() ) );

    connect( client,    &FpServerClient::disconnected,
             [this, client](){
      ui->log->append( tr ( "Отключился клиент: %1:%2" )
                       .arg( client->tcpClient()->socket()->peerAddress().toString() )
                       .arg( client->tcpClient()->socket()->peerPort() ) );
    });
  });

  serv->server()->listen( QHostAddress::Any, 7777 );
  ui->log->append( tr ( "Сервер запущен"));
}

ServerMainWindow::~ServerMainWindow()
{
  delete ui;
}

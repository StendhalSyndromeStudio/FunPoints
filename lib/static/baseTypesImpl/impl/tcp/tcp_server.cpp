#include "tcp_server.h"

TcpServer::TcpServer(QObject *parent)
  : QTcpServer(parent)
{

}

TcpServer::~TcpServer()
{

}


void TcpServer::incomingConnection(qintptr handle)
{
  auto socket = new QTcpSocket();
  socket->setSocketDescriptor( handle );

  auto client = new TcpClient( socket );
  emit connectedClient( client );
}

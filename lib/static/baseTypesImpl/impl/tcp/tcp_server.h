#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QTcpServer>
#include "tcp_client.h"

class TcpServer
    : public QTcpServer
{
  Q_OBJECT
public:
  explicit TcpServer(QObject *parent = nullptr);
  ~TcpServer() override;

signals:
  void connectedClient(TcpClient *client);

  // QTcpServer interface
protected:
  void incomingConnection(qintptr handle) override;
};

#endif // TCP_SERVER_H

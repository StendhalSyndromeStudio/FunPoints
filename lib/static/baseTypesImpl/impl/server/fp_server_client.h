#ifndef FP_SERVER_CLIENT_H
#define FP_SERVER_CLIENT_H

#include <QObject>
#include "impl/tcp/tcp_client.h"

class FpServerClient
    : public QObject
{
  Q_OBJECT
  TcpClient *client;
public:
  explicit FpServerClient(TcpClient *client, QObject *parent = nullptr);
  ~FpServerClient() override;
public:
  TcpClient *tcpClient() const;

signals:
  void incommingCommand(const QByteArray &data);
};

#endif // FP_SERVER_CLIENT_H

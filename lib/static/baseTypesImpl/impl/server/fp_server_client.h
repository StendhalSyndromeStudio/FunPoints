#ifndef FP_SERVER_CLIENT_H
#define FP_SERVER_CLIENT_H

#include <QObject>
#include <IUser>
#include "impl/tcp/tcp_client.h"

class FpServerClient
    : public QObject
{
  Q_OBJECT
public:
  IUser     *_user;
  TcpClient *client;
public:
  explicit FpServerClient(TcpClient *client, QObject *parent = nullptr);
  ~FpServerClient() override;
public:
  IUser *user() const;
  TcpClient *tcpClient() const;

signals:
  void disconnected();
  void incommingCommand(const QByteArray &data);
};

#endif // FP_SERVER_CLIENT_H

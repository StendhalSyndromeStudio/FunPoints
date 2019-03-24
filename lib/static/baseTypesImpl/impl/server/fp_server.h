#ifndef FP_SERVER_H
#define FP_SERVER_H

#include <QMap>
#include <QObject>
#include <IUser>
#include "fp_server_client.h"
#include "impl/tcp/tcp_server.h"
#include "cmd/cmd_handler_provider.h"

class FpServer : public QObject
{
  Q_OBJECT
  TcpServer               *tcpserver;
  QList<FpServerClient*>  allClients;
  QMultiMap<QString, IServerCmdHandler*> handlers;
public:
  explicit FpServer(QObject *parent = nullptr);
  ~FpServer() override;

public:
  TcpServer *server() const;

signals:
  void connectedClient(FpServerClient *client);

private:
  void initilizeHandlers();

private slots:
  void saveDb();
  void loadDb();

private:
  IUser *getFreeUser() const;

private slots:
  void writeUpdates();
  void writeUpdates(FpServerClient *client);
  void writeUpdates(const QList<FpServerClient*> &clients);
  void writeClients(const QList<FpServerClient*> &clients);
  void writeEvents(const QList<FpServerClient*> &clients);
  void incommingConnection(TcpClient *client);

  void incommingMessage(const QByteArray &data);
  void incommingClientMessage(FpServerClient *client, const QByteArray &data);
};

#endif // FP_SERVER_H

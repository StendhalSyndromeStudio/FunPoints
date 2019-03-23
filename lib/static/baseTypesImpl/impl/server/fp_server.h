#ifndef FP_SERVER_H
#define FP_SERVER_H

#include <QMap>
#include <QObject>
#include "fp_server_client.h"
#include "impl/tcp/tcp_server.h"
#include "cmd/cmd_handler_provider.h"

class FpServer : public QObject
{
  Q_OBJECT
  TcpServer   *tcpserver;
  QMultiMap<QString, IServerCmdHandler*> handlers;
public:
  explicit FpServer(QObject *parent = nullptr);
  ~FpServer() override;

public:
  TcpServer *server() const;

signals:
  void connectedClient(FpServerClient *client);

public slots:

private:
  void initilizeHandlers();

private slots:
  void incommingConnection(TcpClient *client);

  void incommingMessage(const QByteArray &data);
  void incommingClientMessage(FpServerClient *client, const QByteArray &data);
  void recognitionClientCommand(FpServerClient *client, const QJsonDocument &doc);

};

#endif // FP_SERVER_H

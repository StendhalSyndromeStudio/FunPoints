#ifndef FP_CLIENT_H
#define FP_CLIENT_H

#include <QObject>
#include <IUser>
#include <IFpCore>
#include "impl/tcp/tcp_client.h"

class FpClient
    : public IBaseSignalObject
{
  Q_OBJECT
  IUser       *user;
  TcpClient   *client;
public:
  explicit FpClient(QObject *parent = nullptr);
  ~FpClient() override;

public:
  bool isConnected() const;

public slots:
  void initConnection();
  void closeConnection();

public:
  IUser *currentUser() const;

public slots:
  virtual QList<ILocalEvent*> getEvents(IFpCore::Filter *filter, int msec = 5000) const;

signals:
  void userChanged();
  void connected();
  void disconnected();
  void eventListChanged();

private slots:
  void connectedToHost();
  void disconnectedFromHost();
};

#endif // FP_CLIENT_H

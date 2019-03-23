#ifndef ISERVER_COMMAN_DHANDLER_H
#define ISERVER_COMMAN_DHANDLER_H

#include <QObject>

class FpServerClient;

class IServerCmdHandler
{
protected:
  IServerCmdHandler();
public:
  virtual ~IServerCmdHandler();

public:
  virtual QStringList cmdList() const = 0;

public slots:
  virtual bool handle(FpServerClient *client, const QString &cmd, const QJsonObject &obj) = 0;

};

#endif // ISERVER_COMMAN_DHANDLER_H

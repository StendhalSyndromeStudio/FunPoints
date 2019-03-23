#include "fp_client.h"

#include <QJsonDocument>
#include <QJsonObject>

FpClient::FpClient(QObject *parent)
  : IBaseSignalObject(parent)
  , client ( new TcpClient( this ) )
{
  connect( client,    &TcpClient::connected,
           this,      &FpClient::connectedToHost );
  connect( client,    &TcpClient::disconnected,
           this,      &FpClient::disconnectedFromHost );
}

FpClient::~FpClient()
{

}

bool FpClient::isConnected() const
{
  return client->isConnected();
}

void FpClient::initConnection()
{
  client->connectToHost( QHostAddress::LocalHost, 7777 );
}

void FpClient::closeConnection()
{
  client->close();
}

IUser *FpClient::currentUser() const
{
  return user;
}

QList<ILocalEvent *> FpClient::getEvents(IFpCore::Filter *, int ) const
{
  return QList<ILocalEvent *>();
}

void FpClient::connectedToHost()
{
  QJsonObject obj;
  obj[ "cmd" ] = "reg";
  client->write( QJsonDocument( obj ).toJson() );

  emit connected();
}

void FpClient::disconnectedFromHost()
{
  emit disconnected();
}

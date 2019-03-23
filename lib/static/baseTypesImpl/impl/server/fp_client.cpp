#include "fp_client.h"

#include <ClientStorage>
#include <IEventStorage>
#include <QJsonDocument>
#include <QJsonObject>

FpClient::FpClient(QObject *parent)
  : IBaseSignalObject(parent)
  , user ( ClientStorage::inst()->user( "" ) )
  , client ( new TcpClient( this ) )
{
  connect( client,    &TcpClient::connected,
           this,      &FpClient::connectedToHost );
  connect( client,    &TcpClient::disconnected,
           this,      &FpClient::disconnectedFromHost );
  connect( client,    &TcpClient::incommingMessage,
           this,      &FpClient::incommingMessage );

  auto cli = ClientStorage::inst();
  connect( cli,   &ClientStorage::addedEvent,
           this,  &FpClient::writeUpdates );
  connect( cli,   &ClientStorage::addedFeedback,
           this,  &FpClient::writeUpdates );
  connect( cli,   &ClientStorage::changedEvent,
           this,  &FpClient::writeUpdates );
  connect( cli,   &ClientStorage::changedFeedback,
           this,  &FpClient::writeUpdates );
}

FpClient::~FpClient()
{

}

void FpClient::writeUpdates()
{
  if ( client->isConnected() ) {
    auto data = user->toJson();
    data[ "created" ] = user->createdEvents()->toJson();

    QJsonObject doc;
    QJsonArray  array;
    array.push_back( data );
    doc[ "cmd" ] = "write";
    doc[ "data" ] = array;
    client->write( QJsonDocument ( doc ).toJson( ) );
  }
}

void FpClient::incommingMessage(const QByteArray &data)
{
  auto json = QJsonDocument::fromJson( data );
  auto cmd = json[ "cmd" ].toString();
  auto buf = json[ "data" ].toObject();

  if ( cmd == "write_user" ) {
    auto uid = buf[ "uid" ].toString();
    QJsonArray arr;
    arr.append( buf );
    ClientStorage::inst()->write( arr );
    user = ClientStorage::inst()->user( uid );
    emit userChanged();
  } else if ( cmd == "write" ) {
    auto array = json[ "data" ].toArray();
    ClientStorage::inst()->write( array );
    emit eventListChanged();
  }
}

bool FpClient::isConnected() const
{
  return client->isConnected();
}

void FpClient::initConnection()
{
  client->connectToHost( QHostAddress( "192.168.43.28" ), 7777 );
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

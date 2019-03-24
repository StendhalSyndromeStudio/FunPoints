#include "fp_server.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QCoreApplication>

#include <IEventStorage>
#include <ClientStorage>

#include "fp_server_client.h"

FpServer::FpServer(QObject *parent)
  : QObject(parent)
  , tcpserver ( new TcpServer( this ) )
{
  QFile f( "test.json" );
  if ( f.open( QIODevice::WriteOnly ) ) {
    f.write( "her" );
    f.close();
  }

  if ( f.open( QIODevice::ReadOnly ) ) {
    qDebug() << "setting file: " << f.readAll();
    f.close();
  }

  connect( tcpserver,   &TcpServer::connectedClient,
           this,        &FpServer::incommingConnection );

  initilizeHandlers();
  loadDb();
  saveDb();
}

FpServer::~FpServer()
{

}

TcpServer *FpServer::server() const
{
  return tcpserver;
}

void FpServer::initilizeHandlers()
{
  for ( auto h: CmdHandlerProvider::createHandlers() )
    for ( auto &cmd: h->cmdList() )
      handlers.insertMulti( cmd, h );
}

void FpServer::saveDb()
{
  QJsonArray array;
  for ( auto u: ClientStorage::inst()->allUserList() ) {
    auto d = u->toJson();
    d[ "created" ] = u->createdEvents()->toJson();
    array.push_back( d );
  }

  QFile f ( QDir::fromNativeSeparators(
              QCoreApplication::applicationDirPath() + "/db.json" ) );
  if ( f.open( QIODevice::WriteOnly ) ) {
    f.write( QJsonDocument( array ).toJson() );
    f.close();
  }
}

void FpServer::loadDb()
{
  QFile f ( QDir::fromNativeSeparators(
              QCoreApplication::applicationDirPath() + "/db.json" ) );
  if ( f.open( QIODevice::ReadOnly ) ) {
    auto array = QJsonDocument::fromJson( f.readAll() ).array();
    ClientStorage::inst()->write( array );
    f.close();
  }
}

IUser *FpServer::getFreeUser() const
{
  for ( auto u: ClientStorage::inst()->allUserList() ) {
    bool finded = false;
    for ( auto c: allClients ) {
      if ( c->user() == u && c->client->isConnected() && u ) {
        finded = true;
        break;
      }
    }

    if ( !finded )
      return u;
  }

  return ClientStorage::inst()->user( QUuid() );
}

void FpServer::writeUpdates()
{
  writeUpdates( allClients );
}

void FpServer::writeUpdates(FpServerClient *client)
{
  writeUpdates( QList<FpServerClient*> { client } );
}

void FpServer::writeUpdates(const QList<FpServerClient *> &clients)
{
  writeClients( clients );
  writeEvents( clients );


  QJsonObject data;
  QJsonArray array;
  int i = 0;
  for ( auto u: ClientStorage::inst()->allUserList() ) {
    auto d = u->toJson();
    d[ "created" ] = u->createdEvents()->toJson();
    array.push_back( d );
    ++i;
  }

  data[ "cmd" ] = "write";
  data[ "data" ] = array;

  auto out = QJsonDocument ( data ).toJson();
  for ( auto &c: clients )
    c->client->write( out );

  qDebug() << "Write to clients";
}

void FpServer::writeClients(const QList<FpServerClient *> &)
{

}

void FpServer::writeEvents(const QList<FpServerClient *> &)
{

}

void FpServer::incommingConnection(TcpClient *client)
{
  auto sclient = new FpServerClient( client );
  connect( sclient,   &FpServerClient::incommingCommand,
           this,      &FpServer::incommingMessage );

  connect( sclient,   &FpServerClient::disconnected,
           [this, sclient]() {
    allClients.removeOne( sclient );
  });
  sclient->_user = getFreeUser();
  allClients << sclient;
  writeUpdates( sclient );

  emit connectedClient( sclient );
}

void FpServer::incommingMessage(const QByteArray &data)
{
  auto cli = dynamic_cast<FpServerClient*>( sender() );
  if ( cli )
    incommingClientMessage( cli, data );
}

void FpServer::incommingClientMessage(FpServerClient *client, const QByteArray &data)
{
  auto doc  = QJsonDocument::fromJson( data );
  if ( !doc.isNull() ) {
    auto cmd  = doc[ "cmd" ].toString();
    auto buf  = doc[ "data" ].toObject();

    if ( cmd == "reg" ) {
      QJsonObject out;
      out[ "cmd" ]  = "write_user";
      out[ "data" ] = client->user()->toJson();

      client->client->write( QJsonDocument ( out ).toJson() );
      writeUpdates( client );
    } else if ( cmd == "write" ) {
      auto array = doc[ "data" ].toArray();
      ClientStorage::inst()->write( array );
      writeUpdates();
      saveDb();
    }

    for ( auto *h: handlers.values( data))
      h->handle( client, cmd, buf );
  }
}

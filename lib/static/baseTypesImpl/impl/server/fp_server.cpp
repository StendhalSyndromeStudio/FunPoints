#include "fp_server.h"

#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

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

void FpServer::incommingConnection(TcpClient *client)
{
  auto sclient = new FpServerClient( client );
  connect( sclient,   &FpServerClient::incommingCommand,
           this,      &FpServer::incommingMessage );

  connect( sclient,   &FpServerClient::destroyed,
           sclient,   &FpServerClient::deleteLater );

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

    qDebug() << cmd;

    for ( auto *h: handlers.values( data))
      h->handle( client, cmd, buf );
  }
}

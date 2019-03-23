#include "fp_server.h"

#include <QFile>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

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
    recognitionClientCommand( client, doc );
  }
}

void FpServer::recognitionClientCommand(FpServerClient *client, const QJsonDocument &doc)
{
  auto cmd  = doc[ "cmd" ].toString();
  auto data = doc[ "data" ].toObject();

  qDebug() << cmd << data;

  if ( cmd == "reg" ) {

  }
}

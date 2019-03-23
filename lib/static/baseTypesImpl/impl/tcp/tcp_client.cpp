#include "tcp_client.h"
#include <QDataStream>


TcpClient::TcpClient(QObject *parent)
  : QObject ( parent )
  , _socket ( new QTcpSocket() )
  , address ( QHostAddress::LocalHost )
  , port ( 80 )
  , reconnect ( false )
{
  startTimer( 2000 );
  connectSocket();
}

TcpClient::TcpClient(QTcpSocket *socket, QObject *parent)
  : QObject(parent)
  , _socket ( socket )
  , address ( QHostAddress::LocalHost )
  , port ( 80 )
  , reconnect ( false )
{
  connectSocket();
}

TcpClient::~TcpClient()
{
  delete _socket;
}

void TcpClient::timerEvent(QTimerEvent *)
{
  if ( _socket ? _socket->state() != QAbstractSocket::ConnectedState && reconnect : false ) {
    if ( _socket->state() != QAbstractSocket::UnconnectedState ) {
      if ( lastTryConnect.msecsTo( QDateTime::currentDateTime() ) > 3500 ) {
        _socket->close();
      }
    } else {
      if ( lastTryConnect.msecsTo( QDateTime::currentDateTime() ) > 5500 ) {
        connectToHost( address, port );
      }
    }
  }
}

QTcpSocket *TcpClient::socket() const
{
  return _socket;
}

bool TcpClient::isConnected() const
{
  return _socket->state() == QAbstractSocket::ConnectedState;
}

void TcpClient::connectToHost(const QHostAddress &address, quint16 port)
{
  if ( _socket ) {
    if ( _socket->state() != QAbstractSocket::UnconnectedState ) {
      close();
    }

    reconnect = true;
    this->address   = address;
    this->port      = port;
    lastTryConnect  = QDateTime::currentDateTime();
    _socket->connectToHost( address, port );
  }
}

void TcpClient::close()
{
  if ( _socket ) {
    reconnect = false;
    _socket->close();
  }
}

int TcpClient::write(const QByteArray &data)
{
  if ( _socket ? _socket->state() == QAbstractSocket::ConnectedState: false ) {
    QByteArray buffer;
    QDataStream out ( &buffer, QIODevice::WriteOnly );
    out << static_cast<qint64>( data.size() );
    buffer.append( data );
    _socket->write( buffer );
    return buffer.size();
  }

  return 0;
}

void TcpClient::connectSocket()
{
  connect( _socket,   &QTcpSocket::connected,
           this,      &TcpClient::connected );
  connect( _socket,   &QTcpSocket::disconnected,
           this,      &TcpClient::disconnected );
  connect( _socket,   &QTcpSocket::readyRead,
           this,      &TcpClient::readyReadPrivate );
}

void TcpClient::readyReadPrivate()
{
  static qint64 headSize = static_cast<qint64>( sizeof ( qint64 ) );
  while ( _socket ? _socket->bytesAvailable() >= headSize: false ) {
    buffer.append( _socket->read( _socket->bytesAvailable() ) );

    while ( buffer.size() > headSize ) {
      qint64 head = 0;
      QDataStream in ( &buffer, QIODevice::ReadOnly );
      in >> head;
      if ( head <= 0 ) {
        buffer = buffer.mid( static_cast<int>( headSize ) );
        continue;
      } else if ( buffer.size() >= head + headSize ){
        auto data = buffer.mid( static_cast<int>( headSize ), static_cast<int>( head ) );
        buffer = buffer.mid( static_cast<int>( headSize + head ) );
        emit incommingMessage( data );
      } else {
        break;
      }
    }
  }
}

void TcpClient::connectedToServer()
{
  emit connected();
}

void TcpClient::disconnectedFromServer()
{
  emit disconnected();
}

#include "fp_server_client.h"

FpServerClient::FpServerClient(TcpClient *client, QObject *parent)
  : QObject(parent)
  , _user ( nullptr )
  , client ( client )
{
  connect( client,    &TcpClient::disconnected,
           this,      &FpServerClient::disconnected );

  connect( client,    &TcpClient::incommingMessage,
           this,      &FpServerClient::incommingCommand );
}

FpServerClient::~FpServerClient()
{

}

IUser *FpServerClient::user() const
{
  return _user;
}

TcpClient *FpServerClient::tcpClient() const
{
  return client;
}

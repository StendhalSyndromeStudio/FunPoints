#include "fp_server_client.h"

FpServerClient::FpServerClient(TcpClient *client, QObject *parent)
  : QObject(parent)
  , client ( client )
{
  connect( client,    &TcpClient::incommingMessage,
           this,      &FpServerClient::incommingCommand );
}

FpServerClient::~FpServerClient()
{

}

TcpClient *FpServerClient::tcpClient() const
{
  return client;
}

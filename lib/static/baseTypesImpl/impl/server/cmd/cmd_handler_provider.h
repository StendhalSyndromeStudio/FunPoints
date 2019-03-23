#ifndef SERVER_CH_PROVIDER_H
#define SERVER_CH_PROVIDER_H

#include "iserver_cmd_handler.h"
#include "iclient_cmd_handler.h"

class CmdHandlerProvider
{
    CmdHandlerProvider() = delete;
    CmdHandlerProvider(const CmdHandlerProvider &) = delete;
public:
    static QList<IServerCmdHandler*> createHandlers();
};

#endif // SERVER_CH_PROVIDER_H

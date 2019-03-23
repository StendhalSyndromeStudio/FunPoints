#include "ifp_core.h"

#include <ClientStorage>

IFpCore::IFpCore(QObject *parent)
  : IBaseSignalObject(parent)
{

}

IFpCore::~IFpCore()
{

}

IUser *IFpCore::remoteUser(int index)
{
  return ClientStorage::inst()->allUserList().at( index );
}

int IFpCore::remoteUserCount()
{
  return ClientStorage::inst()->allUserList().count();
}

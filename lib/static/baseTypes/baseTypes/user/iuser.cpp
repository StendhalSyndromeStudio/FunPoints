#include "iuser.h"

#include <IEventStorage>

IUser::IUser(QObject *parent)
  : IPerson(parent)
  , created ( new IEventStorage() )
  , visited ( new IEventStorage() )
{

}

IUser::~IUser()
{

}

bool IUser::canCreateEvent() const
{
  return true;
}

IEventStorage *IUser::createdEvents() const
{
  return created;
}

IEventStorage *IUser::visitedEvents() const
{
  return visited;
}

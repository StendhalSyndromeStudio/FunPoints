#include "iuser.h"

IUser::IUser(QObject *parent)
  : IPerson(parent)
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

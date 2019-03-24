#include "iuser.h"

#include <QDebug>
#include <IEventStorage>

IUser::IUser(QObject *parent)
  : IPerson(parent)
  , created ( new IEventStorage( this ) )
  , visited ( new IEventStorage( this ) )
{

}

IUser::~IUser()
{
  qDebug() << "removed user" << _uid;
}

QJsonObject IUser::toJson() const
{
  return  IPerson::toJson();
}

void IUser::fromJson(const QJsonObject &obj)
{
  IPerson::fromJson( obj );
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

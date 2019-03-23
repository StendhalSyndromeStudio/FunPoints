#include "ievent_storage.h"

IEventStorage::IEventStorage(QObject *parent)
  : IBaseSignalObject(parent)
{

}

IEventStorage::~IEventStorage()
{

}

int IEventStorage::eventCount() const
{
  return 0;
}

ILocalEvent *IEventStorage::eventAt(int)
{
  return nullptr;
}

ILocalEvent *IEventStorage::create(const QString &, const QString &, const QDateTime &, const QDateTime &, const QPointF &)
{
  return nullptr;
}

bool IEventStorage::addEvent(ILocalEvent *)
{
  return false;
}

bool IEventStorage::removeEvent(ILocalEvent *)
{
  return false;
}

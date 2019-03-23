#include "ievent_storage.h"

IEventStorage::IEventStorage(QObject *parent)
  : IBaseSignalObject(parent)
{

}

IEventStorage::~IEventStorage()
{

}

QJsonObject IEventStorage::toJson() const
{
  QJsonObject obj;
  QJsonArray array;

  for ( int i = 0; i < allEvents.count(); ++i ) {
    array.push_back( allEvents[ i ]->toJson() );
  }

  obj[ "childs" ] = array;
  return obj;
}

void IEventStorage::fromJson(const QJsonObject &obj)
{
  auto array = obj[ "childs" ].toArray();

  for ( int i = 0; i < array.count(); ++i ) {
    auto data = array[ i ].toObject();
    auto uid = QUuid ( data[ "uid" ].toString() );
    bool finded = false;
    for ( auto &e: allEvents ) {
      if ( e->uid() == uid ) {
        e->fromJson( data );
        finded = true;
        break;
      }
    }

    if ( !finded ) {
      auto e = new ILocalEvent( this );
      e->fromJson( data );
      addEvent( e );
    }
  }
}

int IEventStorage::eventCount() const
{
  return allEvents.count();
}

ILocalEvent *IEventStorage::eventAt(int index)
{
  return allEvents[ index ];
}

ILocalEvent *IEventStorage::create(const QString &name, const QString &desc, const QDateTime &start, const QDateTime &end, const QGeoCoordinate &pos, IUser *parent)
{
  auto event = new ILocalEvent( name, desc, start, end, pos, parent, this );
  addEvent( event );

  return event;
}

bool IEventStorage::addEvent(ILocalEvent *event)
{
  allEvents << event;
  emit addedEvent( event );

  return true;
}

bool IEventStorage::removeEvent(ILocalEvent *event)
{
  allEvents.removeOne( event );
  emit removedEvent( event );

  return true;
}

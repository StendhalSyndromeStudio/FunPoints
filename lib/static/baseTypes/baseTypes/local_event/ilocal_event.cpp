#include "ilocal_event.h"

#include <IUser>
#include <QVariant>
#include <ClientStorage>

ILocalEvent::ILocalEvent(QObject *parent)
  : QObject(parent)
  , _user ( nullptr )
  , _rate ( new IRateObject() )
{

}

ILocalEvent::ILocalEvent(const QString &name, const QString &desc, const QDateTime &start, const QDateTime &end, const QGeoCoordinate &pos, IUser *user, QObject *parent)
  : QObject ( parent )
  , _name ( name )
  , _desc ( desc )
  , _pos ( pos )
  , _user ( user )
  , _rate ( new IRateObject() )
{
  _time.span.start  = start;
  _time.span.end    = end;
}

ILocalEvent::~ILocalEvent()
{

}

IRateObject *ILocalEvent::rate() const
{
  return _rate;
}

QJsonObject ILocalEvent::toJson() const
{
  QJsonObject obj;
  obj[ "uid" ]    = _uid.toString();
  obj[ "name" ]   = _name;
  obj[ "desc" ]   = _desc;
  obj[ "tags" ]   = _tags.join( "#" );
  obj[ "start" ]  = QString::number( _time.span.start.toMSecsSinceEpoch() );
  obj[ "end" ]    = QString::number( _time.span.end.toMSecsSinceEpoch() );
  obj[ "lt" ]     = QString::number( _pos.latitude(), 'g', 10 );
  obj[ "lg" ]     = QString::number( _pos.longitude(), 'g', 10 );
  obj[ "user" ]   = organizer()->uid().toString();
  obj[ "rate" ]   = _rate->toJson();

  return obj;
}

void ILocalEvent::fromJson(const QJsonObject &obj)
{
  _uid  = obj[ "uid" ].toString();
  _name = obj[ "name" ].toString();
  _desc = obj[ "desc" ].toString();
  _tags = obj[ "tags" ].toString().split( "#" );

  _time.span.start  = QDateTime::fromMSecsSinceEpoch( QVariant ( obj[ "start" ].toString() ).toInt() );
  _time.span.end    = QDateTime::fromMSecsSinceEpoch( QVariant ( obj[ "end" ].toString() ).toInt() );

  _pos  = QGeoCoordinate (
        QVariant ( obj[ "lt" ].toString() ).toDouble()
      , QVariant ( obj[ "lg" ].toString() ).toDouble() );

  auto userUid = obj[ "user" ].toString();
  _user = ClientStorage::inst()->user( userUid );
  _rate->fromJson( obj[ "rate" ].toObject() );
}

QUuid ILocalEvent::uid() const
{
  return _uid;
}

QString ILocalEvent::name() const
{
  return _name;
}

QStringList ILocalEvent::tags() const
{
  return _tags;
}

QString ILocalEvent::description() const
{
  return _desc;
}

IUser *ILocalEvent::organizer() const
{
  if ( !_user ) {
    _user = ClientStorage::inst()->user( "" );
  }

  return _user;
}

ILocalEvent::Status ILocalEvent::status() const
{
  return Status::Published;
}

QDateTime ILocalEvent::start() const
{
  return timeSpending().span.start;
}

QDateTime ILocalEvent::end() const
{
  return timeSpending().span.end;
}

QGeoCoordinate ILocalEvent::location() const
{
  return _pos;
}

ILocalEvent::TimeSpending ILocalEvent::timeSpending() const
{
  return _time;
}

QList<IExternalResource *> ILocalEvent::resources() const
{
  return QList<IExternalResource *>();
}

bool ILocalEvent::writeInfo(const QString &name, const QString &desc)
{
  _name = name;
  _desc = desc;

  emit changed();
  return true;
}

bool ILocalEvent::writeLocation(const QGeoCoordinate &location)
{
  _pos = location;
  emit changed();
  return true;
}

bool ILocalEvent::writeTime(const QDateTime &start, const QDateTime &end)
{
  _time.span.start  = start;
  _time.span.end    = end;
  emit changed();
  return true;
}

bool ILocalEvent::writeTimeSpanding(const ILocalEvent::TimeSpending &)
{
  return false;
}

bool ILocalEvent::addResource(IExternalResource *)
{
  return false;
}

bool ILocalEvent::removeResource(IExternalResource *)
{
  return false;
}

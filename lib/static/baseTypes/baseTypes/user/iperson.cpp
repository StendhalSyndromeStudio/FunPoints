#include "iperson.h"

IPerson::IPerson(QObject *parent)
  : QObject ( parent)
  , _rate ( new IRateObject ( this ) )
{

}

IPerson::IPerson(const QUuid &uid, const QString &f, const QString &l, const QString &m, QObject *parent)
  : QObject ( parent )
  , _uid ( uid )
  , _fname ( f )
  , _lname ( l )
  , _mname ( m )
  , _rate ( new IRateObject ( this ) )
{

}

IPerson::~IPerson()
{

}

QJsonObject IPerson::toJson() const
{
  QJsonObject obj;
  obj[ "uid" ]  = _uid.toString();
  obj[ "fname" ] = _fname;
  obj[ "lname" ] = _lname;
  obj[ "mname" ] = _mname;

  return obj;
}

void IPerson::fromJson(const QJsonObject &obj)
{
  _uid    = obj[ "uid" ].toString();
  _fname  = obj[ "fname" ].toString();
  _lname  = obj[ "lname" ].toString();
  _mname  = obj[ "mname" ].toString();
}

IRateObject *IPerson::rate() const
{
  return _rate;
}

QUuid IPerson::uid() const
{
  return _uid;
}

QString IPerson::firstName() const
{
  return _fname;
}

QString IPerson::lastName() const
{
  return _lname;
}

QString IPerson::patronimic() const
{
  return  _mname;
}

QString IPerson::shortName() const
{
  return _lname;
}

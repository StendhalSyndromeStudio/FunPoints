#include "ifeedback.h"

#include <QVariant>

IFeedback::IFeedback(QObject *parent)
  : IBaseSignalObject(parent)
{

}

IFeedback::IFeedback(const QString &title, const QString &text, int rate, IPerson *person, QObject *parent)
  : IBaseSignalObject ( parent )
  , _title ( title )
  , _description ( text )
  , _rate ( rate )
  , _person ( person )
{

}

IFeedback::~IFeedback()
{

}

QJsonObject IFeedback::toJson() const
{
  QJsonObject obj;
  obj[ "type" ]   = "feedback";
  obj[ "title" ]  = _title;
  obj[ "desc" ]   = _description;
  obj[ "publ" ]   = QString::number( _publicshed.toMSecsSinceEpoch() );
  obj[ "rate" ]   = QString::number( _rate );

  QJsonArray array;
  for ( int i = 0; i < _pastList.count(); ++i ) {
    array[ i ] = _pastList[ i ]->toJson();
  }

  obj[ "childs" ] = array;

  return obj;
}

void IFeedback::fromJson(const QJsonObject &obj)
{
  _title        = obj[ "title" ].toString();
  _description  = obj[ "desc" ].toString();
  _publicshed   = QDateTime::fromMSecsSinceEpoch( QVariant ( obj[ "title" ].toString() ).toInt() );
  _rate         = QVariant ( obj[ "title" ].toString() ).toInt();
//  _person       = parent;

  auto array    = obj[ "childs" ].toArray();
  for ( int i = 0; i < array.count(); ++i ) {
    auto child = new IFeedback();
    child->fromJson( array[ i ].toObject() );
    _pastList << child;
  }
}

QUuid IFeedback::uid() const
{
  return  _uid;
}

QString IFeedback::title() const
{
  return _title;
}

QString IFeedback::description() const
{
  return _description;
}

QDateTime IFeedback::published() const
{
  return _publicshed;
}

int IFeedback::rate() const
{
  return _rate;
}

IPerson *IFeedback::user() const
{
  return _person;
}

QList<IFeedback *> IFeedback::pastList() const
{
  return _pastList;
}

bool IFeedback::edit(const QString &title, const QString &desc, int rate)
{
  _title        = title;
  _description  = desc;
  _rate         = rate;

  emit changed();
  return true;
}

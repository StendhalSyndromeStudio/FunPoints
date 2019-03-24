#include "irate_object.h"
#include <ClientStorage>

IRateObject::IRateObject(QObject *parrent)
  : IBaseSignalObject(parrent)
{

}

IRateObject::~IRateObject()
{

}

QJsonObject IRateObject::toJson() const
{
  QJsonArray data;

  for ( int i = 0; i < _feedback.count(); ++i ) {
      data.push_back( _feedback[ i ]->toJson() );
  }

  QJsonObject out;
  out[ "feedback" ] = data;
  return out;
}

void IRateObject::fromJson(const QJsonObject &obj)
{
  auto array = obj[ "feedback" ].toArray();

  for ( int i = 0; i < array.count(); ++i ) {
    auto child = array[ i ].toObject();
    auto uid = QUuid ( child[ "uid" ].toString() );
    bool finded = false;
    for ( auto *f: _feedback ) {
      if ( uid == f->uid() ) {
        f->fromJson( child );
        finded = true;
      }
    }

    if ( !finded ) {
      auto feed = new IFeedback(this);
      feed->fromJson( child );
      addFeedback( feed );
    }
  }
}

double IRateObject::rate() const
{
  if ( feedback().isEmpty() ) {
    return 5.0;
  }

  double result = 0.0;
  for ( auto *obj: feedback() ) {
    result += obj->rate();
  }

  return result / feedback().count();
}

QList<IFeedback *> IRateObject::feedback() const
{
  return QList<IFeedback*>();
}

IFeedback *IRateObject::create(const QString &title, const QString &text, int rate, IPerson *user)
{
  auto feedBack = new IFeedback( title, text, rate, user, this );
  addFeedback( feedBack );
  ClientStorage::inst()->addedFeedback( feedBack );
  return  feedBack;
}

bool IRateObject::addFeedback(IFeedback *feedback)
{
  _feedback.append( feedback );
  emit addedFeedback( feedback );
  return true;
}

bool IRateObject::removeFeedback(IFeedback *feedback)
{
  _feedback.removeOne( feedback );
  emit removedFeedback( feedback );
  return true;
}

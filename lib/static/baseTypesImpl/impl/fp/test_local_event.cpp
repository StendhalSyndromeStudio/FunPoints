#include "test_local_event.h"

#include <cmath>

struct EventInfoPrivate {
  QString         name, desc;
  QStringList     tags;
  QGeoCoordinate  pos;
  double          rate = ( rand() % 5000 ) / 1000.0;
  QDateTime       start;
};

namespace  {
  static ILocalEvent::TimeSpending createSpending(const QDateTime &start)
  {
    ILocalEvent::TimeSpending res;
    res.span.start = start;
    res.span.end   = start.addSecs( 3600 * 2 );
    return res;
  }

  static QDateTime createStart() {
    auto start  = QDateTime::currentDateTime();
    if ( std::rand() % 2 == 0 )
      start = start.addSecs( 60 * std::rand() % 2000 + 3600 );
    else
      start = start.addSecs( -( 60 * std::rand() % 2000 + 3600 ) );

    return start;
  };

  static EventInfoPrivate create(const QString &name, const QString &desc, const QStringList &tags, const QGeoCoordinate &pos )
  {
    EventInfoPrivate e;
    e.name = name;
    e.desc = desc;
    e.tags = tags;
    e.pos = pos;
    e.start = createStart();

    return e;
  }
}

static QList<EventInfoPrivate> testList = {
  create( "Квартирник у Андрюхи", "...", { "концерт", "частная" }, QGeoCoordinate( 59.998675, 30.293503 ) )
  , create( "Концерт Кипелова", "...", { "концерт", "юридическая" }, QGeoCoordinate( 59.995896, 30.295277 ) )
  , create( "Поэтический вечер с Пушкиным", "...", { "поэтический вечер", "стихи" }, QGeoCoordinate( 59.996700, 30.304051 ) )
};

TestLocalEvent::TestLocalEvent(QObject *parent)
  : ILocalEvent (parent)
{
  static int index = 0;
  if ( index > testList.count() )
    index = 0;

  auto info = testList[ index++ ];
  _name = info.name;
  _desk = info.desc;
  _tags = info.tags;
  _pos  = info.pos;
  _rate = info.rate;
  _time = createSpending( info.start );

}

TestLocalEvent::~TestLocalEvent()
{

}


double TestLocalEvent::rate() const
{
  return _rate;
}

QList<IFeedback *> TestLocalEvent::feedback() const
{
  return QList<IFeedback *>();
}

bool TestLocalEvent::addFeedback(IFeedback *)
{
  return false;
}
QString TestLocalEvent::name() const
{
  return _name;
}

QStringList TestLocalEvent::tags() const
{
  return _tags;
}

QString TestLocalEvent::description() const
{
  return _desk;
}

IUser *TestLocalEvent::organizer() const
{
  return nullptr;
}

ILocalEvent::Status TestLocalEvent::status() const
{
  return Status::Published;
}

QGeoCoordinate TestLocalEvent::location() const
{
  return _pos;
}

ILocalEvent::TimeSpending TestLocalEvent::timeSpending() const
{
  return _time;
}

QList<IExternalResource *> TestLocalEvent::resources() const
{
  return QList<IExternalResource *>();
}

bool TestLocalEvent::writeInfo(const QString &name, const QString &desc)
{
  _name = name;
  _desk = desc;

  emit changed();
  return true;
}

bool TestLocalEvent::writeLocation(const QGeoCoordinate &location)
{
  _pos = location;

  emit changed();
  return true;
}

bool TestLocalEvent::writeTimeSpanding(const ILocalEvent::TimeSpending &dt)
{
  _time = dt;

  emit changed();
  return true;
}

bool TestLocalEvent::addResource(IExternalResource *)
{
  return false;
}

bool TestLocalEvent::removeResource(IExternalResource *)
{
  return false;
}

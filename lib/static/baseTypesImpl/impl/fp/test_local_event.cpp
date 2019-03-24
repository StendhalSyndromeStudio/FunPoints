#include "test_local_event.h"

#include <cmath>
#include <IEventStorage>
#include <ClientStorage>

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

  static ILocalEvent::TimeSpending createSpending(const QDateTime &start, const QDateTime &end)
  {
    ILocalEvent::TimeSpending res;
    res.span.start = start;
    res.span.end   = end;
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
  : ILocalEvent ( parent)
{
  static int index = 0;
  if ( index > testList.count() )
    index = 0;

  auto info = testList[ index++ ];
  _name = info.name;
  _desc = info.desc;
  _tags = info.tags;
  _pos  = info.pos;
  _time = createSpending( info.start );

  for ( auto u: ClientStorage::inst()->allUserList() ) {
    if ( !u->firstName().isEmpty() ) {
      _user = u;
      _user->createdEvents()->addEvent( this );
      break;
    }
  }
}

TestLocalEvent::TestLocalEvent(const QString &name, const QString &desc, const QDateTime &start, const QDateTime &end, const QGeoCoordinate &location, QObject *parent)
  : ILocalEvent ( name, desc, start, end, location, nullptr, parent )
{

}

TestLocalEvent::~TestLocalEvent()
{

}

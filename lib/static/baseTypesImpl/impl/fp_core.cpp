#include "fp_core.h"

#include <QGeoCoordinate>
#include <QGeoPositionInfo>
#include <QGeoPositionInfoSource>

#include <QJsonDocument>
#include <QJsonObject>
#include <IEventStorage>
#include <ClientStorage>
#include "fp/test_local_event.h"

FpCore::FpCore(QObject *parent)
  : IFpCore(parent)
  , client ( new FpClient(this) )
  , geoSource ( QGeoPositionInfoSource::createDefaultSource(this) )
{
  rebuildEventsList();

  if ( geoSource ) {
    connect( geoSource,     &QGeoPositionInfoSource::positionUpdated,
             this,          &FpCore::updateLocation );
    geoSource->startUpdates();
  }

  connect( client,  &FpClient::connected,
           this,    &FpCore::connected );

  connect( client,  &FpClient::disconnected,
           this,    &FpCore::disconnected );

  connect( client,  &FpClient::userChanged,
           this,    &FpCore::userChanged );

  connect( client,  &FpClient::eventListChanged,
           [this]() {
    this->rebuildEventsList();
  });


  client->initConnection();
}

FpCore::~FpCore()
{

}

QList<ILocalEvent *> FpCore::createTestEventList()
{
  QList<ILocalEvent *> result;

  for ( int i = 0; i < 0; ++i )
   result << new TestLocalEvent();

  return result;
}

void FpCore::rebuildEventsList()
{
  allEvents = createTestEventList();

  for ( auto c: ClientStorage::inst()->allUserList() ) {
    for ( auto e: c->createdEvents()->allEvents )
      allEvents << e;
  }

  emit eventListChanged();
  emit objectListChanged();
}

bool FpCore::isConnected() const
{
  return false;
}

QGeoCoordinate FpCore::location() const
{
  return geoSource
      ? geoSource->lastKnownPosition().coordinate()
      : QGeoCoordinate ( 0.0, 0.0 );
}

IUser *FpCore::user() const
{
  return client->currentUser();
}

int FpCore::eventCount() const
{
  return allEvents.count();
}

ILocalEvent *FpCore::eventAt(int index) const
{
  return allEvents.at( index );
}

IFpCore::Filter *FpCore::filter() const
{
  return nullptr;
}

void FpCore::setFilter(IFpCore::Filter *)
{
}

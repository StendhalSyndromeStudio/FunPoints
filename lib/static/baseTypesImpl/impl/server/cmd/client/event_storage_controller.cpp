#include "event_storage_controller.h"
#include "impl/fp/test_local_event.h"

EventStorageController::EventStorageController(FpClient *client, QObject *parent) : QObject(parent)
{

}

ILocalEvent *EventStorageController::create(const QString &name, const QString &desc, const QDateTime &start, const QDateTime &end, const QGeoCoordinate &location)
{
  auto event = new TestLocalEvent( name, desc, start, end, location );
  return event;
}

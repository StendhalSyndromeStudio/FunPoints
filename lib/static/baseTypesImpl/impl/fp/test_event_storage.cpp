#include "test_event_storage.h"
#include "impl/server/cmd/client/event_storage_controller.h"

TestEventStorage::TestEventStorage(EventStorageController *controller, QObject *parent)
  : IEventStorage(parent)
  , controller ( controller )
{

}

TestEventStorage::~TestEventStorage()
{

}

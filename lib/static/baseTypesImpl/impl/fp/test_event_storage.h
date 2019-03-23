#ifndef TEST_EVENT_STORAGE_H
#define TEST_EVENT_STORAGE_H

#include <IEventStorage>

class EventStorageController;

class TestEventStorage
    : public IEventStorage
{
  Q_OBJECT
  EventStorageController  *controller;
  QList<ILocalEvent*>     allEvents;
public:
  explicit TestEventStorage(EventStorageController *controller = nullptr, QObject *parent = nullptr);
  ~TestEventStorage() override;
};

#endif // TEST_EVENT_STORAGE_H

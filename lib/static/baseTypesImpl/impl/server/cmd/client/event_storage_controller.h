#ifndef EVENT_STORAGE_CONTROLLER_H
#define EVENT_STORAGE_CONTROLLER_H

#include <QObject>
#include <IEventStorage>
#include "impl/server/fp_client.h"

class EventStorageController
    : public QObject
{
  Q_OBJECT
  FpClient    client;
public:
  explicit EventStorageController(FpClient *client, QObject *parent = nullptr);

public:
  ILocalEvent *create(const QString &name
                      , const QString &desc
                      , const QDateTime &start
                      , const QDateTime &end
                      , const QGeoCoordinate &location);
  bool addEvent(ILocalEvent *event);
  bool removeEvent(ILocalEvent *event);
};

#endif // EVENT_STORAGE_CONTROLLER_H

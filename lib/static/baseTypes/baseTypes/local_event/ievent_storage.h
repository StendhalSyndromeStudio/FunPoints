#ifndef EVENT_STORAGE_H
#define EVENT_STORAGE_H

#include "ilocal_event.h"
#include "baseTypes/ibase_signal_object.h"

class ILocalEvent;

class IEventStorage
    : public IBaseSignalObject
{
  Q_OBJECT
  QList<ILocalEvent*> allEvents;
public:
  explicit IEventStorage(QObject *parent = nullptr);
  virtual ~IEventStorage() override;

public slots:
  virtual QJsonObject toJson() const;
  virtual void fromJson(const QJsonObject &obj);

public slots:
  virtual int eventCount() const;
  virtual ILocalEvent *eventAt(int index);
  virtual ILocalEvent *create(const QString &name
                              , const QString &desc
                              , const QDateTime &start
                              , const QDateTime &end
                              , const QGeoCoordinate &location
                              , IUser *parent );

  virtual bool addEvent(ILocalEvent *event);
  virtual bool removeEvent(ILocalEvent *event);

signals:
  void addedEvent(ILocalEvent *event);
  void removedEvent(ILocalEvent *event);
};

#endif // EVENT_STORAGE_H

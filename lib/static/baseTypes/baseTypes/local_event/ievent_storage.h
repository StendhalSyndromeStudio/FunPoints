#ifndef EVENT_STORAGE_H
#define EVENT_STORAGE_H

#include "ilocal_event.h"
#include "baseTypes/ibase_signal_object.h"

class ILocalEvent;

class IEventStorage
    : public IBaseSignalObject
{
  Q_OBJECT
protected:
  explicit IEventStorage(QObject *parent = nullptr);
public:
  virtual ~IEventStorage() override;

public slots:
  virtual QList<ILocalEvent*> events() const = 0;

public slots:
  virtual ILocalEvent *create(const QString &name
                              , const QString &desc
                              , const QDateTime &start
                              , const QDateTime &end
                              , const QPointF &location ) = 0;

  virtual bool addEvent(ILocalEvent *event) = 0;
  virtual bool removeEvent(ILocalEvent *event) = 0;

signals:
  void addedEvent(ILocalEvent *event);
};

#endif // EVENT_STORAGE_H

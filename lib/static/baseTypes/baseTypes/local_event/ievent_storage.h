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
  virtual int eventCount() const;
  virtual ILocalEvent *eventAt(int index);
  virtual ILocalEvent *create(const QString &name
                              , const QString &desc
                              , const QDateTime &start
                              , const QDateTime &end
                              , const QPointF &location );

  virtual bool addEvent(ILocalEvent *event);
  virtual bool removeEvent(ILocalEvent *event);

signals:
  void addedEvent(ILocalEvent *event);
};

#endif // EVENT_STORAGE_H

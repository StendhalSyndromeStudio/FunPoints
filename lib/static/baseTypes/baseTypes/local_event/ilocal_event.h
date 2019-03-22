#ifndef ILOCAL_EVENT_H
#define ILOCAL_EVENT_H

#include <QPointF>
#include <QObject>
#include <QDateTime>
#include "baseTypes/rate/irate_object.h"
#include "iexternal_resource.h"

class IUser;
class IExternalResource;

class ILocalEvent
    : public IRateObject
{
  Q_OBJECT
public:
  ///
  /// \brief Временной отрезок
  ///
  struct TimeSpan
  {
    QDateTime start;
    QDateTime end;
  };

  ///
  /// \brief Время проведения
  ///
  struct TimeSpending
  {
    TimeSpan        span;
    QList<TimeSpan> breaks;
  };

  enum class Status {
    WaitModeration, Moderation, Published, Miss
  };
  Q_ENUM(Status)

protected:
  explicit ILocalEvent(QObject *parent = nullptr);
public:
  virtual ~ILocalEvent() override;

public slots:
  virtual QString name() const = 0;
  virtual QStringList tags() const = 0;
  virtual QString description() const = 0;
  virtual IUser *organizer() const = 0;
  virtual Status status() const = 0;

public slots:
  virtual QPointF location() const = 0;
  virtual TimeSpending timeSpending() const = 0;
  virtual QList<IExternalResource*> resources() const = 0;

public slots:
  virtual bool writeInfo(const QString &name, const QString &desc) = 0;
  virtual bool writeLocation(const QPointF &location) = 0;
  virtual bool writeTimeSpanding(const TimeSpending &dt) = 0;

public slots:
  virtual bool addResource(IExternalResource *resource) = 0;
  virtual bool removeResource(IExternalResource *resource) = 0;

signals:
  void changed();

public slots:
};

#endif // ILOCAL_EVENT_H

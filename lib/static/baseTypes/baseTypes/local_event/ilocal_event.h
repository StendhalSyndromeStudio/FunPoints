#ifndef ILOCAL_EVENT_H
#define ILOCAL_EVENT_H

#include <QPointF>
#include <QObject>
#include <QDateTime>
#include <QGeoCoordinate>
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

public:
  explicit ILocalEvent(QObject *parent = nullptr);
  virtual ~ILocalEvent() override;

public slots:
  virtual QString name() const;
  virtual QStringList tags() const;
  virtual QString description() const;
  virtual IUser *organizer() const;
  virtual Status status() const;

public slots:
  virtual QGeoCoordinate location() const;
  virtual TimeSpending timeSpending() const;
  virtual QList<IExternalResource*> resources() const;

public slots:
  virtual bool writeInfo(const QString &name, const QString &desc);
  virtual bool writeLocation(const QGeoCoordinate &location);
  virtual bool writeTimeSpanding(const TimeSpending &dt);

public slots:
  virtual bool addResource(IExternalResource *resource);
  virtual bool removeResource(IExternalResource *resource);

signals:
  void changed();

  // IRateObject interface
public slots:
  double rate() const override;
  QList<IFeedback *> feedback() const override;
  bool addFeedback(IFeedback *feedback) override;
};

Q_DECLARE_METATYPE(ILocalEvent*)

#endif // ILOCAL_EVENT_H

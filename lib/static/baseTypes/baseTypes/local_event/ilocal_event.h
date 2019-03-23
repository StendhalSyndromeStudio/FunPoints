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
    : public QObject
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

  QUuid           _uid;
  QString         _name;
  QString         _desc;
  QStringList     _tags;
  TimeSpending    _time;
  QGeoCoordinate  _pos;
  mutable IUser   *_user;
  IRateObject     *_rate;
public:
  explicit ILocalEvent(QObject *parent = nullptr);
  explicit ILocalEvent(const QString &name
                       , const QString &desc
                       , const QDateTime &start
                       , const QDateTime &end
                       , const QGeoCoordinate &pos
                       , IUser *user
                       , QObject *parent = nullptr);
  virtual ~ILocalEvent() override;

public slots:
  IRateObject *rate() const;

public slots:
  virtual QJsonObject toJson() const;
  virtual void fromJson(const QJsonObject &obj);

public slots:
  virtual QUuid uid() const;
  virtual QString name() const;
  virtual QStringList tags() const;
  virtual QString description() const;
  virtual IUser *organizer() const;
  virtual Status status() const;

public slots:
  virtual QDateTime start() const;
  virtual QDateTime end() const;
  virtual QGeoCoordinate location() const;
  virtual TimeSpending timeSpending() const;
  virtual QList<IExternalResource*> resources() const;

public slots:
  virtual bool writeInfo(const QString &name, const QString &desc);
  virtual bool writeLocation(const QGeoCoordinate &location);
  virtual bool writeTime(const QDateTime &start, const QDateTime &end);
  virtual bool writeTimeSpanding(const TimeSpending &dt);

public slots:
  virtual bool addResource(IExternalResource *resource);
  virtual bool removeResource(IExternalResource *resource);

signals:
  void changed();
};

Q_DECLARE_METATYPE(ILocalEvent*)

#endif // ILOCAL_EVENT_H

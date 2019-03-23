#ifndef TEST_LOCAL_EVENT_H
#define TEST_LOCAL_EVENT_H

#include <ILocalEvent>

class TestLocalEvent
    : public ILocalEvent
{
  Q_OBJECT
  QString         _name;
  QString         _desk;
  QStringList     _tags;
  double          _rate;
  QGeoCoordinate  _pos;
  TimeSpending    _time;
public:
  explicit TestLocalEvent(QObject *parent = nullptr);
  ~TestLocalEvent() override;

  // IRateObject interface
public slots:
  double rate() const override;
  QList<IFeedback *> feedback() const override;
  bool addFeedback(IFeedback *feedback) override;

  // ILocalEvent interface
public slots:
  QString name() const override;
  QStringList tags() const override;
  QString description() const override;
  IUser *organizer() const override;
  Status status() const override;
  QGeoCoordinate location() const override;
  TimeSpending timeSpending() const override;
  QList<IExternalResource *> resources() const override;
  bool writeInfo(const QString &name, const QString &desc) override;
  bool writeLocation(const QGeoCoordinate &location) override;
  bool writeTimeSpanding(const TimeSpending &dt) override;
  bool addResource(IExternalResource *resource) override;
  bool removeResource(IExternalResource *resource) override;
};

#endif // TEST_LOCAL_EVENT_H

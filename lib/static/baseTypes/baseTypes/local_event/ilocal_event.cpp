#include "ilocal_event.h"

ILocalEvent::ILocalEvent(QObject *parent)
  : IRateObject(parent)
{

}

ILocalEvent::~ILocalEvent()
{

}

QString ILocalEvent::name() const
{
  return "";
}

QStringList ILocalEvent::tags() const
{
  return QStringList();
}

QString ILocalEvent::description() const
{
  return "";
}

IUser *ILocalEvent::organizer() const
{
  return nullptr;
}

ILocalEvent::Status ILocalEvent::status() const
{
  return Status::Published;
}

QGeoCoordinate ILocalEvent::location() const
{
  return QGeoCoordinate();
}

ILocalEvent::TimeSpending ILocalEvent::timeSpending() const
{
  return TimeSpending();
}

QList<IExternalResource *> ILocalEvent::resources() const
{
  return QList<IExternalResource *>();
}

bool ILocalEvent::writeInfo(const QString &, const QString &)
{
  return false;
}

bool ILocalEvent::writeLocation(const QGeoCoordinate &)
{
  return false;
}

bool ILocalEvent::writeTimeSpanding(const ILocalEvent::TimeSpending &)
{
  return false;
}

bool ILocalEvent::addResource(IExternalResource *)
{
  return false;
}

bool ILocalEvent::removeResource(IExternalResource *)
{
  return false;
}


double ILocalEvent::rate() const
{
  return 0.0;
}

QList<IFeedback *> ILocalEvent::feedback() const
{
  return QList<IFeedback*>();
}

bool ILocalEvent::addFeedback(IFeedback *)
{
  return false;
}

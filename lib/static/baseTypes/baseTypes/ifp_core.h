#ifndef IFP_CORE_H
#define IFP_CORE_H

#include <QPointF>
#include <QGeoCoordinate>
#include <QQmlListProperty>

#include "user/iuser.h"
#include "ibase_signal_object.h"
#include "local_event/ilocal_event.h"
#include "fpfilter.h"

class QGeoCoordinate;



class IFpCore
    : public IBaseSignalObject
{
  Q_OBJECT
public:
  using Filter = FpFilter;
protected:
  explicit IFpCore(QObject *parent = nullptr);
public:
  virtual ~IFpCore() override;

public slots:
  virtual bool isConnected() const = 0;

public slots:
  ///
  /// \brief Текущая позиция
  ///
  virtual QGeoCoordinate location() const = 0;

  ///
  /// \brief Текущий пользователь
  ///
  virtual IUser *user() const = 0;

public slots:
  virtual Filter *filter() const = 0;
  virtual int eventCount() const = 0;
  virtual ILocalEvent *eventAt(int index) const = 0;

public slots:
  virtual void setFilter(Filter *filter) = 0;
signals:
  void connected();
  void disconnected();

  void userChanged();
  void updateLocation();
  void eventListChanged();

  void objectListChanged();
};

#endif // IFP_CORE_H

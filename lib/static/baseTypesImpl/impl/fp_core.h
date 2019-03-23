#ifndef FP_CORE_H
#define FP_CORE_H

#include <IFpCore>
#include "server/fp_client.h"

class QGeoPositionInfoSource;

class QQmlEngine;
class QJSEngine;

class FpCore final
    : public IFpCore
{
  Q_OBJECT
  FpClient                *client;
  QList<ILocalEvent*>     allEvents;
  QGeoPositionInfoSource  *geoSource;
public:
  explicit FpCore(QObject *parent = nullptr);
  ~FpCore() override;

private:
  QList<ILocalEvent *> createTestEventList();
  void rebuildEventsList();



  // IFpCore interface
public slots:
  bool isConnected() const override;
  QGeoCoordinate location() const override;
  IUser *user() const override;
  int eventCount() const override;
  ILocalEvent *eventAt(int index) const override;

  // IFpCore interface
public slots:
  Filter *filter() const override;
  void setFilter(Filter *filter) override;
};

#endif // FP_CORE_H

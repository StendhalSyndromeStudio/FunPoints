#ifndef FPFILTER_H
#define FPFILTER_H

#include <QObject>
#include <QDateTime>
#include <QGeoCoordinate>

struct FpFilter
    : public QObject
  {
//  Q_GADGET
public:
  FpFilter();
  ~FpFilter();

  QGeoCoordinate    location;
  double            distance = -1.0;
  QDateTime         start;
  QDateTime         end;
  double            minRate = 0.0;
};

#endif // FPFILTER_H

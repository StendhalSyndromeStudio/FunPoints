#ifndef TEST_LOCAL_EVENT_H
#define TEST_LOCAL_EVENT_H

#include <ILocalEvent>

class TestLocalEvent
    : public ILocalEvent
{
  Q_OBJECT
public:
  explicit TestLocalEvent(QObject *parent = nullptr);
  explicit TestLocalEvent(const QString &name
                          , const QString &desc
                          , const QDateTime &start
                          , const QDateTime &end
                          , const QGeoCoordinate &location
                          , QObject *parent = nullptr);
  ~TestLocalEvent() override;
};

#endif // TEST_LOCAL_EVENT_H

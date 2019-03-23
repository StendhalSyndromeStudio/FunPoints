#ifndef FP_CORE_PROVIDER_H
#define FP_CORE_PROVIDER_H

#include <QObject>
#include <IFpCore>

class QQmlEngine;
class QJSEngine;

class FpCoreProvider : public QObject
{
  Q_OBJECT
  FpCoreProvider() = delete;
public:
  ~FpCoreProvider() override;

public:
  // QML Fabric
public:
  static QObject* singletonProvider(QQmlEngine* engine, QJSEngine* scriptEngine);
};

#endif // FP_CORE_PROVIDER_H

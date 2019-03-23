#include "fp_core_provider.h"

#include <QDebug>

#include "fp_core.h"

FpCoreProvider::~FpCoreProvider()
{

}

QObject *FpCoreProvider::singletonProvider(QQmlEngine *, QJSEngine *)
{
  static IFpCore *core = nullptr;
  if ( !core )
    core = new FpCore();

  qDebug() << "return " << core;
  return core;
}

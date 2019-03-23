#include "fp_core_provider.h"

#include <QDebug>
#include <QQmlApplicationEngine>

#include "fp_core.h"

FpCoreProvider::~FpCoreProvider()
{

}

void FpCoreProvider::regCoreTypes()
{
  qmlRegisterType<ILocalEvent>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "LocalEvent" );

  qmlRegisterType<LocalEventListModel>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "LocalEventList" );

  qmlRegisterType<FpFilter>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "LocalEventFilter" );

  qmlRegisterSingletonType<FpCore>("com.fun.fpcore"
                                    , 1
                                    , 0
                                    , "FpCore"
                                    , FpCoreProvider::singletonProvider);
}

QObject *FpCoreProvider::singletonProvider(QQmlEngine *, QJSEngine *)
{
  static IFpCore *core = nullptr;
  if ( !core )
    core = new FpCore();

  qDebug() << "return " << core;
  return core;
}

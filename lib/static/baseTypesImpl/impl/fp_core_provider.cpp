#include "fp_core_provider.h"

#include <QDebug>
#include <QQmlApplicationEngine>

#include <IUser>
#include <IPerson>
#include <ILocalEvent>
#include <IEventStorage>
#include <IFeedback>

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

  qmlRegisterType<IEventStorage>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "EventStorage" );

  qmlRegisterType<IFeedback>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "Feedback" );

  qmlRegisterType<IRateObject>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "RateObject" );

  qmlRegisterType<IPerson>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "Person" );

  qmlRegisterType<IUser>( "com.fun.fpcore"
                                , 1
                                , 0
                                , "User" );

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
//  static IFpCore *core = nullptr;
//  if ( !core )
//    core = new FpCore();

//  qDebug() << "return " << core;
//  return core;

  return new FpCore();
}

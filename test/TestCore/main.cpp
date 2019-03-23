#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>

#include <FpCoreProvider>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

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

  qmlRegisterSingletonType<IFpCore>("com.fun.fpcore"
                                    , 1
                                    , 0
                                    , "FpCore"
                                    , FpCoreProvider::singletonProvider);



  QQuickView view;
  view.setSource(QUrl(QStringLiteral("qrc:///core_main.qml")));
  view.setWidth(360);
  view.setHeight(640);
  view.show();
  return app.exec();
}

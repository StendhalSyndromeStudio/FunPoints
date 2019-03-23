#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>

#include <FpCoreProvider>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  FpCoreProvider::regCoreTypes();

  QQuickView view;
  view.setSource(QUrl(QStringLiteral("qrc:///core_main.qml")));
  view.setWidth(360);
  view.setHeight(640);
  view.show();
  return app.exec();
}

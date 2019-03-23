#include <QGuiApplication>
#include <QQuickView>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQuickView view;
  view.setSource(QUrl(QStringLiteral("qrc:///main.qml")));
  view.setWidth(360);
  view.setHeight(640);
  view.show();
  return app.exec();
}

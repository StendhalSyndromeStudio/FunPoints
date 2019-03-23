#include <QGuiApplication>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>

#include <FpCoreProvider>

int main(int argc, char *argv[])
{
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);

  FpCoreProvider::regCoreTypes();

  QQuickStyle::setStyle("Material");
  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/core_main.qml")));
  if (engine.rootObjects().isEmpty())
      return -1;

  return app.exec();
}

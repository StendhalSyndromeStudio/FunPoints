#include <QGuiApplication>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include "markermodel.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<MarkerModel>("org.simplemarkermodel.markermodel", 1, 0, "MarkerModel");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Material");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

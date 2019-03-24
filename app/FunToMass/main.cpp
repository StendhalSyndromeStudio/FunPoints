#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "markermodel.h"
#include <FpCoreProvider>
#include <QtWebView>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QtWebView::initialize();

    QQmlApplicationEngine engine;

    qmlRegisterType<MarkerModel>("org.simplemarkermodel.markermodel", 1, 0, "MarkerModel");
    FpCoreProvider::regCoreTypes( );
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

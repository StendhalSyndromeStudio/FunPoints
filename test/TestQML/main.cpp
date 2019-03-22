#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "testclass.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<TestClass>("org.test.testclass", 1, 0, "TestClass");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

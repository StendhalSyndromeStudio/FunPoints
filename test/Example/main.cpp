#include <QGuiApplication>
#include <QQmlApplicationEngine>


#include "ExampleClasses.h"
#include "FabricOfExamples.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QObject::connect( &engine, SIGNAL( quit() ), &app, SLOT( quit() ) );


    qmlRegisterSingletonType<FabricOfExamples>("com.fun.fabric", 1, 0, "FabricOfExamples",FabricOfExamples::singletonProvider);
    qmlRegisterType<Example>("com.fun.example", 1, 0, "Example");
    qmlRegisterType<ExampleChild_1>("com.fun.example_child_1", 1, 0, "ExampleChild_1");
    qmlRegisterType<ExampleChild_2>("com.fun.example_child_2", 1, 0, "ExampleChild_2");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "engine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<mqg::Core::Engine>("mqg.Core", 1,0, "Engine");
    qmlRegisterType<mqg::Core::Environment>("mqg.Core", 1,0, "Environment");

    QQmlApplicationEngine engine;
    engine.load(QStringLiteral("qrc:/qt-project.org/imports/mqg/main.qml"));

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "engine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<mqg::Engine>("mqg.Core.Engine", 1, 0, "Engine");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///mqg/application/main.qml")));

    return app.exec();
}

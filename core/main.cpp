#include "application.h"
#include "jsengineadapterforqt.h"
#include "messageadapterforqt.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

using namespace mqg::Core;

static QObject* app_provider(QQmlEngine *engine, QJSEngine *scriptEngine) {
  Q_UNUSED(engine);

  JSEngineAdapterForQt *script = new JSEngineAdapterForQt(scriptEngine);
  MessageAdapterForQt *message = new MessageAdapterForQt();

  message->installAsQtMessageHandler();

  Application::provide(script);
  Application::provide(message);

  return &Application::instance();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qRegisterMetaType<Message>("Message");
    qmlRegisterSingletonType<Application>("mqg.Core.Application", 1,0,
                                          "App", app_provider);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

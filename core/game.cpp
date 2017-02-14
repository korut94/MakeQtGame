#include <QDebug>
#include <QFile>

#include "entityinterface.h"
#include "entityloader.h"
#include "logic/container/containerbook.h"
#include "logic/container/loader/containerloader.h"
#include "loadplugingame.h"
#include "game.h"

#define BOOTSTRAPPER_PATH ":/mqg/core/bootstrapper.js"

#include "logic/container/container.h"

namespace mqg
{
Game::Game(int argc, char *argv[])
  : QApplication(argc, argv) {}
/*
void Game::eval(QString expression)
{
  Console *console = m_gameWindow.console();
  QScriptValue result = m_engine.evaluate(expression);

  if (m_engine.hasUncaughtException()) {
    console->error(m_engine.uncaughtException().toString());
  } else {
    if (!result.isUndefined())
      console->result(result.toString());
  }
}
*/
void Game::bootstrapping(QScriptEngine &engine)
{
  QFile file(BOOTSTRAPPER_PATH);
  assert(file.open(QFile::ReadOnly|QFile::Text));

  QByteArray payload = file.readAll();
  assert(!payload.isEmpty());

  engine.evaluate(QScriptProgram(payload));
}

QScriptValue Game::import(QScriptContext *context, QScriptEngine *engine)
{
  if (context->argumentCount() != 1) {
    return false;
  }

  QScriptValue extension = context->argument(0);

  if (!extension.isString()) {
    return false;
  }

  QScriptValue status = engine->importExtension(extension.toString());

  return !status.isError();
}

void Game::shareEnvProxyContainerLoaderOverEnv(
    QScriptEngine &engine,
    Logic::Container::Loader::EnvProxyContainerLoader &proxy)
{
  engine.globalObject().setProperty("_containerLoader",
                                    engine.newQObject(&proxy));
}

void Game::shareEnvProxyEntityLoaderOverEnv(
    QScriptEngine &engine,
    Entity::EnvProxyEntityLoader &proxy)
{
  engine.globalObject().setProperty("_entityLoader",
                                    engine.newQObject(&proxy));
}

void Game::shareGameWindowOverEnv(QScriptEngine &engine, GameWindow &window)
{
  // The real widget Console
  Console *rConsole = window.console();

  QScriptValue gameWindow = engine.newQObject(&window);
  engine.globalObject().setProperty("_window", gameWindow);

  QScriptValue console = engine.newQObject(rConsole);
  engine.globalObject().setProperty("_console", console);
}

void Game::shareImportOverEnv(QScriptEngine &engine)
{
  QScriptValue import = engine.newFunction(Game::import);
  engine.globalObject().setProperty("_import", import);
}

int Game::exec()
{
  QScriptEngine engine;

  Entity::EntityBook entityBook;
  Entity::EntityLoader entityLoader(
        entityBook,
        libs::baseLoadPluginGame<libs::EntityInterface>);
  Entity::EnvProxyEntityLoader proxyEntityLoader(entityLoader);

  Logic::Container::ContainerBook containerBook;
  Logic::Container::Loader::ContainerLoader containerLoader(
        containerBook,
        libs::baseLoadPluginGame<libs::ContainerInterface>);
  Logic::Container::Loader::EnvProxyContainerLoader
      proxyContainerLoader(containerLoader);

  World world;
  GameWindow window(world);

  shareEnvProxyContainerLoaderOverEnv(engine, proxyContainerLoader);
  shareEnvProxyEntityLoaderOverEnv(engine, proxyEntityLoader);
  shareGameWindowOverEnv(engine, window);
  shareImportOverEnv(engine);

  bootstrapping(engine);

  Logic::Container::Container* c =
      proxyContainerLoader.create("EvalConsole", {window.console(), &engine});

  QGraphicsItem *b = proxyEntityLoader.create("BoxMan");
  world.addItem(b);

  window.show();

  return QApplication::exec();
}
} // namespace mqg

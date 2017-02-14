#include <QDebug>
#include <QFile>

#include "entityholder.h"
#include "logic/container/loader/containerholder.h"
#include "game.h"

#define BOOTSTRAPPER_PATH ":/mqg/core/bootstrapper.js"

#include "logic/container/container.h"

namespace mqg
{
Game::Game(int argc, char *argv[])
  : QApplication(argc, argv) {}

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

void Game::shareEnvProxyContainerHolderOverEnv(
    QScriptEngine &engine,
    Logic::Container::Loader::EnvProxyContainerHolder &proxy)
{
  engine.globalObject().setProperty("_containerLoader",
                                    engine.newQObject(&proxy));
}

void Game::shareEnvProxyEntityHolderOverEnv(
    QScriptEngine &engine,
    Entity::EnvProxyEntityHolder &proxy)
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
  using Entity::EntityHolder;
  using Entity::EnvProxyEntityHolder;
  using Logic::Container::Loader::ContainerHolder;
  using Logic::Container::Loader::EnvProxyContainerHolder;

  QScriptEngine engine;

  EntityHolder entityHolder;
  EnvProxyEntityHolder proxyEntityHolder(entityHolder);

  ContainerHolder containerHolder;
  EnvProxyContainerHolder proxyContainerHolder(containerHolder);

  World world;
  GameWindow window(world);

  shareEnvProxyContainerHolderOverEnv(engine, proxyContainerHolder);
  shareEnvProxyEntityHolderOverEnv(engine, proxyEntityHolder);
  shareGameWindowOverEnv(engine, window);
  shareImportOverEnv(engine);

  bootstrapping(engine);

  Logic::Container::Container* c =
      proxyContainerHolder.create("EvalConsole", {window.console(), &engine});

  QGraphicsItem *b = proxyEntityHolder.create("BoxMan");
  world.addItem(b);

  window.show();

  return QApplication::exec();
}
} // namespace mqg

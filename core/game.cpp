#include <QDebug>
#include <QFile>

#include "game.h"
#include "entity/resource/entityholder.h"
#include "logic/container/resource/containerholder.h"

#define BOOTSTRAPPER_PATH ":/mqg/core/bootstrapper.js"

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

  if (engine.hasUncaughtException()) {
    throw std::runtime_error(engine.uncaughtException()
                             .toString()
                             .toStdString());
  }
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

void Game::shareEngineOverEnv(QScriptEngine &engine)
{
  engine.globalObject().setProperty("_engine", engine.newQObject(&engine));
}

void Game::shareEnvProxyContainerHolderOverEnv(
    QScriptEngine &engine,
    Logic::Container::Resource::EnvProxyContainerHolder &proxy)
{
  engine.globalObject().setProperty("_containers",
                                    engine.newQObject(&proxy));
}

void Game::shareEnvProxyEntityHolderOverEnv(
    QScriptEngine &engine,
    Entity::Resource::EnvProxyEntityHolder &proxy)
{
  engine.globalObject().setProperty("_entities",
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
  using Entity::Resource::EntityHolder;
  using Entity::Resource::EnvProxyEntityHolder;
  using Logic::Container::Resource::ContainerHolder;
  using Logic::Container::Resource::EnvProxyContainerHolder;

  QScriptEngine engine;

  EntityHolder entityHolder;
  EnvProxyEntityHolder proxyEntityHolder(entityHolder);

  ContainerHolder containerHolder;
  EnvProxyContainerHolder proxyContainerHolder(containerHolder);

  World world;
  GameWindow window(world);

  shareEngineOverEnv(engine);
  shareEnvProxyContainerHolderOverEnv(engine, proxyContainerHolder);
  shareEnvProxyEntityHolderOverEnv(engine, proxyEntityHolder);
  shareGameWindowOverEnv(engine, window);
  shareImportOverEnv(engine);

  bootstrapping(engine);

  // proxyContainerHolder.create("EvalConsole", {window.console(), &engine});
  // world.addItem(proxyEntityHolder.create("BoxMan"));

  window.show();

  return QApplication::exec();
}
} // namespace mqg

#include <QDebug>
#include <QFile>

#include "entityinterface.h"
#include "entityloader.h"
#include "loadplugingame.h"
#include "game.h"

#define BOOTSTRAPPER_PATH ":/mqg/core/bootstrapper.js"

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

void Game::shareEntityBookOverEnv(QScriptEngine &engine,
                                  Entity::EntityBook &book)
{
  QScriptValue entity = engine.newQObject(&book);
  entity.setProperty("list",
                     engine.newFunction(Entity::EntityBook::wrapperList));
  entity.setProperty("create",
                     engine.newFunction(Entity::EntityBook::wrapperCreate));
  engine.globalObject().setProperty("_entity", entity);
}

void Game::shareEnvProxyEntityLoaderOverEnv(
    QScriptEngine &engine,
    Entity::EnvProxyEntityLoader &proxy)
{
  QScriptValue proxyEntityLoader = engine.newQObject(&proxy);
  engine.globalObject().setProperty("_entityLoader", proxyEntityLoader);
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
        libs::loadPluginGame<libs::EntityInterface>
  );
  Entity::EnvProxyEntityLoader proxyEntityLoader(entityLoader);

  World world;
  GameWindow window(world);

  shareEntityBookOverEnv(engine, entityBook);
  shareEnvProxyEntityLoaderOverEnv(engine, proxyEntityLoader);
  shareGameWindowOverEnv(engine, window);
  shareImportOverEnv(engine);

  window.show();

  bootstrapping(engine);
  return QApplication::exec();
}
} // namespace mqg

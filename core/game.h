#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QScriptEngine>

#include "gamewindow.h"
#include "world.h"
#include "entity/resource/envproxyentityholder.h"
#include "logic/container/resource/envproxycontainerholder.h"

namespace mqg
{
/**
 * @brief The whole game is here. This is the main class with the management
 * of all the aspects about a game (process input, render, update, etc.).
 */
class Game : private QApplication
{
  Q_OBJECT

public:
  /**
   * @brief Default costructor.
   * @param Number of arguments
   * @param Array of string with the argument values
   */
  explicit Game(int argc, char *argv[]);

  /**
   * @brief Run the game! But pay attampion to don't get hurt.
   * @return Return the game state's code
   */
  int exec();

private:
  /**
   * @brief Start the bootstrapping phase to load environment's extensions and
   * shared libraries declared in the file `bootstrapper.js`.
   * @param The game engine.
   */
  static void bootstrapping(QScriptEngine &engine);

  /**
   * @brief Define the `_import` statement which import the extensions.
   * @param The context provided from the environenment when using `_import`.
   * @param A pointer to the engine instance.
   * @return Return a QScriptValue wrapper for a bool. If it's true the
   * loading task is performed successfully, false otherwise.
   */
  static QScriptValue import(QScriptContext *context, QScriptEngine *engine);

  /**
   * @brief shareEngineOverEnv
   * @param engine
   */
  static void shareEngineOverEnv(QScriptEngine &engine);

  /**
   * @brief Load the EnvProxyEntityHolder over the environemnt.
   * @param The engine that provides the script environment.
   * @param The EnvProxyEntityHolder instance to load into the environment
   */
  static void shareEnvProxyEntityHolderOverEnv(
      QScriptEngine &engine,
      Entity::Resource::EnvProxyEntityHolder &proxy);

  /**
   * @brief shareEnvProxyContainerHolderOverEnv
   * @param engine
   * @param proxy
   */
  static void shareEnvProxyContainerHolderOverEnv(
      QScriptEngine &engine,
      Logic::Container::Resource::EnvProxyContainerHolder &proxy);

  /**
   * @brief Load the GameWindow over the environemnt.
   * @param The engine that provides the script environment.
   * @param The GameWindow instance to load into the environment
   */
  static void shareGameWindowOverEnv(QScriptEngine &engine,
                                     GameWindow &window);

  /**
   * @brief Wrap the static Game method `import` over the environemnt.
   * @param The engine that provides the script environment.
   */
  static void shareImportOverEnv(QScriptEngine &engine);
};
} // namespace mqg

#endif // GAME_H

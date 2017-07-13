#ifndef ENGINE_H
#define ENGINE_H

#include <QJSValue>
#include <QObject>

#include "environment.h"

namespace mqg
{
namespace Core
{
//! The Engine class ties the QML context with the underlying scripting
//! environment.
/*!
  Engine works as QML type, instantiable into a QML document directly,
  providing a single point inside the application where to enhance the
  environment with the elements of a QML application (QML Type, JavaScript
  object and C++ plugin). Moreover, it exposes the script engine's utilities to
  bind them to the QML elements.

  The way how the Engine grows the environment is through an object
  `Environment` declared over the Engine's `env` property. After that the
  instance of `Engine` has been completed created, it looks up the
  Environment's properties to set the properties of a JavaScript Object.
  The result is a object (named `prefix`) that has the same properties as
  Environment and it can be reached inside the scripting enviroment. The
  purpouse of `prefix` is to avoid likely name clashing providing a common
  namespace for application's specific elements.

  Unfortunately the process to load the environemnt is not automatic because
  the properties' values declared as environment property can be incomplete on
  the instant that the QmlEngine sets Environment as property of `env`. For
  this reason the method `Engine::loadEnvironment()` must be call when the
  signal handler `Component.onCompleted` is invoked, inside the QML document.

  \code[.qml]
  Engine {
    ...

    env: Environment { ... }

    Component.onCompleted: {
      ...

      loadEnvironment()
    }
  }
  \endcode

  After the invokaction of loadEnvironment, any properties declared
  through the Environemnt object is evaluable in a script context writing:
  <prefix>.<property>; where <prefix> is the value of the Environments'
  attribute `prefix`.

  See the Environment's relative documentation to get more information about
  how to define new environment properties and the ways to set the value of
  `prefix`.
 */
class Engine : public QObject
{
  Q_OBJECT
  Q_PROPERTY(Environment* env READ environment WRITE setEnvironment)

public:
  //! Constructs an engine with a no enhanced environemnt
  /*!
    \param parent the parent QObject.
   */
  explicit Engine(QObject *parent = nullptr);

  //! Returns the current environment.
  /*!
    \return The environment assigned to the `env` property.
   */
  Environment*      environment() const;

  //! Creates a property in the global scope that has all the properties
  //! declared in the `Environment` instance attacched to `env` property.
  Q_INVOKABLE void  loadEnvironment() const;

  //! Sets the environment property.
  /*!
    \param env the environment to set.
   */
  void              setEnvironment(Environment *env);

public slots:
  //! Evaluates program like a JavaScript program.
  /*!
    In the case that the evaluation of program throws an exception, the engine
    emits the errorOccurred signal with the arised error as argument.
    \param program the code of the JavaScript program to evaluate.
   */
  void evaluate(const QString &program);

signals:
  //! Signal emitted when the QJSEngine throws an exception during the
  //! program evaluation.
  /*!
    \param error the arised error from the QJSEngine evaluation.
   */
  void errorOccurred(const QJSValue &error);

private:
  Environment *m_environment;
};
} // namespace Core
} // namespace mqg

#endif // ENGINE_H

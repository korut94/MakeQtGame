#include <QtQml>
#include <QQmlEngine>

#include "engine.h"

namespace mqg
{
namespace Core
{
Engine::Engine(QObject *parent)
  : QObject(parent), m_environment(nullptr) {}

Environment* Engine::environment() const
{
  return m_environment;
}

void Engine::evaluate(const QString &program)
{
  QQmlEngine *engine = qmlEngine(this);
  QJSValue result = engine->evaluate(program);

  if (result.isError()) {
    emit errorOccurred(result);
  }
}

void Engine::loadEnvironment() const
{
  m_environment->loadContext(qmlEngine(this));
}

void Engine::setEnvironment(Environment *env)
{
  m_environment = env;
  m_environment->setParent(this);
}
} // namespace Core
} // namespace mqg

#include <QtQml>
#include <QQmlEngine>

#include "engine.h"

namespace mqg
{
Engine::Engine(QObject *parent)
  : QObject(parent) {}

void Engine::evaluate(const QString &program)
{
  QQmlEngine *engine = qmlEngine(this);
  QJSValue result = engine->evaluate(program);

  if (result.isError()) {
    emit errorOccurred(result);
  }
}

void Engine::setGlobalObject(const QString &objectName, QObject *object) const
{
  QQmlEngine *engine = qmlEngine(this);
  engine->globalObject().setProperty(objectName, engine->newQObject(object));
}
} // namespace mqg

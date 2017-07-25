#include "jsengineadapterforqt.h"

#include <QJSValueIterator>
#include <QDebug>

namespace mqg
{
namespace Core
{
JSEngineAdapterForQt::JSEngineAdapterForQt(QJSEngine *engine)
  : m_engine(engine) {}

void JSEngineAdapterForQt::addToEnvironment(const QJSValue &object)
{
  if (object.isObject()) {
    QJSValueIterator it(object);

    while (it.hasNext()) {
      it.next();
      m_engine->globalObject().setProperty(it.name(), it.value());
    }
  }
}

void JSEngineAdapterForQt::evaluate(const QString &program)
{
  QJSValue result = m_engine->evaluate(program);

  if (result.isError()) {
    emit error(result);
  } else {
    emit success(result);
  }
}
} // namespace Core
} // namespace mqg

#include <QMetaProperty>

#include "environment.h"

#ifndef ENV_PREFIX
#define ENV_PREFIX "mqg"
#endif

namespace mqg
{
namespace Core
{
Environment::Environment(QObject *parent)
  : QObject(parent),
    m_prefix(ENV_PREFIX) {}

const QString& Environment::prefix() const
{
  return m_prefix;
}

void Environment::loadContext(QJSEngine *engine) const
{
  QJSValue prefix = engine->newObject();
  const QMetaObject *meta = metaObject();

  for (int i = meta->propertyOffset(); i < meta->propertyCount(); ++i) {
    auto name = meta->property(i).name();
    prefix.setProperty(name, engine->toScriptValue(property(name)));
  }

  engine->globalObject().setProperty(m_prefix, prefix);
  engine->globalObject().setProperty("__prefix", m_prefix);
}

void Environment::setPrefix(const QString &prefix)
{
  m_prefix = prefix;
}
} // namespace Core
} // namespace mqg

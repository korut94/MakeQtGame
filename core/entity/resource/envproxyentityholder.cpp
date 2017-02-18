#include "envproxyentityholder.h"

namespace mqg
{
namespace Entity
{
namespace Resource
{
EnvProxyEntityHolder::EnvProxyEntityHolder(EntityHolder &holder)
  : m_holder(holder) {}

QGraphicsItem* EnvProxyEntityHolder::create(const QString &entity) const
{
  return m_holder.create(entity);
}

QStringList EnvProxyEntityHolder::list() const
{
  return m_holder.list();
}

bool EnvProxyEntityHolder::load(const QString &resourcePath)
{
  return m_holder.load(resourcePath);
}
} // namespace Resource
} // namespace Entity
} // namespace mqg

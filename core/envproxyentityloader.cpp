#include "envproxyentityloader.h"

namespace mqg
{
namespace Entity
{
EnvProxyEntityLoader::EnvProxyEntityLoader(EntityLoader &loader)
  : m_loader(loader) {}

QGraphicsItem* EnvProxyEntityLoader::create(const QString &entity) const
{
  return m_loader.create(entity);
}

QStringList EnvProxyEntityLoader::list() const
{
  return m_loader.list();
}

bool EnvProxyEntityLoader::load(const QString &resourcePath)
{
  return m_loader.load(resourcePath);
}
} // namespace Entity
} // namespace mqg

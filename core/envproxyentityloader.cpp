#include "envproxyentityloader.h"

namespace mqg
{
namespace Entity
{
EnvProxyEntityLoader::EnvProxyEntityLoader(EntityLoader &loader)
  : m_loader(loader) {}

bool EnvProxyEntityLoader::load(const QString &resourcePath)
{
  return m_loader.load(resourcePath);
}
} // namespace Entity
} // namespace mqg

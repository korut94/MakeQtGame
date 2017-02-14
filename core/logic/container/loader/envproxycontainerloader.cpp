#include "envproxycontainerloader.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
EnvProxyContainerLoader::EnvProxyContainerLoader(ContainerLoader &loader)
  : m_loader(loader) {}

Container* EnvProxyContainerLoader::
create(const QString &container, const Dependencies &dependencies) const
{
  return m_loader.create(container, dependencies);
}

QStringList EnvProxyContainerLoader::list() const
{
  return m_loader.list();
}

bool EnvProxyContainerLoader::load(const QString &resourcePath)
{
  return m_loader.load(resourcePath);
}
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

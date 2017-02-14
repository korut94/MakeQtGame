#include "envproxycontainerholder.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
EnvProxyContainerHolder::EnvProxyContainerHolder(ContainerHolder &holder)
  : m_holder(holder) {}

Container* EnvProxyContainerHolder::
create(const QString &container, const Dependencies &dependencies) const
{
  return m_holder.create(container, dependencies);
}

QStringList EnvProxyContainerHolder::list() const
{
  return m_holder.list();
}

bool EnvProxyContainerHolder::load(const QString &resourcePath)
{
  return m_holder.load(resourcePath);
}
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

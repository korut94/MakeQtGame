#include "containerbook.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
Container* ContainerBook::create(const QString &container,
                                 const Dependencies &dependencies) const
{
  auto itr = m_registerFactory.find(container);

  if (itr == m_registerFactory.end()) {
    std::string msgError = "Not found a container registered by name '" +
                           container.toStdString() +
                           "' in the ContainerBook.";

    throw std::runtime_error(msgError);
  }

  return (itr.value())(dependencies);
}

QStringList ContainerBook::list() const
{
  return m_registerFactory.keys();
}
} // namespace Container
} // namespace Logic
} // namespace mqg

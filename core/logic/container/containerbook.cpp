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
  auto itr = m_registerWriter.find(container);

  if (itr == m_registerWriter.end()) {
    std::string msgError = "Not found a container registered by name '" +
                           container.toStdString() +
                           "' in the ContainerBook.";

    throw std::runtime_error(msgError);
  }

  Builder builder;
  (itr.value())(&builder, dependencies);

  return builder.build();
}

QStringList ContainerBook::list() const
{
  return m_registerWriter.keys();
}
} // namespace Container
} // namespace Logic
} // namespace mqg

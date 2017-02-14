#ifndef CONTAINERBOOK_H
#define CONTAINERBOOK_H

#include <functional>

#include <QMap>

#include "../../apply.h"
#include "../../extract.h"
#include "builder.h"
#include "container.h"
#include "containerparts.h"
#include "dependencies.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
class ContainerBook
{
  using Factory = std::function<Container*(const Dependencies&)>;

public:
  Container*  create(const QString &container,
                     const Dependencies &dependencies) const;

  QStringList list() const;

  template <typename... Args>
  void registerContainer(const QString &name,
                         void (*body)(ContainerParts&, Args...));

private:
  QMap<QString, Factory> m_registerFactory;
};

template <typename... Args>
void ContainerBook::
registerContainer(const QString &name,
                  void (*body)(ContainerParts&, Args...))
{
  using Utility::Injector::extract;
  using Utility::Injector::apply;

  m_registerFactory[name] = [body] (const Dependencies &dependencies)
  {
    Builder builder;
    ContainerParts parts(builder);

    std::tuple<ContainerParts&, Args...> args =
        std::tuple_cat(std::tie(parts),
                       extract<Args...>(dependencies.begin()));

    apply(body, args);

    return builder.build();
  };
}
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // CONTAINERBOOK_H

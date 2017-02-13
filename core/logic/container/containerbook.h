#ifndef CONTAINERBOOK_H
#define CONTAINERBOOK_H

#include <functional>

#include <QDebug>
#include <QMap>
#include <QObject>

#include "../../apply.h"
#include "../../extract.h"
#include "container.h"
#include "builder.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
using Dependencies = std::vector<QObject*>;

class ContainerBook
{
  using Writer = std::function<void(Builder*, const Dependencies&)>;

public:
  Container*  create(const QString &container,
                     const Dependencies &dependencies) const;

  QStringList list() const;

  template <typename... Args>
  void registerContainer(const QString &name,
                         void (*body)(Builder*, Args...));

private:
  QMap<QString, Writer> m_registerWriter;
};

template <typename... Args>
void ContainerBook::
registerContainer(const QString &name,
                  void (*body)(Builder*, Args...))
{
  using Utility::Injector::extract;
  using Utility::Injector::apply;

  // Encounter error: before the builder was created inside the factory and
  // concateneted with the dependencies tuple. However the compiler threw a
  // `symbol lookup error` said that the constructor and the build method had
  // an undefined symbol. For this reason now the builder is passed as
  // argument.
  m_registerWriter[name] = [body] (Builder *builder,
                                   const Dependencies &dependencies)
  {
    std::tuple<Builder*, Args...> args =
        std::tuple_cat(std::make_tuple(builder),
                       extract<Args...>(dependencies.begin()));

    apply(body, args);
  };
}
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // CONTAINERBOOK_H

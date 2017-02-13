#ifndef BUILDER_H
#define BUILDER_H

#include "container.h"
#include "../abstractlogic.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
class Builder
{
public:
  Builder();

  template <typename Item, typename... Args>
  Item*       addLogic(Args... arguments);
  Container*  build();

private:
  Container *m_container;
};

template <typename Item, typename... Args>
Item* Builder::addLogic(Args... arguments)
{
  Item *item = new Item(arguments...);
  m_container->push_back(item);

  return item;
}
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // BUILDER_H

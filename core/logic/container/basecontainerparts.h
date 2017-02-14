#ifndef BASECONTAINERPARTS_H
#define BASECONTAINERPARTS_H

namespace mqg
{
namespace Logic
{
namespace Container
{
template <typename BaseBuilder>
class BaseContainerParts
{
public:
  BaseContainerParts(BaseBuilder &builer);

  template <typename Item, typename... Args>
  Item* add(Args... arguments);

private:
  BaseBuilder &m_builder;
};

template <typename BaseBuilder>
BaseContainerParts<BaseBuilder>::BaseContainerParts(BaseBuilder &builder)
  : m_builder(builder) {}

template <typename BaseBuilder>
template <typename Item, typename... Args>
Item* BaseContainerParts<BaseBuilder>::add(Args... arguments)
{
  return m_builder.template addLogic<Item>(arguments...);
}
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // BASECONTAINERPARTS_H

#ifndef BUILDER_H
#define BUILDER_H

#include <vector>

namespace mqg
{
namespace Logic
{
class Logic;

namespace Container
{
class Builder
{
public:
  template <typename Item, typename... Args>
  Item* addLogic(Args... arguments);

private:
  std::vector<Logic> m_tmpContainer;
};
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // BUILDER_H

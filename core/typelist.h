#ifndef TYPELIST_H
#define TYPELIST_H

#include <tuple>

namespace mqg
{
namespace Utility
{
namespace Injector
{
template <typename... Args>
struct TypeList
{
  template <std::size_t N>
  using Type = typename std::tuple_element<N, std::tuple<Args...>>::type;
};
} // namespace Injector
} // namespace Utility
} // namespace mqg

#endif // TYPELIST_H

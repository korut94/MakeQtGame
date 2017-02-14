#ifndef TYPE_LIST_H
#define TYPE_LIST_H

#include <tuple>

namespace mqg
{
namespace Utility
{
namespace Injector
{
template <typename... Args>
struct type_list
{
  template <std::size_t N>
  using type = typename std::tuple_element<N, std::tuple<Args...>>::type;
};
} // namespace Injector
} // namespace Utility
} // namespace mqg

#endif // TYPE_LIST_H

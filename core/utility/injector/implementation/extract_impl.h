#ifndef EXTRACT_IMPL_H
#define EXTRACT_IMPL_H

#include <tuple>

namespace mqg
{
namespace Utility
{
namespace Injector
{
namespace Implementation
{
template <typename... Args, typename Iterator, std::size_t... offset>
constexpr std::tuple<Args...>
extract_impl(const Iterator &begin, std::index_sequence<offset...>)
{
  return std::make_tuple(static_cast<Args>(*(begin + offset))...);
}
} // namespace Implementation
} // namespace Injector
} // namespace Utility
} // namespace mqg

#endif // EXTRACT_IMPL_H

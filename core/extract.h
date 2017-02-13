#ifndef EXTRACT_H
#define EXTRACT_H

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

template <typename... Args, typename Iterator>
constexpr std::tuple<Args...> extract(const Iterator &begin)
{
  return Implementation::extract_impl<Args...>(
        begin,
        std::make_index_sequence<sizeof...(Args)>()
  );
}
} // namespace Injector
} // namespace Utility
} // namespace mqg

#endif // EXTRACT_H

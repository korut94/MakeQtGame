#ifndef APPLY_H
#define APPLY_H

#include <tuple>

namespace mqg
{
namespace Utility
{
namespace Injector
{
namespace Implementation
{
template <typename F, typename... Args, std::size_t... I>
constexpr decltype(auto) apply_impl(const F &f,
                                    const std::tuple<Args...> &t,
                                    std::index_sequence<I...>)
{
  return f(std::get<I>(t)...);
}
} // namespace Implementation

template <typename F, typename... Args>
constexpr decltype(auto) apply(const F &f, const std::tuple<Args...> &t)
{
  return
      Implementation::apply_impl(f, t,
                                 std::make_index_sequence<sizeof...(Args)>());
}
} // namespace Injector
} // namespace Utility
} // namespace mqg

#endif // APPLY_H

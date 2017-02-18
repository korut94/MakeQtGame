#ifndef APPLY_IMPL_H
#define APPLY_IMPL_H

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
} // namespace Injector
} // namespace Utility
} // namespace mqg

#endif // APPLY_IMPL_H

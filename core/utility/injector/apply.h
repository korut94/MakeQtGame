#ifndef APPLY_H
#define APPLY_H

#include <tuple>

#include "implementation/apply_impl.h"

namespace mqg
{
namespace Utility
{
namespace Injector
{
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

#ifndef EXTRACT_H
#define EXTRACT_H

#include <tuple>

#include "implementation/extract_impl.h"

namespace mqg
{
namespace Utility
{
namespace Injector
{
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

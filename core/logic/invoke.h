#ifndef INVOKE_H
#define INVOKE_H

#include <functional>

namespace mqg
{
namespace Logic
{
#define CALL_MEMBER_FN(object, ptrToMember) ((object)->*(ptrToMember))

template <typename Object, typename Result>
std::function<Result()> invoke(Result (Object::* pin)() const,
                               Object *instance)
{
  return [instance, pin] ()
  {
    return CALL_MEMBER_FN(instance, pin)();
  };
}
} // namespace Logic
} // namespace mqg

#endif // INVOKE_H

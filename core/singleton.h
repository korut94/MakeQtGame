#ifndef SINGLETON_H
#define SINGLETON_H

namespace mqg
{
namespace Utility
{
template <typename T>
class Singleton
{
protected:
  Singleton() = default;

  static T instance();
};

template <typename T>
T Singleton<T>::instance()
{
  static T instance;
  return instance;
}
} // namespace Utility
} // namespace mqg

#endif // SINGLETON_H

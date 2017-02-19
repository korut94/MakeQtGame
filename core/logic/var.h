#ifndef VAR_H
#define VAR_H

#include <functional>

namespace mqg
{
namespace Logic
{
template <typename T>
class Var
{
public:
  Var() = default;
  Var(T value);
  Var(const std::function<T()> &generator);

  T operator *() const;

private:
  std::function<T()> m_generator;
};

template <typename T>
Var<T>::Var(T value)
  : m_generator([value] () {
      return value;
    }) {}

template <typename T>
Var<T>::Var(const std::function<T()> &generator)
  : m_generator(generator) {}

template <typename T>
T Var<T>::operator *() const
{
  return m_generator();
}
} // namespace Logic
} // namespace mqg

#endif // VAR_H

#ifndef CONTAINER_H
#define CONTAINER_H

#include <array>
#include <cstddef>
#include <vector>

namespace mqg
{
namespace Logic
{
class Logic;

namespace Cotainer
{
class Builder;

template <std::size_t N>
class Container
{
  friend class Builder;

public:
  void start();

private:
  Container(const std::vector<Logic*> &buffer);

  std::array<Logic*, N> m_buffer;
};

template <std::size_t N>
Container<N>::Container(const std::vector<Logic*> &buffer)
{
  std::copy(buffer.begin(), buffer.end(), m_buffer);
}

template <std::size_t N>
void Container<N>::start()
{
  Logic *current = m_buffer[0];

  while (current != nullptr) {
    current.run();
    current = current.getNext();
  }
}
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // CONTAINER_H

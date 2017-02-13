#include "builder.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
Builder::Builder()
  : m_container(new Container) {}

Container* Builder::build()
{
  m_container->shrink_to_fit();
  return m_container;
}
} // namespace Container
} // namespace Logic
} // namespace mqg

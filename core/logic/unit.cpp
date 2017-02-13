#include "unit.h"

namespace mqg
{
namespace Logic
{
Unit::Unit()
  : m_next(nullptr) {}

AbstractLogic* Unit::getNext() const
{
  return m_next;
}

void Unit::next(AbstractLogic *next)
{
  m_next = next;
}

void Unit::run() {}
} // namespace Logic
} // namespace mqg

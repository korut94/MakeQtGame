#include "entitybook.h"

namespace mqg
{
namespace Entity
{
QGraphicsItem* EntityBook::create(const QString &entity) const
{
  auto itr = m_registerFactory.find(entity);

  return (itr != m_registerFactory.end()) ? (itr.value())() : nullptr;
}

QStringList EntityBook::list() const
{
  return m_registerFactory.keys();
}
} // namespace Entity
} // namespace mqg

#ifndef ENVPROXYENTITYHOLDER_H
#define ENVPROXYENTITYHOLDER_H

#include <QObject>
#include <QGraphicsItem>

#include "entityholder.h"

namespace mqg
{
namespace Entity
{
namespace Resource
{
/**
 * @brief The EnvProxyEntityHolder class allow the control of an EntityHolder
 * instance inside the script environment. The EnvProxyEntityHolder is just
 * a wrapper for the EntityHolder derived from QObject class that allow it
 * to be shared in the script environment.
 */
class EnvProxyEntityHolder : public QObject
{
  Q_OBJECT

public:
  /**
   * @brief Construct an EnvProxyEntityHolder with a reference for the
   * EntityLoader to share into the environment.
   * @param The EntityHolder instance to wrap.
   */
  explicit EnvProxyEntityHolder(EntityHolder &holder);

public slots:
  QGraphicsItem*  create(const QString &entity) const;

  QStringList     list() const;
  /**
   * @brief Identical behavior to the EntityHolder counterpart but, since this
   * method is a slot, the environemnt can invoke it by the
   * EnvProxyEntityHolder instance loaded within.
   * @param The resource's path where find it.
   * @return Return true if the load is performed successfully,
   * false otherwise.
   */
  bool            load(const QString &resourcePath);

private:
  EntityHolder &m_holder;
};
} // namespace Resource
} // namespace Entity
} // namespace mqg

#endif // ENVPROXYENTITYHOLDER_H

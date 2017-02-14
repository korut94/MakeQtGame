#ifndef ENVPROXYENTITYLOADER_H
#define ENVPROXYENTITYLOADER_H

#include <QObject>

#include "entityloader.h"

namespace mqg
{
namespace Entity
{
/**
 * @brief The EnvProxyEntityLoader class allow the control of an EntityLoader
 * instance inside the script environment. The EnvProxyEntityLoader is just
 * a wrapper for the EntityLoader derived from QObject class that allow it
 * to be shared in the script environment.
 */
class EnvProxyEntityLoader : public QObject
{
  Q_OBJECT

public:
  /**
   * @brief Construct an EnvProxyEntityLoader with a reference for the
   * EntityLoader to share into the environment.
   * @param The EntityLoader instance to wrap.
   */
  explicit EnvProxyEntityLoader(EntityLoader &loader);

public slots:
  /**
   * @brief Identical behavior to the EntityLoader counterpart but, since this
   * method is a slot, the environemnt can invoke it by the
   * EnvProxyEntityLoader instance loaded within.
   * @param The resource's path where find it.
   * @return Return true if the load is performed successfully,
   * false otherwise.
   */
  bool load(const QString &resourcePath);

private:
  EntityLoader &m_loader;
};
} // namespace Entity
} // namespace mqg

#endif // ENVPROXYENTITYLOADER_H

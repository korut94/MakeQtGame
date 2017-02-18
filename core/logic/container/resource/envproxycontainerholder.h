#ifndef ENVPROXYCONTAINERHOLDER_H
#define ENVPROXYCONTAINERHOLDER_H

#include <QObject>

#include "../container.h"
#include "../dependencies.h"
#include "containerholder.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Resource
{
class EnvProxyContainerHolder : public QObject
{
  Q_OBJECT

public:
  explicit EnvProxyContainerHolder(ContainerHolder &holder);

public slots:
  Container*  create(const QString &container,
                     const Dependencies &dependencies) const;
  QStringList list() const;
  bool        load(const QString &resourcePath);

private:
  ContainerHolder &m_holder;
};
} // namespace Resource
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // ENVPROXYCONTAINERLOADER_H

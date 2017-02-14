#ifndef ENVPROXYCONTAINERLOADER_H
#define ENVPROXYCONTAINERLOADER_H

#include <QObject>

#include "../container.h"
#include "../dependencies.h"
#include "containerloader.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
class EnvProxyContainerLoader : public QObject
{
  Q_OBJECT

public:
  explicit EnvProxyContainerLoader(ContainerLoader &loader);

public slots:
  Container*  create(const QString &container,
                     const Dependencies &dependencies) const;
  QStringList list() const;
  bool        load(const QString &resourcePath);

private:
  ContainerLoader &m_loader;
};
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // ENVPROXYCONTAINERLOADER_H

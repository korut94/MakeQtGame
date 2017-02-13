#ifndef ENVPROXYCONTAINERLOADER_H
#define ENVPROXYCONTAINERLOADER_H

#include <QObject>

#include "abstractcontainerloader.h"
#include "containerloader.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
class EnvProxyContainerLoader : public QObject, public AbstractContainerLoader
{
  Q_OBJECT

public:
  explicit EnvProxyContainerLoader(ContainerLoader &loader);

public slots:
  QStringList list() const;
  bool        load(const QString &resourcePath) override;

private:
  ContainerLoader &m_loader;
};
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // ENVPROXYCONTAINERLOADER_H

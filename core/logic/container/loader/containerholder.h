#ifndef CONTAINERHOLDER_H
#define CONTAINERHOLDER_H

#include "../../../basepluginloader.h"
#include "../../../containerinterface.h"
#include "../../../resourceholder.h"
#include "../containerbook.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
using ContainerHolder = ResourceHolder<
  ContainerBook,
  libs::BasePluginLoader<libs::ContainerInterface>
>;
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // CONTAINERHOLDER_H

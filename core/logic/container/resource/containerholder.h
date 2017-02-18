#ifndef CONTAINERHOLDER_H
#define CONTAINERHOLDER_H

#include "../../../libs/basepluginloader.h"
#include "../../../libs/containerinterface.h"
#include "../../../resourceholder.h"
#include "../containerbook.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Resource
{
using ContainerHolder = ResourceHolder<
  ContainerBook,
  libs::BasePluginLoader<libs::ContainerInterface>
>;
} // namespace Resource
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // CONTAINERHOLDER_H

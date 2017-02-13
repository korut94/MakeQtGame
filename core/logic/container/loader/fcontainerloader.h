#ifndef FCONTAINERLOADER_H
#define FCONTAINERLOADER_H

#include <functional>

#include "containerinterface.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
using FContainerLoader =
  std::function<libs::ContainerInterface*(const QString&)>;
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // FCONTAINERLOADER_H

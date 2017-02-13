#ifndef ABSTRACTCONTAINERLOADER_H
#define ABSTRACTCONTAINERLOADER_H

#include "../../../abstractresourceloader.h"
#include "../containerbook.h"
#include "fcontainerloader.h"

namespace mqg
{
namespace Logic
{
namespace Container
{
namespace Loader
{
using AbstractContainerLoader =
  AbstractResourceLoader<ContainerBook, FContainerLoader>;
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // ABSTRACTCONTAINERLOADER_H

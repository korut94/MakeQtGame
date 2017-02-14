#ifndef CONTAINERLOADER_H
#define CONTAINERLOADER_H

#include "../../../resourceloader.h"
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
using ContainerLoader = ResourceLoader<ContainerBook, FContainerLoader>;
} // namespace Loader
} // namespace Container
} // namespace Logic
} // namespace mqg

#endif // CONTAINERLOADER_H

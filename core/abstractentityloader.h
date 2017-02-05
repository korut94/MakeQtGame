#ifndef ABSTRACTENTITYLOADER_H
#define ABSTRACTENTITYLOADER_H

#include "abstractresourceloader.h"
#include "entitybook.h"
#include "functionentityloader.h"

namespace mqg
{
namespace Entity
{
typedef
AbstractResourceLoader<EntityBook, FunctionEntityLoader> AbstractEntityLoader;
} // namespace Entity
} // namespace mqg

#endif // ABSTRACTENTITYLOADER_H

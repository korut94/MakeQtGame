#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H

#include "entitybook.h"
#include "functionentityloader.h"
#include "resourceloader.h"

namespace mqg
{
namespace Entity
{
using EntityLoader = ResourceLoader<EntityBook, FunctionEntityLoader>;
} // namespace Entity
} // namespace mqg

#endif // ENTITYLOADER_H

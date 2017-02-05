#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H

#include "entitybook.h"
#include "functionentityloader.h"
#include "resourceloader.h"

namespace mqg
{
namespace Entity
{
typedef ResourceLoader<EntityBook, FunctionEntityLoader> EntityLoader;
} // namespace Entity
} // namespace mqg

#endif // ENTITYLOADER_H

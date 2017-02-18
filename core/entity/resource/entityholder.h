#ifndef ENTITYHOLDER_H
#define ENTITYHOLDER_H

#include "../../libs/basepluginloader.h"
#include "../../libs/entityinterface.h"
#include "../../resourceholder.h"
#include "../entitybook.h"

namespace mqg
{
namespace Entity
{
namespace Resource
{
using EntityHolder =
  ResourceHolder<EntityBook, libs::BasePluginLoader<libs::EntityInterface>>;
} // namespace Resource
} // namespace Entity
} // namespace mqg

#endif // ENTITYHOLDER_H

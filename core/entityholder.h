#ifndef ENTITYHOLDER_H
#define ENTITYHOLDER_H

#include "basepluginloader.h"
#include "entitybook.h"
#include "entityinterface.h"
#include "resourceholder.h"

namespace mqg
{
namespace Entity
{
using EntityHolder =
  ResourceHolder<EntityBook, libs::BasePluginLoader<libs::EntityInterface>>;
} // namespace Entity
} // namespace mqg

#endif // ENTITYHOLDER_H

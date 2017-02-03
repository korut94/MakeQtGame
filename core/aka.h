#ifndef AKA_H
#define AKA_H

#include <functional>

#include "entityinterface.h"
#include "resourceloader.h"

/**
 * The collection of all `typedef` (from this the name `aka`) for the vary
 * namespaces. The goal is to have only one place where no-header declaration
 * are defined.
 */
namespace mqg
{
namespace Entity
{
typedef
std::function<libs::EntityInterface*(const QString&)>     FunctionEntityLoader;

typedef
AbstractResourceLoader<EntityBook, FunctionEntityLoader>  AbstractEntityLoader;

typedef
ResourceLoader<EntityBook, FunctionEntityLoader>          EntityLoader;
} // namespace Entity
} // namespace mqg

#endif // AKA_H

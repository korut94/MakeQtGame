#ifndef FUNCTIONENTITYLOADER_H
#define FUNCTIONENTITYLOADER_H

#include <functional>

#include "entityinterface.h"

namespace mqg
{
namespace Entity
{
typedef
std::function<libs::EntityInterface*(const QString&)> FunctionEntityLoader;
} // namespace Entity
} // namespace mqg

#endif // FUNCTIONENTITYLOADER_H

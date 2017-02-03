#include "boxman.h"
#include "boxmanplugin.h"

namespace mqggame
{
namespace Entity
{
namespace BoxMan
{
void BoxManPlugin::saveIn(mqg::Entity::EntityBook &book) const
{
  book.registerEntity<BoxMan>("BoxMan");
}
} // namespace BoxMan
} // namespace Entity
} // namespace mqggame

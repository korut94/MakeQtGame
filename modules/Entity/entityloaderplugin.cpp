#include "entityloaderplugin.h"

#define LOAD_D(name, type) \
  dispatcher.registerEntity(name, &mqg::Entity::defaultFactory<type>)

#define LOAD(name, factory) \
  dispatcher.registerEntity(name, &factory)

namespace mqggame
{
void EntityLoaderPlugin::load(mqg::Entity::IDispatcherEntity &dispatcher) const
{
  LOAD_D("Rect", QGraphicsRectItem);
  LOAD_D("Circle", QGraphicsEllipseItem);
}
} // namespace mqggame

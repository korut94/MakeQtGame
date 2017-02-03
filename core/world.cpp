#include "world.h"

namespace mqg
{
World::World(QObject *parent)
  : QGraphicsScene(parent) {}

void World::addEntity(QGraphicsItem *entity)
{
  addItem(entity);
}
} // namespace mqg

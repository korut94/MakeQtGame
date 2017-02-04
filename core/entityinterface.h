// The header owns the EntityInterface definition plus the IEntityLoader alias
//

#ifndef ENTITYINTERFACE_H
#define ENTITYINTERFACE_H

#include <functional>

#include <QString>

namespace mqg
{
namespace Entity
{
class EntityBook;
} // namespace Entity

namespace libs
{
/**
 * @brief Any entities to be load and use during the game execution must supply
 * its constructor so, when is require, the new entity can be instantiate. To
 * achieve at this the target class can invoke the EntityBook::registerEntity
 * method replacing, with the entity class name, the template attribute.
 *
 * An example with a custom class, MyEntity:
 *
 * // myentity_plugin.cpp
 *
 * void load(Entity::EntityBook &book) const
 * {
 *    book.registerEntity<MyEntity>("MyEntity");
 * }
 *
 * // myentity.h
 *
 * class MyEntity : public QGraphicsItem
 * {
 *    ...
 * };
 *
 * Through this declaration, in game will be able to create new instances of
 * MyEntity class without importing the MyEntity definition in the core
 * library.
 */
class EntityInterface
{
public:
  virtual ~EntityInterface() {}

  virtual void saveIn(Entity::EntityBook &book) const = 0;
};

typedef std::function<EntityInterface*(const QString&)> IEntityLoader;
} // namespace libs
} // namespace mqg

#define EntityInterface_iid "mqg.libs.EntityInterface"
Q_DECLARE_INTERFACE(mqg::libs::EntityInterface, EntityInterface_iid)

#endif // ENTITYINTERFACE_H

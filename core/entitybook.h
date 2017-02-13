#ifndef ENTITYBOOK_H
#define ENTITYBOOK_H

#include <functional>

#include <QMap>
#include <QObject>
#include <QScriptContext>
#include <QScriptEngine>

#include "world.h"

namespace mqg
{
namespace Entity
{
using Factory = std::function<QGraphicsItem*()>;

/**
 * @brief The EntityBook class registers all the entities of the game keeping
 * a list of their name.
 */
class EntityBook : public QObject
{
  Q_OBJECT

public:
  // Simple wrapper fore create and list so to use them in the script
  // enviromnemt
  static QScriptValue wrapperCreate(QScriptContext *context,
                                    QScriptEngine *engine);
  static QScriptValue wrapperList(QScriptContext *context,
                                  QScriptEngine *engine);

  /**
   * @brief This method create an istance of the entity thas has as name the
   * value passed by argument. If no entity match with the specified name a
   * nullptr is returned.
   * @param The entity's name.
   * @return An pointer to entity instance.
   */
  QGraphicsItem*  create(const QString &entity);
  /**
   * @brief Get the list of the registered entities until now.
   * @return A string list with the name.
   */
  QStringList     list() const;
  /**
   * @brief Put the factory function for the relative class (specify by the
   * Entity template param) associate with the entity's name to have a simple
   * recovery way.
   * @param The entity's name.
   */
  template <typename Entity>
  void            registerEntity(const QString &name);

signals:
  /**
   * @brief Signal emitted when the user create a new instance of an entity.
   * @param The pointer to new entity.
   */
  void entityCreated(QGraphicsItem *entity);

private:
  QMap<QString, Factory>  m_registerFactory;
};

template <typename Entity>
void EntityBook::registerEntity(const QString &name)
{
  m_registerFactory[name] = [] ()
  {
    return new Entity();
  };
}
} // namespace Entity
} // namespace mqg

#endif // ENTITYBOOK_H

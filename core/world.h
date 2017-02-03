#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
#include <QScriptEngine>

namespace mqg
{
/**
 * @brief The environment where anything happens. The class contains all data
 * relatead to the rendering, phisics, logic.
 */
class World : public QGraphicsScene
{
  Q_OBJECT

public:
  /**
   * @brief Default costructor.
   * @param The parent object.
   */
  explicit World(QObject *parent = nullptr);

public slots:
  void addEntity(QGraphicsItem *entity);
};
} // namespace mqg

#endif // WORLD_H

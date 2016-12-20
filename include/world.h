#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>

/**
 * @brief The environment where anything happens. The class contains all data
 * relatead to the rendering, phisics, logic.
 */
class World : public QGraphicsScene
{
  public:
    /**
     * @brief Default costructor.
     * @param The parent object.
     */
    explicit World(QObject *parent = nullptr);
};

#endif // WORLD_H

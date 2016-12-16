#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
#include <QGraphicsView>

/**
 * @brief The environment where anything happens. The class contains all data
 * relatead to the rendering, phisics, logic and the comunication with the
 * Game class.
 */
class World
{
  public:
    /**
     * @brief Default costructor.
     * @param The parent widget where the scene will be showed.
     */
    explicit World(QWidget *parent = 0);
    /**
     * @brief Draw the scene with the up-to-date elements.
     * @param Percentage distance from the previous tick and the time
     * when the call to draw it's done.
     */
    void draw(const qreal dt);
    /**
     * @brief Advance with the logic game of a precise time step.
     * @param Time step
     */
    void update(const qreal elapsedTime);

  private:
    /**
     * @brief The world's scene
     */
    QGraphicsScene  mScene;
    /**
     * @brief The main view. Whatever is inside to the virtual rect drawed by
     * the view will be showed in the game's window.
     */
    QGraphicsView   mView;
};

#endif // WORLD_H

#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <QTime>

class Game;

/**
 * @brief The GameLoop class is concerned with the game loop pattern.
 * GameClock just decides when is the time to invoke the Game's method so to
 * go ahead with the game.
 */
class GameLoop
{
  public:
    /**
     * @brief Base class.
     * @param Reference to the game to run.
     */
    explicit GameLoop(Game &game);

    /**
     * @brief Build a new complete frame of the game. This involve calling
     * Game's update and render class methods so to calculate the new image
     * to show.
     */
    void start();

  private:
    /**
     * @brief Time between two frames.
     */
    static const qreal _TIME_PER_FRAME;
    /**
     * @brief Residual time between two frames.
     */
    qreal mlag;
    /**
     * @brief Similar to a stopwatch, the clock get the passed time since the
     * last measurement.
     */
    QTime mClock;
    /**
     * @brief A reference to the Game object.
     */
    Game &game;
};

#endif // GAMELOOP_H

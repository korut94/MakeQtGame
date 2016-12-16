#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QFrame>

#include "gameloop.h"
#include "world.h"

/**
 * @brief The whole game is here. This is the main class with the managment
 * of all the aspects about a game (process input, render, update, etc.).
 */
class Game
{
    friend class GameLoop;

  public:
    /**
     * @brief Default costructor.
     */
    Game(int argc, char *argv[]);

    /**
     * @brief Run the game! But pay attampion to don't get hurt.
     */
    void run();

  private:
    QApplication        mHandlerEvents;
    /**
     * @brief The windows that show the game.
     */
    QFrame              mWindow;
    /**
     * @brief The place in the game where the things happens.
     */
    World               mWorld;
    /**
     * @brief The loop logic
     */
    GameLoop            mLoop;

    /**
     * @brief Determine when the game is concluded
     * @return Return the condition stop status
     */
    bool  isRunning() const;
    /**
     * @brief Process all events are queuing
     */
    void  processEvents();
    /**
     * @brief Call the window's method to refresh the scene with the possible
     * changes
     * @param dt, value between 0 and 1 that define the normileze distance
     * from the current update to next one.
     */
    void  render(const qreal dt);
    /**
     * @brief Call the scene's method to advance with the game.
     * @param elapsedTime, the time occurred between two frame. Passed the time
     * occured as variable allow to use both fixed time step and variable delta
     * time.
     */
    void  update(const qreal elapsedTime);
};

#endif // GAME_H

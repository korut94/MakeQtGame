#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsView>

#include "world.h"

/**
 * @brief The whole game is here. This is the main class with the managment
 * of all the aspects about a game (process input, render, update, etc.).
 */
class Game
{
  public:
    /**
     * @brief Default costructor.
     * @param Number of arguments
     * @param Array of string with the argument values
     */
    Game(int argc, char *argv[]);

    /**
     * @brief Run the game! But pay attampion to don't get hurt.
     * @return Return the game state's code
     */
    int run();

  private:
    /**
     * @brief Number arguments passed by command line
     */
    int   m_argc;
    /**
     * @brief Argument values
     */
    char  **m_argv;
};

#endif // GAME_H

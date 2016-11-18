#ifndef GAME_H
#define GAME_H

/**
 * @brief The whole game is here. This is the main class with the managment
 * of all the aspects about a game (process input, render, update, etc.).
 */
class Game
{
  public:
    /**
     * @brief Default costructor. There aren't any options at the moment.
     */
    Game();

    /**
     * @brief Run the game! But pay attampion to don't get hurt.
     */
    void run();
};

#endif // GAME_H

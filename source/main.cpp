#include <QApplication>

#include "game.h"

int main(int argc, char *argv[])
{
  Game game(argc, argv);
  game.run();

  return 0;
}
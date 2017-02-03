#include "game.h"

int main(int argc, char **argv)
{
  mqg::Game game(argc, argv);
  return game.exec();
}

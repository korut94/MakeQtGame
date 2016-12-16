#include "game.h"
#include "gameloop.h"

const qreal GameLoop::_TIME_PER_FRAME = 1.f / 60.f;

GameLoop::GameLoop(Game &game) : mlag(0), game(game) {}

void GameLoop::start()
{
  while (game.isRunning())
  {
    // The method return the millisecond since the last restart express as
    // integer. So to get the equivalent value in second just divided it for
    // one thousand.
    mlag += mClock.restart() / 1000.f;

    game.processEvents();

    // Apply the fixed time step
    while (mlag >= _TIME_PER_FRAME) {
      mlag -= _TIME_PER_FRAME;
      game.update(_TIME_PER_FRAME);
    }

    game.render(mlag / _TIME_PER_FRAME);
  }
}

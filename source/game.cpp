#include <QTime>

#include "game.h"

Game::Game(int argc, char *argv[])
: mHandlerEvents(argc, argv),
  mWindow(),
  mWorld(&mWindow),
  mLoop(*this) {}

bool Game::isRunning() const
{
  return mWindow.isVisible();
}

void Game::processEvents()
{
  mHandlerEvents.processEvents();
}

void Game::render(const qreal dt)
{
  mWorld.draw(dt);
}

void Game::run()
{
  mWindow.show();
  mLoop.start();
}

void Game::update(const qreal elapsedTime)
{
  mWorld.update(elapsedTime);
}

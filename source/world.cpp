#include "world.h"

World::World(QWidget *parent) : mView(&mScene, parent)
{
  // Configure the view and the scene's dimension so to take up the whole
  // parent's graphic space.
  mScene.setSceneRect(parent->geometry());
  mView.setSceneRect(parent->geometry());

  // Show the scene on the screen
  mView.show();
}

void World::update(const qreal elapsedTime)
{
  Q_UNUSED(elapsedTime);
  mScene.advance();
}

void World::draw(const qreal dt)
{
  Q_UNUSED(dt);
  // It's no necessary call update to render the last modifies
  // mScene.update();
}

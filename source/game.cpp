#include "game.h"

Game::Game(int argc, char *argv[])
: m_argc(argc),
  m_argv(argv) {}

int Game::run()
{
  QApplication app(m_argc, m_argv);

  World world;
  world.setSceneRect(0, 0, 800, 600);

  QGraphicsView view(&world);
  view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view.setFixedSize(world.sceneRect().size().toSize());
  view.show();

  return app.exec();
}

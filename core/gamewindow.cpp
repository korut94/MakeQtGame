#include <QAction>
#include <QBoxLayout>
#include <QSplitter>

#include "gamewindow.h"

namespace mqg
{
GameWindow::GameWindow(World &world, QWidget *parent)
  : QWidget(parent),
    m_console(),
    m_view(&world)

{
  m_view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  m_view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  // m_console.hide();

  // Allow the resizing of the console
  QSplitter *splitter = new QSplitter(Qt::Vertical);
  splitter->addWidget(&m_view);
  splitter->addWidget(&m_console);

  QBoxLayout *layout = new QBoxLayout(QBoxLayout::TopToBottom);
  layout->setSpacing(0);
  layout->setMargin(0);

  layout->addWidget(splitter);

  setLayout(layout);
  setMinimumSize(800, 600);

  setGlobalShortcut();
}

Console* GameWindow::console()
{
  return &m_console;
}

void GameWindow::showOrHideConsole()
{
  if (m_console.isVisible()) {
    m_console.hide();
  } else {
    m_console.show();
  }
}

void GameWindow::setGlobalShortcut()
{
  // Set CTRL+F12 as global shortcut to open or close the console
  QAction *console = new QAction();
  console->setShortcut(Qt::Key_F12 | Qt::CTRL);
  QObject::connect(console,
                   SIGNAL(triggered()),
                   this,
                   SLOT(showOrHideConsole()));

  addAction(console);
}
} // namespace mqg

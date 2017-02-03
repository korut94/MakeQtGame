#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QGraphicsView>
#include <QScriptEngine>
#include <QWidget>

#include "console.h"
#include "world.h"

namespace mqg
{
class GameWindow : public QWidget
{
  Q_OBJECT

public:
  explicit GameWindow(World &world, QWidget *parent = nullptr);

  Console* console();

private slots:
  void showOrHideConsole();

private:
  void setGlobalShortcut();

  Console       m_console;
  QGraphicsView m_view;
};
} // namespace mqg

#endif // GAMEWINDOW_H

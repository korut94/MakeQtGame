#include "mqggame.h"

namespace mqggame
{
MQGGame::MQGGame(QObject *parent)
  : QScriptExtensionPlugin(parent) {}

void MQGGame::initialize(const QString &key, QScriptEngine *engine)
{
  Q_UNUSED(key);
  Q_UNUSED(engine);
}

QStringList MQGGame::keys() const
{
  return QStringList() << "Game";
}
} // namespace mqggame

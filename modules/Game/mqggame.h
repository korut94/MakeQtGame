#ifndef MQGGAME_H
#define MQGGAME_H

#include <QScriptEngine>
#include <QScriptExtensionPlugin>
#include <QStringList>

namespace mqggame
{
class MQGGame : public QScriptExtensionPlugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QScriptExtensionInterface")

public:
  MQGGame(QObject *parent = nullptr);

  void        initialize(const QString &key, QScriptEngine *engine);
  QStringList keys() const;
};
} // namespace mqggame

#endif // MQGGAME_H

#ifndef JSENGINEADAPTERFORQT_H
#define JSENGINEADAPTERFORQT_H

#include "jsscriptengine.h"

#include <QJSEngine>

namespace mqg
{
namespace Core
{
class JSEngineAdapterForQt : public JSScriptEngine
{
  Q_OBJECT

public:
  explicit JSEngineAdapterForQt(QJSEngine *engine);

  void addToEnvironment(const QJSValue &object);

public slots:
  void evaluate(const QString &program);

private:
  QJSEngine *m_engine;
};
} // namespace Core
} // namespace mqg

#endif // JSENGINEADAPTERFORQT_H

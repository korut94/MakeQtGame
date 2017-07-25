#ifndef NULLJSSCRIPTENGINE_H
#define NULLJSSCRIPTENGINE_H

#include "application.h"

#include <QDebug>

namespace mqg
{
namespace Core
{
class Application::NullJSScriptEngine : public JSScriptEngine
{
  Q_OBJECT

public:
  inline void addToEnvironment(const QJSValue &object) { Q_UNUSED(object) }

public slots:
  void evaluate(const QString &program) { Q_UNUSED(program) }
};
} // namespace Core
} // namespace mqg

#endif // NULLJSSCRIPTENGINE_H

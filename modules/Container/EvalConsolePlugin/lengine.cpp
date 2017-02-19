#include <QDebug>
#include <QScriptValue>

#include "lengine.h"

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
LEngine::LEngine(QScriptEngine *engine)
  : m_engine(engine) {}

void LEngine::run()
{
  QScriptValue result = m_engine->evaluate(*m_expression);

  if (m_engine->hasUncaughtException()) {
    qDebug() << m_engine->uncaughtException().toString();
  } else {
    if (!result.isUndefined())
      qDebug() << result.toString();
  }
}

void LEngine::toEval(const mqg::Logic::Var<QString> &expression)
{
  m_expression = expression;
}
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

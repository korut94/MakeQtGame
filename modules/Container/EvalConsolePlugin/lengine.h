#ifndef LENGINE_H
#define LENGINE_H

#include <functional>

#include <QScriptEngine>

#include "core/logic/unit.h"

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
class LEngine : public mqg::Logic::Unit
{
public:
  LEngine(QScriptEngine* engine);

  void toEval(const std::function<QString()> &expression);

private:
  void run() override;

  QScriptEngine            *m_engine;
  std::function<QString()>  m_expression;
};
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

#endif // LENGINE_H

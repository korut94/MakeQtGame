#ifndef LENGINE_H
#define LENGINE_H

#include <QScriptEngine>

#include "core/logic/unit.h"
#include "core/logic/var.h"

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

  void toEval(const mqg::Logic::Var<QString> &expression);

private:
  void run() override;

  QScriptEngine             *m_engine;
  mqg::Logic::Var<QString>   m_expression;
};
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

#endif // LENGINE_H

#include <functional>

#include <QScriptEngine>

#include "core/console.h"
#include "core/logic/invoke.h"
#include "core/logic/container/builder.h"

#include "evalconsoleplugin.h"
#include "lconsole.h"
#include "lengine.h"

using mqg::Console;
using mqg::Logic::Container::Builder;
using mqg::Logic::Container::ContainerBook;

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
void eval_console(Builder *builder, Console *console, QScriptEngine *engine)
{
  using mqg::Logic::invoke;

  LConsole *lConsole = builder->addLogic<LConsole>();
  LEngine  *lEngine  = builder->addLogic<LEngine>(engine);

  lEngine->toEval(invoke(&LConsole::expression, lConsole));
  lConsole->next(lEngine);

  QObject::connect(console,
                   SIGNAL(evaluate(QString)),
                   lConsole,
                   SLOT(setExpression(QString)));
}

void EvalConsolePlugin::saveIn(ContainerBook &book) const
{
  book.registerContainer("EvalConsole", eval_console);
}
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

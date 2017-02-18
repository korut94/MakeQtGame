#include <functional>

#include <QScriptEngine>

#include "core/console.h"
#include "core/logic/invoke.h"
#include "core/logic/container/containerparts.h"

#include "evalconsoleplugin.h"
#include "lconsole.h"
#include "lengine.h"

using mqg::Console;
using mqg::Logic::Container::ContainerParts;
using mqg::Logic::Container::ContainerBook;

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
void eval_console(ContainerParts &parts,
                  Console *console,
                  QScriptEngine *engine)
{
  using mqg::Logic::invoke;

  LConsole *lConsole = parts.add<LConsole>();
  LEngine  *lEngine  = parts.add<LEngine>(engine);

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

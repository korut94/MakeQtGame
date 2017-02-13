#include "lconsole.h"

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
QString LConsole::expression() const
{
  return m_expression;
}

void LConsole::setExpression(const QString &expression)
{
  m_expression = expression;

  startContainer();
}
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

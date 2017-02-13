#ifndef LCONSOLE_H
#define LCONSOLE_H

#include <QObject>
#include <QString>

#include "core/logic/unit.h"

namespace mqggame
{
namespace Container
{
namespace EvalConsole
{
class LConsole : public QObject, public mqg::Logic::Unit
{
  Q_OBJECT

public:
  QString expression() const;

public slots:
  void setExpression(const QString &expression);

private:
  QString m_expression;
};
} // namespace EvalConsole
} // namespace Container
} // namespace mqggame

#endif // LCONSOLE_H

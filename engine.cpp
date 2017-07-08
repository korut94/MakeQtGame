#include <QtQml>
#include <QQmlEngine>

#include "backend.h"

namespace mqg
{
BackEnd::BackEnd(QObject *parent)
  : QObject(parent) {}

void BackEnd::evaluate(const QString &program)
{
  QQmlEngine *engine = qmlEngine(this);
  engine->evaluate(program);
}
} // namespace mqg

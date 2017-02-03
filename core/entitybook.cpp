#include "entitybook.h"

namespace mqg
{
namespace Entity
{
QGraphicsItem* EntityBook::create(const QString &entity)
{
  QMap<QString, Factory>::const_iterator itr = m_registerFactory.find(entity);

  if (itr != m_registerFactory.end()) {
    QGraphicsItem *pEntity = (itr.value())();

    emit entityCreated(pEntity);
    return pEntity;
  } else {
    return nullptr;
  }
}

QStringList EntityBook::list() const
{
  return m_registerFactory.keys();
}

QScriptValue EntityBook::wrapperCreate(QScriptContext *context,
                                       QScriptEngine *engine)
{
  QScriptValue object = context->thisObject();
  EntityBook *book = qobject_cast<EntityBook*>(object.toQObject());

  if (book != nullptr && context->argumentCount() > 0) {
    // Take only the first argument, the other ones are ignored.
    QScriptValue arg = context->argument(0);

    if (arg.isString()) {
      book->create(arg.toString());
    }
  }

  return engine->undefinedValue();
}

QScriptValue EntityBook::wrapperList(QScriptContext *context,
                                     QScriptEngine *engine)
{
  QScriptValue object = context->thisObject();
  EntityBook *book = qobject_cast<EntityBook*>(object.toQObject());

  if (book == nullptr) {
    return engine->undefinedValue();
  } else {
    return book->list().join(" ");
  }
}
} // namespace Entity
} // namespace mqg

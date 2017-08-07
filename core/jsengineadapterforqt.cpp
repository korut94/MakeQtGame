/******************************************************************************
 * MakeQtGame
 * Copyright (C) 2017 Andrea Mantovani
 *
 * This file is part of MakeQtGame
 *
 * MakeQtGame is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MakeQtGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MakeQtGame. If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#include "jsengineadapterforqt.h"

#include <QJSValueIterator>

namespace mqg
{
namespace Core
{
JSEngineAdapterForQt::JSEngineAdapterForQt(QJSEngine *engine)
  : m_engine(engine) {}

void JSEngineAdapterForQt::addToEnvironment(const QJSValue &object)
{
  if (object.isObject()) {
    QJSValueIterator it(object);

    while (it.hasNext()) {
      it.next();
      m_engine->globalObject().setProperty(it.name(), it.value());
    }
  }
}

void JSEngineAdapterForQt::evaluate(const QString &program)
{
  QJSValue result = m_engine->evaluate(program);

  if (result.isError()) {
    emit error(result);
  } else {
    emit success(result);
  }
}
} // namespace Core
} // namespace mqg

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

#ifndef JSENGINEADAPTERFORQT_H
#define JSENGINEADAPTERFORQT_H

#include "jsscriptengine.h"

#include <QJSEngine>

namespace mqg
{
namespace Core
{
class JSEngineAdapterForQt : public JSScriptEngine
{
  Q_OBJECT

public:
  explicit JSEngineAdapterForQt(QJSEngine *engine);

  void addToEnvironment(const QJSValue &object);

public slots:
  void evaluate(const QString &program);

private:
  QJSEngine *m_engine;
};
} // namespace Core
} // namespace mqg

#endif // JSENGINEADAPTERFORQT_H

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
/*!
 * The JSEngineAdapterForQt class wraps QJSEngine to make it in compilance
 * with JSScriptEngine interface.
 */
class JSEngineAdapterForQt : public JSScriptEngine
{
  Q_OBJECT

public:
  /*!
   * Creates a script service provider points to a QJSEngine *engine*.
   */
  explicit JSEngineAdapterForQt(QJSEngine *engine);

  /*!
   * Puts as root objects in the script environment all properties own to
   * *object*.
   */
  void addToEnvironment(const QJSValue &object);

public slots:
  /*!
   * Evaluates *program* and emits a different signal if an error is occurred
   * or not.
   */
  void evaluate(const QString &program);

private:
  QJSEngine *m_engine;
};
} // namespace Core
} // namespace mqg

#endif // JSENGINEADAPTERFORQT_H

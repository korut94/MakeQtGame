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

#ifndef JSSCRIPTENGINE_H
#define JSSCRIPTENGINE_H

#include <QJSValue>
#include <QObject>

namespace mqg
{
namespace Core
{
/*!
 * The JSScriptEngine interface defines what services a JavaScript engine
 * service has to provide.
 */
class JSScriptEngine : public QObject
{
  Q_OBJECT

public:
  virtual ~JSScriptEngine() = default;

  /*!
   * The derived classes have to provide the way to insert *object*'s
   * properties in the context of the global object.
   */
  Q_INVOKABLE virtual void addToEnvironment(const QJSValue &object) = 0;

public slots:
  /*!
   * The derived classes have to define how *program* is evaluated by a
   * JavaScipt engine.
   *
   * If an error is occurred the `error` signal must be emitted with the error
   * arised as argument, instead if the evaluation is completed successfully
   * emit the signal `success` with the evaluation's result.
   */
  virtual void evaluate(const QString &program) = 0;

signals:
  /*!
   * Emitted when an error in the evaluation phase is arised.
   */
  void error(const QJSValue &error);
  /*!
   * Emitted when the evaluation has been completed successfully.
   */
  void success(const QJSValue &result);
};
} // namespace Core
} // namespace mqg

#endif // JSSCRIPTENGINE_H

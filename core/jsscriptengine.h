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
class JSScriptEngine : public QObject
{
  Q_OBJECT

public:
  virtual ~JSScriptEngine() = default;

  Q_INVOKABLE virtual void addToEnvironment(const QJSValue &object) = 0;

public slots:
  virtual void evaluate(const QString &program) = 0;

signals:
  void error(const QJSValue &error);
  void success(const QJSValue &result);
};
} // namespace Core
} // namespace mqg

#endif // JSSCRIPTENGINE_H

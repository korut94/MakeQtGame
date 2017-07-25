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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MakeQtGame. If not, see <http://www.gnu.org/licenses/>.
 *
 *****************************************************************************/

#ifndef NULLJSSCRIPTENGINE_H
#define NULLJSSCRIPTENGINE_H

#include "application.h"

namespace mqg
{
namespace Core
{
/*!
 * The Application::NullJSScriptEngine class defines a *null* service for
 * scripting task.
 *
 * In way to avoid temporary states where the script engine service in the
 * Application class is no setted (that should involve in a dereferentation of
 * a null pointer), the NullJSScriptEngine provides a *null* service where in
 * any method nothing is done.
 *
 * **Note**: This class not should be use in the application directly, since
 * the Application class worries about the instantiation of a null service when
 * requirement. For example:
 *
 * \code{.cpp}
 * Application::provide(nullptr) // Application will use a NullJSScriptEngine
 * \endcode
 */
class Application::NullJSScriptEngine : public JSScriptEngine
{
  Q_OBJECT

public:
  /*!
   * Does nothing, *object* is ignored.
   */
  inline void addToEnvironment(const QJSValue &object) { Q_UNUSED(object) }

public slots:
  /*!
   * Does nothig, *program* is ignored.
   */
  void evaluate(const QString &program) { Q_UNUSED(program) }
};
} // namespace Core
} // namespace mqg

#endif // NULLJSSCRIPTENGINE_H

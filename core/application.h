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

#ifndef APPLICATION_H
#define APPLICATION_H

#include "jsscriptengine.h"
#include "messagehandler.h"

#include <QObject>

namespace mqg
{
namespace Core
{
/*!
 * The Application class provides a global point of access to all application's
 * services.
 *
 * Application is a static class to supply in any part of the program the main
 * application's services. Application covers the following areas:
 * - **Scripting** provided by JSScriptEngine interface
 * - **Messaging** provided by MessageHandler interface
 *
 * Any one of the services above has its relative method `provide` to set the
 * service provider implements the specific interface. Once that the service
 * provider has been setted, Application class will worry about its destruction
 * when it is no more required (either providing a new service provider or
 * closing the application).
 *
 * In MakeQtGame, Application is also accessible from QML context importing the
 * `mqg.Core.Application` module at the preferred version. Now the service
 * providers instantiated in the C++ context can be refered by the `App`'s
 * properties, one for each thematic area:
 * - **script** for scripting task
 * - **message** for messaging task
 *
 * ```
 * MessageHandler *handler = Application::getMessageHandler();
 *
 * connect(handler, SIGNAL(log), [] (const Message &message) {
 *  qDebug() << message.text;
 * });
 * ```
 *
 * ```
 * import mqg.Core.Application 1.0
 *
 * Item {
 *  ...
 *
 *  Component.onCompleted: {
 *    App.message.log.connect(function (message) {
 *      console.log(message.text)
 *    })
 *  }
 * }
 * ```
 *
 * Both in QML context and in C++ context the getter methods return always
 * valid references to the services, so no check is needed.
 */
class Application : public QObject
{
  Q_OBJECT
  Q_DISABLE_COPY(Application)
  /*!
   Reference to the service provider for the scripting service.
   */
  Q_PROPERTY(JSScriptEngine* script   READ getJSScriptEngine  WRITE provide)
  /*!
   Reference to the service provider for the messaging service.
   */
  Q_PROPERTY(MessageHandler* message  READ getMessangeHandler WRITE provide)

  class NullJSScriptEngine;
  class NullMessageHandler;

public:
  /*!
   * Returns the service provider setted to supply the scripting service.
   *
   * In QML, the service can be refered by the property `script`.
   *
   *     App.script.<method or property>
   *
   */
  static JSScriptEngine*  getJSScriptEngine();
  /*!
   * Returns the service provider setted to supply the messaging service.
   *
   * In QML, the service can be refered by the property `message`.
   *
   *     App.message.<method or property>
   *
   */
  static MessageHandler*  getMessangeHandler();
  /*!
   * Returns a reference to the application's Application instance.
   *
   * If no instance has been allocated a new one will be created.
   */
  static Application&     instance();
  /*!
   * Sets the service provider *service* to supply the scripting service.
   *
   * In QML, as in C++ too, the service provider can be changed by assigning
   * to the property `script` the desired one.
   *
   *     App.script = <service provider>
   *
   * **Note**: if a null pointer has been passed as argument, Application will
   * set NullJSScriptEngine as service provider.
   */
  static void             provide(JSScriptEngine *service);
  /*!
   * Sets the service provider *service* to supply the messaging service.
   *
   * In QML, as in C++ too, the service provider can be changed by assigning
   * to the property `message` the desired one.
   *
   *     App.message = <service provider>
   *
   * **Note**: if a null pointer has been passed as argument, Application will
   * set NullMessageHandler as service provider.
   */
  static void             provide(MessageHandler *service);

private:
  explicit Application(QObject* parent = nullptr);
  ~Application() = default;

  static NullJSScriptEngine _nullJSScriptEngine;
  static NullMessageHandler _nullMessageHandler;
  JSScriptEngine           *m_jsScriptEngineService;
  MessageHandler           *m_messageHandlerService;
};
} // namespace mqg
} // namespace Core

#endif // APPLICATION_H

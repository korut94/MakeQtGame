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

#include "application.h"
#include "Private/nulljsscriptengine.h"
#include "Private/nullmessagehandler.h"

namespace mqg
{
namespace Core
{
Application::NullJSScriptEngine Application::_nullJSScriptEngine;
Application::NullMessageHandler Application::_nullMessageHandler;

Application::Application(QObject *parent)
  : QObject(parent),
    m_jsScriptEngineService(&_nullJSScriptEngine),
    m_messageHandlerService(&_nullMessageHandler) {}

JSScriptEngine* Application::getJSScriptEngine()
{
  return Application::instance().m_jsScriptEngineService;
}

MessageHandler* Application::getMessangeHandler()
{
  return Application::instance().m_messageHandlerService;
}

Application& Application::instance()
{
  static Application *instance = new Application();
  return *instance;
}

void Application::provide(JSScriptEngine *service)
{
  Application &instance = Application::instance();

  if (service == nullptr) {
    instance.m_jsScriptEngineService = &_nullJSScriptEngine;
  } else {
    service->setParent(&instance);
    instance.m_jsScriptEngineService = service;
  }
}

void Application::provide(MessageHandler *service)
{
  Application &instance = Application::instance();

  if (service == nullptr) {
    instance.m_messageHandlerService = &_nullMessageHandler;
  } else {
    service->setParent(&instance);
    instance.m_messageHandlerService = service;
  }
}
} // namespace Core
} // namespace mqg

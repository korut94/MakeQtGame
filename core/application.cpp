#include "application.h"
#include "Private/nulljsscriptengine.h"
#include "Private/nullmessagehandler.h"

#include <QDebug>

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

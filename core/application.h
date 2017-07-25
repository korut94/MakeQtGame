#ifndef APPLICATION_H
#define APPLICATION_H

#include "jsscriptengine.h"
#include "messagehandler.h"

#include <QObject>

namespace mqg
{
namespace Core
{
class Application : public QObject
{
  Q_OBJECT
  Q_DISABLE_COPY(Application)
  Q_PROPERTY(JSScriptEngine* script   READ getJSScriptEngine  WRITE provide)
  Q_PROPERTY(MessageHandler* message  READ getMessangeHandler WRITE provide)

  class NullJSScriptEngine;
  class NullMessageHandler;

public:
  static JSScriptEngine*  getJSScriptEngine();
  static MessageHandler*  getMessangeHandler();
  static Application&     instance();
  static void             provide(JSScriptEngine *service);
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

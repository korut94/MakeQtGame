#include "application.h"
#include "messageadapterforqt.h"

#include <assert.h>

namespace mqg
{
namespace Core
{
void MessageAdapterForQt::installAsQtMessageHandler()
{
  qInstallMessageHandler([] (QtMsgType type,
                             const QMessageLogContext &context,
                             const QString &msg) {
    MessageHandler *handler = Application::getMessangeHandler();

    assert(dynamic_cast<MessageAdapterForQt*>(handler) != nullptr);

    switch (type) {
    case QtDebugMsg: emit handler->log(Message(msg, context)); break;
    case QtInfoMsg: emit handler->info(Message(msg, context)); break;
    case QtWarningMsg: emit handler->warn(Message(msg, context)); break;
    case QtCriticalMsg: emit handler->error(Message(msg, context)); break;
    case QtFatalMsg: break;
    }
  });
}
} // namespace Core
} // namespace mqg

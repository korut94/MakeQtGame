#ifndef NULLMESSAGEHANDLER_H
#define NULLMESSAGEHANDLER_H

#include "application.h"

namespace mqg
{
namespace Core
{
class Application::NullMessageHandler : public MessageHandler
{
  Q_OBJECT
};
} // namespace Core
} // namespace mqg

#endif // NULLMESSAGEHANDLER_H

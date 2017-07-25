#ifndef MESSAGEADAPTERFORQT_H
#define MESSAGEADAPTERFORQT_H

#include "messagehandler.h"

namespace mqg
{
namespace Core
{
class MessageAdapterForQt : public MessageHandler
{
  Q_OBJECT

public:
  void installAsQtMessageHandler();
};
} // namespace Core
} // namespace mqg

#endif // MESSAGEADAPTERFORQT_H

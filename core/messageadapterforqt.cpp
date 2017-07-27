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
#include "messageadapterforqt.h"

#include <assert.h>

namespace mqg
{
namespace Core
{
void
MessageAdapterForQt::handleMessageByEmitting(QtMsgType type,
                                             const QMessageLogContext &context,
                                             const QString &msg)
{
  MessageHandler *handler = Application::getMessangeHandler();

  assert(dynamic_cast<MessageAdapterForQt*>(handler) != nullptr);

  switch (type) {
  case QtDebugMsg: emit handler->log(Message(msg, context)); break;
  case QtInfoMsg: emit handler->info(Message(msg, context)); break;
  case QtWarningMsg: emit handler->warn(Message(msg, context)); break;
  case QtCriticalMsg: emit handler->error(Message(msg, context)); break;
  case QtFatalMsg: emit handler->fatal(Message(msg, context)); abort();
  };
}

void MessageAdapterForQt::installAsQtMessageHandler()
{
  qInstallMessageHandler(handleMessageByEmitting);
}

void MessageAdapterForQt::restoreDefaultQtMessageHandler()
{
  qInstallMessageHandler(0);
}
} // namespace Core
} // namespace mqg

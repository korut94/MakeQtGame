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

#ifndef MESSAGEADAPTERFORQT_H
#define MESSAGEADAPTERFORQT_H

#include "messagehandler.h"

namespace mqg
{
namespace Core
{
/*!
 * The MessageAdapterForQt class adapts QMessageLogger to make it in compilance
 * with MessageHandler interface.
 */
class MessageAdapterForQt : public MessageHandler
{
  Q_OBJECT

public:
  /*!
   * Installs the MessageAdapterForQt's message handler as Qt message handler.
   *
   * The MessageAdapterForQt's message handler emits all the messages generated
   * from a QMessageLogger. In other worlds when the applications would prints
   * by invoking qCritical(), qDebug(), qFatal(), qInfo() and qWarning() the
   * following signals are emitted rispectively:
   * - MessageHandler::error() for *critical* messages
   * - MessageHandler::log() for *debug* messages
   * - MessageHandler::fatal() for *fatal* messages
   * - MessageHandler::info() for *info* messages
   * - MessageHandler::warn() for *warning* messages
   *
   * In the case of *fatal* messages the application will be aborted after the
   * fatal signal emission. In all cases no message one has an agreed output
   * because it depends on which slot the signal has been connected before
   * its emission.
   */
  void installAsQtMessageHandler();
  /*!
   * Installs the default Qt message handler.
   */
  void restoreDefaultQtMessageHandler();

private:
  static void handleMessageByEmitting(QtMsgType type,
                                      const QMessageLogContext &context,
                                      const QString &msg);
};
} // namespace Core
} // namespace mqg

#endif // MESSAGEADAPTERFORQT_H

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

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>

namespace mqg
{
namespace Core
{
/*!
 * The Message class is a container for the information about an application
 * message.
 *
 * Since that QMetaType knows the type Message, it can be used in a QVariant as
 * well as inside JavaScript context, as value-type, through either QJSEngine
 * or inside a QML application.
 *
 * For each attributes the Message defines a counterpart property as well.
 *
 * The class is an constant class therefore once that it is instantiated no
 * modifies can be applied anymore.
 */
class Message
{
  Q_GADGET
  //! Category of the message.
  Q_PROPERTY(QString  category  READ category)
  //! The file name where the debug action has been done.
  Q_PROPERTY(QString  file      READ file)
  //! The function name where the debug action has been done.
  Q_PROPERTY(QString  function  READ function)
  //! The line of the file where the debug action has been done.
  Q_PROPERTY(int      line      READ line)
  //! The message content.
  Q_PROPERTY(QString  text      READ text)
  //! Version.
  Q_PROPERTY(int      version   READ version)

public:
  /*!
   * Creates a Message with *text* as content.
   *
   * The other attributes are instantiated with default values:
   * - `"No setted in this context"` for string value
   * - -1 for integer value
   */
  explicit Message(const QString &text = QString());
  /*!
   * Creates a Message with *text* as content and other information taked from
   * *context*.
   */
  Message(const QString &text, const QMessageLogContext &context);

  /*!
   * Returns the message category.
   */
  inline QString  category()  const { return m_category; }
  /*!
   * Returns the file name.
   */
  inline QString  file()      const { return m_file; }
  /*!
   * Returns the function name.
   */
  inline QString  function()  const { return m_function; }
  /*!
   * Returns the line of the file.
   */
  inline int      line()      const { return m_line; }
  /*!
   * Returns the message content.
   */
  inline QString  text()      const { return m_text; }
  /*!
   * Returns the version.
   */
  inline int      version()   const { return m_version; }

private:
  static const int   _UNDEFINED_INTEGER_ATTRIBUTE;
  static const char *_UNDEFINED_STRING_ATTRIBUTE;
  const char        *m_category;
  const char        *m_file;
  const char        *m_function;
  int                m_line;
  QString            m_text;
  int                m_version;
};

/*!
 * The MessageHandler interface defines what services a message handler service
 * has to provide.
 */
class MessageHandler : public QObject
{
  Q_OBJECT

signals:
  /*!
   * Emits when a message of category error is require.
   */
  void error(const Message &message);
  /*!
   * Emits when a message of category fatal is require.
   */
  void fatal(const Message &message);
  /*!
   * Emits when a message of category info is require.
   */
  void info(const Message &message);
  /*!
   * Emits when a message of category debug is require.
   */
  void log(const Message &message);
  /*!
   * Emits when a message of category warning is require.
   */
  void warn(const Message &message);
};
} // namespace Core
} // namespace mqg

Q_DECLARE_METATYPE(mqg::Core::Message)

#endif // MESSAGEHANDLER_H

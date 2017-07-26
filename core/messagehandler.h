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
class Message
{
  Q_GADGET
  Q_PROPERTY(QString  category  READ category)
  Q_PROPERTY(QString  file      READ file)
  Q_PROPERTY(QString  function  READ function)
  Q_PROPERTY(int      line      READ line)
  Q_PROPERTY(QString  text      READ text)
  Q_PROPERTY(int      version   READ version)

public:
  explicit Message(const QString &text = QString());
  Message(const QString &text, const QMessageLogContext &context);

  inline QString  category()  const { return m_category; }
  inline QString  file()      const { return m_file; }
  inline QString  function()  const { return m_function; }
  inline int      line()      const { return m_line; }
  inline QString  text()      const { return m_text; }
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

class MessageHandler : public QObject
{
  Q_OBJECT

signals:
  void error(const Message &message);
  void info(const Message &message);
  void log(const Message &message);
  void warn(const Message &message);
};
} // namespace Core
} // namespace mqg

Q_DECLARE_METATYPE(mqg::Core::Message)

#endif // MESSAGEHANDLER_H

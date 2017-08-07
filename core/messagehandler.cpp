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

#include "messagehandler.h"

namespace mqg
{
namespace Core
{
const int   Message::_UNDEFINED_INTEGER_ATTRIBUTE = -1;
const char *Message::_UNDEFINED_STRING_ATTRIBUTE = "No setted in this context";

Message::Message(const QString &text)
  : m_category(_UNDEFINED_STRING_ATTRIBUTE),
    m_file(_UNDEFINED_STRING_ATTRIBUTE),
    m_function(_UNDEFINED_STRING_ATTRIBUTE),
    m_line(_UNDEFINED_INTEGER_ATTRIBUTE),
    m_text(text),
    m_version(_UNDEFINED_INTEGER_ATTRIBUTE) {}

Message::Message(const QString &text, const QMessageLogContext &context)
  : m_category(context.category),
    m_file(context.file),
    m_function(context.function),
    m_line(context.line),
    m_text(text),
    m_version(context.version) {}
} // namespace Core
} // namespace mqg

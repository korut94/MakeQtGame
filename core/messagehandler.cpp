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
